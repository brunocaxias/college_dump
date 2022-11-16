#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  app20211BSI0119Q2.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import mod20211BSI0119Q2
from mod20211BSI0119Q2 import f_calcProduto

def main():
    a = int(0)
    b = int(0)
    prod = int(0)
    savmsg = str("")
    maiorprod = int(0)
    menorprod = int(9999999) 

    a = int(input("coloque a: "))
    b = int(input("coloque b: "))
    if a > 0 and b > 0:
        while a > 0 and b > 0:
            prod = f_calcProduto(a,b)
            savmsg += str("%ix%i=%i\n" % (a,b,prod))
            
            if prod > maiorprod:
                maiorprod = prod
            if prod < menorprod:
                menorprod = prod

            a = int(input())
            b = int(input())
        print ("%sMAIOR PRODUTO=%i\nMENOR PRODUTO=%i" % (savmsg,maiorprod,menorprod))


if __name__ == "__main__":
    main()
