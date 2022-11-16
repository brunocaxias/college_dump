#include <stdio.h>
#include "exHeader.h"
#include <stdlib.h>


void imprime(int *v, int tam)
{
	int i;
	
    for (i = 0; i < tam; ++i) {
         v[i] = i;
    }
    for (i = 0; i < tam; ++i) {
        printf("%d \n", v[i]);
    }
    free(v);
}
