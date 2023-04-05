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

void remplir(int **Mat,struct list *ligne,int M ,int N)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Mat[i][j]!=0)
            {
                struct element* p=(struct element*)malloc(sizeof(struct element));
                p->col=j;
                p->val=Mat[i][j];
                if((ligne+i)->premier==NULL)
                {
                    (ligne)->premier=p;
                }
                else
                {
                    (ligne+i)->dernier->suivant=p;
                }
                    (ligne)->dernier=p;

            }
        }
    }

}