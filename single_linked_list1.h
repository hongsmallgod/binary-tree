/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file     single_linked_list.h
* @author   hongsmallgod
* @version  V1.0.0
* @data     2019-9-10 10:31:28
* @brief    单链表头文件
********************************************************************************/
#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H
#include "element_definition.h"
typedef struct sll_node node;
struct sll_node {
    element data;
    node *next; 
};
//ascending order 、descending order 、unordered
//升序、降序、无序
extern int sll_insert1(node *head, element data);
extern int sll_insert2(node *head, element data);
extern int sll_insert3(node *head, element data);
extern int sll_delete1(node *head, element data);
extern int sll_delete2(node *head, element data);
#if 0
extern void sll_traversal(node *head);
extern node *create_sll(void);
extern void sll_sort(node *head);
#endif
extern int sll_insert4(node *head, element data);
extern int sll_insert5(node *head, element data);
extern int sll_delete3(node *head, element data);
extern void sll_destroy(node *head);
extern size_t get_sll_node_num(node *head);

extern int sll_insert6(node **rootp, element data);
extern int sll_delete_tail(node *head);
extern int sll_delete_head(node *head);
extern int sll_get_head(node *head, element *data);
extern int sll_get_tail(node *head, element *data);
extern int sll_get_and_delete_head(node *head, element *data);
extern int sll_get_and_delete_tail(node *head, element *data);
#endif
