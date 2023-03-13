// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
// A structure to represent a stack
struct StackNode {
	int data;
	struct StackNode* next;
};

struct StackNode* cree(int data)
{
	struct StackNode* stackNode =
	(struct StackNode*)
	malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int vide(struct StackNode* root)
{
	return !root;
}

void empiler(struct StackNode** root, int data)
{
	struct StackNode* stackNode = cree(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}

int depiler(struct StackNode** root)
{
	if (vide(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int sommet(struct StackNode* root)
{
	if (vide(root))
		return INT_MIN;
	return root->data;
}

