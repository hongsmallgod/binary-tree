#include <stdio.h>  
#include "common.h"
#include <stdlib.h>
#include "element_definition.h"
//#include "single_linked_list1.h"
typedef struct sll_node node;
struct sll_node {
    element data;
    int pos;
    node *next;
};
/*
** function  : sll_insert_ascending_same_head_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)升序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head: (有头结点)头指针; @data: 关键值
** return    : -2: 指针参数为空; -1: 内存不足; 1: 插入成功;
*/
int sll_insert_ascending_same_head_has_head_node(node *head, element data)
{
    node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return -2;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data < data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return 1;
}

/*
** function  : sll_insert_descending_same_head_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head: (有头结点)头指针; @data: 关键值
** return    : -2: 指针参数为空; -1: 内存不足; 1: 插入成功;
*/
int sll_insert_descending_same_head_has_head_node(node *head, element data)
{
    node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return -2;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data >= data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return 1;
}

/*
** function  : sll_insert_ascending_same_discard_no_head_node
** author    : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head: (无头结点)头指针的地址; @data: 关键值
** return    : 1: 插入成功; -1: 内存不足; 0:链表当中有相同的内容i; -2: 指针参数为空
*/
int sll_insert_ascending_same_discard_no_head_node(node **head, element data)
{
    node **current = head;
    node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return -2;

    /* 遍历寻找合适的插入点 */
    for(; *current && (*current)->data <= data; current = &(*current)->next) {
        if ((*current)->data == data)
            return 0;
    }

    /* 为新节点申请内存空间 */
    new = (node *)malloc(sizeof(node));
    if (NULL == new)
        return -1;
    new->data = data;
    new->next = *current;

    *current = new;

    return 1;
}
int sll_delete_ascending_same_all_has_head_node(node *head, element data)
{
    node *tmp = NULL;
    int has_same = 0;
    while (head->next && head->next->data <= data) {
        if (head->next->data == data) {
            tmp = head->next->next;
            head->next->next = NULL;
            free(head->next);
            head->next = tmp;
            has_same = 1;
            continue;
        }
        head = head->next;
    }
    if (has_same)
        return 1;
    return 0;
}

/*
** function  : sll_delete_ascending_same_head_has_head_node
** author    : hongsmallgod
** brief     : 升序单链表节点删除函数, 删除第一个节点
** argument  : @head: (有头结点)头指针; @data: 关键值
** return    : 1: 删除成功; 0: 链表当中没有所要删除的元素
*/
int sll_delete_ascending_same_head_has_head_node(node *head, element data)
{
    node *tmp = NULL;
    for (; head->next && head->next->data <= data; head = head->next) {
        if (head->next->data == data) {
            tmp = head->next->next;
            head->next->next = NULL;
            free(head->next);
            head->next = tmp;
            return 1;
        }   
    }   
    return 0;
}
int sll_delete_ascending_same_tail_has_head_node(node *head, element data)
{
    node *tmp1 = NULL;
    node *tmp2 = NULL;
    for (; head->next && head->next->data <= data; head = head->next) {
        if (head->next->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = tmp1->next->next;
        tmp1->next->next = NULL;
        free(tmp1->next);
        tmp1->next = tmp2;
        return 1;
    }   
    return 0;
}
int sll_delete_ascending_same_all_no_head_node(node **head, element data)
{
    node *tmp = NULL;
    int has_same = 0;
    while (*head && (*head)->data <= data) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            has_same = 1;
            continue;
        }   
        head = &(*head)->next;
    }   
    if (has_same)
        return 1;
    return 0;
}
int sll_delete_ascending_same_tail_no_head_node(node **head, element data)
{
    node **tmp1 = NULL; /* 保存最后一个要删除元素的节点  */
    node *tmp2 = NULL; /* 删除节点时的中间变量 */
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data)
            tmp1 = head;
    }
    if (NULL != tmp1) {
        tmp2 = (*tmp1)->next;
        (*tmp1)->next = NULL;
        free(*tmp1);
        *tmp1 = tmp2;
        return 1;
    }
    return 0;
}

int sll_delete_ascending_same_head_no_head_node(node **head, element data)
{
    node *tmp = NULL;
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            return 1;
        }
    }   
    return 0;
}

void sll_traversal_no_head_node(node *head)
{
    node *current = head;
    while (current) {
        printf("%5d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void sll_traversal_has_head_node(node *head)
{
    node *current = head->next;
    while (current) {
        printf("%5d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void sll_traversal_has_head_node1(node *head)
{
    while (head = head->next)
        printf("%5d ", head->data);
    printf("\n");
}

/*
 * @head: 首元节点指针
 * */
void pos_num(node *head)
{
    for (int i = 0; head; head = head->next, i++) {
        head->pos = i;
    }
}
void pos_prinrt(node *head)
{
    for (int i = 0; head; head = head->next, i++) {
       printf("%5d ", head->pos);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    //struct sll_node *head = NULL;
    struct sll_node head = {.data = 0, .next = NULL};
    int array[] = {1, 2, 3, 7,10,1000,3,1,88,3,4,-12,9,4, 5, 6};
    for (int i = 0; i < ARRAY_SIZE(array); i++) {
       //sll_insert_ascending_same_discard_no_head_node(&head, array[i]);
       sll_insert_ascending_same_head_has_head_node(&head, array[i]);
    }
    sll_traversal_has_head_node(&head);
    pos_num(head.next);
    pos_prinrt(head.next);
    printf("sll_delete_ascending_same_tail_no_head_node(&head.next, 3) = %d\n", sll_delete_ascending_same_tail_no_head_node(&head.next, 3));
    
    sll_traversal_has_head_node1(&head);
    pos_prinrt(head.next);
    //sll_delete_ascending_same_tail_no_head_node(&head.next, 3);
    //sll_traversal_has_head_node(&head);
    //pos_prinrt(head.next);

    return 0;
}
