#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// https://thehuxley.com/problem/4200?quizId=8320

double calcForca(int amistoso, int eliminatorias, int torneios, int copas, int forcaDoTime, int forcaRegional)
{

    double total = ((amistoso * 1) + (eliminatorias * 2.5) + (torneios * 3.0) + (copas * 4.0)) + forcaDoTime;

    if (forcaRegional == 1) // UEFA
        total += 1;

    if (forcaRegional == 2) // CONMEBOL
        total += 1.3;

    if (forcaRegional == 3) // AFC
        total += 0.86;

    if (forcaRegional == 4) // CAF
        total += 0.86;

    if (forcaRegional == 5) // OFC
        total += 0.85;

    return total;
}

int main()
{
    // vitoria + 3 empate + 1
    int amistosoSelecao1, amistosoSelecao2, eliminatoriasSelecao1, eliminatoriasSelecao2;
    int torneioSelecao1, torneioSelecao2, copasSelecao1, copasSelecao2;
    int forcaSelecao1, forcaSelecao2, forcaRegional1, forcaRegional2;

    scanf("%d %d %d %d %d %d", &amistosoSelecao1, &eliminatoriasSelecao1, &torneioSelecao1, &copasSelecao1, &forcaSelecao1, &forcaRegional1);
    scanf("%d %d %d %d %d %d", &amistosoSelecao2, &eliminatoriasSelecao2, &torneioSelecao2, &copasSelecao2, &forcaSelecao2, &forcaRegional2);

    double time1 = calcForca(amistosoSelecao1, eliminatoriasSelecao1, torneioSelecao1, copasSelecao1, forcaSelecao1, forcaRegional1);
    double time2 = calcForca(amistosoSelecao2, eliminatoriasSelecao2, torneioSelecao2, copasSelecao2, forcaSelecao2, forcaRegional2);

    if (time1 > time2)
    {
        printf("Selecao 1\n");
    }
    else if (time2 > time1)
    {
        printf("Selecao 2\n");
    }
    else
    {
        printf("As duas selecoes estao no mesmo nivel");
    }

    return 0;
}