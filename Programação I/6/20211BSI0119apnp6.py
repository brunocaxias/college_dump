#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp6.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# Esse programa checa se a pessoa está apta ou não ao recebimento de sua aposentadoria 
#
# ----------------------------------------------------------------------

def main():
    #----------------------------
    # Criação de Variaveis & Inserção de valores nas variaveis
    #----------------------------
    sexo = input ('Digite "m" caso seja mulher e "h" caso seja homem: ')
    idade = int(input('Escreve a sua idade: '))
    tpo_contr = int(input('Coloque quantos anos de contribuição: ')) 
    soma = idade + tpo_contr
    #---------------------------
    # Processo
    #---------------------------
    if (sexo == 'h'):
        if (idade >= 65):
            if (tpo_contr >= 15):
                if (soma >= 95):
                    print('Pode aposentar')
                    return
    elif (sexo == 'm'):
        if (idade >= 62):
            if (tpo_contr >= 15):
                if (soma >= 92):
                    print('Pode aposentar')
                    return
    else:
        print('Ocorreu um erro, revise suas respostas e reinicie o programa')
        return
    
    print('Não pode aposentar')
    return
    #--------------------------
    #fim do processo
    #--------------------------
if __name__ == "__main__":
    main()


    
