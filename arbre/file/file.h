
struct element
{
    struct noeud* valeur;
    struct element* suivant;
};

struct File
{
    struct element* tete;
    struct element* queue;
};

void creer_file(struct File**);
void enfiler(struct File*,struct noeud*);
struct noeud* defiler(struct File*);
int vide_file(struct File*);
void display(struct File*);
