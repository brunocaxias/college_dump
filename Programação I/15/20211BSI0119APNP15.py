#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119APNP15.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

# função com o programa principal
import appApnp15
from appApnp15 import f_calcula_mdc

def main():
    n1 = int(0)
    n2 = int(0)
    n3 = int(0)
    savnum = str("")
    aux = int(0)
    mdc = int(0)
    #-----------------------
    for i in range(25):
        n1 = int(input())
        n2 = int(input())
        n3 = int(input())
    #-----------------------
        savnum = ("MDC(%i, %i, %i)=" % (n1, n2 ,n3))

        mdc = f_calcula_mdc(n1,n2)

        while n3 != 0:
            aux = mdc % n3
            mdc = n3
            n3 = aux

        # Saida de Dados
        print ("%s%i" % (savnum, mdc))
# fim da função main

#invocação/chamada do programa principal
if __name__ == "__main__":
    main()

#fim