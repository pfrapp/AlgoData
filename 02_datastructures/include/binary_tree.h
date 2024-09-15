#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "array.h"

typedef struct BinaryTree BinaryTree;
struct BinaryTree
{
    Array *nodes;
};

void binary_tree_init(BinaryTree* t, int capacity);
void binary_tree_levelorder(BinaryTree* t, int i);
void binary_tree_preorder(BinaryTree* t, int i);
void binary_tree_inorder(BinaryTree* t, int i);
void binary_tree_postorder(BinaryTree* t, int i);

#endif // BINARY_TREE_H_