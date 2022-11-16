#ifndef __hfile_h_
#define __hfile_h_


typedef struct no no_t;
typedef struct matriz matriz_t;

/*Funcoes da matriz*/
matriz_t *criaMatriz(int nlinhas, int ncolunas);
void inserir(matriz_t *m, int linhas, int coluna, double valor);
void imprimirMatriz(matriz_t *m);
void desalocar(matriz_t *m);
void soma(matriz_t *m, int linha,int coluna , double valor);
void remover(matriz_t *m, int linha, int coluna);
void populaMatriz(matriz_t *m,FILE *file);
void somaMatriz(matriz_t *m, matriz_t *n);
/*------------------------------------------------*/

/*Funcoes auxiliares*/
int getOrdem(FILE *fp);
int isInteger(double N);
/*------------------------------------------------*/
#endif