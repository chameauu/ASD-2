struct noeud 
{
     int info;
     struct noeud *sag;
     struct noeud *sad;
     struct noeud *pere;

};

struct noeud* creer_arbre();
unsigned vide(struct noeud*);
struct noeud* construire(char, struct noeud*,struct noeud*);
struct noeud* gauche(struct noeud*);
struct noeud* droite(struct noeud*);
char lire_racine(struct noeud*);
unsigned taille(struct noeud*);
unsigned nb_feuille(struct noeud*);
unsigned recherche(struct noeud*,int x);
int hauteur(struct noeud*);
void afficher_par_niveau(struct noeud*);
unsigned non_degenerer(struct noeud *);
void afficher_par_niveau(struct noeud*);