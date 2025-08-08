/*3.  Desenvolva um programa que calcule a soma  de duas matrizes MxN de números reais (double).
A implementação deste programa  deve considerar as dimensões fornecida pelo  usuário (Dica: represente a matriz através de  variáveis do tipo double ,
usando alocação dinâmica de memória). Apos desaloque a memória utilizada.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Alocar memória da matriz
double **alocarMatriz(int linhas, int colunas)
{
    double **matriz = (double **)malloc(linhas * sizeof(double *));
    if (matriz == NULL)
        return NULL;

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (double *)malloc(colunas * sizeof(double));
        if (matriz[i] == NULL)
            return NULL;
    }
    return matriz;
}

// Leitura da matriz 
//ATENÇÃO QUANDO FOR SOMA DE MATRIZES E ESTIVER USANDO O TIPO DOUBLE SE ATENTAR NO SCANF
void lerMatriz(double **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o valor [%d] [%d]: ", i, j);
            scanf("%lf", &matriz[i][j]); // %lf para double
        }
    }
}

// Impressão da matriz
//ATENÇÃO QUANDO FOR SOMA DE MATRIZES E ESTIVER USANDO O TIPO DOUBLE SE ATENTAR NO PRINTF
void imprimirMatriz(double **matriz, int linhas, int colunas)
{
    printf("\nMatriz:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.2lf ", matriz[i][j]); // %.2lf para double com 2 casas decimais
        }
        printf("\n");
    }
}

// Função que soma duas matrizes e retorna a matriz resultado
double **somarMatrizes(double **matrizA, double **matrizB, int linhas, int colunas)
{

    double **resultado = alocarMatriz(linhas, colunas);
    int i, j;

    if (resultado == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

// Desalocar memória da matriz
void desalocarMatriz(double **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    int linhas, colunas;
    double **matrizA, **matrizB, **matrizSoma;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Alocar as matrizes
    matrizA = alocarMatriz(linhas, colunas);
    matrizB = alocarMatriz(linhas, colunas);

    if (matrizA == NULL || matrizB == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Ler matrizes A e B
    printf("\n--- Leitura da matriz A ---\n");
    lerMatriz(matrizA, linhas, colunas);

    printf("\n--- Leitura da matriz B ---\n");
    lerMatriz(matrizB, linhas, colunas);

    matrizSoma = somarMatrizes(matrizA, matrizB, linhas, colunas);

    if (matrizSoma == NULL)
    {
        printf("Erro ao alocar memória para a matriz soma!\n");
        // Liberar matrizes A e B antes de sair
        desalocarMatriz(matrizA, linhas);
        desalocarMatriz(matrizB, linhas);
        return 1;
    }

    // Imprimir matriz soma
    printf("\n--- Resultado da soma ---\n");
    imprimirMatriz(matrizSoma, linhas, colunas);

    // Desalocar todas as matrizes
    desalocarMatriz(matrizA, linhas);
    desalocarMatriz(matrizB, linhas);
    desalocarMatriz(matrizSoma, linhas);

    return 0;
}