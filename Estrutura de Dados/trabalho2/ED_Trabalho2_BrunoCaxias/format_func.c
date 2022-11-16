#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"


int isInteger(double N)/*Checa se um double pode ser representado como inteiro*/
{
    int X = N;
 
    double temp2 = N - X;

    if (temp2 != 0) {
        return 0;
    }
    return X;
}

int getOrdem(FILE *fp)/*Checa a ordem da matriz quadrada*/
{
    int ordem;
    fscanf(fp,"%d",&ordem);
    return ordem;
}