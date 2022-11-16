#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp15.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------
def f_calcula_mdc(a,b):
    a = int(0)
    b = int(0)
    r = int(0) 
    while (b != 0):
        r = a % b
        a = b
        b = r
    return a













