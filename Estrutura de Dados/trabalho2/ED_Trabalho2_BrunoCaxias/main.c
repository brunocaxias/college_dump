#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"

int main(int argc, char *argv[])
{
	int ordem;

	FILE *file1, *file2;
	file1 = fopen(argv[1],"r");
	file2 = fopen(argv[2],"r");

	ordem = getOrdem(file1);
	

	matriz_t *a = criaMatriz(ordem,ordem);
	matriz_t *b = criaMatriz(ordem,ordem);
	matriz_t *c;


	populaMatriz(a,file1);
	populaMatriz(b,file2);

	c = b;

	somaMatriz(a,c);


	imprimirMatriz(c);

	desalocar(a);
	desalocar(b);
	fclose(file1);
	fclose(file2);
	return 0;
}
