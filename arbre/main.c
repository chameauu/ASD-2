#include <stdio.h>
#include "arbre.h"
#include <stdlib.h>

void main()
{
    struct Arbre arbre;
    creer_Noeud(&arbre.racine,5);
    printf("%d",arbre.racine->val);
    ajouter_noeud(&arbre,15,'G');
   
    
}