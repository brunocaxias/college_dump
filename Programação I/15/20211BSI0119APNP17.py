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
    while nb3 >= 0:

        f_base3_para_base10(nb3)

        nb3 = f_base3_para_base10
    
    


    

# fim da função main

#invocação/chamada do programa principal
if __name__ == "__main__":
    main()

#fim