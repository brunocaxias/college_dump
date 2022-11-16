def main():
    #Declaração de Variáveis
    tempoP1 = float(0.0)
    tempoP2 = float(0.0)
    tempoP3 = float(0.0)
    tempoAbsoluto = float(0.0)
    pontoPorEtapa = float(0.0)
    totalPontos = float(0.0)
    maiorPonto = float(0.0)
    numInsc = int(0)
    etapas = int(0)
    nomeEquipe = str("")
    textoDisplay = str("")
    textoGanhador = str("")

    #Pede tempo padrão para comparação
    tempoP1 = float(input("Digite o tempo padrão 1: "))
    tempoP2 = float(input("Digite o tempo padrão 2: "))
    tempoP3 = float(input("Digite o tempo padrão 3: "))
    numInsc = int(input("Digite o número de inscrição da equipe: "))

    #Condição de inicialização do algoritmo
    if numInsc == 9999:
        print("Ninguém foi na corrida!")

    while numInsc != 9999:
        nomeEquipe = str(input("Nome da equipe: "))
        etapas = 0
        totalPontos = 0
        textoDisplay = ""

        #Condição para cada etapa
        while etapas != 3:
            tempoE = 0
            #Zera o ponto por etapa a cada etapa
            pontoPorEtapa = 0
            tempoE = float(input(f"Digite o tempo da equipe {nomeEquipe} na etapa {etapas+1}: "))

            #Definição do tempo Absoluto
            if etapas + 1 == 1:
                tempoAbsoluto = abs(tempoP1 - tempoE)
            elif etapas + 1 == 2:
                tempoAbsoluto = abs(tempoP2 - tempoE)
            elif etapas + 1 == 3:
                tempoAbsoluto = abs(tempoP3 - tempoE)

            #Cálculo de pontos
            if tempoAbsoluto < 3:
                pontoPorEtapa = 100
                totalPontos += pontoPorEtapa
            elif tempoAbsoluto >= 3 and tempoAbsoluto <= 5:
                pontoPorEtapa = 80
                totalPontos += pontoPorEtapa
            elif tempoAbsoluto > 5:
                pontoPorEtapa = 80 - (tempoAbsoluto - 5)/5
                totalPontos += pontoPorEtapa
                
            #Atribuição de pontos à etapa
            textoDisplay += f"A equipe {nomeEquipe} obteve uma pontuação igual a {pontoPorEtapa} na etapa {etapas + 1}\n"
            etapas += 1

        #saída de dados sobre a equipe
        print(f"Número de inscrição {numInsc}")
        print("---//---//---//---//---//---//---//---")
        textoDisplay += f"\nO total de pontos da equipe {nomeEquipe} é igual a {totalPontos}\n"
        print(textoDisplay)

        #Atribuição de texto padrão ao ganhador
        if totalPontos > maiorPonto:
            textoGanhador = f"A equipe {nomeEquipe} é a vencedora com um total de {totalPontos}\n"

        #Input usuário
        #Flag
        numInsc = int(input("Digite o número de inscrição da equipe: "))
    #Texto do ganhador
    print(f"\n{textoGanhador}")

if __name__ == "__main__":
    main()