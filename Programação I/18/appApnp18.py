#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp18.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_quant_divisor(n):
    div = int(1)
    aux = int(1)
    for i in range(1, int(n / 2) + 1):
        if n % i == 0:
            div += 1
    return div