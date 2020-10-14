#include <stdio.h>

int main()
{
    int p, m, f, q, b, k;

    scanf("%d", &p);
    int portugues[p];

    for (int i = 0; i < p; i++)
    {
        scanf(" %d", &portugues[i]);
    }

    scanf("\n%d", &m);
    int matematica[m];

    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &matematica[i]);
    }

    scanf("\n%d", &f);
    int fisica[f];

    for (int i = 0; i < f; i++)
    {
        scanf(" %d", &fisica[i]);
    }

    scanf("\n%d", &q);
    int quimica[q];

    for (int i = 0; i < q; i++)
    {
        scanf(" %d", &quimica[i]);
    }

    scanf("\n%d", &b);
    int biologia[b];

    for (int i = 0; i < b; i++)
    {
        scanf(" %d", &biologia[i]);
    }

    scanf("\n%d", &k);
    int maiores[k];

    for (int i = 0; i < k; i++)
    {
        maiores[i] = -1;
    }

    for (int i = 0; i < p; i++)
    {
        for (int y = 0; y < m; y++)
        {
            for (int w = 0; w < f; w++)
            {
                for (int x = 0; x < q; x++)
                {
                    for (int z = 0; z < b; z++)
                    {
                        int valor = portugues[i] + matematica[y] + fisica[w] + quimica[x] + biologia[z];

                        for (int t = 0; t < k; t++)
                        {
                            if (valor > maiores[t])
                            {
                                int temp1 = maiores[t];
                                maiores[t] = valor;
                                for (int u = t + 1; u < k; u++)
                                {
                                    int temp2 = maiores[u];
                                    maiores[u] = temp1;
                                    temp1 = temp2;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < k; i++)
    {
        total += maiores[i];
    }

    printf("%d", total);

    return 0;
}