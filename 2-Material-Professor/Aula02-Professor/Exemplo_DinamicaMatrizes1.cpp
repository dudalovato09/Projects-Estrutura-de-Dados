// Objetivo: Mostrar a alocação de memória para uma matriz bidimensional
// Dados de entrada: Dimensões da matriz (número de linhas e colunas)
// Dados de saída: A matriz inicializada

#include <stdio.h>
#include <stdlib.h> // Para calloc(), free() e exit()

int **Aloca_Matriz(int lin, int col);
void Libera_Matriz(int **mat, int l);
void LeMatriz(int **mat, int lin, int col, const char *nome_mat);
void MostraMatriz(int **mat, int lin, int col, const char *nome_mat);

int main(void) {
    int **pmatriz;  // Ponteiro para a matriz de inteiros
    int linha, coluna;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linha);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &coluna);

    pmatriz = Aloca_Matriz(linha, coluna);

    LeMatriz(pmatriz, linha, coluna, "MatrizA");
    MostraMatriz(pmatriz, linha, coluna, "MatrizA");

    Libera_Matriz(pmatriz, linha);

    return 0;
}

int **Aloca_Matriz(int lin, int col) {
    int **mat;
    int i, k;

    mat = (int **) calloc(lin, sizeof(int *));
    if (mat == NULL) {
        printf("Memória insuficiente.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < lin; i++) {
        mat[i] = (int *) calloc(col, sizeof(int));
        if (mat[i] == NULL) {
            printf("Memória insuficiente.\n");
            for (k = i - 1; k >= 0; k--) // libera linhas já alocadas
                free(mat[k]);
            free(mat);
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

void Libera_Matriz(int **mat, int lin) {
    int i;
    for (i = 0; i < lin; i++)
        free(mat[i]); 
    free(mat); 
}

void LeMatriz(int **mat, int lin, int col, const char *nome_mat) {
    int i, j;
    printf("\nDigite os elementos da matriz %s:\n", nome_mat);
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%s[%d][%d]: ", nome_mat, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void MostraMatriz(int **mat, int lin, int col, const char *nome_mat) {
    int i, j;
    printf("\nOs elementos da matriz %s são:\n", nome_mat);
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
