
自己画个图, 然后看代码。这样会容易上手。
这个帖子会持续修改的。
下面的树是链式结构实现的
```
#include <stdlib.h>
#include <stdbool.h>	/* C99 */

typedef struct tree_node tree;
struct tree_node {
	int data;
	tree *left;
	tree *right;
};

```
如果要被删除的节点有两个孩子节点，有两种方案：
① 将其左子树的最大节点，替换要删除的节点
② 将其右子树的最小节点， 替换要删除的节点
下面的函数选择的是方案①
```
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
```

```
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
```

```
/*
** function  : destory_tree
** author	 : hongsmallgod
** brief     : 把整颗树给销毁掉
** argument  : @root: 树根节点指针
** return 	 : none
*/
void destory_tree(tree *root)
{
	if (root) {
		destory_tree(root->left);
		root->left = NULL;
		destory_tree(root->right);
		root->right = NULL;
		free(root);
	}
}
```

```
/*
**  递归的前序、中序、后序遍历
*/
void pre_order_traversal(tree *bt)
{
	if (bt) {
		printf("%d", bt->data);
		pre_order_traversal(bt->left);
		pre_order_traversal(bt->right);
	}
}

void in_order_traversal(tree *bt)
{
	if (bt) {
		pre_order_traversal(bt->left);
		printf("%d", bt->data);
		pre_order_traversal(bt->right);
	}
}

void post_order_traversal(tree *bt)
{
	if (bt) {
		pre_order_traversal(bt->left);
		printf("%d", bt->data);
		pre_order_traversal(bt->right);
	}
}
```
求树的深度
```
/*
** function  : destory_tree
** author	 : hongsmallgod
** brief     : 求一颗树的深度
** argument  : @root: 树根节点指针
** return 	 : 树的深度
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

```
