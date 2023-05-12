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
    
    while(!vide_file(file))
    {
        test=file->tete->valeur;
        printf("%d ",test->info);
        


        if(test->sag!=NULL)
        {
            enfiler(file,test->sag);
            
        }

        if(test->sad!=NULL)
        {
            enfiler(file,test->sad);
            
        }
        defiler(file);
    }


}

void afficher_par_niveau2(struct noeud* test)
{
    assert(!vide(test));
    struct File* file;
    creer_file(&file);
    struct noeud* p;
    enfiler(file,test);
    printf("%d ",test->info);
    while(!vide_file(file))
    {
        p=defiler(file);


        if(p->sag!=NULL)
        {
            enfiler(file,p->sag);
            printf("%d ",p->sag->info);
        }

        if(p->sad!=NULL)
        {
            enfiler(file,p->sad);
            printf("%d ",p->sad->info);
        }
    }


}



struct noeud* rechercheBinaire(struct noeud* test,int x)
{
    if(test==NULL)
        return NULL;
    if(test->info!=x)
    {
        if(x<test->info)
            rechercheBinaire(test->sag,x);
        else if(x>test->info)
            rechercheBinaire(test->sad,x);
    }else
        return test;
}

// void ajout_arbre_binaire(struct noeud** test,int x)
// {

//     if(*test==NULL)
//     {
//         struct noeud*p=(struct noeud*)malloc(sizeof(struct noeud));
//         p->sad=p->sag=NULL;
//         p->info=x;
//         *test=p;
//     }
//     if(x<(*test)->info)
//         return ajout_arbre_binaire(&((*test)->sag),x);
//     else if(x>(*test)->info)
//         return ajout_arbre_binaire(&((*test)->sad),x);
// }

struct noeud* ajout_arbre_binaire(struct noeud* test,int x)
/* utiliser la return a la place de double pointeur , a la fin de chaque appelle on retourne l'adresse de la racine de sous arbre gauche ou droite
 */
{

    if(test==NULL)
    {
        struct noeud*p=(struct noeud*)malloc(sizeof(struct noeud));
        p->sad=p->sag=NULL;
        p->info=x;
        test=p;
    }
    if(x<(test)->info)
        test->sag= ajout_arbre_binaire((test)->sag,x);
    else if(x>(test)->info)
        test->sad= ajout_arbre_binaire((test)->sad,x);
    return test;
}

void inOrder(struct noeud* test)
{
    if(test!=NULL)
    {
        inOrder(test->sag);
        printf("%d ",test->info);
        inOrder(test->sad);
    }
}

void preOrder(struct noeud*test)
{
    if(test!=NULL)
    {
        printf("%d ",test->info);
        preOrder(test->sag);
        preOrder(test->sad);
    }
}

void postOrder(struct noeud* test)
{
    if(test!=NULL)
    {
        postOrder(test->sag);
        postOrder(test->sad);
        printf("%d ",test->info);
    }
}

struct noeud* rechercheBinaireMoinsUn(struct noeud*test,int x)
{
    if(test==NULL)
        return NULL;
    if(x>test->info)
    {
        if(x==test->sad->info)
        {
            return test;
        }else
        {
            rechercheBinaireMoinsUn(test->sad,x);
        }
    }else if(x<test->info)
    {
        if(x==test->sag->info)
        {
            return test;
        }
        else{
            rechercheBinaireMoinsUn(test->sag,x);
        }
    }

}

struct noeud* inPre(struct noeud* test)
{
    while(test && test->sad && test->sad)
    {
        test=test->sad;
    }
    return test;
}

struct noeud* inSucc(struct noeud* test)
{
    while(test && test->sag && test->sag->sag)
    {
        test=test->sag;
    }
    return test;
}


struct noeud* supprimer(struct noeud*test,int x)

{
    if(test==NULL) return NULL;
    if(test->sad==NULL && test->sag==NULL)
    {
        free(test);
        return NULL;
    }
    if(x>test->info)
    {
        test->sad=supprimer(test->sad,x);
    }
    else if(x<test->info)
        test->sag=supprimer(test->sag,x);
    else
    {
        if(test->sad)
        {
            test->info=test->sad->info;
            test->sad=supprimer(test->sad,test->sad->info);
        }else if(test->sag)
        {
            test->info=test->sag->info;
            test->sag=supprimer(test->sag,test->sag->info);

        }
    }
    return test;

}

// struct noeud* supprimer(struct noeud *test,int x)
// {
//     struct noeud* q;
//     if(test==NULL) return NULL;
//     if(test->sag==NULL && test->sad==NULL)
//     {
//         free(test);
//         return NULL;
//     }
//     if(x< test->info)
//         test->sag=supprimer(test->sag,x);
//     else if(x>test->info)
//         test->sad=supprimer(test->sad,x);
//     else
//     {
//         if(hauteur(test->sag)>hauteur(test->sad))
//         {
//             q=inPre(test->sag);
//             test->info=q->info;
//             test->sag->sad=supprimer(q,q->info);
//         }else
//         {
//             q=inSucc(test->sad);
//             test->info=q->info;
//             tsupprimer(q,q->info);

//         }
//     }
//     return test;

// }





// void supprimer(struct noeud **test,int x)
// {
//     struct noeud* elementToDelete;
//     if((*test)->info==x)
//         elementToDelete=*test;
//     else
//         elementToDelete=rechercheBinaireMoinsUn(*test,x);

//     if(elementToDelete!=NULL)
//     {
//         struct noeud* p=elementToDelete;
//         if(elementToDelete->sag && elementToDelete->sad)
//         {
//             p=elementToDelete->sag;
//             while(p->sad)
//             {
//                 p=p->sad;

//             }
//             p->sad=elementToDelete->sad;
//             elementToDelete->sad=elementToDelete->sag->sad;
//             elementToDelete->info=elementToDelete->sag->info;
//             elementToDelete->sag=p->sag;

//         }
//         else if (elementToDelete->sad)
//         {
//             p=elementToDelete->sad;
//             elementToDelete->sad=p->sad;
//             elementToDelete->sag=p->sag;
//             elementToDelete->info=p->info;
//         }
//         else if(elementToDelete->sag)
//         {
//             p=elementToDelete->sag;
//             elementToDelete->sad=p->sad;
//             elementToDelete->sag=p->sag;
//             elementToDelete->info=p->info;
//         }

//         free(p);

//     }
// }


