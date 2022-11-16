#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119APNP17.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

# função com o programa principal
import appApnp17
from appApnp17 import f_base3_para_base10
from appApnp17 import f_base10_para_base3

def main():
    nb3 = int(0)
    nb10 = int(0)
    entrada = int(0)
    #------------------------------
    while entrada >= 0:
        entrada = 0
        nb10 = 0
        entrada = int(input())
        nb10 = entrada
        if entrada >= 0:

            nb3 = int(f_base10_para_base3(nb10))

            nb10 =f_base3_para_base10(nb3)

            print("ENTRADA = %i BASE3 = %i BASE10 = %i" % (entrada, nb3, nb10))

# fim da função main

#invocação/chamada do programa principal
if __name__ == "__main__":
    main()

#fim