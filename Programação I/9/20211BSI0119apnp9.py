#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp9.py
#
#  Copyright 2021 Bruno Carvalho Caxias
#
# ----------------------------------------------------------------------

def main():
    n1 = int(input(""))
    n2 = int(input(""))
    quoc = int (0)
    div = n1 + n2   
    if n2 < n1:
        if n1 > 0 and n2 > 0:
            while div > n2:
                div = div - n2
                quoc += 1
            if (quoc * n2) > n1:
                quoc -= 1
            print("QUOCIENTE=%i" % (quoc))
        else:
            print("ENTRADA INVALIDA")
    else:
        if n1 > 0 and n2 > 0:
            print("QUOCIENTE=0")
        else:
            print("ENTRADA INVALIDA")
if __name__ == "__main__":
    main()
