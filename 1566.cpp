#include <stdio.h>

void quickSort(int *vet, int inicio, int fim)
{
    int i = inicio, j = fim, pivo = vet[(inicio + fim) / 2], aux;

    while (i <= j)
    {
        while (vet[i] < pivo)
            i++;

        while (vet[j] > pivo)
            j--;

        if (i <= j)
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quickSort(vet, inicio, j);

    if (i < fim)
        quickSort(vet, i, fim);
}

int main()
{
    int numCidades;

    scanf("%d\n", &numCidades);

    for (int i = 0; i < numCidades; i++)
    {
        int numHabitantes;
        scanf("%d\n", &numHabitantes);

        int alturas[numHabitantes];
        int numAlturasValidas = 0, aux;

        for (int j = 0; j < numHabitantes; j++)
        {
            scanf("%d", &aux);
            if (aux >= 20 && aux <= 230)
            {
                alturas[numAlturasValidas] = aux;
                numAlturasValidas++;
            }
        }

        quickSort(alturas, 0, numAlturasValidas - 1);

        for (int x = 0; x < numAlturasValidas; x++)
        {
            printf("%d ", alturas[x]);
        }

        printf("\n");
    }

    return 0;
}