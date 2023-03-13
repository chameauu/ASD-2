#include "list.h"
#include <stdio.h>

void afficher(struct Noeud* test)
{
    printf("%d\t",test->val);
    
}

void main()
{
    struct List list_nb1;
    struct List list_nb2;
    struct List list_nb3;
    creer_list(&list_nb1);
    creer_list(&list_nb2);
    for(int i=1 , j=6 ;i<=3;i+=2,j=+2)
    {
        ajout_list(j,&list_nb1);
        ajout_list(i,&list_nb2);
    }
    parcour(&list_nb1,afficher);
    printf("\n");
    parcour(&list_nb2,afficher);
    printf("\n");
    list_nb3=merge(&list_nb1,&list_nb2);
    parcour(&list_nb3,afficher);
    printf("\n");
    parcour(&list_nb2,afficher);
    printf("\n");
    parcour(&list_nb1,afficher);
    printf("\n");
}