#include <stdio.h>
#include "arbre_binaire.h"

void main()
{
    struct noeud* exp;
    //exp=construire('*',construire('+',NULL,NULL),LL);
    exp=construire(10,construire(5,construire(4,NULL,NULL),construire(7,NULL,NULL)),construire(15,construire(12,NULL,NULL),construire(16,NULL,NULL)));
    //exp=construire('*',construire('+',construire('a',NULL,NULL),construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),construire('d',NULL,NULL)));
    printf("taille = %d\n",taille(exp));
    printf("nombre de feuilles = %d\n",nb_feuille(exp));
    printf("recherche est %d\n",recherche(exp,7));
    printf("hauteur = %d\n",hauteur(exp));
    printf("non_degenerer = %d\n",non_degenerer(exp));
    printf("afficher par niveau\n");
    afficher_par_niveau(exp);
    printf("\nrecherche binaire est %d\n",rechercheBinaire(exp,7)->info);
    ajout_arbre_binaire(&exp,20);
    printf("\ntranversale par inordre\n");
    inOrder(exp);
    printf("\n tranversale preordre\n");
    preOrder(exp);
    printf("\n tranversale postordre\n");
    postOrder(exp);
    printf("\n");
    supprimer(exp,5);
    printf("afficher par niveau\n");
    afficher_par_niveau(exp);
    printf("\nafficher recherche moins un %d\n",rechercheBinaireMoinsUn(exp,20)->info);
}
// calcule de la taille d'un arbre binaire 
// nombre de feuilles 
// rechercher element 
// verifier arbre n'est pas generer