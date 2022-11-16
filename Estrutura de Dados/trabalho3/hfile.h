#ifndef __hfile_h_
#define __hfile_h_


/* Structs e enum fixos*/
typedef enum {CILINDRO = 1, CONE = 2, ESFERA = 3} Prioridade; /*enum com as prioridades de cada rolamento */

/* criando data types para cada struct */
typedef struct lista_str Lista;
typedef struct rolamento Rolamento;
typedef struct fila Fila;
typedef struct elemFila ElemF;
/*--------------------------------------*/


/*Fila Prioridade */
typedef struct ElemPQ /* elemento da fila de prioridade*/
{
    Rolamento*  r;
    struct ElemPQ *next;
    Prioridade prty;

}ElemPQ, *ElemPQPtr;

typedef struct filapq /* fila de prioridade com lista encadeada*/
{

    ElemPQPtr top;
    ElemPQPtr tail;

} FilaPQ, *PQ;



/*---------------------------------------*/


/* Fila */

struct elemFila { /* elemento da fila padrao */
    ElemF* next;
    void (*fun_ptr)(Rolamento *);
};

struct fila { /*estrutura da fila com lista encadeada*/
    ElemF *front, *rear;
};


/*------------------------*/

/* Rolamento */
struct rolamento /* estrutura do rolamento */
{
    double tempChegada, tempProducao;
    Prioridade priority;
    Fila * seqMaquinas;
    PQ t,f,m;
    float tempEstadia[3];
    int type;
};
/*-------------------------*/

/* Lista */
struct lista_str { /*estrutura de lista encadeada*/
    float data;
    Lista* next;
};
/*---------------------------*/

/* Maquinas */
void maquina(PQ pq, float * estadia, int contadorQuant[4], double contadorValor[4],float timer,Rolamento** rolAtual,int pos); /* funcao da maquina para realizar a producao do rolamento*/
/*-------------------------------------------------*/






/* Funcoe da lista */
void pushList(Lista** head_ref, float new_data); /* Coloca valor na lista */
void deleteNodeList(Lista** head_ref, float key); /* Deleta uma elemento da lista */
void printList(Lista* node); /* Printa a lista completa */
double getSmallestList(Lista* node, int option); /* Pega menor termo da lista*/
void updateList(Lista**node, int pos); /* Da um update no menor termo da lista baseado na posicao dele */
/*-----------------------------------------------*/

/* Funcoes de fila */
Fila* createQueue(); /* Cria fila */
void enQueue(Fila* q, void (*maquina)(Rolamento *)); /* Encaixa ponteiro para funcao na fila */
void deQueue(Fila* q); /* retira primeiro elemento da fila */
int isEmptyQueue(Fila* q); /* verifica se a fila esta vazia */
/*-----------------------------------------------*/

/* Funcoes de fila de prioridade */
PQ initPQ(); /* inicia a fila de prioridade */
void pEnqueue(PQ q, Rolamento * r, int prty); /* encaixa rolamento na fila de prioridade */
Rolamento * dequeuePQ(PQ q); /* retira rolamento na fila de prioridade e retorna o mesmo */
int isEmptyPQ(PQ q); /* verifica se a fila esta vazia */
void addValue(PQ q); /* adiciona valor (nesse caso 1 pois o programa roda de segundo em segundo) a todos os valores da lista de prioridade */
void adicionarContador(int contadorQuant[4], double contadorValor[4],Rolamento * rolAtual); /* Adiciona nos contadores os rolamentos produzidos */
void destroyPQ(PQ q); /* Da free no node da lista e nos elementos dela */
/*-----------------------------------------------*/


/* Funcoes dos rolamentos */
Rolamento * criarRolamento(double tempChegada, Prioridade priority, PQ t, PQ f, PQ m); /* gera o rolamento */
void inserir(Lista* chegadas,PQ torno,PQ fresa,PQ mandril, float timer); /* insere e envia o rolamento para a primeira fila de prioridade da maquina */
/*-----------------------------------------------*/

/* functions file*/
float Gera_Exponencial (float avg); /* gera o tempo de chegada de cada tipo de rolamento */
float tempo(float Estadia_Equipamento_Rolamento); /* gera o tempo que cada rolamento ficara na maquina*/
float stof(const char* s); /* Funcao para substituir atof e pegar o numero de ticks que o codigo rodara */
void setTimeout(double milliseconds); /* cria um timeout de 1seg */
/*-----------------------------------------------*/


#endif
