#include <stdio.h>
#include <vector>

using namespace std;

struct Maca
{
    int linha, coluna, instante;
};

vector<Maca> macas;
int linhas, colunas, qntMacas, instanteFinal, canvas[20][20][2000];
int calcularMax(int, int, int);

int main()
{
    while (scanf("%d %d %d\n", &linhas, &colunas, &qntMacas) && linhas)
    {
        Maca leitura;
        instanteFinal = 0;
        macas.clear();
        for (int z = 0; z < qntMacas; z++)
        {
            scanf("%d %d %d\n", &leitura.linha, &leitura.coluna, &leitura.instante);
            leitura.linha--;
            leitura.coluna--;
            instanteFinal = max(leitura.instante + 1, instanteFinal);
            macas.push_back(leitura);
        }

        int linhaAtual, colunaAtual;
        scanf("%d %d\n", &linhaAtual, &colunaAtual);
        linhaAtual--;
        colunaAtual--;

        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                for (int k = 0; k < 2000; k++)
                {
                    canvas[i][j][k] = -1;
                }
            }
        }

        printf("%d\n", calcularMax(linhaAtual, colunaAtual, 0));
    }

    return 0;
}

int calcularMax(int linhaAtual, int colunaAtual, int instanteAtual)
{
    if (instanteAtual == instanteFinal)
        return 0;
    if (canvas[linhaAtual][colunaAtual][instanteAtual] != -1)
        return canvas[linhaAtual][colunaAtual][instanteAtual];

    int contador = 0;
    for (int i = 0; i < qntMacas; i++)
    {
        if (macas[i].linha == linhaAtual && macas[i].coluna == colunaAtual && macas[i].instante == instanteAtual)
            contador++;
    }

    int maximo = calcularMax(linhaAtual, colunaAtual, instanteAtual + 1);

    int proximaLinha, proximaColuna;
    int andarLinha[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int andarColuna[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < 8; i++)
    {
        proximaLinha = linhaAtual + andarLinha[i];
        proximaColuna = colunaAtual + andarColuna[i];

        if (proximaLinha >= 0 && proximaLinha < linhas && proximaColuna >= 0 && proximaColuna < colunas)
            maximo = max(maximo, calcularMax(proximaLinha, proximaColuna, instanteAtual + 1));
    }

    return canvas[linhaAtual][colunaAtual][instanteAtual] = contador + maximo;
}