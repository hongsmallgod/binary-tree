#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "chain_queue.h"
//#include "binary_tree.h"
//#include "dynamic_stack.h"
#include "single_linked_list.h"

int main(int argc, char *argv[])
{
    #if 1
    tree *root = NULL;
    tree *t;
	create_tree(&root);//4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
    tree_insert(&root, 0);
    tree_insert(&root, -1);
    in_order_traversal (root);
    #endif
    //node *u = create_sll();
	return 0;
}
