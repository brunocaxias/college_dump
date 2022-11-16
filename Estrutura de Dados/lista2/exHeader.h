#ifndef __exHeader_h_
#define __exHeader_h_

#define M 5
#define N 4

void calcula(float l, float *area, float *perimetro);
void imprime(int *v, int tam);
void swap(int *a, int *b);
void populaMatriz(int m, int n, int arr[m][n]);
void printMatriz(int m, int n, int arr[m][n]);
void charcpy(char* dest, const char* src, int count);

#endif