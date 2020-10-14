#include <stdio.h>

int n;

bool tudoDesligado(int *vet)
{
    bool desligados = true;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] == 0)
        {
            desligados = false;
            break;
        }
    }

    return desligados;
}

int main()
{
    while (scanf("%d\n", &n) && n)
    {
        int m = 0, ultimo = 1;
        int desligados[n];

        while (ultimo != 13)
        {
            m++;

            for (int i = 0; i < n; i++)
            {
                desligados[i] = 0;
            }

            desligados[0] = 1;
            ultimo = 1;

            int aux = 0;
            while (!tudoDesligado(desligados))
            {
                int i;
                for (i = 1; i < n; i++)
                {
                    if (!desligados[i])
                    {
                        aux++;
                        if (aux == m)
                        {
                            desligados[i] = 1;
                            ultimo = i + 1;
                            aux = 0;
                        }
                    }
                }
            }
        }

        printf("%d\n", m);
    }
    return 0;
}