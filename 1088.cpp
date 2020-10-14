#include <stdio.h>
#include <vector>

using namespace std;

vector<int> seq;
int contadorJogadas = 0;

vector<int> mergeSort(int, int);

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        int num;
        for (int i = 0; i < n; i++)
        {
            scanf(" %d", &num);
            seq.push_back(num);
        }

        mergeSort(0, n);

        if (contadorJogadas % 2 != 0)
            printf("Marcelo\n");
        else
            printf("Carlos\n");

        scanf("\n");

        seq.clear();
        contadorJogadas = 0;
    }

    return 0;
}

vector<int> mergeSort(int inicio, int fim)
{
    vector<int> arr;
    int meio = (inicio + fim) / 2;

    if (inicio + 1 >= fim)
    {
        arr.push_back(seq[inicio]);
        return arr;
    }

    vector<int> parte1 = mergeSort(inicio, meio);
    vector<int> parte2 = mergeSort(meio, fim);

    arr.clear();

    int tam1 = parte1.size(), tam2 = parte2.size(), i = 0, j = 0;

    while (i < tam1 && j < tam2)
    {
        if (parte1[i] < parte2[j])
        {
            arr.push_back(parte1[i]);
            i++;
        }
        else
        {
            arr.push_back(parte2[j]);
            contadorJogadas += (int)(parte1.size()) - i;
            j++;
        }
    }

    while (i < tam1)
    {
        arr.push_back(parte1[i]);
        i++;
    }

    while (j < tam2)
    {
        arr.push_back(parte2[j]);
        j++;
    }

    return arr;
}