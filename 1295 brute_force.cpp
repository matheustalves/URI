#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

struct Ponto
{
    double x, y;
};

vector<Ponto> pontos;

int main()
{
    int n;
    while (scanf("%d\n", &n) && n)
    {
        Ponto leitura;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf\n", &leitura.x, &leitura.y);
            pontos.push_back(leitura);
        }

        double menorDistancia = 10000;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    double distancia = sqrt(pow((pontos[i].x - pontos[j].x), 2) + pow((pontos[i].y - pontos[j].y), 2));

                    if (distancia < menorDistancia)
                        menorDistancia = distancia;
                }
            }
        }

        if (menorDistancia < 10000)
            printf("%0.4lf\n", menorDistancia);
        else
            printf("INFINITY\n");

        pontos.clear();
    }
    return 0;
}
