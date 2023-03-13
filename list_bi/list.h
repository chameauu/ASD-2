struct Noeud 
{
    int cle;
    struct Noeud* suivant;
    struct Noeud* precedent;
};

struct List
{
    struct Noeud* tete;
    struct Noeud* queue;
    int nb_element; 
};

void creer_list(struct List**);
void inserer(int,struct List*);
int supprimer(struct List*);
int dernier(struct List*);
int premier(struct List*);
void afficher(struct List**,int);