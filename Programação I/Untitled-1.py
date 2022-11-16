#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119Q1.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def main():
    # Declaração de Variaveis
    l1 = float(0.0)
    l2 = float(0.0)
    l3 = float(0.0)
    sp  = float(0.0)
    maiorarea = float(0.0)
    medequi = float(0.0)
    mediso = float(0.0)
    medesca = float(0.0)
    perctriang = float(0.0)
    tdstriang = float(0.0)
    area = float(0.0)
    peri = float(0.0)
    tipo = str("")
    falsetriang = float(0.0)
    savlados = str("")
    auxeq = int(0)
    auxiso = int (0)
    auxesc = int(0)
    # Entrada de dados
    l1 = float(input())
    l2 = float(input())
    l3 = float(input())
    #Processos
    if (l1 != 0) and (l2 != 0) and (l3 != 0):
        while (l1 != 0) and (l2 != 0) and (l3 != 0):
            if l1+l2>l3 and l2+l3>l1 and l3+l1>l2:
                peri = l1 + l2 + l3
                sp = peri/2
                area = (sp*(sp-l1)*(sp-l2)*(sp-l3))**0.5
                if l1 == l2 and l2 == l3:
                    tipo = ("EQUILATERO")
                    medequi += peri
                    auxeq += 1
                elif l1 == l2 or l2 == l3 or l3 == l1:
                    tipo = ("ISOSCELES")
                    mediso += peri
                    auxiso += 1
                else:
                    tipo = ("ESCALENO")
                    medesca += peri
                    auxesc += 1
                
                print ("AREA=%.2f PERIMETRO=%.2f TIPO=%s" % (area, peri, tipo))

                if maiorarea < area:
                    maiorarea = area
                    savlados = str("lado1 = %.2f, lado2 = %.2f e lado3 = %.2f" %(l1, l2, l3))

                perctriang += 1

            else:
                print("NAO TRIANGULO")
                falsetriang += 1
            
            tdstriang += 1

            l1 = float(input())
            l2 = float(input())
            l3 = float(input())  
        
        if medequi != 0:
            medequi = (medequi / auxeq)
        if mediso != 0:
            mediso = (mediso / auxiso)
        if medesca != 0:
            medesca = (medesca / auxesc)

        perctriang = (perctriang*100)/tdstriang
        # Saida de dados
        if falsetriang != tdstriang:
            print ("A maior area = %.2f eh do triangulo: %s" % (maiorarea, savlados))
            print ("%.2f eh o perimetro medio dos triangulos equilateros" % (medequi))
            print ("%.2f eh o perimetro medio dos triangulos isoceles" % (mediso))
            print ("%.2f eh o perimetro medio dos triangulos escalenos" % (medesca))

        print("Percentual de triangulos = %.2f" % (perctriang))
        print("Percentual de não triangulos = %.2f" % abs(perctriang - 100))

    else:
        print("NAO HA DADOS PARA PROCESSAR")

if __name__ == "__main__":
    main()




















if __name__ == "__main__":
    main()
