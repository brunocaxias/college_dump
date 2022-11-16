#include <stdio.h>
#include "exHeader.h"
#include <stdlib.h>


int main(int argc, char **argv)
{	
	/*float l;
	float area;
	float perimetro;
	
	int tam;
    int *v;
	
	int a;
	int b;
	
	printf("Escreva o lado do quadrado: \n");
	scanf("%f",&l);
	calcula(l, &area, &perimetro);
	
	
	printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);
	v = (int *)malloc(tam * sizeof(int));
    imprime(v,tam);
	
	
	scanf("%i",&a);
	scanf("%i",&b);
	swap(&a,&b);
	
	
	int m = M;
    int n = N;
 
    int matriz[m][n];
 
    populaMatriz(m, n, matriz);
	
	printMatriz(m,n,matriz);*/
	
	char str1[] = "Bruno"; 
	char str2[] = "Pedro"; 
	 
	printf("String 1 before memcpy \n");
	printf(str1);
	printf("\n");
	 
	charcpy (str1, str2, sizeof(str2));
	 
	printf("\nstring 1 depois do charcpy \n");
	printf(str1);
	
	
	return 0;
}