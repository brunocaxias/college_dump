#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp17.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

# Função de conversão base 3
def f_base3_para_base10(nb3): 
    i = int(0)
    decimal = int(0)
    while nb3 > 0:
        dec = nb3 % 10
        decimal = decimal + dec * (3**i)
        nb3 = nb3//10
        i += 1
    return decimal

def f_base10_para_base3(nb10):
    base3 = str("")
    quoc = int(0)
    if nb10 < 4:
        base3 = str(nb10)
    else:
        while nb10 > 0:
            quoc = nb10 % 3
            base3 = str(quoc) + base3
            nb10 = nb10 // 3
    return base3 
    







