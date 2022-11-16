#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "hfile.h"


void torno(Rolamento * r)
{
    deQueue(r->seqMaquinas);    /* retira o ponteiro de funcao da fila*/
    pEnqueue(r->t,r,r->priority); /* encaixa o rolamento na fila de prioridade da maquina*/
    
    
}

void fresa(Rolamento * r)
{
    deQueue(r->seqMaquinas);    /* retira o ponteiro de funcao da fila*/
    pEnqueue(r->f,r,r->priority);   /* encaixa o rolamento na fila de prioridade da maquina*/
    
       
}

void mandril(Rolamento * r)
{
    deQueue(r->seqMaquinas);    /* retira o ponteiro de funcao da fila*/
    pEnqueue(r->m,r,r->priority);   /* encaixa o rolamento na fila de prioridade da maquina*/
    
    
}


void maquina(PQ pq, float * estadia, int contadorQuant[4], double contadorValor[4],float timer,Rolamento** rolAtual,int pos)
{
    if(*estadia == 0) /* verifica se a maquina esta vazia*/
    {
        if(!isEmptyPQ(pq)) /* se estiver verifica se a fila de prioridade esta vazia */
        {
            (*rolAtual) = dequeuePQ(pq); /* retira o primeiro termo da fila*/
            (*rolAtual)->tempProducao += tempo((*rolAtual)->tempEstadia[pos]); /* gera o novo tempo de producao do produto */
            *estadia += ((*rolAtual)->tempChegada+(*rolAtual)->tempProducao); /* guarda quanto tempo a maquina ira ficar ocupada */
            return;
        }else
        {
            return; /* se a fila estiver vazia nada acontece*/
        }
        
    }
    else if(*estadia <= timer) /* verifica se esta na hora do rolamento sair da maquina */
    {   
        if(!isEmptyQueue((*rolAtual)->seqMaquinas)) /* verifica se ele tem que ir para outra maquina */
        {
            (*rolAtual)->seqMaquinas->front->fun_ptr((*rolAtual)); /* manda para outra maquina*/
        }else{ /* se nao tiver */
            adicionarContador(contadorQuant,contadorValor,(*rolAtual)); /* adiciona ao contador*/
         }
        *estadia = 0; /* coloca a maquina como vazia*/
    }
    else /*se a maquina estiver cheia */
    {
        addValue(pq); /*adiciona tempo a todos os rolamentos na fila de prioridade */
    }
}

int probEsfera()
{
  return ( ( (double)rand() / (double)RAND_MAX ) < 0.1 ) ? 1 : 0;
}

Rolamento * criarRolamento(double tempChegada, Prioridade priority, PQ t, PQ f, PQ m)
{
    Rolamento * r = (Rolamento *)malloc(sizeof(Rolamento));
    r->priority = priority;
    r->tempChegada = tempChegada;
    r->tempProducao = 0;
    r->t = t;
    r->f = f;
    r->m = m;
    

    switch (priority)
    {
    case CILINDRO:
        r->seqMaquinas = createQueue();
        enQueue(r->seqMaquinas,torno);
        enQueue(r->seqMaquinas,fresa);
        enQueue(r->seqMaquinas,torno);
        enQueue(r->seqMaquinas,mandril);
        r->tempEstadia[0] = 0.8;
        r->tempEstadia[1] = 0.5;
        r->tempEstadia[2] = 1.2;
        r->type = 0;
        break;
    
    case CONE:
        r->seqMaquinas = createQueue();
        enQueue(r->seqMaquinas,torno);
        enQueue(r->seqMaquinas,mandril);
        enQueue(r->seqMaquinas,torno);
        r->tempEstadia[0] = 1.8;
        r->tempEstadia[1] = 0;
        r->tempEstadia[2] = 2.1;
        r->type = 0;
        break;

    case ESFERA:
        if(probEsfera())
        { /* Titanio */
            r->seqMaquinas = createQueue();
            enQueue(r->seqMaquinas,fresa);
            enQueue(r->seqMaquinas,mandril);
            enQueue(r->seqMaquinas,torno);
            enQueue(r->seqMaquinas,fresa);
            enQueue(r->seqMaquinas,torno);
            r->tempEstadia[0] = 1.6;
            r->tempEstadia[1] = 0.6;
            r->tempEstadia[2] = 1.5;
            r->type = 0;
        }else
        { /* Aco */
            r->seqMaquinas = createQueue();
            enQueue(r->seqMaquinas,fresa);
            enQueue(r->seqMaquinas,mandril);
            enQueue(r->seqMaquinas,torno);
            r->tempEstadia[0] = 1.0;
            r->tempEstadia[1] = 0.5;
            r->tempEstadia[2] = 1.4;
            r->type = 1;
        }

        break;
    }

    return r;
}

void inserir(Lista* chegadas,PQ torno,PQ fresa,PQ mandril,float timer)
{

    Rolamento * newR = criarRolamento(getSmallestList(chegadas,0),getSmallestList(chegadas,1)+1,torno,fresa,mandril);
    newR->seqMaquinas->front->fun_ptr(newR);  

 
       
}