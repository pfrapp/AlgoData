#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "binary_tree.h"

void binary_tree_init(BinaryTree* t, int capacity)
{
    t->nodes = (Array*)malloc(sizeof(Array));
    array_init(t->nodes, capacity);
}

void binary_tree_levelorder(BinaryTree* t, int i)
{
	Queue q; queue_init(&q);

	queue_enqueue(&q, (char)i);
	while(!queue_empty(&q))
	{
		int j = (int)queue_dequeue(&q);
		printf("%c, ", t->nodes->elements[j]);
		if (2*j+1 < t->nodes->size) queue_enqueue(&q, (char)2*j+1);
		if (2*j+2 < t->nodes->size) queue_enqueue(&q, (char)2*j+2);
	}
}

void binary_tree_preorder(BinaryTree* t, int i)
{
	if (i >= t->nodes->size) return;

	printf("%c, ", t->nodes->elements[i]);
	binary_tree_preorder(t, 2*i+1);
	binary_tree_preorder(t, 2*i+2);
}


void binary_tree_inorder(BinaryTree* t, int i)
{
	if (i >= t->nodes->size) return;
	
	binary_tree_inorder(t, 2 * i + 1);
	printf("%c, ", t->nodes->elements[i]);
	binary_tree_inorder(t, 2 * i + 2);
}

void binary_tree_postorder(BinaryTree* t, int i)
{
	if (i >= t->nodes->size) return;

	binary_tree_postorder(t, 2 * i + 1);
	binary_tree_postorder(t, 2 * i + 2);
	printf("%c, ", t->nodes->elements[i]);
}