
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void creer_list(struct List** test)
{
    *test=(struct List*)malloc(sizeof(struct List));
    (*test)->dernier=NULL;
    (*test)->premier=NULL;
    
}
unsigned vide(struct List *test)
{
    return test->premier==NULL;
}
void ajout_list(int info,struct List** test)
{
    struct Noeud* new_element=(struct Noeud*)malloc(sizeof(struct Noeud));
    new_element->val=info;
    new_element->suivant=NULL;
    if(!vide(*test))
    {
        
        (*test)->dernier->suivant=new_element;
        (*test)->dernier=new_element;
    }else
    {
        (*test)->premier=new_element;
        (*test)->dernier=new_element;

    }
}

void reverser(struct List* test)
{
    struct Noeud *avant_premier = NULL;
    struct Noeud* avant_avant_premier=NULL;
    while(test->premier!=NULL)
    {
        avant_avant_premier=avant_premier;
        avant_premier=test->premier;
        test->premier=test->premier->suivant;
        avant_premier->suivant=avant_avant_premier;
        
    }
    test->premier=avant_premier;

}

// void recursive_reverse(struct List* test,struct Noeud test_noeud )
// {
//     if(test->premier->suivant!=NULL)
//     {
//         recursive_reverse(test->premier->suivant);
//         printf("%d\t",test->premier->val);
//     }
// }


void parcour(struct List* test,void (*fake)(struct Noeud*))
{
    struct Noeud* p=test->premier;
    while(p!=NULL)
    {
        (*fake)(p);
        p=p->suivant;
    }
}

struct List merge(struct List* test_nb1,struct List* test_nb2)
{
    struct List list_nb3;
    struct Noeud* third,*last;
    if((test_nb1->premier->val)<(test_nb1->premier->val))
    {
        third=test_nb1->premier;
        test_nb1->premier=test_nb1->premier->suivant;
    }else
    {
        third=test_nb2->premier;
        test_nb2->premier=test_nb2->premier->suivant;

    }

    while(test_nb1->premier!=NULL && test_nb2!=NULL)
    {
        if((test_nb1->premier->val)<(test_nb1->premier->val))
        {
            last=test_nb1->premier;
            third->suivant=last;
            test_nb1->premier=test_nb1->premier->suivant;
        }else
        {
            last=test_nb2->premier;
            third->suivant=last;
            test_nb2->premier=test_nb2->premier->suivant;
        }

    }
    while(test_nb1->premier!=NULL)
    {   
        last=test_nb1->premier;
            third->suivant=last;
            test_nb1->premier=test_nb1->premier->suivant;
        

    }
    while(test_nb2->premier!=NULL)
    {   
        last=test_nb2->premier;
            third->suivant=last;
            test_nb2->premier=test_nb2->premier->suivant;
        

    }

    list_nb3.premier=third;
    return list_nb3;
}

int supprimer_element(struct Noeud* test)
{
    struct Noeud*p1;
    assert(test->suivant);
    p1=test->suivant;
    *test=*p1;
    free(p1);   
}

struct List* concatination(struct List *first,struct List *second)
{
    first->dernier->suivant=second->premier;

    return first;
}