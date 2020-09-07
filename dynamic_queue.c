/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	dynamic_queue.c
* @author 	hongsmallgod
* @version	V1.0.1
* @data		2019-9-10 10:31:28
* @brief	动态数组源文件
********************************************************************************/
//下面程序的名称随着项目的进行, 一般会不断的进行改进的.
#include <stdlib.h>
#include "dynamic_queue.h"
static int get_queue_elem_num(queue *);
static int head(queue *, element *);
static int tail(queue *, element *);
static int enqueue(queue *, element);
static int dequeue(queue *, element *);
static int full(queue *);
static int empty(queue *);
queue *create_queue(int size)
{
    queue *q= (queue*)malloc(sizeof(queue)); //申请队列结构体的空间
    if (q== NULL)
        return NULL;
    q->size  = size;
#if dynamic_array_queue ==  TAIL1
    q->front = 1;
    q->rear = 0;
#else
    q->front = 0;
    q->rear  = 0;
#endif
    q->num = get_queue_elem_num;
    q->head = head;
    q->tail = tail;
    q->enqueue = enqueue;
    q->dequeue = dequeue;
    q->full = full;
    q->empty = empty;
    q->data = (element *)malloc(sizeof(element)*size);
    if (q->data == NULL) {
        free(q);
        return NULL;
    }
    return q;
}
static int full(queue *q)
{
#if dynamic_array_queue == TAIL
    return (q->rear + 1) % q->size == q->front;
#else
	return (q->rear + 2) % q->size == q->front;
#endif
}
static int empty(queue *q)
{
#if dynamic_array_queue == TAIL
    return q->rear == q->front;
#else
	return q->rear + 1 == q->front;
#endif
}
static int enqueue(queue *q, element data)
{
    if (full(q))
        return 0;
#if dynamic_array_queue == TAIL
    q->data[q->rear++] = data; 
#else
	q->data[++q->rear] = data; 
#endif
    return 1;
}
static int dequeue(queue *q, element *data)
{
    if (empty(q))
        return 0;
	*data = q->data[q->front++];
	return 1;
}
void destroy_queue(queue *q)
{
    free(q->data);
    q->data = NULL;
    free(q);
}
static int get_queue_elem_num(queue *q)
{
#if dynamic_array_queue == TAIL
    return (q->rear - q->front + q->size) % q->size;
#else
    return (q->rear +1 - q->front + q->size) % q->size;
#endif
}
static int head(queue *q, element *data)
{
	if (empty(q))
		return 0;
	*data = q->data[q->front];
    return 1;
}
static int tail(queue *q, element *data)
{
	if (empty(q))
		return 0;
#if dynamic_array_queue == TAIL
	*data = q->data[q->rear - 1];
#else
	*data = q->data[q->rear];
#endif
	return 1;
}

