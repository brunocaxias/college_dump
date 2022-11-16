#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"


/* Lista */
void pushList(Lista** head_ref, float new_data)
{
    Lista* new_node = (Lista*)malloc(sizeof(Lista));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void deleteNodeList(Lista** head_ref, float key)
{
    Lista *temp = *head_ref, *prev;
 
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;

    prev->next = temp->next;
 
    free(temp); // Free memory
}
 
void printList(Lista* node)
{
    while (node != NULL) {
        printf("%f ", node->data);
        node = node->next;
    }
}


double getSmallestList(Lista* node, int option)
{
    int pos = 0;
    Lista * smallest = node;
    for(int i = 0; i < 3; i++)
    {
        if(smallest->data > node->data)
        {
            smallest = node;
            pos = i;
        }
        node = node->next;
        
    }
    switch (option)
    {
    case 0:
        return smallest->data;
        break;
    
    default:
        return pos;
        break;
    }
    
}

void updateList(Lista**node, int pos)
{
    if(pos == 0)
    {
        (*node)->data += Gera_Exponencial(21.5);
    }
    if(pos == 1)
    {
        (*node)->next->data += Gera_Exponencial(19.1);
    }
    if(pos == 2)
    {
        (*node)->next->next->data += Gera_Exponencial(8.0);
    }
}



/* -------------------------------------------------------------------------------------- */


/* Queue */

ElemF* newNode(void (*maquina)(Rolamento *))
{
    ElemF* temp = (ElemF*)malloc(sizeof(ElemF));
    temp->fun_ptr = maquina;
    temp->next = NULL;
    return temp;
}
  
Fila* createQueue()
{
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->front = q->rear = NULL;
    return q;
}
  
void enQueue(Fila* q, void (*maquina)(Rolamento *))
{
    ElemF* temp = newNode(maquina);
  
    if (q->rear == NULL) 
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}
  

void deQueue(Fila* q)
{

    if (q->front == NULL)
    {
        return;
    }
        
    ElemF* temp = q->front;
  
    q->front = q->front->next;
  
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    
    free(temp);
}

int isEmptyQueue(Fila* q)
{
    return q->front == NULL;
}

/*----------------------------------------------------------------*/






/* Priority Queue */

int isEmptyPQ(PQ q)
{return q->top == NULL;}

PQ initPQ()
{
    PQ newQueue = malloc(sizeof(FilaPQ));
    newQueue->top = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

void pEnqueue(PQ q, Rolamento * r, int prty)
{

    ElemPQPtr newNode = malloc(sizeof(ElemPQ));
    newNode->r = r;
    newNode->next = NULL;
    newNode->prty = prty;
    
    if(!isEmptyPQ(q))
    {

        if(newNode->prty < q->top->prty)
        {
            newNode->next = q->top;
            q->top = newNode;
        }else{
            ElemPQPtr prevTemp = q->top;
            ElemPQPtr temp = q->top->next;
            while (temp != NULL && temp->prty < newNode->prty)
            {
                prevTemp = temp;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                prevTemp->next = newNode;
                q->tail = newNode;
            }else{
                newNode->next = temp;
                prevTemp->next = newNode;
            }
        }

    }
    else{
        q->top = newNode;
        q->tail = newNode;
    }

}

Rolamento * dequeuePQ(PQ q)
{
    if(isEmptyPQ(q)) 
    {
        return NULL;
    }else{
        ElemPQPtr temp = q->top;
        Rolamento * tempNum = q->top->r;
        q->top = q->top->next;
        free(temp);

        return tempNum;
    }
    
}

void destroyPQ(PQ q)
{
    if(isEmptyPQ(q)) 
    {
        return;
    }else{
        ElemPQPtr temp = q->top;
        Rolamento * tempNum = q->top->r;
        free(tempNum->seqMaquinas);
        free(tempNum);
        q->top = q->top->next;
        free(temp);
    }
    
}

void addValue(PQ q)
{
    ElemPQPtr temp = q->top;
    while (temp != NULL)
    {
        temp->r->tempProducao += 1;
        temp = temp->next;
    }

}


/*-----------------------------------------------------------*/