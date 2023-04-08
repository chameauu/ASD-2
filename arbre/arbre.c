#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"


void creer_Noeud(struct Noeud** test,int k)
{

    *test=(struct Noeud*)malloc(sizeof(struct Noeud));
    (*test)->val=k;
    (*test)->droite=NULL;
    (*test)->gauche=NULL;
    
}

void ajouter_noued(struct Arbre* test,int k,char D)
{
    struct Noeud* p;
    if(D=='G')
    {
        p=test->racine->gauche;
        while(p!=NULL)
        {
            p=p->gauche;
        }
        creer_Noeud(&p,k);
        
    }
    else if(D='D')
    {
    
        p=test->racine->droite;
        while(p!=NULL)
        {
            p=p->droite;
        }
        creer_Noeud(&p,k);
        
    }
    else
        exit(EXIT_FAILURE);
}
   

