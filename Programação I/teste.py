#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119aquecimento.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def main():
    # Declaração de Variaveis
    num = int(0)
    ultbase = str("")
    quoc = int(0)
    savbase = int(0)
    letters = str("")
    # Entrada de Dados
    num = int(input())
    savbase = num
    # Processos
    while num >= 0:
        ultbase = str("")
        if num < 10:
            ultbase = str(num)
        else:
            while num > 0:
                quoc = num % 16
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
                ultbase = letters + ultbase
                num = num // 16
                

            
    # Saida de Dados
        print ("BASE10=%s BASE16=%s" % (savbase, ultbase))
        num = int(input())
        savbase = num
        
            
    
    
    
if __name__ == "__main__":
    main()