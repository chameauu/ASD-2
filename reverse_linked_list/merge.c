struct Noeud
{
    int val;
    struct Noeud* suivant;
};

struct List
{
    struct Noeud* premier;
    struct Noeud* dernier;
};


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void creer_list(struct List* test)
{
    test->dernier=NULL;
    test->premier=NULL;
    
}
unsigned vide(struct List *test)
{
    return test->premier==NULL;
}
void ajout_list(int info,struct List* test)
{
    struct Noeud* new_element=(struct Noeud*)malloc(sizeof(struct Noeud));
    new_element->val=info;
    new_element->suivant=NULL;
    if(vide(test))
    {
        
        test->premier=new_element;   
        test->dernier=new_element;

    }else
    {
        test->dernier->suivant=new_element;
        test->dernier=new_element;
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
    struct Noeud* third,*last,*start;
    if((test_nb1->premier->val)<(test_nb1->premier->val))
    {
        third=test_nb1->premier;
        test_nb1->premier=test_nb1->premier->suivant;
    }else
    {
        third=test_nb2->premier;
        test_nb2->premier=test_nb2->premier->suivant;

    }
    last=third;

    while(test_nb1->premier!=NULL && test_nb2->premier!=NULL)
    {
        if((test_nb1->premier->val)<(test_nb2->premier->val))
        {
            last->suivant=test_nb1->premier;
            last=last->suivant;
            test_nb1->premier=test_nb1->premier->suivant;
            
            
        }else
        {
            last->suivant=test_nb2->premier;
            last=last->suivant;
            test_nb2->premier=test_nb2->premier->suivant;
        }

    }
    if(test_nb1->premier!=NULL)
    {   
        last->suivant=test_nb1->premier;
        

    }

    if(test_nb2->premier!=NULL)
    {   
        last->suivant=test_nb1->premier;

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
    for(int i=1 ;i<=6;i++)
    {
        if(i%2==0)
        ajout_list(i,&list_nb1);
        else
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