#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  programaFluxograma.py
#
#  Copyright 2020 Alessandra Aguiar Vilarinho
#
#  Este programa não executa uma tarefa útil, foi feito para ser
#  exemplo de como fazer um fluxograma de um programa

#Declaração de variáveis
a = 0.0   # tipo real
b = ""    # tipo cadeia de caracter
c = 0     # tipo inteiro
d = 0     # tipo inteiro
e = False # tipo lógico

#inicialização de algumas variáveis
b = "oi tudo bem"
c = 10

#entrada de dados
a = int(input("Digite um número inteiro:"))

#saída de dados
print("vamos estudar")

# comando condicional composto ou
# desvio de fluxo composto
if a > 10:
	print("primeiro if")
	print("O valor de a eh:", a)
	print(e)
	b = "esta entendendo?"
	if c < 5:
		print("segundo if")
		print("O valor de c é menor que 5")
	else:
		print("segundo else")
		print("O valor de c é maior ou igual a 5")
	d = a + c
else:
	print("primeiro else")
	print("Os valores de a, b, c, d, e são:", a,b,c,d,e)
print("terminando o estudo")
