#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  mod20211BSI0119Q3.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_piramide(i,n):
    piramid = str("")
    value = str(i)
    numadd = int(0)
    j = int(0)
    cont = int(0)
    if i == 0:
        numadd = 1
    for j in range (j,n):
        piramid += ("%s \n" % value)
        value += str(" %i" % numadd) 
        value = value[::-1]
        cont += 1
        if cont % 2 == 0:
                numadd = (numadd+1) % 2
    return piramid