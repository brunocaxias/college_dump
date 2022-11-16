#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119APNP18.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import appApnp18
from appApnp18 import f_quant_divisor


def main():
    n = int(0)
    div = 0
    #--------------------
    n = int(input())
    while n > 0:
        div = f_quant_divisor(n)

        if n == 1:
            print("%i POSSUI %i DIVISOR" % (n,div))
        else:
            print("%i POSSUI %i DIVISORES" % (n,div))

        n = int(input())
            
if __name__ == "__main__":
    main()