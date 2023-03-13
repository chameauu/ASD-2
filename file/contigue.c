#include <stdio.h>
#include <assert.h>
#define N 10
#include "contigue.h"

struct file
{
    int tab[N+1];
    int tete,queue;
};
struct file f;
void creer()
{
    f.tete=0;
    f.queue=0; //n'importe indice
    
}

unsigned vide()
{
    return f.tete==f.queue;
}

void enfiler(int info)
{
    f.queue++;
    if(f.queue>N)
        f.queue=0;
    assert(!vide());
    f.tab[f.queue]=info;
    printf("%d indice %d\n",info,f.queue);

}

unsigned defiler()
{
    assert(!vide());
    f.tete++;
    if(f.tete>N-1)
        f.tete=0;
    return f.tab[f.tete];
}

unsigned premier()
{
    unsigned indice;
    assert(!vide());
    indice=f.tete+1>N-1?0:f.tete+1;
    return f.tab[indice];

}

void afficher()
{
    for(int i=0;i<=N;i++)
{
    printf("%d\t| ",f.tab[i]);

}
printf("\n");

}
