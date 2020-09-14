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
/****************************有头结点 -- START*********************************/
/****************************升序 -- START*************************************/
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
/****************************乱序 -- END***************************************/
/****************************有头结点 -- END***********************************/
#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H
#include <stddef.h> /* For size_t */
#include "element_definition.h"

typedef enum sll_ret {        /* Return value */
  SLL_OK          =    0,     /* Single linked list function execute success */
  SLL_ERR_INVAL   =    1,     /* Invalid argument */
  SLL_ERR_NOMEM   =    2,     /* Not enough space */
  SLL_ERR_EMPTY   =    3,     /* Single linked list is empty */
  /* delete  */
  SLL_DEL_OK      =   SLL_OK, /* Single linked list delete function execute success */
  SLL_DEL_NOVAL   =   11,     /* Single linked list is no such value */
  
  /* insert */
  SLL_INS_OK      =   SLL_OK, /* Single linked list insert function execute success */
  SLL_INS_SAME    =   22,     /* Single linked list has same value */
  
  /* create  */
  SLL_CRE_OK      =   SLL_OK, /* Single linked list create function execute success */

  /* query */
  SLL_QUE_OK      =   SLL_OK, /* Single linked list query function execute success */
  SLL_QUE_NOVAL   =   31,     /* Single linked list is no such value */
} SLL_RET;

typedef struct sll_node sll_node;
struct sll_node {
    element data;
    sll_node *next; 
};
/* ascending order(升序) 、descending order(降序) 、unordered(无序) */
/****************************有头结点 -- START*********************************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_insert_ascending_same_discard_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_ascending_same_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_ascending_same_tail_has_head_node(sll_node *head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_insert_descending_same_discard_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_descending_same_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_descending_same_tail_has_head_node(sll_node *head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_insert_unordered_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_unordered_tail_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_insert_tail_has_head_node(sll_node *head, element data);
/****************************乱序 -- END***************************************/
/****************************有头结点 -- END*********************************/

/****************************无头结点 -- START*********************************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_insert_ascending_same_discard_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_ascending_same_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_ascending_same_tail_no_head_node(sll_node **head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_insert_descending_same_discard_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_descending_same_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_descending_same_tail_no_head_node(sll_node **head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_insert_unordered_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_unordered_tail_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_insert_tail_no_head_node(sll_node **head, element data);
/****************************乱序 -- END***************************************/
/****************************无头结点 -- END***********************************/

/****************************兼容有无头结点两种情况 -- START*******************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_insert_ascending_same_discard(sll_node **head, element data);
extern SLL_RET sll_insert_ascending_same_head(sll_node **head, element data);
extern SLL_RET sll_insert_ascending_same_tail(sll_node **head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_insert_descending_same_discard(sll_node **head, element data);
extern SLL_RET sll_insert_descending_same_head(sll_node **head, element data);
extern SLL_RET sll_insert_descending_same_tail(sll_node **head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_insert_head(sll_node **head, element data);
extern SLL_RET sll_insert_tail(sll_node **head, element data);
/****************************乱序 -- END***************************************/
/****************************兼容有无头结点两种情况 -- END*********************/

/****************************有头结点 -- START*********************************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_delete_ascending_same_all_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_ascending_same_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_ascending_same_tail_has_head_node(sll_node *head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_delete_descending_same_all_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_descending_same_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_descending_same_tail_has_head_node(sll_node *head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_delete_unordered_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_unordered_tail_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_head_has_head_node(sll_node *head, element data);
extern SLL_RET sll_delete_tail_has_head_node(sll_node *head, element data);
/****************************乱序 -- END***************************************/
/****************************有头结点 -- END***********************************/

/****************************无头结点 -- START*********************************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_delete_ascending_same_all_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_ascending_same_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_ascending_same_tail_no_head_node(sll_node **head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_delete_descending_same_all_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_descending_same_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_descending_same_tail_no_head_node(sll_node **head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_delete_unordered_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_unordered_tail_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_head_no_head_node(sll_node **head, element data);
extern SLL_RET sll_delete_tail_no_head_node(sll_node **head, element data);
/****************************乱序 -- END***************************************/
/****************************无头结点 -- END***********************************/

/****************************兼容有无头结点两种情况 -- START*******************/
/****************************升序 -- START*************************************/
extern SLL_RET sll_delete_ascending_same_all(sll_node **head, element data);
extern SLL_RET sll_delete_ascending_same_head(sll_node **head, element data);
extern SLL_RET sll_delete_ascending_same_tail(sll_node **head, element data);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_delete_descending_same_all(sll_node **head, element data);
extern SLL_RET sll_delete_descending_same_head(sll_node **head, element data);
extern SLL_RET sll_delete_descending_same_tail(sll_node **head, element data);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_delete_head(sll_node **head, element data);
extern SLL_RET sll_delete_tail(sll_node **head, element data);
/****************************乱序 -- END***************************************/
/****************************兼容有无头结点两种情况 -- END*********************/

/****************************有头结点 -- START*********************************/
extern SLL_RET sll_create_null_has_head_node(sll_node **head);
/****************************升序 -- START*************************************/
extern SLL_RET sll_create_ascending_has_head_node(sll_node **head, element array[], size_t size);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_create_descending_has_head_node(sll_node **head, element array[], size_t size);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_create_unordered_has_head_node(sll_node **head, element array[], size_t size);
/****************************乱序 -- END***************************************/
/****************************有头结点 -- END***********************************/


/****************************无头结点 -- START*********************************/
extern SLL_RET sll_create_null_no_head_node(sll_node **head);
/****************************升序 -- START*************************************/
extern SLL_RET sll_create_ascending_no_head_node(sll_node **head, element array[], size_t size);
/****************************升序 -- END***************************************/
/****************************降序 -- START*************************************/
extern SLL_RET sll_create_descending_no_head_node(sll_node **head, element array[], size_t size);
/****************************降序 -- END***************************************/
/****************************乱序 -- START*************************************/
extern SLL_RET sll_create_unordered_no_head_node(sll_node **head, element array[], size_t size);
/****************************乱序 -- END***************************************/
/****************************无头结点 -- END***********************************/

extern void sll_destroy(sll_node *head);
#if 0
extern void sll_traversal_has_head_node(sll_node *head);
extern void sll_traversal_no_head_node(sll_node *head);
extern void sll_traversal(sll_node *head);
#endif

extern SLL_RET sll_get_head_has_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_head_no_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_head(sll_node *head, element *data);

extern SLL_RET sll_get_tail_has_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_tail_no_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_tail(sll_node *head, element *data);

extern SLL_RET sll_get_and_delete_head_has_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_and_delete_head_no_head_node(sll_node **head, element *data);
extern SLL_RET sll_get_and_delete_head(sll_node **head, element *data);

extern SLL_RET sll_get_and_delete_tail_has_head_node(sll_node *head, element *data);
extern SLL_RET sll_get_and_delete_tail_no_head_node(sll_node **head, element *data);
extern SLL_RET sll_get_and_delete_tail(sll_node **head, element *data);

extern SLL_RET sll_get_node_num_has_head_node(sll_node *head);
extern SLL_RET sll_get_node_num_no_head_node(sll_node *head);
extern SLL_RET sll_get_node_num(sll_node *head);

#if 0
extern void sll_sort_has_head_node(sll_node *head);
extern void sll_sort_no_head_node(sll_node *head);
extern void sll_sort(sll_node *head);
#endif /* 0 */
extern SLL_RET sll_query_has_head_node(sll_node *head, element data);
extern SLL_RET sll_query_no_head_node(sll_node *head, element data);
extern SLL_RET sll_query(sll_node *head, element data);

#endif /* 0 */
