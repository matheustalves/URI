#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int pesoMochila = 15, numItens = 4;
    int valor[numItens] = {1, 5, 6, 8};
    int peso[numItens] = {1, 4, 5, 6};
    int melhorValor[numItens][pesoMochila + 1];

    for (int i = 0; i < numItens; i++)
    {
        for (int j = 0; j <= pesoMochila; j++)
        {
            melhorValor[i][j] = 0;
        }
    }

    for (int i = 1; i <= pesoMochila; i++)
    {
        if (i >= peso[0])
            melhorValor[0][i] = valor[0];
    }

    for (int i = 1; i < numItens; i++) // itens
    {
        for (int j = 1; j <= pesoMochila; j++) // tamanhos
        {
            if (peso[i] > j)
            {
                melhorValor[i][j] = melhorValor[i - 1][j];
            }
            else
            {
                melhorValor[i][j] = max(valor[i] + melhorValor[i - 1][j - peso[i]], melhorValor[i - 1][j]);
            }
        }
    }

    cout << "Conteudo Mochila Otima: " << endl;
    cout << "Custo: " << melhorValor[numItens - 1][pesoMochila] << endl;

    return 0;
}