#include <stdlib.h>
#include <stdio.h>
#include "matrice_creuse.h"


void creation(struct element** ligne)
{
    for(int i=0;i<3;i++)
    {
        *(ligne+i)=NULL;
    }
    
}

void remplir(int **Mat,struct element **ligne,int M ,int N)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Mat[i][j]!=0)
            {
                struct element* p=(struct element*)malloc(sizeof(struct element));
                if(*(ligne+i)!=NULL)
                {
                    *(ligne+i)->suivant=p;
                }

            }
        }
    }

}