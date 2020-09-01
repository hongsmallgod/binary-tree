/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	binary_tree.h
* @author 	hongsmallgod
* @version	V1.0.1
* @data		2019-9-17 10:29:20
* @brief	二叉树头文件
********************************************************************************/
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <stdbool.h>
typedef struct tree_node binary_tree, tree;
struct tree_node {
    int data;
    tree *left;
    tree *right;
};
extern int create_tree(tree **node);
extern tree *find_ordered(tree *root, int key);
extern void destroy_tree(tree *root);
extern tree *find_unordered(tree *root, int key);
extern bool delete_tree_node(tree *root, int key);
extern int get_tree_node_num(tree *root);
extern int tree_depth(tree *root);
extern int tree_insert(tree **root, int data);
extern void pre_order_traversal(tree *bt);
extern void in_order_traversal(tree *bt);
extern void post_order_traversal(tree *bt);
extern void level_order_traversal(tree *root);
#endif
