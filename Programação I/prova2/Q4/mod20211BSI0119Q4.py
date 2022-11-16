#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  mod20211BSI0119Q4.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_serie_fibonacci(n):
    cont = 0
    n1 = int(0)
    n2 = int(1)
    savseq = str("")
    nth = int(0)
    sompar = int(0)
    somimpar = int(0)
    razao = float(0.0)
    out = str("")
    #--------------------------------
    while cont < n:
        savseq += str("%i\n" % n1)
        nth = n1 + n2

        if n1 % 2 == 0:
            sompar += n1
        if n1 % 2 == 1:
            somimpar += n1
       # Atualizar Valores
        n1 = n2
        n2 = nth
        cont += 1
    # Organizar return
    razao = sompar / somimpar
    out = str("%sSOMA TERMOS PARES=%i SOMA TERMOS IMPARES=%i RAZAO=%.5f" % (savseq, sompar, somimpar, razao))
    return out

    