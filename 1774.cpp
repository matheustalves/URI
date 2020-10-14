#include <stdio.h>

int main()
{
    int numRoteadores, numCabos;
    scanf("%d %d\n", &numRoteadores, &numCabos);

    int grafo[numCabos][3];

    for (int i = 0; i < numCabos; i++)
    {
        scanf("%d %d %d\n", &grafo[i][0], &grafo[i][1], &grafo[i][2]);
    }

    // ===== Calcula Menor Preco usando Algoritmo de PRIM ======

    int verticesAtuais[numRoteadores]; // Roteador 1: Posicao 0, Roteador 2: Posicao 1... etc
    verticesAtuais[0] = 1;             // Inicia o algoritmo no Roteador 1 marcando a posicao 0 como 1.

    for (int i = 1; i < numRoteadores; i++) // Coloca valor 0 no restante dos Roteadores
    {
        verticesAtuais[i] = 0;
    }

    int menorPreco, menorVerticeAdjacente, precoTotal = 0, qntAtuais = 0;

    while (qntAtuais < numRoteadores - 1)
    {
        menorPreco = 10001;
        for (int i = 0; i < numRoteadores; i++)
        {
            if (verticesAtuais[i]) // Se o roteador esta marcado como 1 no array...
            {
                for (int j = 0; j < numCabos; j++)
                {
                    if (grafo[j][0] == (i + 1) && !verticesAtuais[grafo[j][1] - 1] && grafo[j][2] < menorPreco)
                    {
                        menorPreco = grafo[j][2];
                        menorVerticeAdjacente = grafo[j][1];
                    }
                    else if (grafo[j][1] == (i + 1) && !verticesAtuais[grafo[j][0] - 1] && grafo[j][2] < menorPreco)
                    {
                        menorPreco = grafo[j][2];
                        menorVerticeAdjacente = grafo[j][0];
                    }
                }
            }
        }
        verticesAtuais[menorVerticeAdjacente - 1] = 1;
        qntAtuais++;
        precoTotal += menorPreco;
    }

    printf("%d\n", precoTotal);

    return 0;
}