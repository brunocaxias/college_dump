#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119APNP19.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def main():
    n = int(input())
    b = int(input())
    number = str(n)
    j = int(0)
    baserange = str("")
    translate = str("")
    genbaserange = str("012345678")
    for j in range(b):
        baserange += str(" %i" % j)
        translate += str("  ")

    mute = genbaserange.maketrans(baserange,translate)
    genbaserange = genbaserange.translate(mute)

    chars = set(genbaserange)
    if any((c in chars) for c in number):
        print('Errado')
    else:
        print('Certo')

if __name__ == "__main__":
    main()
