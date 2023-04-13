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

<<<<<<< HEAD
void remplir(int *Mat,struct list* ligne,int M,int N);
=======
void remplir(int *Mat,struct list* ligne,int M,int N);

int diff_size();
>>>>>>> 3d3acc2c37907c3d811ecc8cc365dcbba0aef1b9
