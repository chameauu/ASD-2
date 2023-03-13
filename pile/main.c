#include <stdio.h>
#include "pile.h"
#include <stdlib.h>

void main()
{
    struct Pile* test=(struct Pile*)malloc(sizeof(struct Pile));
    cree_pile(test);
   printf("%d\n",vide(test));
   empiler(test,5);
   printf("%d\n",dernier(test));
   empiler(test,8);
   empiler(test,9);
   depiler(test);
    printf("%d\n",dernier(test));
    printf("%d\n",nombre_element(test));

}