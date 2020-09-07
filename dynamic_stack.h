/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	dynaminc_stack.h
* @author 	hongsmallgod
* @version	V1.0.0
* @data		2019-9-10 15:53:29
* @brief	动态堆栈源文件
********************************************************************************/
#ifndef _DYNAMIC_STACK_H
#define _DYNAMIC_STACK_H
#include <stdbool.h> /* C99 */
#include "element_definition.h"

typedef struct stack {
    int top; /* 从 0 开始 */
    int size;
    element *arr;
    int (*num)(struct stack *); /* 堆栈元素的数量 */
    bool (*pop)(struct stack *, element *); 
    bool (*push)(struct stack *, element);
    bool (*full)(struct stack *); 
    bool (*empty)(struct stack *); 
} stack;
extern stack *create_stack(int size);
extern void destory_stack(stack *s);
#endif

