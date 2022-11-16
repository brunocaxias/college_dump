#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  20211BSI0119apnp12.py
#  
#  Copyright 2021 Bruno Carvalho Caxias
#  
# ----------------------------------------------------------------------

def main():
    #------------------------------
    temp1 = float(0.0)
    temp2 = float(0.0)
    temp3 = float(0.0)
    numequipe = str("")
    eqtp = float(0.0)
    vencequipe = int(0) 
    pontmax = float(0.0)
    pont1 = float(0.0)
    pont2 = float(0.0)
    pont3 = float(0.0)
    #------------------------------

    temp1 = float(input())
    temp2 = float(input())
    temp3 = float(input())

    numequipe = str(input())

    if numequipe != "9999":
        while numequipe != "9999":
            aux = 1
            pontotal = 0
            while aux < 4:
                eqtp = float(input())

                if aux == 1:
                    tempo = temp1
                elif aux == 2:
                    tempo = temp2
                else:
                    tempo = temp3
                eqtp = abs(tempo - eqtp)

                if eqtp < 3:
                    eqtp = 100
                elif eqtp >= 3 and eqtp <= 5:
                    eqtp = 80
                else:
                    eqtp = 80 - (eqtp - 5) / 5

                if aux == 1:
                    pont1 = eqtp
                elif aux == 2:
                    pont2 = eqtp
                else:
                    pont3 = eqtp
                aux += 1
            pontotal = pont1 + pont2 + pont3
            if pontotal > pontmax:
                pontmax = pontotal
                vencequipe = numequipe
            print ("EQUIPE=%s P1=%.2f P2=%.2f P3=%.2f PT=%.2f" % (numequipe, pont1, pont2, pont3, pontotal))
            numequipe = str(input())
        print("EQUIPE VENCEDORA=%s PONTUACAO TOTAL=%.2f" % (vencequipe, pontmax))
    else:
        print ("SEM EQUIPES CADASTRADAS")
if __name__ == "__main__":
    main()
