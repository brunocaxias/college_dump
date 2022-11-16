#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  appApnp20.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def f_padroes_visuais(padrao, caractere):

    if padrao == "a":
        padrao = ("****** \n****** \n****** \n****** \n****** \n******\n").replace("*", caractere)
    if padrao == "b":
        padrao = ("* \n** \n*** \n**** \n***** \n******\n").replace("*", caractere)
    if padrao == "c":
        padrao = ("     * \n    ** \n   *** \n  **** \n ***** \n******\n").replace("*", caractere)
    if padrao == "d":
        padrao = ("   * \n  *** \n ***** \n******* \n ***** \n  *** \n   *\n").replace("*", caractere)
    if padrao == "e":
        padrao = ("****** \n***** \n**** \n*** \n** \n*\n").replace("*", caractere)
    if padrao == "f":
        padrao = ("****** \n ***** \n  **** \n   *** \n    ** \n     \n*").replace("*", caractere)
    return padrao

