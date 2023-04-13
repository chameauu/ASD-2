#include <stdlib.h>
#include <stdio.h>
#include "matrice_creuse.h"


void creation(struct list* ligne)
{
    for(int i=0;i<3;i++)
    {
        (ligne+i)->premier=NULL;
        (ligne+i)->dernier=NULL;
    }
    
    
    
    
}

<<<<<<< HEAD
void remplir(int *Mat,struct list *ligne,int M ,int N)
{
    for(int i=0;i<M;i++)
    {
        printf("%x\n",ligne+i);
=======
void remplir(int *Mat,struct list *ligne,int M ,int N) /*  matrix is sequence of elements to get an element
                                                        we multiply nb_rows with with the row of element plus its column
                                                            */
{                                                                                           
    for(int i=0;i<M;i++)
    {
        
>>>>>>> 3d3acc2c37907c3d811ecc8cc365dcbba0aef1b9
        for(int j=0;j<N;j++)
        {
            if(Mat[i*M+j]!=0)
            {
                struct element* p=(struct element*)malloc(sizeof(struct element));
                p->col=j;
                p->val=Mat[i*M+j];
<<<<<<< HEAD
                printf("%x\n",ligne+i);
=======
                
>>>>>>> 3d3acc2c37907c3d811ecc8cc365dcbba0aef1b9
                if((ligne+i)->premier==NULL)
                {
                    (ligne+i)->premier=p;
                }
                else
                {
                    (ligne+i)->dernier->suivant=p;
                }
                    (ligne+i)->dernier=p;

            }
        }
    }

}