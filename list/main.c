#include <stdio.h>
#include "list.h"

void main()
{
    struct List* ll1,*ll2,*ll3;
    creer_list(&ll1);
    creer_list(&ll2);
    ajout_list(10,&ll1);
    ajout_list(20,&ll1);
    ajout_list(30,&ll2);
    ll3=concatination(ll1,ll2);

}