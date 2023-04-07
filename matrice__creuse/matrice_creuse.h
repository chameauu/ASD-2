struct element
{
    int col;
    int val;
    struct element* suivant;
};

struct list
{
    struct element* premier;
    struct element* dernier;
    
};

void creation(struct list* ligne);

void remplir(int *Mat,struct list* ligne,int M,int N);

int diff_size();
