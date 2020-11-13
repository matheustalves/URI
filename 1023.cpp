#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
    int n, numCidade = 1;

    while(scanf("%d\n", &n) && n)
    {
        int x[n], y[n];
        double medias[n], somaPessoas = 0.0, somaConsumo = 0.0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d\n", &x[i], &y[i]);
            somaPessoas += x[i];
            somaConsumo += y[i];
            medias[i] = floor(y[i] / x[i]);

            int j = i - 1;
            while (j >= 0)
            {
                if (medias[i] < medias[j])
                {
                    int swap = medias[i];
                    medias[i] = medias[j];
                    medias[j] = swap;
                    swap = x[i];
                    x[i] = x[j];
                    x[j] = swap;
                    swap = y[i];
                    y[i] = y[j];
                    y[j] = swap;
                }
                j--;
            }
        }

        double mediaTotal = (double)somaConsumo / (double)somaPessoas;
        
        printf("Cidade# %d:\n", numCidade);

        for (int i = 0; i < n; i++)
        {
            printf("%d-%.0f ", x[i], medias[i]);
        }

        std::cout << "\nConsumo medio: " << std::fixed << std::setprecision(2) << mediaTotal << " m3." << std::endl
                    << "\n";

        numCidade++;
    }

    return 0;
}