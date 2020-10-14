#include <stdio.h>

bool ehMultiplo(char *ano, int divisor)
{
    int resto = 0;

    for (int i = 0; ano[i]; ++i)
    {
        int num = ano[i] - '0';
        resto = (num + resto * 10) % divisor;
    }

    bool verifica = !resto;

    return verifica;
}

bool ehBissexto(char *ano)
{
    bool verifica = false;

    if (ehMultiplo(ano, 400) || (ehMultiplo(ano, 4) && !ehMultiplo(ano, 100)))
        verifica = true;

    return verifica;
}

bool ehBulukulu(char *ano)
{
    bool verifica = false;

    if (ehMultiplo(ano, 55))
        verifica = true;

    return verifica;
}

bool ehHuluculu(char *ano)
{
    bool verifica = false;

    if (ehMultiplo(ano, 15))
        verifica = true;

    return verifica;
}

int main()
{
    char ano[2000];

    scanf("%s", ano);
    while (1)
    {
        if (ehBissexto(ano))
        {
            printf("This is leap year.\n");
            if (ehHuluculu(ano))
                printf("This is huluculu festival year.\n");
            if (ehBulukulu(ano))
                printf("This is bulukulu festival year.\n");
        }
        else if (ehHuluculu(ano))
        {
            printf("This is huluculu festival year.\n");
        }
        else
        {
            printf("This is an ordinary year.\n");
        }

        if (scanf("%s", ano) != EOF)
            printf("\n");
        else
            break;
    }

    return 0;
}