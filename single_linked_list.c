/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file     single_linked_list.c
* @author   hongsmallgod
* @version  V1.0.0
* @data     2020-9-14 14-24-09
* @brief    单链表头文件
********************************************************************************/

#include <stdlib.h> /* For malloc()  */
#include <stdio.h>
#include "single_linked_list.h" /* For element、node  */
/* 建议使用不带 has_head_node/no_head_node 的函数：
 * 感觉它们会很少有用到，因为函数名太长了，看起来不太干净整洁的样子。学习使用似乎也需要费点时间
 *
 *  */
/********************************************************************************
* 单链表插入函数命名规则:
*   1. sll_insert 说明这个是单链表插入函数
*   2. ascending/descending  代表这个单链表是升序还是降序的
*   3. same_discard/same_head/same_tail 如果要插入的值在链表当中存在相同值，有三种选择: 丢弃、插在前面、插在后面
*   4. has_head_node/no_head_node 代表是否有头结点，有头结点、无头结点
********************************************************************************/ 
/* 画图读程序是很容易明白的  */
/* 元素类型是结构体的话，关键值在结构体内部，那么函数就需要进行更改了 */
/* 函数的错误处理统一抛给上层函数去处理？ */

/* 
** 防御性编程:
**  1. 代码的开发初期
**  2. 团队协作的开发过程中
**  3. 防止自己的傻逼错误
**  4. 性能会受到损失，但可以节省后期的代码测试和维护成本
**  5. 其性能可以在迭代开发过程中，逐渐提升
**  6. 代码的可读性是与阅读代码人员的功力深浅有关的
*/

/*
**  入参检测:
**      1. 这里有一个责任问题，到底是函数调用者检测，还是函数开发者自身做检测
**      2. 这也是一个信任问题，是选择笃信函数调用者不会出错，还是选择怀疑
**      3. 程序性能必然下降，但可以节省后期的代码测试和维护成本
*/

/******************************************************************************/
/****************************有头结点 -- START*********************************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_ascending_same_discard_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)升序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_discard_has_head_node(sll_node *head, element data)
{
    sll_node *new;
    
    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;
    
    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data <= data; head = head->next) {
        if (head->next->data == data)
            return SLL_INS_SAME;
    } 

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;
    
    head->next = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_head_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)升序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_head_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data < data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)升序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_tail_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data <= data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_descending_same_discard_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_discard_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data >= data; head = head->next) {
        if (head->next->data == data)
            return SLL_INS_SAME;
    }

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}
/*
** function  : sll_insert_descending_same_head_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_head_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data > data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}
/*
** function  : sll_insert_descending_same_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_tail_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for (; head->next && head->next->data >= data; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_unordered_head_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)乱序单链表插入函数, 直接插入到链表开始
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_unordered_head_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_unordered_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)乱序单链表插入函数, 直接插入到链表末尾
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_unordered_tail_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历到链表末尾 */
    for (; head->next; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_head_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)乱序单链表插入函数, 直接插入到链表开始
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_head_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)乱序单链表插入函数, 直接插入到链表末尾
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_tail_has_head_node(sll_node *head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历到链表末尾 */
    for (; head->next; head = head->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = head->next;

    head->next = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************有头结点 -- END***********************************/
/******************************************************************************/



/******************************************************************************/
/****************************无头结点 -- START*********************************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_ascending_same_discard_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)升序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_discard_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data)
            return SLL_INS_SAME;
    }

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_head_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)升序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_head_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data < data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)升序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_tail_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data <= data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_descending_same_discard_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)降序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_discard_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data)
            return SLL_INS_SAME;
    }

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_descending_same_head_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)降序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_head_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data > data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_descending_same_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)降序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_tail_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data >= data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_unordered_head_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)乱序单链表插入函数, 直接插入到链表开始
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_unordered_head_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*
** function  : sll_insert_unordered_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)乱序单链表插入函数, 直接插入到链表末尾
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_unordered_tail_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历到链表末尾 */
    for (; *head; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*
** function  : sll_insert_head_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)乱序单链表插入函数, 直接插入到链表开始
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_head_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)乱序单链表插入函数, 直接插入到链表末尾
** argument  : @head[in]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_tail_no_head_node(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历到链表末尾 */
    for (; *head; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************无头结点 -- END***********************************/
/******************************************************************************/

/******************************************************************************/
/****************************兼容有无头结点两种情况 -- START*******************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_ascending_same_discard
** author    : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_discard(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data)
            return SLL_INS_SAME;
    }

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_head
** author    : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_head(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data < data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_ascending_same_tail
** author    : hongsmallgod
** brief     : 升序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_ascending_same_tail(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data <= data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_descending_same_discard
** author    : hongsmallgod
** brief     : 降序单链表插入函数, 如果链表中有相同的值, 不进行插入
** argument  : @head[in]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_discard(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data)
            return SLL_INS_SAME;
    }

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_descending_same_head
** author    : hongsmallgod
** brief     : 降序单链表插入函数, 如果链表中有相同的值, 插入到起始
** argument  : @head[in[out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_head(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data > data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}

/*
** function  : sll_insert_descending_same_tail
** author    : hongsmallgod
** brief     : 降序单链表插入函数, 如果链表中有相同的值, 插入到末尾
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_descending_same_tail(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历寻找合适的插入点 */
    for(; *head && (*head)->data >= data; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_insert_head
** author    : hongsmallgod
** brief     : 乱序单链表插入函数, 直接插入到链表开始
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_head(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/*
** function  : sll_insert_tail
** author    : hongsmallgod
** brief     : 乱序单链表插入函数, 直接插入到链表末尾
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_insert_tail(sll_node **head, element data)
{
    sll_node *new;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    /* 遍历到链表末尾 */
    for (; *head; head = &(*head)->next);

    /* 为新节点申请内存空间 */
    new = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == new)
        return SLL_ERR_NOMEM;
    new->data = data;
    new->next = *head;

    *head = new;

    return SLL_INS_OK;
}
/******************************************************************************/
/****************************兼容有无头结点两种情况 -- END*********************/
/******************************************************************************/


/********************************************************************************
* 单链表删除函数命名规则:
*   1. sll_delete 说明这个是单链表删除函数
*   2. ascending/descending/unordered 代表这个单链表是升序还是降序的还是无序的
*   3. same_all/same_head/same_tail 删除链表当中所有的相同值、删除第一个、删除最后一个
*   4. has_head_node/no_head_node 代表是否有头结点，有头结点、无头结点
********************************************************************************/ 

/******************************************************************************/
/****************************有头结点 -- START*********************************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_ascending_same_all_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)升序单链表节点删除函数, 删除所有节点
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_all_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;
    int has_same = 0;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    while (head->next && head->next->data <= data) { /* 使用for循环实现不了这么简洁 */
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
    
    /* 判断是否有节点被删除 */
    if (has_same)
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_head_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)升序单链表节点删除函数, 删除第一个节点
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_head_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;

    /* 入参检测-防御性编程 */
    if (NULL == head)
        return SLL_ERR_INVAL;

    for (; head->next && head->next->data <= data; head = head->next) {
        if (head->next->data == data) {
            tmp = head->next->next;
            head->next->next = NULL;
            free(head->next);
            head->next = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)升序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_tail_has_head_node(sll_node *head, element data)
{
    sll_node *tmp1 = NULL;
    sll_node *tmp2 = NULL;
    for (; head->next && head->next->data <= data; head = head->next) {
        if (head->next->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = tmp1->next->next;
        tmp1->next->next = NULL;
        free(tmp1->next);
        tmp1->next = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_descending_same_all_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表节点删除函数, 删除所有节点
** argument  : @head[in]: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_all_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;
    int has_same = 0;
    while (head->next && head->next->data >= data) {
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
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_head_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)降序单链表节点删除函数, 删除第一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_head_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;
    for (; head->next && head->next->data >= data; head = head->next) {
        if (head->next->data == data) {
            tmp = head->next->next;
            head->next->next = NULL;
            free(head->next);
            head->next = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)降序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_tail_has_head_node(sll_node *head, element data)
{
    sll_node *tmp1 = NULL;
    sll_node *tmp2 = NULL;
    for (; head->next && head->next->data >= data; head = head->next) {
        if (head->next->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = tmp1->next->next;
        tmp1->next->next = NULL;
        free(tmp1->next);
        tmp1->next = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_unordered_head_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)乱序单链表节点删除函数, 删除第一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_unordered_head_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;
    if (head->next) {
		tmp = head->next->next;
		head->next->next = NULL;
		free(head->next);
		head->next = tmp;
		return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_unordered_tail_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)乱序单链表节点删除函数, 删除最后一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_unordered_tail_has_head_node(sll_node *head, element data)
{
    if (NULL != head->next) {
        for (; head->next->next; head = head->next);
		free(head->next);
		head->next = NULL;
		return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_head_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)乱序单链表节点删除函数, 删除第一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_head_has_head_node(sll_node *head, element data)
{
    sll_node *tmp = NULL;
    if (head->next) {
		tmp = head->next->next;
		head->next->next = NULL;
		free(head->next);
		head->next = tmp;
		return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_tail_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)乱序单链表节点删除函数, 删除最后一个节点
** argument  : @head: (有头结点)头指针; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_tail_has_head_node(sll_node *head, element data)
{
    if (NULL != head->next) {
        for (; head->next->next; head = head->next);
		free(head->next);
		head->next = NULL;
		return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/******************************************************************************/
/****************************有头结点 -- END***********************************/
/******************************************************************************/

/******************************************************************************/
/****************************无头结点 -- START*********************************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_ascending_same_all_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)升序单链表节点删除函数, 删除所有节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_all_no_head_node(sll_node **head, element data)
{
    sll_node *tmp = NULL;
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
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_head_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)升序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_head_no_head_node(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)升序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_tail_no_head_node(sll_node **head, element data)
{
    sll_node **tmp1 = NULL; /* 保存最后一个要删除元素的节点  */
    sll_node *tmp2 = NULL; /* 删除节点时的中间变量 */
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = (*tmp1)->next;
        (*tmp1)->next = NULL;
        free(*tmp1);
        *tmp1 = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_descending_same_all_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除所有节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_all_no_head_node(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    int has_same = 0;
    while (*head && (*head)->data >= data) {
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
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_head_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_head_no_head_node(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    for (; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_tail_no_head_node(sll_node **head, element data)
{
    sll_node **tmp1 = NULL; /* 保存最后一个要删除元素的节点  */
    sll_node *tmp2 = NULL; /* 删除节点时的中间变量 */
    for (; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = (*tmp1)->next;
        (*tmp1)->next = NULL;
        free(*tmp1);
        *tmp1 = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_unordered_head_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_unordered_head_no_head_node(sll_node **head, element data)
{
    sll_node *tmp; /* 两数交换的中间变量 */
    /* 如果链表不是空链表 */
    if (*head) {
        tmp = (*head)->next;
        (*head)->next = NULL;
        free(*head);
        *head = tmp;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*
** function  : sll_delete_unordered_tail_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_unordered_tail_no_head_node(sll_node **head, element data)
{
    /* 如果链表不是空链表 */
    if (*head) {
        /* 直接遍历到 *head 指向最后一个节点 */
        for (; (*head)->next; head = &(*head)->next);
        free(*head);
        *head = NULL;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*
** function  : sll_delete_head_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_head_no_head_node(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    /* 如果链表不是空链表 */
    if (*head) {
        tmp = (*head)->next;
        (*head)->next = NULL;
        free(*head);
        *head = tmp;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*
** function  : sll_delete_tail_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)降序单链表节点删除函数, 删除最后一个节点
** argument  : @head[in][out]: (无头结点)头指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_tail_no_head_node(sll_node **head, element data)
{
    /* 如果链表不是空链表 */
    if (*head) {
        /* 直接遍历到 *head 指向最后一个节点 */
        for (; (*head)->next; head = &(*head)->next);
        free(*head);
        *head = NULL;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************无头结点 -- END***********************************/
/******************************************************************************/


/******************************************************************************/
/****************************兼容有无头结点两种情况 -- START*******************/
/******************************************************************************/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_ascending_same_all
** author    : hongsmallgod
** brief     : 升序单链表节点删除函数, 删除相同所有节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_all(sll_node **head, element data)
{
    sll_node *tmp = NULL;
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
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_head
** author	 : hongsmallgod
** brief     : 升序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_head(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_ascending_same_tail
** author    : hongsmallgod
** brief     : 升序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_ascending_same_tail(sll_node **head, element data)
{
    sll_node **tmp1 = NULL; /* 保存最后一个要删除元素的节点  */
    sll_node *tmp2 = NULL; /* 删除节点时的中间变量 */
    for (; *head && (*head)->data <= data; head = &(*head)->next) {
        if ((*head)->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = (*tmp1)->next;
        (*tmp1)->next = NULL;
        free(*tmp1);
        *tmp1 = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_descending_same_all
** author    : hongsmallgod
** brief     : 降序单链表节点删除函数, 删除所有节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_all(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    int has_same = 0;
    while (*head && (*head)->data >= data) {
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
        return SLL_INS_OK;
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_head
** author	 : hongsmallgod
** brief     : 降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_head(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    for (; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data) {
            tmp = (*head)->next;
            (*head)->next = NULL;
            free(*head);
            *head = tmp;
            return SLL_INS_OK;
        }
    }
    return SLL_DEL_NOVAL;
}

/*
** function  : sll_delete_descending_same_tail
** author    : hongsmallgod
** brief     : 降序单链表节点删除函数, 如果有相同的元素，删除最后一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_descending_same_tail(sll_node **head, element data)
{
    sll_node **tmp1 = NULL; /* 保存最后一个要删除节点的指针的地址  */
    sll_node *tmp2 = NULL;  /* 删除节点时的中间变量 */
    for (; *head && (*head)->data >= data; head = &(*head)->next) {
        if ((*head)->data == data)
            tmp1 = head;
    }   
    if (NULL != tmp1) {
        tmp2 = (*tmp1)->next;
        (*tmp1)->next = NULL;
        free(*tmp1);
        *tmp1 = tmp2;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_delete_head
** author	 : hongsmallgod
** brief     : 降序单链表节点删除函数, 删除第一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_head(sll_node **head, element data)
{
    sll_node *tmp = NULL;
    /* 如果链表不是空链表 */
    if (*head) {
        tmp = (*head)->next;
        (*head)->next = NULL;
        free(*head);
        *head = tmp;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*
** function  : sll_delete_tail
** author	 : hongsmallgod
** brief     : 降序单链表节点删除函数, 删除最后一个节点
** argument  : @head[in][out]: 首元节点指针的地址; @data[in]: 关键值
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_delete_tail(sll_node **head, element data)
{
    /* 如果链表不是空链表 */
    if (*head) {
        /* 直接遍历到 *head 指向最后一个节点 */
        for (; (*head)->next; head = &(*head)->next);
        free(*head);
        *head = NULL;
        return SLL_INS_OK;
    }
    return SLL_DEL_NOVAL;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************兼容有无头结点两种情况 -- END*********************/
/******************************************************************************/

/*******************************************************************************
* 单链表创建函数命名规则:
*   1. sll_create 说明这个是单链表删除函数
*   2. ascending/descending/unordered/null 代表这个单链表是升序还是降序的还是无序的,抑或是空链表
*   3. has_head_node/no_head_node 代表是否有头结点，有头结点、无头结点
*******************************************************************************/ 

/******************************************************************************/
/****************************有头结点 -- START*********************************/
/******************************************************************************/
/*
** function  : sll_create_null_has_head_node
** author	 : hongsmallgod
** brief     : 创建(有头结点)空链表 
** argument  : @head[out]: (有头结点)头指针的地址
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_null_has_head_node(sll_node **head)
{
    *head = (sll_node *)malloc(sizeof(sll_node));
    if (NULL == *head)
        return SLL_ERR_NOMEM;
    (*head)->next = NULL;
    
    return SLL_CRE_OK;
}

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_ascending_has_head_node
** author	 : hongsmallgod
** brief     : 创建(有头结点)升序链表 
** argument  : @head[in]: (有头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_ascending_has_head_node(sll_node **head, element array[], size_t size)
{
    if (SLL_ERR_NOMEM == sll_create_null_has_head_node(head))
        return SLL_ERR_NOMEM;
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_ascending_same_head_has_head_node(*head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_descending_has_head_node
** author	 : hongsmallgod
** brief     : 创建(有头结点)升序链表 
** argument  : @head[in]: (有头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_descending_has_head_node(sll_node **head, element array[], size_t size)
{
    if (SLL_ERR_NOMEM == sll_create_null_has_head_node(head))
        return SLL_ERR_NOMEM;
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_descending_same_head_has_head_node(*head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_unordered_has_head_node
** author	 : hongsmallgod
** brief     : 创建(有头结点)升序链表 
** argument  : @head[in]: (有头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_unordered_has_head_node(sll_node **head, element array[], size_t size)
{
    if (SLL_ERR_NOMEM == sll_create_null_has_head_node(head))
        return SLL_ERR_NOMEM;
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_unordered_tail_has_head_node(*head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************有头结点 -- END***********************************/
/******************************************************************************/

/******************************************************************************/
/****************************无头结点 -- START*********************************/
/******************************************************************************/
/*
** function  : sll_create_null_no_head_node
** author	 : hongsmallgod
** brief     : 创建(无头结点)空链表 
** argument  : @head[out]: (无头结点)头指针的地址
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_null_no_head_node(sll_node **head)
{
    *head = NULL;
    return SLL_CRE_OK;
}

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_ascending_no_head_node
** author	 : hongsmallgod
** brief     : 创建(无头结点)升序链表 
** argument  : @head[out]: (无头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_ascending_no_head_node(sll_node **head, element array[], size_t size)
{
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_ascending_same_head_no_head_node(head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!升序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_descending_no_head_node
** author	 : hongsmallgod
** brief     : 创建(无头结点)降序链表 
** argument  : @head[out]: (无头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_descending_no_head_node(sll_node **head, element array[], size_t size)
{
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_descending_same_tail_no_head_node(head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!降序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*
** function  : sll_create_unordered_no_head_node
** author	 : hongsmallgod
** brief     : 创建(无头结点)乱序链表 
** argument  : @head[out]: (无头结点)头指针的地址; @array[in]: 数组首地址; @size[in]: 数组大小
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_create_unordered_no_head_node(sll_node **head, element array[], size_t size)
{
    for (int i = 0; i < size; i++) {
        if (SLL_ERR_NOMEM == sll_insert_unordered_tail_no_head_node(head, array[i])) {
            sll_destroy(*head);
            return SLL_ERR_NOMEM;
        }
    }
    return SLL_CRE_OK;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!乱序 -- END!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/******************************************************************************/
/****************************无头结点 -- END***********************************/
/******************************************************************************/
/*
** function  : sll_destroy
** author	 : hongsmallgod
** brief     : 销毁单链表
** argument  : @head[in]: 头指针
** return 	 : none
*/
void sll_destroy(sll_node *head)
{
    sll_node *tmp;
    sll_node *current = head;

    while (current) {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}
#if 0
/*
** function  : sll_traversal_has_head_node
** author	 : hongsmallgod
** brief     : 遍历单链表， 只适用于 数据域为 int 型数据
** argument  : @head[in]: (有头结点)头指针
** return 	 : none
*/
void sll_traversal_has_head_node(sll_node *head)
{
    while (head = head->next)
        printf("%5d ", head->data);
    printf("\n");
}
/*
** function  : sll_traversal_no_head_node
** author    : hongsmallgod
** brief     : 遍历单链表， 只适用于 数据域为 int 型数据
** argument  : @head[in]: (无头结点)头指针
** return    : none
*/
void sll_traversal_no_head_node(sll_node *head)
{
    for (;head ;head = head->next)
        printf("%5d ", head->data);
    printf("\n");
}
/*
** function  : sll_traversal
** author    : hongsmallgod
** brief     : 遍历单链表， 只适用于 数据域为 int 型数据
** argument  : @head[in]: 首元节点指针
** return    : none
*/
void sll_traversal(sll_node *head)
{
    for (;head ;head = head->next)
        printf("%5d ", head->data);
    printf("\n");
}
#endif
/****************************有头结点 -- START*********************************/
/*
** function  : sll_get_head_has_head_node
** author    : hongsmallgod
** brief     : 获取单链表第一个元素
** argument  : @head[in]: (有头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_head_has_head_node(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;
    
    *data = head->next->data;
    return SLL_OK;
}

/*
** function  : sll_get_and_delete_head_has_head_node
** author    : hongsmallgod
** brief     : 获取并删除单链表第一个元素
** argument  : @head[in]: (有头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_head_has_head_node(sll_node *head, element *data)
{
    sll_node *tmp;
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;
    
    /* 获取数据 */
    *data = head->next->data;

    /* 删除节点 */
	tmp = head->next->next;
	head->next->next = NULL;
	free(head->next);
	head->next = tmp;
	return SLL_OK;
}
/****************************有头结点 -- END***********************************/
/****************************无头结点 -- START*********************************/
/*
** function  : sll_get_head_no_head_node
** author    : hongsmallgod
** brief     : 获取单链表第一个元素
** argument  : @head[in]: (无头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_head_no_head_node(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head == NULL)
        return SLL_ERR_EMPTY;
    
    *data = head->data;
    return SLL_OK;
}

/*
** function  : sll_get_and_delete_head_no_head_node
** author    : hongsmallgod
** brief     : 获取并删除单链表第一个元素
** argument  : @head[in]: (无头结点)头指针的地址; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_head_no_head_node(sll_node **head, element *data)
{
    sll_node *tmp;

    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (*head == NULL)
        return SLL_ERR_EMPTY;
    
    /* 获取数据 */
    *data = (*head)->data;

    /* 删除节点 */
	tmp = (*head)->next;
	(*head)->next = NULL;
	free(*head);
	*head = tmp;
	return SLL_OK;
}
/****************************无头结点 -- END***********************************/
/****************************兼容有无头结点两种情况 -- START*******************/
/*
** function  : sll_get_head
** author    : hongsmallgod
** brief     : 获取单链表第一个元素
** argument  : @head[in]: 首元节点指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_head(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head == NULL)
        return SLL_ERR_EMPTY;
    
    *data = head->data;
    return SLL_OK;
}
/*
** function  : sll_get_and_delete_head
** author    : hongsmallgod
** brief     : 获取并删除单链表第一个元素
** argument  : @head[in]: 首元节点指针的地址; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_head(sll_node **head, element *data)
{
    sll_node *tmp;

    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (*head == NULL)
        return SLL_ERR_EMPTY;
    
    /* 获取数据 */
    *data = (*head)->data;

    /* 删除节点 */
	tmp = (*head)->next;
	(*head)->next = NULL;
	free(*head);
	*head = tmp;
	return SLL_OK;
}
/****************************兼容有无头结点两种情况 -- END*********************/

/****************************有头结点 -- START*********************************/
/*
** function  : sll_get_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)获取单链表最后一个元素
** argument  : @head[in]: (有头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_tail_has_head_node(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;

    /* 遍历链表，直到指针指向最后一个节点 */
    for (; head->next; head = head->next);
    *data = head->data;
    return SLL_OK;
}

/*
** function  : sll_get_and_delete_tail_has_head_node
** author    : hongsmallgod
** brief     : (有头结点)获取并删除单链表最后一个元素
** argument  : @head[in]: (有头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_tail_has_head_node(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;
    
    /* 遍历链表，直到指针指向倒数第二个节点 */
    for (; head->next->next; head = head->next);

    /* 获取数据 */
    *data = head->next->data;

    /* 删除节点*/
    free(head->next);
    head->next = NULL;
    return SLL_OK;

}
/****************************有头结点 -- END***********************************/

/****************************无头结点 -- START*********************************/
/*
** function  : sll_get_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)获取单链表最后一个元素
** argument  : @head[in]: (无头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_tail_no_head_node(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head == NULL)
        return SLL_ERR_EMPTY;

    /* 遍历链表，直到指针指向最后一个节点 */
    for (head = head->next; head->next; head = head->next);
    *data = head->data;
    return SLL_OK;
}

/*
** function  : sll_get_and_delete_tail_no_head_node
** author    : hongsmallgod
** brief     : (无头结点)获取并删除单链表最后一个元素
** argument  : @head[in]: (无头结点)头指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_tail_no_head_node(sll_node **head, element *data)
{
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (*head == NULL)
        return SLL_ERR_EMPTY;
    
    /* 遍历链表，直到*head指向最后一个节点 */
    for (; (*head)->next; head = &(*head)->next);

    /* 获取数据 */
    *data = (*head)->data;

    /* 删除节点*/
    free(*head);
    *head = NULL;
    return SLL_OK;

}
/****************************无头结点 -- END***********************************/
/****************************兼容有无头结点两种情况 -- START*******************/
/*
** function  : sll_get_tail
** author    : hongsmallgod
** brief     : 获取单链表最后一个元素
** argument  : @head[in]: 首元节点指针; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_tail(sll_node *head, element *data)
{
    /* 入参检测-防御性编程 */
    if (data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (head == NULL)
        return SLL_ERR_EMPTY;

    /* 遍历链表，直到指针指向最后一个节点 */
    for (; head->next; head = head->next);
    *data = head->data;
    return SLL_OK;
}
/*
** function  : sll_get_and_delete_tail
** author    : hongsmallgod
** brief     : 获取并删除单链表最后一个元素
** argument  : @head[in]: 首元节点指针的地址; @data[out]: 数据指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_get_and_delete_tail(sll_node **head, element *data)
{
    /* 入参检测-防御性编程 */
    if (head == NULL || data == NULL)
        return SLL_ERR_INVAL;
    
    /* 判断是否为空链表 */
    if (*head == NULL)
        return SLL_ERR_EMPTY;
    
    /* 遍历链表，直到*head指向最后一个节点 */
    for (; (*head)->next; head = &(*head)->next);

    /* 获取数据 */
    *data = (*head)->data;

    /* 删除节点*/
    free(*head);
    *head = NULL;
    return SLL_OK;

}
/****************************有头结点 -- START*********************************/
/*
** function  : sll_get_node_num_has_head_node
** author	 : hongsmallgod
** brief     : 获取单链表(元素)节点数
** argument  : @head[in]: (有头结点)头指针
** return 	 : SLL_ERR_INVAL: 指针参数为空; @count: 元素节点数
*/
SLL_RET sll_get_node_num_has_head_node(sll_node *head)
{
    int count = 0;
    
    /* 入参检测-防御性编程 */
    if (head == NULL)
        return SLL_ERR_INVAL;
    
    /* 统计元素节点数目*/
    for (; head->next; head = head->next)
        count++;
    return count;
}
/****************************有头结点 -- END***********************************/
/****************************无头结点 -- START*********************************/
/*
** function  : sll_get_node_num_no_head_node
** author	 : hongsmallgod
** brief     : 获取单链表(元素)节点数
** argument  : @head[in]: (无头结点)头指针
** return 	 : @count: 元素节点数
*/
SLL_RET sll_get_node_num_no_head_node(sll_node *head)
{
    int count = 0;
    
    /* 统计元素节点数目*/
    for (; head; head = head->next)
        count++;
    return count;
}
/****************************无头结点 -- END***********************************/
/****************************兼容有无头结点两种情况 -- START*******************/
/*
** function  : sll_get_node_num
** author	 : hongsmallgod
** brief     : 获取单链表(元素)节点数
** argument  : @head[in]: 首元节点指针
** return 	 : @count: 元素节点数
*/
SLL_RET sll_get_node_num(sll_node *head)
{
    int count = 0;
    
    /* 统计元素节点数目*/
    for (; head; head = head->next)
        count++;
    return count;
}
/****************************兼容有无头结点两种情况 -- END*********************/

/****************************有头结点 -- START*********************************/
#if 0
/*
** function  : sll_sort_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)单链表排序函数(冒泡法)
** argument  : @head[in]: (有头结点)头指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_sort_has_node_head(sll_node *head)
{
    int num;  /* 元素节点数 */
    int flag; /* 记录最后一次交换的地点 */
    int tmp;  /* 用于两数交换的中间变量 */
    int k;    /* 比较次数 */

    /* 入参检测 */
    if (head == NULL)
        return SLL_ERR_INVAL;

    /* 判断链表是否为空 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;
    head = head->next;
    num = sll_get_node_num_has_head_node(head);
    int k = num - 1;
    while (k) {
    	flag = 0;
        for (int i = 0; i < k; i++) {
            if (head->data > head->next->data) {
                tmp = head->data;
                head->data = head->next->data;
                head->next->data = tmp;
                flag = i;
            }
            head = head->next;
        }
        k = flag;
        head = head->next;
    }
    return SLL_OK;
}
#endif
/****************************有头结点 -- END***********************************/

/****************************无头结点 -- START*********************************/
#if 0
/*
** function  : sll_sort_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)单链表排序函数(冒泡法)
** argument  : @head[in]: (无头结点)头指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_sort(sll_node *head)
{
    int num;  /* 元素节点数 */
    int flag; /* 记录最后一次交换的地点 */
    int tmp;  /* 用于两数交换的中间变量 */
    int k;    /* 比较次数 */

    /* 判断链表是否为空 */
    if (head == NULL)
        return SLL_ERR_EMPTY;

    num = sll_get_node_num_has_head_node(head);
    int k = num - 1;
    while (k) {
    	flag = 0;
        for (int i = 0; i < k; i++) {
            if (head->data > head->next->data) {
                tmp = head->data;
                head->data = head->next->data;
                head->next->data = tmp;
                flag = i;
            }
            head = head->next;
        }
        k = flag;
        head = head->next;
    }
    return SLL_OK;
}
#endif
/****************************无头结点 -- END***********************************/
/****************************兼容有无头结点两种情况 -- START*******************/
#if 0
/*
** function  : sll_sort
** author	 : hongsmallgod
** brief     : 单链表排序函数(冒泡法)
** argument  : @head[in]: 首元节点指针
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_sort(sll_node *head)
{
    int num;  /* 元素节点数 */
    int flag; /* 记录最后一次交换的地点 */
    int tmp;  /* 用于两数交换的中间变量 */
    int k;    /* 比较次数 */

    /* 判断链表是否为空 */
    if (head == NULL)
        return SLL_ERR_EMPTY;

    num = sll_get_node_num_has_head_node(head);
    int k = num - 1;
    while (k) {
    	flag = 0;
        for (int i = 0; i < k; i++) {
            if (head->data > head->next->data) {
                tmp = head->data;
                head->data = head->next->data;
                head->next->data = tmp;
                flag = i;
            }
            head = head->next;
        }
        k = flag;
        head = head->next;
    }
    return SLL_OK;
}
#endif
/****************************兼容有无头结点两种情况 -- END*********************/
/*
** function  : sll_query_has_head_node
** author	 : hongsmallgod
** brief     : (有头结点)单链表查询函数(冒泡法)
** argument  : @head[in]: (有头结点)头指针; @data[in]: 要查询的数据
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_query_has_head_node(sll_node *head, element data)
{
    /* 入参检测 */
    if (head == NULL)
        return SLL_ERR_INVAL;

    /* 判断链表是否为空 */
    if (head->next == NULL)
        return SLL_ERR_EMPTY;
    
    for (head = head->next; head; head = head->next) {
        if (head->data == data)
           return SLL_QUE_OK;
    }
    return SLL_QUE_NOVAL;
} 

/*
** function  : sll_query_no_head_node
** author	 : hongsmallgod
** brief     : (无头结点)单链表查询函数(冒泡法)
** argument  : @head[in]: (无头结点)头指针; @data[in]: 要查询的数据
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_query_no_head_node(sll_node *head, element data)
{
    /* 判断链表是否为空 */
    if (head == NULL)
        return SLL_ERR_EMPTY;
    
    do {
        if (head->data == data)
            return SLL_QUE_OK;
    } while (head = head->next);
    return SLL_QUE_NOVAL;
} 

/*
** function  : sll_query
** author	 : hongsmallgod
** brief     : 单链表查询函数(冒泡法)
** argument  : @head[in]: 首元节点指针; @data[in]: 要查询的数据
** return 	 : 参考@SLL_RET
*/
SLL_RET sll_query(sll_node *head, element data)
{
    /* 判断链表是否为空 */
    if (head == NULL)
        return SLL_ERR_EMPTY;
    
    do {
        if (head->data == data)
            return SLL_QUE_OK;
    } while (head = head->next);
    return SLL_QUE_NOVAL;
} 
