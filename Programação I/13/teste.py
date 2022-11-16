#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp8.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import math

def main():
    rep = int(0)
    aux  = int(0)
    num = float(0.0)
    numlist = [0]
    aux2 = int(1)
    func = float(0.0)
    # Listagem
    while rep >= 0:
        num = float(input(""))
        numlist.append(num)
    # Loop
    while rep >= aux:
        x = numlist[aux2]
        aux += 1
        while numlist[aux2] != numlist[0]:
            func = math.exp(numlist[aux2])
            print (x, func)



if __name__ == "__main__":
    main()
