#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <assert.h>

void creer_file(struct File** test)
{
    *test=(struct File*)malloc(sizeof(struct File));
    printf("hello\n");
    (*test)->queue=NULL;
    (*test)->tete=NULL;

}

int vide(struct File* test)
{
    if(test->queue==NULL && test->tete==NULL)
    
        return 1;
    else
        return 0;

}
void enfiler(struct File* test,int k)
{
    struct element* new_element=(struct element*)malloc(sizeof(struct element));
    new_element->valeur=k;
    new_element->suivant=NULL;
    if(vide(test))
    {
        
        test->tete=new_element;   

    }else
    {
        test->queue->suivant=new_element;
        
    }
    test->queue=new_element;
    
}

int defiler(struct File *test)
{
    assert(!vide(test));
    struct element* tmp=test->tete;
    int x= tmp->valeur;
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