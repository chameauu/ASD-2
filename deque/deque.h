struct element
{
    int cle;
    struct element* suivant;
};

struct deque
{
    int nb_element;
    struct element* tete;
    struct element* queue;
};

enum direction {gauche,droite};


void creer_deque(struct deque*);
unsigned deque_vide(struct deque*);
int extremite(struct deque*,enum direction);
void endequer(struct deque*,int,enum direction);
int dedequer(struct deque*,enum direction);
void initialiser(struct deque*,int);