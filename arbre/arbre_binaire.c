#include <stdio.h>
#include <stdlib.h>
#include "arbre_binaire.h"
#include <assert.h>


struct noeud* creer_arbre()
{
    return NULL;
}

unsigned vide(struct noeud* test)
{
    return test==NULL;
}

struct noeud* gauche(struct noeud* test)
{
    assert(!vide(test));
    return test->sag;
}

struct noeud* droite(struct noeud* test)
{
    assert(!vide(test));
    return test->sad;
}

struct noeud* construire(char val,struct noeud* gauche,struct noeud* droite)
{
    struct noeud* ab;
    ab=(struct noeud*)malloc(sizeof(struct noeud));
    ab->info=val;
    ab->sad=droite;
    ab->sag=gauche;
    return ab;
}

char lire_racine(struct noeud* test)
{
    assert(!vide(test));
    return test->info;
}

unsigned taille(struct noeud* test)
{
    if(test==NULL)
    {
        return 0;
    }
    else
    {
        return 1+taille(test->sad)+taille(test->sag);
    }
}

unsigned nb_feuille(struct noeud* test)
{
    if(test==NULL)
    {
        return 0;
    }

    else if(test->sad==NULL && test->sag==NULL)
    {
        return 1;
    }
    else
    {
        return nb_feuille(test->sad)+nb_feuille(test->sag);
    }
}

unsigned recherche(struct noeud* test,int x)
{
    if(test==NULL)
    
        return 0;
    
    else if(test->info==x)
        return 1;
    else if(recherche(test->sad,x))
        return 1;
    else if(recherche(test->sag,x));
        return 1;

}

int hauteur(struct noeud* test)
{
    if(vide(test))
        return -1;
    return 1+max(hauteur(test->sad),hauteur(test->sag));
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else 
        return b;
}

unsigned non_degenerer(struct noeud* test)
{
    if(test==NULL)
        return 0;
    else if(test->sad!=NULL && test->sag!=NULL)
        return 1;
    else
        return non_degenerer(test->sad)+non_degenerer(test->sag);
}