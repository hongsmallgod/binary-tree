/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	dynamic_queue.h
* @author 	hongsmallgod
* @version	V1.0.0
* @data		2019-9-10 10:31:28
* @brief	动态队列头文件
********************************************************************************/
#ifndef _DYNAMIC_QUEUE_H
#define _DYNAMIC_QUEUE_H
#include "element_definition.h"
#define TAIL  0 /* 若队列不空，尾指针指向队列尾元素的下一个位置 */
#define TAIL1 1 /* 若队列不空，尾指针指向队列尾元素 */
#define dynamic_array_queue  TAIL1
typedef struct queue queue;
struct queue {
    int front;
    int rear;
    element *data;
    int size; /* 队列的大小 */
	/* 函数(方法) */
	int (*num)(queue *); /* 元素数量 */
	int (*enqueue)(queue *, element); /* 入队操作 */
	int  (*dequeue)(queue *, element *); /* 出队操作 */
	int (*head)(queue *, element *); /* 获取队列头元素, 不改变队列 */
	int (*tail)(queue *, element *);  /* 获取队列尾元素, 不改变队列 */
    int (*full)(queue *); /* 判断队列是否已满 */
    int (*empty)(queue *); /* 判断队列是否已空 */
};
extern queue *create_queue(int size);
extern void destroy_queue(queue *q);
#endif


