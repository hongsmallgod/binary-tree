/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	dynaminc_stack.c
* @author 	hongsmallgod
* @version	V1.0.0
* @data		2019-9-10 15:53:29
* @brief	动态堆栈源文件
********************************************************************************/
#include <stdlib.h>
#include "dynamic_stack.h"
static bool full(stack *s);
static bool empty(stack *s);
static bool push(stack *s, element d);
static bool pop(stack *s, element *d);
static int get_stack_num(stack *);

stack *create_stack(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (NULL == s)
        return NULL;
    s->top = -1;
    s->size = size;

    s->arr = (element *)malloc(sizeof(element));
    if (NULL == s->arr) {
        free(s);
        return NULL;
    }

    s->num = get_stack_num;
    s->pop = pop;
    s->push = push;
    s->full = full;
    s->empty = empty;
    return s;
}

static int get_stack_num(stack *s)
{
    return s->top + 1;
}
static bool full(stack *s)
{
    if ((s->top + 1) == s->size)
        return true;
    return false;
}
static bool empty(stack *s)
{
    return s->top == -1;
}
static bool push(stack *s, element d)
{
    if (full(s))
        return false;
    s->arr[++s->top] = d;

    return true;
}

static bool pop(stack *s, element *d)
{
    if (empty(s))
        return 0;
    *d = s->arr[s->top--];
    return 1;
}
void destory_stack(stack *s)
{
    free(s->arr);
    s->arr = NULL;
    free(s);
}

