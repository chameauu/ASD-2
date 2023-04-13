#include <stdio.h>
#include "matrice_creuse.h"



void main()
{
    int Mat[3][3]={{0,1,0},{6,0,0},{5,6,3}};
    struct list ligne[3];
    creation(ligne);
<<<<<<< HEAD
    printf("%x\n",&ligne);
    remplir((int *)Mat,ligne,3,3);
=======
    remplir((int *)Mat,ligne,3,3);
    printf("%d",sizeof(ligne));
>>>>>>> 3d3acc2c37907c3d811ecc8cc365dcbba0aef1b9

    
    
}