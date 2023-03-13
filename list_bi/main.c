#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void main()
{
    struct List *test;
    printf("test main %x\n",test);
    creer_list(&test);
    //printf("%d\n",test->queue==NULL);
    inserer(15,test);
    //printf("%d\n",test->nb_element);
    inserer(10,test);
    afficher(&test,2);
    //printf("%d\n",test->nb_element);
    printf("test main %x\n",test);
    printf("test main1 %d\n",test->queue);

}