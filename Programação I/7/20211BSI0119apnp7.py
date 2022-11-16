#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp7.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------


def main():
    #-----------------------------------------------------------------------
    # Ditando e recebendo as variaveis  
    #-----------------------------------------------------------------------
    a = float(input(""))
    b = float(input(""))
    c = float(input(""))
    delta = (b ** 2) - 4 * a * c
    #-----------------------------------------------------------------------
    # Código, comandos e exceções
    #-----------------------------------------------------------------------
    if a == 0:
        print ("NAO EH EQ 2G")
    elif delta < 0:
        print ("NAO TEM SOLUCAO NO DOMINIO DO NUMEROS REAIS")
    else:
        x1 = (-b + delta ** 0.5) / (2 * a)
        x2 = (-b - delta ** 0.5) / (2 * a)
    #-----------------------------------------------------------------------
    # Resultados
    #-----------------------------------------------------------------------

        print("x1:%.2f" % (x1)) 
        print("x2:%.2f" % (x2)) 
    
    #fim do codigo
        
if __name__ == "__main__":
    main()