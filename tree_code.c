
�Լ�����ͼ, Ȼ�󿴴��롣�������������֡�
������ӻ�����޸ĵġ�
�����������ʽ�ṹʵ�ֵ�
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
���Ҫ��ɾ���Ľڵ����������ӽڵ㣬�����ַ�����
�� ���������������ڵ㣬�滻Ҫɾ���Ľڵ�
�� ��������������С�ڵ㣬 �滻Ҫɾ���Ľڵ�
����ĺ���ѡ����Ƿ�����
```
/*
** function  : delete_tree_node
** author	 : hongsmallgod
** brief     : ���ݹؼ�ֵ, ɾ���������ڵ�
** argument  : @root: ���ڵ�ָ��; @key: �ؼ�ֵ
** return 	 : true: ɾ���ɹ�; false: ɾ��ʧ��
*/
bool delete_tree_node(tree *root, int key)
{
	tree *current = root;	/* �������ɶ��� */
	tree **pre = NULL;    	/* ����ָ��ǰ�ڵ�ָ���ָ�� */

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
	**  û�ҵ���Ӧ�ڵ�
	*/
	if (NULL == current)
		return false;
	/*
	**  ��ȡ���ӽڵ���
	*/
	int child_num = 0;
	if (current->left)
		child_num++;
	if (current->right)
		child_num++;
	
	/*
	**  ����current�ڵ�ĺ��ӽڵ���, ���������:
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
		**  ɾ�����������йؼ�ֵ���Ľڵ㣬������ڵ�����ݸ�ֵ����ǰ�ڵ�
		*/
		{
			tree **pre = NULL;
			tree *this = current;
			
			pre = &this->left;	/* ���Դ���ʱ, ������©����һ�� */
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
		/* ����������������� */
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
** brief     : ��ȡ���ڵ�����
** argument  : @root: �����ڵ�ָ��
** return 	 : �ڵ���
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
** brief     : �������������ٵ�
** argument  : @root: �����ڵ�ָ��
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
**  �ݹ��ǰ�����򡢺������
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
���������
```
/*
** function  : destory_tree
** author	 : hongsmallgod
** brief     : ��һ���������
** argument  : @root: �����ڵ�ָ��
** return 	 : �������
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
