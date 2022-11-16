massaIn = float(0)
segundos = int(0)
minutos = int(0)
horas = int(0)
init = float(0)
massas = [0]
aux = int(0)

while massaIn >= 0:
    massaIn = float(input(""))
    massas.append(massaIn)
aux += 1
while massas[aux] >= 0:
    segundos = int(0)
    init = massas[aux]

    while massas[aux] >= 0.5:
         massas[aux]/=2
         segundos += 50
    final = massas[aux]
    minutos = int(segundos / 60)
    segundos -= (minutos * 60)
    horas = int(minutos / 60)
    minutos -= (horas * 60)
    print ("MASSA INICIAL=%.3f MASSA FINAL=%.3f TEMPO DECORRIDO= %i:%i:%i" % (init, final, horas, minutos, segundos))
    aux += 1
print ("FIM")