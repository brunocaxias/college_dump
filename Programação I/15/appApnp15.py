#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp15.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

# Função de cálculo do mdc
def f_calcula_mdc(a,b): 
    while (b != 0):
        r = a % b
        a = b
        b = r
    mdc = a
    return mdc
#fim da função













