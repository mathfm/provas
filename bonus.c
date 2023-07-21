#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// https://thehuxley.com/problem/4283?quizId=8323

void buscar_tesouro(int i, int j, int n, int m, int matrix[][m], int visitado[][m], int *pontuacao, int soma, int pontos)
{
    // verifica se a posicao atual e valida
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    // verifica se a posicao atual ja foi visitada
    if (visitado[i][j])
        return;

    // carca a posicao atual como visitada
    visitado[i][j] = 1;

    int result = matrix[i][j];
    soma += result;

    // maior pontuacao achada
    if (soma > *pontuacao)
    {
        *pontuacao = soma;
    }

    soma += pontos;

    // cima, baixo eesquerda, e direita
    buscar_tesouro(i + 1, j, n, m, matrix, visitado, pontuacao, soma, pontos);
    buscar_tesouro(i, j + 1, n, m, matrix, visitado, pontuacao, soma, pontos);

    // desmarca a posi??o atual como visitada antes de voltar
    visitado[i][j] = 0;
}

int main()
{
    int linhas, colunas, pontuacao = 0;
    scanf("%d%d", &linhas, &colunas);
    int matriz[linhas][colunas];
    int pontos = 0;
    int visitado[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            visitado[i][j] = 0;
        }
    }

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            scanf("%d", &matriz[i][j]);

    buscar_tesouro(0, 0, linhas, colunas, matriz, visitado, &pontuacao, 0, pontos);

    printf("%d\n", pontuacao);

    return 0;
}