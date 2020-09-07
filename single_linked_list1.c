#include <stdlib.h> /* For malloc()  */
#include <stdio.h>
#include "single_linked_list.h" /* For element、node  */

/*
** function  : sll_insert_ascending_same_no
** author	 : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head: 头结点指针; @data: 关键值
** return 	 : 1: 插入成功; -1: 内存不足; 0:链表当中有相同的内容
*///应该还有一个入参检测
int sll_insert_ascending_same_no(node *head, element data)
{
    node *current = head;
    node *new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;

    for (; current->next && current->next->data <= data; current = current->next) {
        if (current->next->data == data)
            return 0;
    }
    new->next = current->next;
    current->next = new;

    return 1;
}

/*
** function  : sll_insert2 (单链表的插入函数, 区别不大)
** author	 : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 插入到最后
** argument  : @head: 头结点指针; @data: 关键值
** return 	 : 1: 删除成功; -1: 内存不足;
*///如果传入了一个空指针，怎么办，这样子函数会出错的，函数需要修改
int sll_insert2(node *head, element data)
{
    node *current = head;
    node *new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;

    for (; current->next && current->next->data <= data; current = current->next);

	new->next = current->next;
	current->next = new;
    return 1;
}

/*
** function  : sll_insert3 (单链表的插入函数, 区别不大)
** author	 : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head: 头结点指针; @data: 关键值
** return 	 : 1: 删除成功; -1: 内存不足;
*/
int sll_insert3(node *head, element data)
{
    node *current = head;
    node *new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;

    for (; current->next && current->next->data < data; current = current->next);

	new->next = current->next;
	current->next = new;
    return 1;
}

/*
** function  : sll_delete1
** author	 : hongsmallgod
** brief     : 升序单链表节点删除函数, 如果相邻节点有相同的值, 删除第一个
** argument  : @head: 链表头结点指针; @data: 关键值
** return 	 : 1: 删除成功; 0: 链表当中没有所要删除的元素
*/
int sll_delete1(node *head, element data)
{
    node *current = head;
    node *tmp = NULL;
    for (; current->next; current = current->next) {
        if (current->next->data == data) {
        	tmp = current->next->next;
        	free(current->next);
            current->next = current->next->next;
            return 1;
        }
        if (current->next->data > data)
            return 0;
    }
    return 0;
}

/*
** function  : sll_delete2
** author	 : hongsmallgod
** brief     : 升序单链表节点删除函数, 如果相邻节点有相同的值, 一并删除
			   例: 2 2 1 2 3 4 5 6(这个不是升序链表), 调用这个函数删除 2 , 结果  1 3 4 5 6
** argument  : @head: 链表头结点指针; @data: 关键值
** return 	 : 1: 删除成功; 0: 链表当中没有所要删除的元素
*/
int sll_delete2(node *head, element data)
{
    node *current = head;
    node *tmp = NULL;
    int status = 0;
    while (current->next) {
        if (current->next->data == data) {
        	tmp = current->next->next;
        	free(current->next);
            current->next = tmp ;
            status = 1;
            continue;
        }
        if (current->next->data > data)
            break;
        current = current->next;
    }

    if (1 == status)
        return 1;
    return 0;
}
/*
** function  : sll_delete_head
** author	 : hongsmallgod
** brief     : 删除单链表第一个节点(首元结点)
** argument  : @head: 链表头结点指针
** return 	 : 1:删除成功; 0: 链表为空
*/
int sll_delete_head(node *head)
{
    if (NULL == head->next)
        return 0;
    node *tmp = head->next->next;
    free(head->next);
    head->next = tmp;
    return 1;
}

/*
** function  : sll_delete_tail
** author    : hongsmallgod
** brief     : 删除单链表最后一个节点(尾结点)
** argument  : @head: 链表头结点指针
** return    : 1:删除成功; 0: 链表为空
*/
int sll_delete_tail(node *head)
{
    node *current = head;
    if (NULL == head->next)
        return 0;
    for (; current->next->next; current = current->next);
    free(current->next);
    current->next = NULL;
    return 1;
}

#if 0
/*
** function  : sll_traversal
** author	 : hongsmallgod
** brief     : 遍历单链表， 只适用于 数据域为 int 型数据
** argument  : @head: 链表头结点指针
** return 	 : none
*/
void sll_traversal(node *head)
{
    node *current = head->next;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
#endif

/*
** function  : sll_insert4
** author	 : hongsmallgod
** brief     : 无序单链表插入函数, 插入到链表尾部
** argument  : @head: 头结点指针; @data: 关键值
** return 	 : 1: 插入成功; -1: 内存不足
*/
int sll_insert4(node *head, element data)
{
    node *current = head;
    node *new = NULL;
    new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;
    new->next = NULL;
    for (; current->next; current = current->next); //直接滑到链表尾部
    current->next = new;
    return 1;
}

/*
** function  : sll_insert5
** author	 : hongsmallgod
** brief     : 无序单链表插入函数, 插入到链表头
** argument  : @head: 头结点指针; @data: 关键值
** return 	 : 1: 删除成功; -1: 内存不足;
*/
int sll_insert5(node *head, element data)
{
    node *new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;

    new->next = head->next;
    head->next = new;
    return 1;
}

/*
** function  : sll_delete3
** author	 : hongsmallgod
** brief     : 单链表节点删除函数, 如果链表有相同的值, 一并删除
** argument  : @head: 链表头结点指针; @data: 关键值
** return 	 : 1: 删除成功; 0: 链表当中没有所要删除的元素
*/
int sll_delete3(node *head, element data)
{
    node *current = head;
    node *tmp = NULL;
    int status = 0;
    while (current->next) {
        if (current->next->data == data) {
        	tmp = current->next->next;
        	free(current->next);
            current->next = tmp ;
            status = 1;
            continue;
        }

        current = current->next;
    }

    if (1 == status)
        return 1;
    return 0;
}
#if 0
/*
** function  : create_sll
** author	 : hongsmallgod
** brief     : 创建单链表, 无序
** argument  : void
** return 	 : NULL:内存不足; else: 链表头节点指针
*/
node *create_sll(void)
{
    int data = -1;
    /*
    ** 创建头节点
    */
    node *head = (node *)malloc(sizeof(node));
    if (NULL == head)
            return NULL;
    head->data = 0;
    head->next = NULL;

    while (scanf("%d", &data) == 1 && data != -1) {
       sll_insert3(head, data);
    }
    return head;
}
#endif
/*
** function  : sll_destroy
** author	 : hongsmallgod
** brief     : 销毁单链表
** argument  : 链表头节点指针
** return 	 : none
*/
void sll_destroy(node *head)
{
    node *tmp;
    node *current = head;

    while (current) {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}
/*
** function  : sll_get_head
** author    : hongsmallgod
** brief     : 获取单链表第一个元素
** argument  : @head: 链表头结点指针; @data: 数据指针
** return    : 1:获取成功; 0: 链表为空
*/
int sll_get_head(node *head, element *data)
{
    if (head->next == NULL)
        return 0;
    *data = head->next->data;
    return 1;
}

/*
** function  : sll_get_tail
** author    : hongsmallgod
** brief     : 获取单链表最后一个元素
** argument  : @head: 链表头结点指针; @data: 数据指针
** return    : 1:获取成功; 0: 链表为空
*/
int sll_get_tail(node *head, element *data)
{
    node *current = head->next;
    if (NULL == head->next)
        return 0;
    for (; current->next; current = current->next);
    *data = current->data;
    return 1;
}
/*
** function  : sll_get_and_delete_head
** author    : hongsmallgod
** brief     : 获取并删除单链表第一个元素
** argument  : @head: 链表头结点指针; @data: 数据指针
** return    : 1:获取成功; 0: 链表为空
*/
int sll_get_and_delete_head(node *head, element *data)
{
    if (NULL == head->next)
        return 0;
    node *tmp = head->next->next;
    *data = head->next->data;
    free(head->next);
    head->next = tmp;
    return 1;

}

/*
** function  : sll_get_and_delete_tail
** author    : hongsmallgod
** brief     : 获取并删除单链表最后一个元素
** argument  : @head: 链表头结点指针; @data: 数据指针
** return    : 1:获取成功; 0: 链表为空
*/
int sll_get_and_delete_tail(node *head, element *data)
{
    node *current = head;
    if (NULL == head->next)
        return 0;
    for (; current->next->next; current = current->next);
    *data = current->next->data;
    free(current->next);
    current->next = NULL;
    return 1;

}
/*
** function  : get_sll_node_num
** author	 : hongsmallgod
** brief     : 获取单链表节点数
** argument  : @head: 链表头结点指针
** return 	 : @count: 节点数
*/
size_t get_sll_node_num(node *head)
{
    int count = 0;
    node *current = head;
    while (current->next) {
        count++;
        current = current->next;
    }
    return count;
}
#if 0
/*
** function  : sll_sort
** author	 : hongsmallgod
** brief     : 单链表排序函数(冒泡法)
** argument  : @head: 链表头结点指针
** return 	 : none
*/
void sll_sort(node *head)
{
    int num = get_sll_node_num(head);
    node *current = head->next;
    int flag;
    int tmp;
    if (num == 0)
        return;
    int k = num - 1;
    while (k) {
    	flag = 0;
        for (int i = 0; i < k; i++) {
            if (current->data > current->next->data) {
                tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                flag = i;
            }
            current = current->next;
        }
        k = flag;
        current = head->next;
    }
}
#endif
/*
** function  : sll_insert6
** author	 : hongsmallgod
** brief     : 单链表节点插入函数
** argument  : @rootp: 链表头指针的指针(链表头指针的地址); @data: 关键值
** return 	 : -1: 内存不足; 1:插入成功
*/
int sll_insert6(node **rootp, element data)
{
    node *current;
    node *new = (node *)malloc(sizeof(node));
    if (NULL == new)
            return -1;
    new->data = data;

    while ((current = *rootp) && current->data < data)
        rootp = &current->next;

    *rootp = new;
    new->next = current;

    return 1;
}
