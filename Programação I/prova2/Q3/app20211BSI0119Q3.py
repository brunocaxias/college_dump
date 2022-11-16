#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  app20211BSI0119Q3.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import mod20211BSI0119Q3
from mod20211BSI0119Q3 import f_piramide

def main():
    i = int(0)
    n = int(0)
    piram = str("")
    savmsg = str("")
    #-------------------
    i = int(input())
    n = int(input())
    if (i == 0 or i == 1) and n > 0:
        while (i == 0 or i == 1) and n > 0:
            piram = f_piramide(i,n)
            savmsg += ("%s\n" % piram) 
            i = int(input())
            n = int(input())
        print (savmsg)

if __name__ == "__main__":
    main()
