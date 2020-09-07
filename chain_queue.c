/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file     chain_queue.c
* @author   hongsmallgod
* @version  V1.0.1
* @data     2019-9-10 10:31:28
* @brief    链式队列源文件
********************************************************************************/
#include <stdlib.h> // For malloc()
#include "chain_queue.h"
static int get_queue_elem_num(queue *); //关于元素 element 的定义，应该另起一个文件
static int head(queue *, element *);
static int tail(queue *, element *);
static int enqueue(queue *, element);
static int dequeue(queue *, element *);
static int full(queue *);
static int empty(queue *);

/*
** function  : create_queue
** author	 : hongsmallgod
** brief     : 创建一个队列
** argument  : void
** return 	 : @q: 队列指针; NULL: 队列申请失败
*/
queue *create_queue(void)
{
    queue *q= (queue*)malloc(sizeof(queue)); //为 队列结构体 申请空间
    if (q== NULL)
        return NULL;

    q->root = (node *)calloc(1, sizeof(node));
    if (NULL == q->root) { //队列元素头指针？
        free(q);
        return NULL;
    }

    q->num = get_queue_elem_num; //这个是函数: 获取队列元素值
    q->head = head; //获取队列头
    q->tail = tail; //获取队列尾
    q->enqueue = enqueue; // 入队
    q->dequeue = dequeue; //出队
    q->full = full;
    q->empty = empty;

    return q;
}

/*
** function  : full
** author	 : hongsmallgod
** brief     : 判断队列是都满了
** argument  : @q: 队列指针
** return 	 : 1: 满了; 0: 未满
*/
static int full(queue *q)
{
    return 0;
}

/*
** function  : empty
** author	 : hongsmallgod
** brief     : 判断队列是为空
** argument  : @q: 队列指针
** return 	 : 1: 空了; 0: 未空
*/
static int empty(queue *q)
{
    return q->root->next == NULL;
}

/*
** function  : enqueue
** author	 : hongsmallgod
** brief     : 入队操作
** argument  : @q: 队列指针(头指针？); @data: 入队元素
** return 	 : 1: 成功; 0: 失败
*/
static int enqueue(queue *q, element data)
{
    if (sll_insert4(q->root, data) == -1)
        return 0;
    return 1;
}

/*
** function  : dequeue
** author	 : hongsmallgod
** brief     : 出队操作
** argument  : @q: 队列指针; @data: 出队元素存放地址
** return 	 : 1: 成功; 0: 失败
*/
static int dequeue(queue *q, element *data)
{
    return sll_get_and_delete_head(q->root, data);
}

/*
** function  : destroy_queue
** author	 : hongsmallgod
** brief     : 销毁队列
** argument  : @q: 队列指针
** return 	 : none
*/
void destroy_queue(queue *q)
{
    sll_destroy(q->root);
    q->root = NULL;
    free(q);
}

/*
** function  : get_queue_elem_num
** author	 : hongsmallgod
** brief     : 获取队列元素数量
** argument  : @q: 队列指针
** return 	 : 队列元素数量
*/
static int get_queue_elem_num(queue *q)
{
    return get_sll_node_num(q->root);
}

/*
** function  : head
** author	 : hongsmallgod
** brief     : 获取队头元素
** argument  : @q: 队列指针; @data: 队头元素存放地址
** return 	 : 1: 成功; 0: 失败
*/
static int head(queue *q, element *data)
{
    return sll_get_head(q->root, data);
}

/*
** function  : tail
** author	 : hongsmallgod
** brief     : 获取队尾元素
** argument  : @q: 队列指针; @data: 队尾元素存放地址
** return 	 : 1: 成功; 0: 失败
*/
static int tail(queue *q, element *data)
{
    return sll_get_tail(q->root, data);
}
