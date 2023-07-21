#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// https://thehuxley.com/problem/4275?quizId=8322

void lerArray(int i, int cont, int array[], int p)
{

    if (i == cont)

        return;

    scanf("%d", &array[i]);

    if (p == 1)

        array[i] += i;

    lerArray(i + 1, cont, array, p);
}

void comparar(int i, int cont, int canais[], int pontos[], int maiorValor, int tempo, int melhorCanal, int Semtempo)
{

    if (i == cont)

    {

        if (Semtempo == cont)

        {

            printf("%d\n", -1);

            return;
        }

        printf("%d\n", melhorCanal + 1);

        return;
    }

    if (canais[i] > tempo)

    {

        Semtempo++;

        pontos[i] = 0;

        canais[i] = 0;
    }

    else if (canais[i] <= tempo && pontos[i] > maiorValor)

    {

        melhorCanal = i;

        maiorValor = pontos[i];
    }

    comparar(i + 1, cont, canais, pontos, maiorValor, tempo, melhorCanal, Semtempo);
}

int main()
{

    int tam, tempo, semTempo = 0;

    scanf("%d%d", &tam, &tempo);

    int canais[tam], pontuacaoCanais[tam];

    lerArray(0, tam, canais, 1);

    lerArray(0, tam, pontuacaoCanais, 0);

    comparar(0, tam, canais, pontuacaoCanais, 0, tempo, 0, semTempo);

    return 0;
}