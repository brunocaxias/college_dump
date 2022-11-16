#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp19.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import math 

def f_checa_raiz(i):
    raiz = float(0)
    checagem = float(0)
    raiz = float(i**0.5)
    checagem = math.floor(raiz)**2
    if checagem == i:
        return True
    else:
        return False


def f_checa_capicua(i):
    strnum = str(i)
    revers = strnum[::-1]
    if revers == strnum:
        return True
    else:
        return False
