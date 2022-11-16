#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  mod20211BSI0119Q1.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_validaNumBase(n,b):
    # Variaveis
    number = str(n)
    j = int(0)
    baserange = str("")
    translate = str("")
    genbaserange = str("0123456789")
    # Formatacao de strings para encontrar os numeros nao aceitos
    for j in range(b):
        baserange += str(" %i" % j)
        translate += str("  ")

    mute = genbaserange.maketrans(baserange,translate)
    genbaserange = genbaserange.translate(mute)
    # Checagem do numero
    chars = set(genbaserange)
    if any((c in chars) for c in number):
        return False
    else:
        return True 

def f_converteBaseNBase10(n,b): 
    i = int(0)
    decimal = int(0)
    while n > 0:
        dec = n % 10
        decimal = decimal + dec * (b**i)
        n = n//10
        i += 1
    return decimal


def f_converteBaseNBase16(n,b):
    i = int(0)
    decimal = int(0)
    #-----------------------
    while n > 0:
        dec = n % 10
        decimal = decimal + dec * (b**i)
        n = n//10
        i += 1
    #-----------------------
    hexadecimal = str("")
    quoc = int(0)
    letters = str("")
    if decimal < 10:
        hexadecimal = str(decimal)
    else:
        while decimal > 0:
            quoc = decimal % 16
            letters = str(quoc)
            if quoc == 10:
                letters = str("A")

            if quoc == 11:
                letters = str("B")

            if quoc == 12:
                letters = str("C") 

            if quoc == 13:
                letters = str("D") 

            if quoc == 14:
                letters = str("E") 

            if quoc == 15:
                letters = str("F")
            hexadecimal = letters + hexadecimal
            decimal = decimal // 16
    return hexadecimal