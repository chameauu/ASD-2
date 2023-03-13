#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void creer_list(struct List** test)
{
  *test=(struct List*)malloc(sizeof(struct List));
  (*test)->nb_element=0;
  (*test)->queue=NULL;
  (*test)->tete=NULL;
}

// void creer_list(struct List** test)
// {
//  printf("test fonction1 %x\n",&test);   
//  *test=(struct List*)malloc(sizeof(struct List)); 
//  printf("test fonction %x\n",&test);
//   (*test)->nb_element=0;
//   (*test)->queue=NULL;
//   (*test)->tete=NULL;
// }


void inserer(int info ,struct List* test)
{
    struct Noeud* element=(struct Noeud*)malloc(sizeof(struct Noeud));

    test->nb_element++;
    element->cle=info;
    if(test->nb_element-1==0)
    {
        
        test->tete=element;
        test->queue=element;
        element->precedent=NULL;
    }else
    {
        element->precedent=test->queue;
        test->queue->suivant=element;
        test->queue=element;
    }
    test->queue->suivant=NULL;

}

void afficher(struct List** test,int n)
{
    int i=0;
    while((*test)->queue && i<n)
    {
        i++;
        printf("%d\n",(*test)->queue->cle);
        (*test)=(*test)->queue->precedent;
    }
    

}

int supprimer(struct List* test)
{


}