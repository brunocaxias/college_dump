#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"

 
struct no{
	double valor;
	int lin,col;
	no_t *pcol, *plin;
};


struct matriz
{
	no_t **lin, **col;
	int nlin, ncol; 
};


/*Funcao para criar a matriz*/
matriz_t *criaMatriz(int nlinhas, int ncolunas)
{
	matriz_t *m = (matriz_t *)malloc(sizeof(matriz_t));
	m->nlin = nlinhas;
	m->ncol = ncolunas;

	m->lin = (no_t **)malloc(sizeof(no_t *)* nlinhas);
	m->col = (no_t **)malloc(sizeof(no_t *)* ncolunas);

	for(int i = 0; i < nlinhas; i++)
	{
		m->lin[i] = NULL;
	}
	for(int i = 0; i < ncolunas; i++)
	{
		m->col[i] = NULL;
	}

	return m;
}


/*Funcao para criar no*/
no_t *criaNo(int linha, int coluna, double valor)
{
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->lin = linha;
	p->col = coluna;
	p->valor = valor;
	p->pcol = NULL;
	p->plin = NULL;

	return p;
}


/*Funcao de inserir no na matriz*/
void inserir(matriz_t *m, int linha, int coluna, double valor)
{
	no_t *p = criaNo(linha,coluna,valor);

	no_t *aux = m->lin[linha];
	no_t *ant = NULL;
	while(aux != NULL && aux->col < coluna)
	{
		ant = aux;
		aux = aux->pcol;
	}
	/*Inserindo no inicio da lista*/
	if(ant == NULL)
	{
		/*Caso a lista ja tenha algum elemento*/
		if(aux != NULL)
		{
			p->pcol = aux;
		} 
		m->lin[linha]= p;
	}else{

		ant->pcol = p;
		p->pcol = aux;
	}

	aux = m->col[coluna];
	ant = NULL;
	while(aux != NULL && aux->lin < linha)
	{
		ant = aux;
		aux = aux->plin;
	}
	/*Inserindo no inicio da coluna*/
	if(ant == NULL)
	{
		/*Caso a coluna ja tenha algum elemento*/
		if(aux != NULL)
		{
			p->plin = aux;
		} 
		m->col[coluna]= p;
	}else{

		ant->plin = p;
		p->plin = aux;
	}
}


/*Funcao para imprimir a matriz*/
void imprimirMatriz(matriz_t *m)
{
	printf("%d\n",m->nlin);
	for(int i=0; i< m->nlin; i++)
	{
		no_t *aux = m->lin[i];
		while(aux != NULL)
		{	
			int n = isInteger(aux->valor); 
			if(n == 0)
			{
				printf("%d;%d;%.1f\n",aux->lin+1, aux->col+1, aux->valor);
			} else {
				printf("%d;%d;%i\n",aux->lin+1, aux->col+1, n);
			}
			aux = aux->pcol;
		}
	}
}


/*Funcao para remover no de uma matriz*/
void remover(matriz_t *m, int linha, int coluna)
{
	no_t *aux = m->lin[linha];
	no_t *ant = NULL;
	while (aux != NULL && aux->col != coluna) /*Procura pelas linhas a posicao*/
	{
		ant = aux;
		aux = aux->pcol;
	}
	if(aux == NULL)
	{
		return; /*Retorna nada se a linha estiver vazia*/
	}
	if(ant == NULL)
	{
		m->lin[linha] = aux->pcol;
	} else {
		ant->pcol = aux->pcol;
	}

	aux = m->col[coluna];
	ant = NULL;
	while (aux != NULL && aux->lin != linha) /*Procura pelas colunas a posicao*/
	{
		ant = aux;
		aux = aux->plin;
	}
	if(aux == NULL)
	{
		return;/*Retorna nada se a coluna estiver vazia*/
	}
	if(ant == NULL)
	{
		m->col[coluna] = aux->plin;
	} else {
		ant->plin = aux->plin;
	}

	free(aux);
	
}


/*Funcao para desalocar a matriz*/
void desalocar(matriz_t *m)
{
	no_t *aux2;
	for(int i=0; i < m->nlin; i++) /*Desaloca todos os nos*/
	{
		no_t *aux = m->lin[i];
		while(aux != NULL)
		{
			aux2 = aux;
			aux = aux->pcol;
			free(aux2);
		}
	}
	free(m->lin);
	free(m->col);
	free(m);
}


/*Funcao para somar a um nó na matriz*/
void soma(matriz_t *m, int linha,int coluna , double valor)
{
	no_t *aux = m->lin[linha];
	if(aux == NULL) /* Verifica se a lista da linha esta vazia*/
	{
		inserir(m,linha,coluna,valor);
		return;
	}
	while (aux != NULL)
	{
		if(coluna == aux->col)/*Cenario que incrementa o valor em no ja existente*/
		{
			aux->valor += valor;
			if(aux->valor == 0)/*Checa se o valor da 0 para deleta-lo*/
			{
				remover(m, linha, coluna);
			}
			return;
		}
		if(coluna < aux->col) /*Checa se a coluna desejada ja passou*/
		{
			inserir(m, linha, coluna, valor);
			return;
		}
		aux = aux->pcol;
	}
	inserir(m,linha,coluna,valor);
	 
}


void populaMatriz(matriz_t *m, FILE *file)
{
    int lin = 0;
	int col = 0;
    double valor = 0;

    char frase[100];
    
    while (fgets(frase,sizeof(frase), file)) {
        sscanf(frase,"%i;%i;%lf",&lin,&col,&valor);
        if(valor != 0.0)
        {
			/*printf("%d %d %f\n",lin,col,valor);*/
			inserir(m,lin-1,col-1,valor);
        }
    }
}

void somaMatriz(matriz_t *m, matriz_t *n)
{
	for(int i=0; i< m->nlin; i++)
	{
		no_t *aux = m->lin[i];
		if(aux != NULL)
		{
			while(aux != NULL)
			{	
				soma(n,aux->lin, aux->col, aux->valor);
				aux = aux->pcol;					
			}
		}
		
	}
}
