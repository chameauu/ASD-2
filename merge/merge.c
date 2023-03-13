#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void creer_list(struct List* test)
{
    //test->dernier=NULL;
    test->premier=NULL;
    
}

void ajout_list(int info,struct List* test)
{
    struct Noeud* nv_element=(struct Noeud*)malloc(sizeof(struct Noeud));
    nv_element->val=info;
    nv_element->suivant=test->premier;
    test->premier=nv_element;
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


void parcour(struct List* test,void (*fake)(struct Noeud*))
{
    struct Noeud* p=test->premier;
    while(p!=NULL)
    {
        (*fake)(p);
        p=p->suivant;
    }

}
void afficherrr(struct Noeud* test)
{
    printf("%d\t",test->val);
    
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

