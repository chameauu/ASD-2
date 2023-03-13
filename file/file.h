struct element
{
    int valeur;
    struct element* suivant;
};

struct File
{
    struct element* tete;
    struct element* queue;
};

void creer_file(struct File**);
void enfiler(struct File*,int);
int defiler(struct File*);
int vide(struct File*);
void display(struct File*);
