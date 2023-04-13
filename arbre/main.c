#include <stdio.h>
<<<<<<< HEAD
#include "arbre_binaire.h"

void main()
{
    struct noeud* exp;
    // exp=construire('*',construire('+',NULL,NULL),LL);
    exp=construire('*',construire('+',construire('a',NULL,NULL),construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),construire('d',NULL,NULL)));
    printf("%d\n",taille(exp));
    printf("%d\n",nb_feuille(exp));
    printf("%d\n",recherche(exp,(int)'d'));
    printf("%d\n",hauteur(exp));
    printf("%d\n",non_degenerer(exp));

}
// calcule de la taille d'un arbre binaire 
// nombre de feuilles 
// rechercher element 
// verifier arbre n'est pas generer
=======
#include "arbre.h"
#include <stdlib.h>

void main()
{
    struct Arbre arbre;
    creer_Noeud(&arbre.racine,5);
    printf("%d",arbre.racine->val);
    ajouter_noeud(&arbre,15,'G');
   
    
}
>>>>>>> 3d3acc2c37907c3d811ecc8cc365dcbba0aef1b9
