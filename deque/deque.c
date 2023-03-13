#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void creer_deque(struct deque* test)
{
    
    test->nb_element=0;
    test->queue=NULL;
    test->tete=NULL;
}

unsigned deque_vide(struct deque *test)
{
    return test->nb_element;
}

void endequer(struct deque* test,int info,enum direction dir)
{
    test->nb_element++;
    struct element* n_element=(struct element*)malloc(sizeof(struct element));
    n_element->cle=info;
    if(dir)
    {
        n_element->suivant=NULL;
        test->queue->suivant=n_element;
        test->queue=n_element;
    }
    else
    {
        printf("hello\n");
        n_element->suivant=test->tete;
        test->tete=n_element;
        
    }

}

int extremite(struct deque* test,enum direction dir)
{
    return dir?test->tete->cle:test->queue->cle;
    
}

int dedequer(struct deque* test,enum direction dir)
{
    assert(deque_vide(test));
    struct element* tmp;
    if(dir)
    {
        tmp=test->tete;
        while(test->queue!=tmp->suivant)
        {
            tmp=tmp->suivant;
        }
        test->queue=tmp;
        tmp=tmp->suivant;
        test->queue->suivant=NULL;
    }else
    {
        tmp=test->tete;
        test->tete=test->tete->suivant;
    }
    int x=tmp->cle;
    free(tmp);
    return x;
}

void initialiser(struct deque* test,int info)
{
    test->nb_element++;
    struct element* n_element=(struct element*)malloc(sizeof(struct element));
    n_element->cle=info;
    n_element->suivant=NULL;
    test->queue=test->tete=n_element;   
}