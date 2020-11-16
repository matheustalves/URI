#include <stdio.h>

int main()
{
    double valor, resultado;
    scanf("%lf", &valor);

    double notas[6] = {100, 50, 20, 10, 5, 2},
           moedas[6] = {100, 50, 25, 10, 5, 1};

    printf("NOTAS:\n");

    for (int i = 0; i < 6; i++)
    {
        resultado = int(valor / notas[i]);
        printf("%d nota(s) de R$ %.2f\n", int(resultado), notas[i]);
        valor -= resultado * notas[i];
    }

    printf("MOEDAS:\n");
    valor *= 100;

    for (int i = 0; i < 6; i++)
    {
        resultado = int(valor / moedas[i]);
        printf("%d moeda(s) de R$ %.2f\n", int(resultado), moedas[i] / 100);
        valor -= resultado * moedas[i];
    }

    return 0;
}