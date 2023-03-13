/* l'idée est que une parenthée fermante  est associeée à la dernier erreur parenthése ouvrant rencontre 
=> le principe il LIFO nous avons besoin stocké au fur et ç mesure de parcourir la chaine char par char de stocker les indices
des parenthése ouvrantes renocontres*/

#include "../pile.h"
#include <stdio.h>

void main()
{
    char* str="a+(b-(ara)(c*d)+8.14)-(d*k)";
    struct element* test=NULL;
    for(int i=0;*(str+i)!=0;i++)
    {
        if(*(str+i)=='(')
            empiler(&test,i);
        if(*(str+i)==')'){
            for(int j=depiler(&test);j<=i;j++)
            {
                printf("%c",*(str+j));
            }
            printf("\n");
        }
    }
}