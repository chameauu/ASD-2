#include "deque.h"
#include <stdio.h>

void main()
{
    struct deque first;
    creer_deque(&first);
    initialiser(&first,15);
    endequer(&first,10,gauche);
    printf("tete %d\n",*(first.tete));
    printf("queue %d\n",*(first.queue));
    endequer(&first,100,gauche);
    printf("tete%d\n",*(first.tete));
    printf("%d queue\n",*(first.queue));
    dedequer(&first,droite);
    printf("%d tete\n",*(first.tete));
    printf("%d queue\n",*(first.queue));
    printf("%x\n",first.queue->suivant);
}