#include <stdio.h>
#include "contigue.h"
#define N 10

void main()
{
creer();
printf("%d\n",vide());
for(int j=0;j<N;j++)
{
    enfiler(j+11);

}
afficher();
printf("%d\n",vide());
printf("%d\n",defiler());
enfiler(10);
printf("%d\n",defiler());
enfiler(1001);
afficher();
printf("%d\n",premier());

}