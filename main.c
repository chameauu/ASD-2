#include <stdio.h>
#include "pile.h"
int main()
{
	struct element* sommet = NULL;
    
	empiler(&root, 10);
	empiler(&root, 20);
	empiler(&root, 30);

	printf("%d popped from stack\n", depiler(&root));

	printf("Top element is %d\n", sommet(root));

	return 0;
}
