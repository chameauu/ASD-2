#include <stdio.h>
#include "matrice_creuse.h"



void main()
{
    int Mat[3][3]={{0,1,0},{6,0,0},{5,6,3}};
    struct list ligne[3];
    creation(ligne);
    remplir((int *)Mat,ligne,3,3);
    printf("%d",sizeof(ligne));

    
    
}