#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  app20211BSI0119Q4.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

import mod20211BSI0119Q4 
from mod20211BSI0119Q4 import f_serie_fibonacci

def main():
    n = int(0)
    savmsg = str("")
    out = str("")
    #--------------------------
    n = int(input())
    while n >= 2:
        out = f_serie_fibonacci(n)
        savmsg += str("\n%s" % out)
        n = int(input())
    print (savmsg)
if __name__ == "__main__":
    main()
