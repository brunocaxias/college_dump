#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  app20211BSI0119Q1.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import mod20211BSI0119Q1
from mod20211BSI0119Q1 import f_validaNumBase
from mod20211BSI0119Q1 import f_converteBaseNBase10
from mod20211BSI0119Q1 import f_converteBaseNBase16

def main():
    b = int(0)
    n = int(0)
    n10 = int(0)
    n16 = str("")
    savmsg = str("")
    n = int(input())
    b = int(input())
    while b >=2 and b >= 9:
        if f_validaNumBase(n,b):
            n10 = f_converteBaseNBase10(n,b)
            n16 = f_converteBaseNBase16(n,b)
            savmsg += str("n=%i b=%i n10=%s n16=%s\n" % (n,b,n10,n16))
        else:
            savmsg += str("%i INVALIDO NA BASE %i\n" % (n,b))
        n = int(input())
        b = int(input())
    print (savmsg)

if __name__ == "__main__":
    main()
