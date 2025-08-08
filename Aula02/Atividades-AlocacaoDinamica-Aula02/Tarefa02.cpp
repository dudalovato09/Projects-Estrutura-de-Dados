/*2.Aloque uma matriz dinamicamente e encontre o elemento minimax. Imprima no main o elemento encontrado. Utilizar os seguinte módulos: alocar memória,
leitura da matriz, escrita da matriz, encontrar minimax e desalocar memória. Minimax de uma matriz é o menor elemento da linha onde se encontra o maior elemento da matriz.*/

/*ANOTAÇÕES

> A matriz tem 2 * antes dela pois é um ponteeiro para ponteiro, ou seja uma matriz dinâmica*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Alocar memória da matriz
int **alocarMatriz(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
        return NULL;

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL)
            return NULL;
    }
    return matriz;
}

// Leitura da matriz
void lerMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o valor [%d] [%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Impressão da matriz
void imprimirMatriz(int **matriz, int linhas, int colunas)
{
    printf("\nMatriz:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); // quebra a linha
    }
}

// Encontrar o Minimax
int encontraMinimax(int **matriz, int linhas, int colunas)
{
    int maior = matriz[0][0];
    int linhaMaior = 0;

    // Encontrar o maior elemento e sua linha
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                linhaMaior = i;
            }
        }
    }

    // Encontrar o menor elemento da linha onde está o maior
    int menorDaLinha = matriz[linhaMaior][0];
    for (int j = 1; j < colunas; j++)
    {
        if (matriz[linhaMaior][j] < menorDaLinha)
        {
            menorDaLinha = matriz[linhaMaior][j];
        }
    }

    return menorDaLinha;
}

// Desalocar memória da matriz
void desalocarMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros
}

// Função principal
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int linhas, colunas;
    int **matriz, minimax;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    matriz = alocarMatriz(linhas, colunas);
    if (matriz == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    lerMatriz(matriz, linhas, colunas);
    imprimirMatriz(matriz, linhas, colunas);

    minimax = encontraMinimax(matriz, linhas, colunas);
    printf("\nO elemento minimax é: %d\n", minimax);

    desalocarMatriz(matriz, linhas);

    return 0;
}
