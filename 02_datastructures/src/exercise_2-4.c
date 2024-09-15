#include <stdio.h>
#include "binary_tree.h"

int main()
{
    BinaryTree my_tree;
    binary_tree_init(&my_tree, 1);

    // Fill with data
    char elements[] = { '*','+','-','3','4','7','2' };
    for (int i = 0; i < 7; i++) array_push_back(my_tree.nodes, elements[i]);

    // Print in different orders
    binary_tree_preorder(&my_tree, 0);   printf("\n");
    binary_tree_inorder(&my_tree, 0);    printf("\n");
    binary_tree_postorder(&my_tree, 0);  printf("\n");
    binary_tree_levelorder(&my_tree, 0); printf("\n");

    return 0;
}