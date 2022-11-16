#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "hfile.h"



float Gera_Exponencial (float avg)
{
    float u=0; /* Gera randomicamente um numero entre 0 e 1 */
    do 
        u = ((float)rand()) / ((float) RAND_MAX);
    while ((u==0) || (u==1));
    return (-avg * log (u));
}

float tempo(float Estadia_Equipamento_Rolamento)
{
    float u = ((float)rand()) / ((float) RAND_MAX);
    return 2.0 * Estadia_Equipamento_Rolamento * u;
}

/* Funcao generica para transformar string in double*/
float stof(const char* s)
{
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
}


void setTimeout(double milliseconds) /* cria um timeout de 1seg */
{
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    int end = milliseconds_since + milliseconds;
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}


void adicionarContador(int contadorQuant[4], double contadorValor[4],Rolamento * rolAtual)
{
    switch (rolAtual->priority)
    {
    case CILINDRO:
        contadorQuant[0] += 1;
        contadorValor[0] += rolAtual->tempProducao;
        break;
    
    case CONE:
        contadorQuant[1] += 1;
        contadorValor[1] += rolAtual->tempProducao;
        break;

    case ESFERA:
        if (rolAtual->type == 0)
        {
            contadorQuant[3] += 1;
            contadorValor[3] += rolAtual->tempProducao;
        }else{
            contadorQuant[2] += 1;
            contadorValor[2] += rolAtual->tempProducao;
        }
    }


}