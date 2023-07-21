#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// https://thehuxley.com/problem/4202?quizId=8320

void chanceTotal(int generoDoFilme, int diaDoFilme, int horarioDoFilme, int amigosConvidados)
{

    double chance = 0;
    if (generoDoFilme == 1)
        chance += 27.4;

    else if (generoDoFilme == 2)
        chance -= 10.5;

    else if (generoDoFilme == 3)
        chance += 19.7;

    // dia
    if (diaDoFilme == 1)
        chance -= 41.3;

    else if (diaDoFilme == 2)
        chance += 40.4;

    // horario

    if (horarioDoFilme == 1)
        chance -= 22.8;

    else if (horarioDoFilme == 2)
        chance += 11.4;

    else if (horarioDoFilme == 3)
        chance += 38.6;

    chance += (amigosConvidados * 2.3);

    if (chance <= 40)
    {
        printf("Melhor nao tentar.\n");
        return;
    }

    else if (chance > 40 && chance <= 80)
    {
        printf("Chances boas, pode convidar.\n");
        return;
    }

    else if (chance > 80)
    {
        printf("Provavelmente vao aceitar.\n");
        return;
    }
}

int main()
{

    int genero, dia, horario, amigos;
    double chance = 0;
    scanf("%d %d %d %d", &genero, &dia, &horario, &amigos);

    chanceTotal(genero, dia, horario, amigos);

    return 0;
}