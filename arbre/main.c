#include <stdio.h>
#include "arbre_binaire.h"

void main()
{
    struct noeud* exp;
    //exp=construire('*',construire('+',NULL,NULL),LL);
    exp=construire(20,construire(10,construire(5,NULL,NULL),construire(15,NULL,NULL)),construire(30,construire(25,NULL,NULL),construire(35,NULL,NULL)));
    //exp=construire('*',construire('+',construire('a',NULL,NULL),construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),construire('d',NULL,NULL)));
    printf("taille = %d\n",taille(exp));
    printf("nombre de feuilles = %d\n",nb_feuille(exp));
    printf("recherche est %d\n",recherche(exp,7));
    printf("hauteur = %d\n",hauteur(exp));
    printf("non_degenerer = %d\n",non_degenerer(exp));
    printf("afficher par niveau\n");
    afficher_par_niveau(exp);
    printf("\nrecherche binaire est %d\n",rechercheBinaire(exp,20)->info);
   
    exp=ajout_arbre_binaire(exp,17);
    exp=ajout_arbre_binaire(exp,16);
   
    exp=ajout_arbre_binaire(exp,14);
    exp=ajout_arbre_binaire(exp,24);
    exp=ajout_arbre_binaire(exp,23);
    exp=ajout_arbre_binaire(exp,34);
    exp=ajout_arbre_binaire(exp,40);
    printf("\ntranversale par inordre\n");
    inOrder(exp);
    printf("\n tranversale preordre\n");
    preOrder(exp);
    printf("\n tranversale postordre\n");
    postOrder(exp);
    printf("\n");
    printf("afficher par niveau avant suppression\n");
    afficher_par_niveau(exp);
    supprimer(exp,20);
    printf("afficher par niveau apres suppression\n");
    afficher_par_niveau(exp);
    // printf("\nafficher recherche moins un %d\n",rechercheBinaireMoinsUn(exp,20)->info);
}
// calcule de la taille d'un arbre binaire 
// nombre de feuilles 
// rechercher element 
// verifier arbre n'est pas generer