#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp10.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def main():
    #-------------------------
    freq = str("")
    matric = str("")
    ident = str("")
    quantaluno = int(0)
    aus = int(0)
    texto = str("")
    perc = float(0.0)
    maioraus = 0
    maiorturma = str("")
    menoraus = 100
    menorturma = str("")
    maiorvinte = 0
    #-------------------------
    nturmas = int(input(""))
    for i in range(nturmas):
        aus = 0
        ident = str(input(""))
        quantaluno = int (input(""))
        for x in range(quantaluno):
            matric = str(input(""))
            freq = str(input(""))
            if freq == "A":
                aus += 1
        perc = float((aus * 100) / quantaluno)
        print("TURMA=%s AUSENCIA=%.2f%%" % (ident, perc))
        if perc > maioraus:
            maioraus = perc
            maiorturma = ident
        if perc < menoraus:
            menoraus = perc
            menorturma = ident
        if perc > 20:
            maiorvinte += 1
    print ("TURMA COM MAIOR PORCENTAGEM DE AUSENCIA=%s AUSENCIA=%.2f%%" % (maiorturma, maioraus))
    print ("TURMA COM MENOR PORCENTAGEM DE AUSENCIA=%s AUSENCIA=%.2f%%" % (menorturma, menoraus))
    print ("%i TURMAS COM PORCENTAGEM DE AUSENCIA SUPERIOR A 20%%" % (maiorvinte))
    
if __name__ == "__main__":
    main ()