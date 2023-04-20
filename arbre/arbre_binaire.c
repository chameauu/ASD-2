#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arbre_binaire.h"
#include "file/file.h"

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

void afficher_par_niveau(struct noeud* test)
{
    assert(!vide(test));
    struct File* file;
    creer_file(&file);
    struct noeud* p;
    enfiler(file,test);
    printf("%c ",test->info);
    while(!vide_file(file))
    {
        p=defiler(file);
        

        if(p->sag!=NULL)
        {
            enfiler(file,p->sag);
            printf("%c ",p->sag->info);
        }

        if(p->sad!=NULL)
        {
            enfiler(file,p->sad);
            printf("%c ",p->sad->info);
        }
    }
    

}

void ajout_arbre_binaire(struct noeud** test,int x)
{

    if(*test==NULL)
    {
        struct noeud*p=(struct noeud*)malloc(sizeof(struct noeud));
        p->sad=p->sag=NULL;
        p->info=x;
        *test=p;        
    }
    if(x<(*test)->info)
        return ajout_arbre_binaire(&((*test)->sag),x);
    else if(x>(*test)->info)
        return ajout_arbre_binaire(&((*test)->sad),x);
}

void inOrder(struct noeud* test)
{
    if(test!=NULL)
    {
        inOrder(test->sag);
        printf("%d",test->info);
        inOrder(test->sad);
    }
}