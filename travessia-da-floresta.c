#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// https://thehuxley.com/problem/4274?quizId=8322


void lerArray(int i, int array[], int cont)
{
    if (i == cont)
        return;

    scanf("%d", &array[i]);

    lerArray(i + 1, array, cont);
}

void imprimir(int i, int cont, int array[])
{
    if (i == cont)
        return;

    printf("%d\n", array[i]);

    imprimir(i + 1, cont, array);
}

void juntarArrays(int i, int cont, int jogadores[], int bonusJogadores[])
{
    if (i == cont)
        return;

    jogadores[i] += bonusJogadores[i];

    juntarArrays(i + 1, cont, jogadores, bonusJogadores);
}

void floresta(int i, int cont, int jogadores[], int dificuldade, int maiorValor, int menorValor, int passaram)
{
    if (i == cont)
    {
        printf("Jogadores que passaram: %d\nMaior valor: %d\nMenor valor: %d\n", passaram, maiorValor, menorValor);
        return;
    }
    if (jogadores[i] >= dificuldade)
    {
        passaram++;
    }
    if (jogadores[i] > maiorValor)
    {
        maiorValor = jogadores[i];
    }
    if (jogadores[i] < menorValor)
    {
        menorValor = jogadores[i];
    }

    floresta(i + 1, cont, jogadores, dificuldade, maiorValor, menorValor, passaram);
}

int main()
{

    int dificuldade, jogadores[5], bonusJogador[5];
    scanf("%d", &dificuldade);
    lerArray(0, jogadores, 5);
    lerArray(0, bonusJogador, 5);
    juntarArrays(0, 5, jogadores, bonusJogador);
    int menorValor = jogadores[0], maiorValor = jogadores[0];

    floresta(0, 5, jogadores, dificuldade, maiorValor, menorValor, 0);

    return 0;
}