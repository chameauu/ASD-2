struct element
{
    int col;
    int colonne;
    struct element* suivant;
};

void creation(struct element** ligne);

void remplir(int Mat,struct element** ligne);