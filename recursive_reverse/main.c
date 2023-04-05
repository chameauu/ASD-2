#include <stdio.h>
#include <stdlib.h>

struct Noeud
{
    int val;
    struct Noeud* suivant;
};

struct Pile
{
    struct Noeud* sommet;
};

void empiler(int x,struct Pile* test)
{
    struct Noeud* nv_element=(struct Noeud*)malloc(sizeof(struct Noeud));
    nv_element->val=x;
    nv_element->suivant=test->sommet;
    test->sommet=nv_element;
}

void recursive_reverse(struct Noeud* test)
{
    if(test!=NULL)
    {
        recursive_reverse(test->suivant);
        printf("%d\t",test->val);
    }
}

void main()
{
    struct Pile pile;
    pile.sommet=NULL;
    for(int i=0;i<4;i++)
        empiler(i+10,&pile);
    recursive_reverse(pile.sommet);
    printf("%d\t",pile.sommet->val);

}