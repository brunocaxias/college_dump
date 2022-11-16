massainicial = 0.0
massafinal = 0.0
tempodeco = 0
horas = 0
minutos = 0
segundos = 0

massainicial = float(input())

while massainicial >= 0:
    massafinal = massainicial
    tempodeco = 0
    while massafinal >= 0.5:
        tempodeco += 50
        massafinal /= 2
    horas = tempodeco // 3600
    minutos = (tempodeco % 3600) // 60
    segundos = (tempodeco % 3600) % 60
    print("MASSA INICIAL=%.3f MASSA FINAL=%.3f TEMPO DECORRIDO=%d:%d:%d" % ( massainicial, massafinal, horas, minutos, segundos))

    massainicial = float(input())
print("FIM")