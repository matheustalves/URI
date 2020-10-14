#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        cout << "Case #" << (z + 1) << ":" << endl;

        int qntVertices, qntArestas;
        cin >> qntVertices >> qntArestas;

        char grafo[qntVertices][qntVertices];
        for (int i = 0; i < qntVertices; i++)
        {
            for (int y = 0; y < qntVertices; y++)
            {
                grafo[i][y] = '!';
            }
            grafo[i][i] = char(97 + i);
        }

        for (int i = 0; i < qntArestas; i++)
        {
            char v1, v2;
            cin >> v1 >> v2;

            int index1 = (v1 - 97), index2 = (v2 - 97);

            char copiaV1[qntVertices];
            for (int y = 0; y < qntVertices; y++) // Copia Linha do Vertice 1.
            {
                copiaV1[y] = grafo[index1][y];
            }

            for (int y = 0; y < qntVertices; y++) // Coloca conectados do v2 em v1
            {
                if (y != index1 && y != index2)
                {
                    if (grafo[index1][y] == '!' && grafo[index2][y] != '!')
                        grafo[index1][y] = grafo[index2][y];
                }
            }

            for (int y = 0; y < qntVertices; y++) // Coloca conectados do v1 em v2
            {
                if (y != index1 && y != index2)
                {
                    if (grafo[index2][y] == '!' && copiaV1[y] != '!')
                        grafo[index2][y] = copiaV1[y];
                }
            }

            grafo[index1][index2] = v2;
            grafo[index2][index1] = v1;

            for (int y = 0; y < qntVertices; y++)
            {
                if (y != index1 && y != index2)
                {
                    if (grafo[y][index1] == v1)
                    {
                        for (int q = 0; q < qntVertices; q++)
                        {
                            grafo[y][q] = grafo[index1][q];
                        }
                    }

                    if (grafo[y][index2] == v2)
                    {
                        for (int q = 0; q < qntVertices; q++)
                        {
                            grafo[y][q] = grafo[index2][q];
                        }
                    }
                }
            }
        }

        char jaConectou[qntVertices];
        for (int i = 0; i < qntVertices; i++)
        {
            jaConectou[i] = '!';
        }

        int qntComponentes = 0;

        for (int i = 0; i < qntVertices; i++)
        {
            bool jaMarcou = false;
            if (jaConectou[i] == grafo[i][i])
                jaMarcou = true;

            if (!jaMarcou)
            {
                qntComponentes++;
                cout << grafo[i][i] << ",";

                for (int y = 0; y < qntVertices; y++)
                {
                    if (y != (int(grafo[i][i]) - 97) && grafo[i][y] != '!' && jaConectou[y] == '!')
                    {
                        jaConectou[y] = grafo[i][y];
                        cout << grafo[i][y] << ",";
                    }
                }
                cout << endl;
            }
        }

        cout << qntComponentes << " connected components\n"
             << endl;
    }

    return 0;
}