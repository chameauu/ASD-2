#include <stdio.h>
#include "pile.h"
#include <stdlib.h>
#include <assert.h>


void cree_pile(struct Pile* pile)
{
    printf("hello\n");
    pile->sommet=NULL;
    pile->nbelement=0;
}

int vide(struct Pile*pile)
{
    return !(pile->sommet);
}
void empiler(struct Pile* pile,int info)
{

    struct element* n_element=(struct element*)malloc(sizeof(struct element));
    
    n_element->valeur=info;
    
    n_element->suivant=pile->sommet;
    //printf("hello\n");
    pile->sommet=n_element;
    pile->nbelement++;
}

int depiler(struct Pile* pile)
{
    assert(!vide(pile));
    int x=pile->sommet->valeur;
    struct element* temp=pile->sommet;
    pile->sommet=pile->sommet->suivant;
    free(temp);
    pile->nbelement--;
    return x;
}

int dernier(struct Pile* pile)
{   
    int x=0;
    struct element*p=pile->sommet;
    while(p!=NULL)
    {
        x=p->valeur;
        p=p->suivant;
        
    }
    return x;
}

int nombre_element(struct Pile* pile)
{
    return pile->nbelement;
}

int long_parenthese(char* s)
{
    int len1=0;
    int len2=0;
    struct Pile parenthese;
    cree_pile(&parenthese);

    for(int i=0;*(s+i);i++)
    {
        if(*(s+i)=='(')
        {
            empiler(&parenthese,1);
            len1++;

        }else
        {
            if(!vide(&parenthese))
            {
                depiler(&parenthese);
                len1++;
            }else
            {
                if(len2<len1)
                {
                    len2=len1;
                    len1=0;
                }

            }

        }

    }
    return len2>len1?len2:len1;    

}