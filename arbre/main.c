#include <stdio.h>
#include "arbre_binaire.h"

void main()
{
    struct noeud* exp;
    //exp=construire('*',construire('+',NULL,NULL),LL);
    exp=construire(10,construire(8,construire(6,NULL,NULL),construire(9,NULL,NULL)),construire(15,construire(13,NULL,NULL),construire(16,NULL,NULL)));
    //exp=construire('*',construire('+',construire('a',NULL,NULL),construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),construire('d',NULL,NULL)));
    printf("%d\n",taille(exp));
    printf("%d\n",nb_feuille(exp));
    printf("%d\n",recherche(exp,(int)'d'));
    printf("%d\n",hauteur(exp));
    printf("%d\n",non_degenerer(exp));
    afficher_par_niveau(exp);
    ajout_arbre_binaire(&exp,20);
    inOrder(exp);

}
// calcule de la taille d'un arbre binaire 
// nombre de feuilles 
// rechercher element 
// verifier arbre n'est pas generer