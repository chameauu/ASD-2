struct Noeud
{
    int val;
    struct Noeud* droite;
    struct Noued* gauche;
};

struct Arbre
{
    struct Noeud* racine;
};



void creer_Noeud(struct Noeud**,int );
void ajouter_noeud(struct Arbre*,int,char);
void preordre_parcour(struct Noeud* );
void inordre_parcour(struct Noeud* );
void postordre_parcour(struct Noeud*);
int nb_element(struct Noeud*);
int hauteur(struct Noeud*);






