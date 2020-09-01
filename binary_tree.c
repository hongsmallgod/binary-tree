#include <stdio.h>       /* FOR scanf() */
#include <stdlib.h>
#include "binary_tree.h"
#include "dynamic_stack.h"
#include "chain_queue.h"
#define MAX_STACK_SIZE 1024
/********************************************************************************
* Copyright(c) 2019-20xx
* All right resered.
*
* @file  	binary_tree.c
* @author 	hongsmallgod
* @version	V1.0.1
* @data		2019-9-17 10:29:20
* @brief	二叉树源文件
********************************************************************************/

/*
** function  : create_tree
** author    : hongsmallgod
** brief     : 按前序遍历创建二叉树，节点为NULL时， 输入 -1
**             完全二叉搜索树(4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1)
** argument  : @node: 根节点指针的指针
** return    : 1: 创建成功; -1: 创建失败; 0: 结束当前节点的创建
*/
int create_tree(tree **node)
{
    *node = (tree *)calloc(1, sizeof(tree));
    if (*node == NULL)
        return -1;
    if (scanf("%d", &(*node)->data) != 1 || (*node)->data == -1) {
        free(*node);
        *node = NULL;
        return 0;
    }
    if (-1 == create_tree(&(*node)->left)) {
		free(*node);
		*node = NULL;
		return -1;
	}

    if (-1 == create_tree(&(*node)->right)) {
        destroy_tree(*node);
		*node = NULL;
		return -1;
	}
    return 1;
}

/*
** function  : find_ordered
** author    : hongsmallgod
** brief     : 有序二叉树的查找
** argument  : @node: 根节点指针的指针; @key: 查找的关键值
** return    : NULL: 没有找到; else: 节点的地址
*/
tree *find_ordered(tree *root, int key)
{
    tree *current = root;
    while (current) {
        if (current->data > key)
            current = current->left;
        else if (current->data < key)
            current = current->right;
        else
            break;
    }
    return current;
}

/*
** function  : destrioy_tree
** author    : hongsmallgod
** brief     : 销毁二叉树
** argument  : @root: 根节点指针
** return    : none
*/
void destroy_tree(tree *root)
{
    if (root) {
        destroy_tree(root->left);
        root->left = NULL;
        destroy_tree(root->right);
        root->right = NULL;
        free(root);
    }
}

/*
** function  : find_unordered
** author    : hongsmallgod
** brief     : 无序二叉树的查找
** argument  : @root: 根节点指针; @key: 查找的关键值
** return    : NULL: 没有找到; else: 节点的地址
*/
tree *find_unordered(tree *root, int key)
{
    tree *ret = NULL;
    if (root) {
        if (root->data == key)
            return root;
        ret = find_unordered(root->left, key);
        if (ret)
            return ret;
        ret = find_unordered(root->right, key);
        if (ret)
            return ret;
    }
    return NULL;
}
#if 1
/*
** function  : pre_order_traversal
** author    : hongsmallgod
** brief     : 二叉树的前序遍历
** argument  : @bt: 根节点指针
** return    : none
*/
void pre_order_traversal(tree *bt)
{
	binary_tree *t = bt;
    stack *s = create_stack(MAX_STACK_SIZE);
#if 0 /* 前面这部分是自实现的, 后面的是MOOC上的数据结构课程的 */
    while (1) {
        while (t) {
            s->push(s, t);
            printf("%d ", t->data);
            t = t->left;
        }

        if (s->empty(s)) /* 什么情况下堆栈会为空 */
            break;
        s->pop(s, &t);
        t = t->right;
    }
#else
	while (t || !s->empty(s)) {
		while (t) {
			s->push(s, t);
			printf("%d ", t->data);
			t = t->left;
		}
		
		if (!s->empty(s)) {
			s->pop(s, &t);
			t = t->right;
		}
	}
#endif
	printf("\n");
	destory_stack(s);
}

/*
** function  : in_order_traversal
** author    : hongsmallgod
** brief     : 二叉树的中序遍历
** argument  : @bt: 根节点指针
** return    : none
*/
void in_order_traversal(tree *bt)
{
    binary_tree *t = bt;
    stack *s = create_stack(MAX_STACK_SIZE);
    while (t || !s->empty(s)) {
        while (t) {
            s->push(s, t);
            t = t->left;
        }

        if (!s->empty(s)) {
            s->pop(s, &t);
            printf("%d ", t->data);
            t = t->right;
        }
    }
    printf("\n");
    destory_stack(s);
}

/*
** function  : post_order_traversal
** author    : hongsmallgod
** brief     : 二叉树的后序遍历
** argument  : @bt: 根节点指针
** return    : none
*/
void post_order_traversal(tree *bt)
{
    binary_tree *t = bt;
    stack *s = create_stack(MAX_STACK_SIZE);
    /*
    ** 前面的这个是自己想到的(感觉违反了后续遍历的定义 ), 后面的是慕课数据结构
    ** 课程的讨论环节的个别讨论评论
    */
#if 0
    while (t || !s->empty(s)) {
        while (t) {
            s->push(s, t);
            printf("%d ", t->data);
            t = t->right;
        }

        if (!s->empty(s)) {
            s->pop(s, &t);
            t = t->left;
        }
    }
#else
    tree *pre = NULL;
    while ((t || !s->empty(s)) && pre != bt) {
        while (t) {
            s->push(s, t); 
            t = t->left;
        }

        while (!s->empty(s)) {
            s->pop(s, &t);
            if (t->right == pre || t->right == NULL) {
                printf("%d ", t->data);
                pre = t;
            } else {
                s->push(s, t);
                t = t->right;
                break;
            }
        }
    }
#endif
	printf("\n");
    destory_stack(s);
}
#else
void pre_order_traversal(tree *bt)
{
	if (bt) {
		printf("%d ", bt->data);
        fflush(stdout);
		pre_order_traversal(bt->left);
		pre_order_traversal(bt->right);
	}
}

void in_order_traversal(tree *bt)
{
	if (bt) {
		in_order_traversal(bt->left);
		printf("%d ", bt->data);
        fflush(stdout);
		in_order_traversal(bt->right);
	}
}

void post_order_traversal(tree *bt)
{
	if (bt) {
		post_order_traversal(bt->left);
		post_order_traversal(bt->right);
		printf("%d ", bt->data);
        fflush(stdout);
	}
}
#endif
/*
** function  : level_order_traversal
** author    : hongsmallgod
** brief     : 二叉树的后序遍历
** argument  : @root: 根节点指针
** return    : none
*/
void level_order_traversal(tree *root)
{
    queue *q = create_queue();
    do {
        if (root) {
            printf("%d ", root->data);
            if (root->left)
                q->enqueue(q, root->left);
            if (root->right)
                q->enqueue(q, root->right);
        }
        if (q->empty(q))
            break;
        q->dequeue(q, &root);
    } while (1);
	printf("\n");
    destroy_queue(q);
}

/*
** function  : delete_tree_node
** author	 : hongsmallgod
** brief     : 根据关键值, 删除二叉树节点
** argument  : @root: 根节点指针; @key: 关键值
** return 	 : true: 删除成功; false: 删除失败
*/
bool delete_tree_node(tree *root, int key)
{
	tree *current = root;	/* 变量名可读性 */
	tree **pre = NULL;    	/* 保存指向当前节点指针的指针 */

	while (current) {
		if (current->data < key) {
			pre = &current->right;
			current = current->right;
		} else if (current->data > key) {
			pre = &current->left;
			current = current->left;
		} else {
			break;
		}
	}

	/*
	**  没找到对应节点
	*/
	if (NULL == current)
		return false;
	/*
	**  获取孩子节点数
	*/
	int child_num = 0;
	if (current->left)
		child_num++;
	if (current->right)
		child_num++;

	/*
	**  根据current节点的孩子节点数, 分三种情况:
	*/
	switch (child_num) {
	case 0:
		*pre = NULL;
		break;

	case 1:
		if (current->left)
			*pre = current->left;
		else
			*pre = current->right;
		break;

	case 2:
		/*
		**  删除其左子树中关键值最大的节点，并将其节点的内容赋值到当前节点
		*/
		{
			tree **pre = NULL;
			tree *this = current;

			pre = &this->left;	/* 调试代码时, 发现遗漏了这一句 */
			this = this->left;
			while (this->right) {
				pre = &this->right;
				this = this->right;
			}

			*pre = NULL;
			current->data = this->data;

			free(this);
			this = NULL;
		}
	break;

	default :
		/* 非正常情况会跑这里 */
		exit(EXIT_FAILURE);
		break;
	}
	return true;
}

/*
** function  : get_tree_node_num
** author	 : hongsmallgod
** brief     : 获取树节点数量
** argument  : @root: 树根节点指针
** return 	 : 节点数
*/
int get_tree_node_num(tree *root)
{
    int count = 0;
    if (root) {
        count++;
        count += get_tree_node_num(root->left);
        count += get_tree_node_num(root->right);
    }
    return count;
}

/*
** function  : tree_depth
** author	 : hongsmallgod
** brief     : 求树的最大深度
** argument  : @root: 树根节点指针
** return 	 : 节点数
*/
int tree_depth(tree *root)
{
    if (root) {
        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
    return 0;
}

/*
** function  : tree_insert
** author	 : hongsmallgod
** brief     : 二叉搜索树的插入
** argument  : @root: 树根节点指针的指针; @data: 要插入的数据
** return 	 : 1: 插入成功; 0:有相同的值，插入失败; -1: 内存不足
*/
int tree_insert(tree **root, int data)
{
    tree *current = *root;
    tree **pre = root;
    /*
    ** 寻找要插入的位置
    */
    while (current) {
        if (data > current->data) {
            pre = &current->right;
            current = current->right;
        } else if (data < current->data) {
            pre = &current->left;
            current = current->left;
        } else {
            return 0;
        }
    }

    //current = (tree *)calloc(1, sizeof(tree));
    current = (tree *)malloc(sizeof(tree));
    if (NULL == current)
        return -1;
    current->data = data;
    current->left=current->right = NULL;
    *pre = current;
    return 1;
}
