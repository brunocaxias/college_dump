#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "hfile.h"



int main(int argc, char const *argv[])
{
    /* Inicializa contadores que guardarao a informacao que sera printada no final*/
    int contadorQuant[4] = {0,0,0,0};
    double contadorValor[4] = {0,0,0,0};
    /*----------------------------------------------------------------------------*/

    /*Time e delay que guardarao o tempo decorrido e o tempo que falta para acabar a execucao respectivamente*/
    float timer = 1;
    double delay = stof(argv[1]);
    /*-------------------------------------------------------------------------------------------------------*/

    /* variaveis de tempo de estadia e rolamento que guardarao o tempo e rolamento atual de cada maquina*/
    float estadiaT = 0;
    float estadiaF = 0;
    float estadiaM = 0;
    Rolamento  * rolT = (Rolamento *)malloc(sizeof(Rolamento));
    Rolamento  * rolF = (Rolamento *)malloc(sizeof(Rolamento));
    Rolamento  * rolM = (Rolamento *)malloc(sizeof(Rolamento));
    /*---------------------------------------------------------------------------------------------------*/

    srand(time(NULL)); /* <-- parte obrigatoria do codigo */

    /* Criacao da lista que guardara o tempo de chegada de cada tipo de rolamento*/
    Lista* chegadas = NULL;
    pushList(&chegadas,Gera_Exponencial(8.0));
    pushList(&chegadas,Gera_Exponencial(19.1));
    pushList(&chegadas,Gera_Exponencial(21.5));
    /*----------------------------------------------------------------------------*/

    /* Inicializacao das filas de prioridade de cada maquina*/
    PQ torno = initPQ();
    PQ mandril = initPQ();
    PQ fresa = initPQ();
    /*------------------------------------------------------*/

    do
    {
        timer++;

        if(getSmallestList(chegadas,0) <= timer)
        {
            inserir(chegadas,torno,fresa,mandril,timer);
            updateList(&chegadas,(int)getSmallestList(chegadas,1));
        }

        maquina(torno,&estadiaT, contadorQuant,contadorValor,timer,&rolT,0);

        maquina(fresa,&estadiaF, contadorQuant,contadorValor,timer,&rolF,1);

        maquina(mandril,&estadiaM, contadorQuant,contadorValor,timer,&rolM,2);

        /*setTimeout(1000); CASO QUEIRA USAR A FUNCAO APENAS RETIRE O COMENTARIO */

        delay--;
    } while (delay > 0);



    /* Loop para printar e formatar os contadores */
    for (int i = 0; i < 4; i++)
   {
      if(contadorQuant[i] != 0 && contadorValor[i] != 0)
      {
         contadorValor[i] = contadorValor[i]/contadorQuant[i];
      }
      else{
         contadorValor[i] = 0;
      }
   }
   printf("Resultado:\n");
   printf("Cilindricos            : %7.2f \t %d \n", contadorValor[0], contadorQuant[0]);
   printf("Conicos                : %7.2f \t %d \n", contadorValor[1], contadorQuant[1]);
   printf("Esfericos de Aco       : %7.2f \t %d \n", contadorValor[2], contadorQuant[2]);
   printf("Esfericos de Titanio   : %7.2f \t %d \n", contadorValor[3], contadorQuant[3]);



   while(!isEmptyPQ(torno))
   {
    destroyPQ(torno);
   }
    while(!isEmptyPQ(fresa))
   {
    destroyPQ(fresa);
   }
    while(!isEmptyPQ(mandril))
   {
    destroyPQ(mandril);
   }
   free(chegadas);

   return 0;
}
