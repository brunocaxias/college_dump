#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119Q2.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------


def main():
    # Declaração de Variaveis
    n = int(0)
    pi = float(0.0)
    soma = float(0.0)
    div = int(1)
    aux = int(1)
    serie = float(0.0)
    # Entrada de dados
    n = int(input())
    # Processos
    if n > 0:
        for i in range(n):
            print ("%i/%i^3" % (aux, div))
            serie = aux/div**3
            div += 2
            aux *= -1    
            soma += serie     
        pi = (soma*32)**(1/3)
    # Saida de dados
        print ("N=%i SOMATORIO=%.5f PI=%.5f" % (n, soma, pi))   

    else:
        print("N=%i N INVALIDO" % (n))




if __name__ == "__main__":
    main()