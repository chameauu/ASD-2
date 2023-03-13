#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void main()
{
    struct File* test;
    creer_file(&test);
    printf("%d\n",vide(test));
    for(int i=0;i<6;i++){
        enfiler(test,i);
    }
    
    display(test);
    defiler(test);
    display(test);
    
    
}