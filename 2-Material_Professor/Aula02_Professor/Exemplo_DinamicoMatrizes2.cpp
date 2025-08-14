// Objetivo: Mostra a alocação de memória para uma matriz bidimensional
// Dados de entrada: Dimensões da matriz: número de linhas e de colunas
// Dados de saída: A matriz inicializada

#include <stdio.h>
#include <stdlib.h> // calloc, free, exit

int **Aloca_Matriz(int lin, int col);
void Libera_Matriz(int **mat);
void LeMatriz(int **mat, int lin, int col, const char *nome_mat);
void MostraMatriz(int **mat, int lin, int col, const char *nome_mat);

int main(void)
{
    int **pmatriz, linha, coluna;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linha);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &coluna);

    pmatriz = Aloca_Matriz(linha, coluna);
    LeMatriz(pmatriz, linha, coluna, "PMATRIZ");
    MostraMatriz(pmatriz, linha, coluna, "PMATRIZ");
    Libera_Matriz(pmatriz);

    return 0;
}

int **Aloca_Matriz(int lin, int col)
{
    int **mat;
    int *posicao;
    int i;

    // Aloca vetor de ponteiros (linhas)
    mat = (int **)calloc(lin, sizeof(int *));
    if (mat == NULL)
    {
        printf("Memória insuficiente para linhas.\n");
        exit(EXIT_FAILURE);
    }

    // Aloca espaço contínuo para todos os elementos
    posicao = (int *)calloc(lin * col, sizeof(int));
    if (posicao == NULL)
    {
        free(mat);
        printf("Memória insuficiente para elementos.\n");
        exit(EXIT_FAILURE);
    }

    // Faz cada ponteiro de linha apontar para o local certo
    for (i = 0; i < lin; i++)
    {
        mat[i] = &posicao[i * col];
    }

    return mat;
}

void LeMatriz(int **mat, int lin, int col, const char *nome_mat)
{
    int i, j;
    printf("\nDigite os elementos da matriz %s:\n", nome_mat);
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%s[%d][%d]: ", nome_mat, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void MostraMatriz(int **mat, int lin, int col, const char *nome_mat)
{
    int i, j;
    printf("\nOs elementos da matriz %s são:\n", nome_mat);
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void Libera_Matriz(int **mat)
{
    free(mat[0]); // libera bloco de elementos
    free(mat);    // libera vetor de ponteiros
}