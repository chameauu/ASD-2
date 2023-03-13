#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



























void afficher(struct Noeud*test)
{
    printf("\t%d",test->val);
}
void main()
{
    struct List p_list;
    creer_list(&p_list);
    for(int i=0;i<5;i++)
        ajout_list(i+15,&p_list);
    //printf("%d\n",p_list.premier->suivant->suivant->val);
    parcour(&p_list,afficher);
    printf("\n");
    recursive_reverse(&p_list);
    parcour(&p_list,afficher);
    // supprimer_element(p_list.premier);
    // parcour(&p_list,afficher);

        
}