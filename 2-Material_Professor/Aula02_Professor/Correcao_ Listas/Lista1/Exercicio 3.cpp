/*
	Desenvolva um programa que calcule a soma  de duas matrizes MxN de números reais (double). 
	A implementação deste programa  deve considerar as dimensões fornecida pelo  usuário 
	(Dica: represente a matriz através de  variáveis do tipo double , usando alocação dinâmica de memória). 
	Apos desaloque a memória utilizada.
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
 
float **Aloca_Matriz(int linha, int coluna);
void Libera_Matriz(float **mat, int lin);
void LeMatriz (float **mat, int lin, int col, char *nome_mat);
void MostraMatriz (float **mat, int lin, int col, char *nome_mat);
void Soma_Matriz(float **matrizResultado, float **mat1, float **mat2,  int lin, int col);



main (void)
{
	int linha,coluna;
	float  **matriz1, **matriz2, **matrizSoma;
	
	
	system("cls");
	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%d" ,&linha);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d" ,&coluna);
	
	matriz1 = Aloca_Matriz(linha, coluna);
	matriz2 = Aloca_Matriz(linha, coluna);
	matrizSoma = Aloca_Matriz(linha, coluna);
	
	LeMatriz (matriz1, linha, coluna, "matriz 1");
	LeMatriz (matriz2, linha, coluna, "matriz 2");
	
	Soma_Matriz(matrizSoma, matriz1, matriz2, linha, coluna);
	
	MostraMatriz (matrizSoma, linha, coluna, "matriz resultante");
	
	Libera_Matriz(matriz1, linha);
	Libera_Matriz(matriz2, linha);
	Libera_Matriz(matrizSoma, linha);
	getch();
} 	// fim main

float ** Aloca_Matriz (int lin, int col)
{
	float ** mat;
	int i, k;
	
	mat = (float **) calloc(lin, sizeof(float *)); //aloca um vetor com linha
			// posições para armazenar
			// ponteiros inteiros
	if (mat == NULL) {
		printf("Memoria insuficiente.\n");
		exit(1);
	}
	for (i=0; i<lin; i++)
	{
		mat[i]= (float *)calloc(col, sizeof (float)); //aloca um vetor com //coluna
			// posições para inteiros, em que o endereço é atribuído a
			//cada linha da matriz
		if (mat[i] == NULL) {
			printf("Memoria insuficiente.\n");
			
			for (k = i-1; k >= 0; k--) // devolve os blocos alocados
				free(mat[k]);
			free(mat);
			exit (1); //abandona a tarefa
		}//fim if
	}// fim for
	return mat;
}

void Libera_Matriz(float **mat, int lin)
{
	int i;
	for (i=0; i<lin; i++)
		free(mat[i]); // libera o vetor de inteiros com coluna posições para
		// cada linha
	free(mat); // libera o vetor de ponteiros com linha posições
}

void LeMatriz (float **mat, int lin, int col, char *nome_mat)
{
	int i, j;
	printf("\n Digite os elementos da matriz %s \n", nome_mat);
	for (i=0; i<lin; i++)
		for (j=0; j<col; j++)
		{
			printf("%s[%d][%d]:" , nome_mat, i, j );
			scanf("%f", &mat[i][j]);
		}	
}

void MostraMatriz (float **mat, int lin, int col, char *nome_mat)
{
	int i, j;
	printf("\n Os elementos da matriz %s sao: \n", nome_mat);
	for (i=0; i<lin; i++)
	{
		for (j=0; j<col; j++)
			printf("%.2f ", mat[i][j]); //printf("%d ", *(*(mat+i)+j) );
		printf("\n");
	}
}

void Soma_Matriz(float **matrizResultado, float **mat1, float **mat2,  int lin, int col)
{
	int i, j;
	for (i=0; i<lin; i++)
	{
		for (j=0; j<col; j++)
		{
			matrizResultado[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}


