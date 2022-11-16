#include <stdio.h>
#include "exHeader.h"


void populaMatriz(int m, int n, int arr[m][n])
{
	int i,k = 0;
	
	for (i = 0; i < m*n; i++)
    {
		arr[i/n][i%n] = k;
		k++;
        
    }
}

void printMatriz(int m, int n, int arr[m][n])
{
	int x = 0;
    int y = 0;

    for(x = 0 ; x < m ; x++) {
        for(y = 0 ; y < n ; y++){
            printf("%d     ", arr[x][y]);
        }
        printf("\n");
    }
}