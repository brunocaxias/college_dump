#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119APNP20.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import appApnp20
from appApnp20 import f_padroes_visuais

def main():
    padrao = str("")
    caractere = str("")
    imagem = str("")
    savimg = str("")
    #-------------------------------
    padrao = str(input())
    #-------------------------------
    if padrao == "a" or padrao =="b" or padrao =="c" or padrao =="d" or padrao =="e" or padrao =="f":
        while padrao == "a" or padrao =="b" or padrao =="c" or padrao =="d" or padrao =="e" or padrao =="f":
            caractere = str(input())
            imagem = str("")
            
            imagem = f_padroes_visuais(padrao, caractere)
            
            savimg += ("%s \n" % imagem)

            padrao = str(input())
        print (savimg)
if __name__ == "__main__":
    main()