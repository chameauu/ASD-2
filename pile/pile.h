struct element
{
    int valeur;
    struct element* suivant;
};
struct Pile
{
    struct element* sommet;
    unsigned int nbelement;
};
void cree_pile(struct Pile*);
void empiler(struct Pile * ,int );
int depiler(struct Pile *);
int dernier(struct Pile*);
int vide(struct Pile*);
int nombre_element(struct Pile*);
int long_parenthese(char*  );

