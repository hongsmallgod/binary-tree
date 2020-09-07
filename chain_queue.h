/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file     chain_queue.h
* @author   hongsmallgod
* @version  V1.0.0
* @data     2019-9-10 10:31:28
* @brief    链式动态队列头文件
********************************************************************************/
#ifndef _CHAIN_QUEUE_H
#define _CHAIN_QUEUE_H
#include "element_definition.h"
#include "single_linked_list.h"

typedef struct queue queue;
struct queue {
    int front;
    int rear;
    node *root;

    /* 函数(方法) */
    int (*num)(queue *); /* 元素数量 */
    int (*enqueue)(queue *, element); /* 入队操作 */
    int  (*dequeue)(queue *, element *); /* 出队操作 */
    int (*head)(queue *, element *); /* 获取队列头元素, 不改变队列 */
    int (*tail)(queue *, element *);  /* 获取队列尾元素, 不改变队列 */
    int (*full)(queue *); /* 判断队列是否已满 */
    int (*empty)(queue *); /* 判断队列是否已空 */
};
extern queue *create_queue(void);
extern void destroy_queue(queue *q);
#endif

