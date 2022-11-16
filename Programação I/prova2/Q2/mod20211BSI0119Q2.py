#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  mod20211BSI0119Q2.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_calcProduto(a,b):
    sumb = int(0)
    while a > 0:
        if a % 2 == 1:
            sumb += b
        a = a // 2
        b = b * 2
    return sumb
