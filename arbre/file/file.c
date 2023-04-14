#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <assert.h>

void creer_file(struct File** test)
{
    *test=(struct File*)malloc(sizeof(struct File));
    (*test)->queue=NULL;
    (*test)->tete=NULL;

}

int vide_file(struct File* test)
{
    if(test->queue==NULL && test->tete==NULL)
    
        return 1;
    else
        return 0;

}
void enfiler(struct File* test,struct noeud* k)
{
    struct element* new_element=(struct element*)malloc(sizeof(struct element));
    new_element->valeur=k;
    new_element->suivant=NULL;
    if(vide_file(test))
    {
        
        test->tete=new_element;   

    }else
    {
        test->queue->suivant=new_element;
        
    }
    test->queue=new_element;
    
}

struct noeud* defiler(struct File *test)
{
    assert(!vide_file(test));
    struct element* tmp=test->tete;
    struct noeud* x= tmp->valeur;
    if(test->tete==test->queue)
        test->tete=test->queue=NULL;
    else
        test->tete=test->tete->suivant;
    free(tmp);
    return x;

}

void display(struct File *test)
{
    struct element* tmp=test->tete;
    while(tmp!=NULL)
    {
        printf("%d",tmp->valeur);
        tmp=tmp->suivant;
        
    }
    printf("\n");
}