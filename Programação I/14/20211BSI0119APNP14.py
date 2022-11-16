#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119aquecimento.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------
'''Esta função recebe como parâmetro um valor inteiro na base 10 maior ou igual a zero 
representado pelo parâmetro num10 e retorna um valor string que representa o valor 
em hexadecimal obtido pela conversão de num10 para a base 16'''

def f_base10tobase16(num):
    # Variaveis Locaisa
    ultbase = str("")
    quoc = int(0)
    letters = str("")
    #-------------------------
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
    return ultbase 
#fim da função f_base10tobase16



'''Programa ou função principal'''       
def main():
    # Declaração de Variaveis
    num = int(0)
    ultbase = str("")
    quoc = int(0)
    savbase = int(0)
    letters = str("")
    # Entrada de dados
    num = int(input())
    savbase = num
    # Processamento
    while num >= 0:

        f_base10tobase16(num)  

        ultbase = f_base10tobase16(num)
    
        print ("BASE10=%s BASE16=%s" % (savbase, ultbase))
        num = int(input())
        savbase = num
#fim da função main

#invocação/chamada do programa principal  
if __name__ == "__main__":
    main()
#fim