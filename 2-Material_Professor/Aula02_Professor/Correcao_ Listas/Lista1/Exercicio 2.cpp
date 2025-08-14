/*
   Aloque uma matriz dinamicamente e encontre o elemento minimax. 
   Imprima no main o elemento encontrado. 
   Utilizar os seguinte módulos: 
   alocar memória, - ok
   leitura da matriz, - ok
   escrita da matriz, - ok
   encontrar minimax e 
   desalocar memória. - ok
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
 
int **Aloca_Matriz(int linha, int coluna);
void Libera_Matriz(int **mat, int lin);
void LeMatriz (int **mat, int lin, int col, char *nome_mat);
void MostraMatriz (int **mat, int lin, int col, char *nome_mat);
int CalcularMiniMax (int **mat, int lin, int col);


main (void)
{
	int linha,coluna, **matriz, miniMax;
	
	system("cls");
	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%d" ,&linha);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d" ,&coluna);
	
	matriz = Aloca_Matriz(linha, coluna);
	
	LeMatriz (matriz, linha, coluna, "matriz");
	
	miniMax = CalcularMiniMax(matriz, linha, coluna);
	
	MostraMatriz (matriz, linha, coluna, "matriz");
	
	printf("O elemento minimax da matriz acima eh %d", miniMax);
	
	Libera_Matriz(matriz, linha);
	getch();
} 	// fim main

int ** Aloca_Matriz (int lin, int col)
{
	int ** mat;
	int i, k;
	
	mat = (int **) calloc(lin, sizeof(int *)); //aloca um vetor com linha
			// posições para armazenar
			// ponteiros inteiros
	if (mat == NULL) {
		printf("Memoria insuficiente.\n");
		exit(-1);
	}
	for (i=0; i<lin; i++)
	{
		mat[i]= (int *)calloc(col, sizeof (int)); //aloca um vetor com //coluna
			// posições para inteiros, em que o endereço é atribuído a
			//cada linha da matriz
		if (mat[i] == NULL) {
			printf("Memoria insuficiente.\n");
			
			for (k = i-1; k >= 0; k--) // devolve os blocos alocados
				free(mat[k]);
			free(mat);
			exit (-1); //abandona a tarefa
		}//fim if
	}// fim for
	return mat;
}

void Libera_Matriz(int **mat, int lin)
{
	int i;
	for (i=0; i<lin; i++)
		free(mat[i]); // libera o vetor de inteiros com coluna posições para
		// cada linha
	free(mat); // libera o vetor de ponteiros com linha posições
}

void LeMatriz (int **mat, int lin, int col, char *nome_mat)
{
	int i, j;
	printf("\n Digite os elementos da matriz %s \n", nome_mat);
	for (i=0; i<lin; i++)
		for (j=0; j<col; j++)
		{
			printf("%s[%d][%d]:" , nome_mat, i, j );
			scanf("%d", &mat[i][j]);
		}	
}

void MostraMatriz (int **mat, int lin, int col, char *nome_mat)
{
	int i, j;
	printf("\n Os elementos da matriz %s sao: \n", nome_mat);
	for (i=0; i<lin; i++)
	{
		for (j=0; j<col; j++)
			printf("%d ", mat[i][j]); //printf("%d ", *(*(mat+i)+j) );
		printf("\n");
	}
}

int CalcularMiniMax (int **mat, int lin, int col)
{
	int linhaMaiorElemento, maiorElementoTemp, menorElemento;	
	int i, j;
	
	linhaMaiorElemento = 0;
	maiorElementoTemp = -2147483648; // menor valor possivel
	for (i=0; i<lin; i++)
	{
		for (j=0; j<col; j++)
		{
			if (mat[i][j] > maiorElementoTemp)
			{
				maiorElementoTemp = mat[i][j];
				linhaMaiorElemento = i;
			}
		}
	}
	
	menorElemento = mat[linhaMaiorElemento][0];
	for (j=0; j<col; j++)
	{
		if (mat[linhaMaiorElemento][j] < menorElemento)
		{
			menorElemento = mat[linhaMaiorElemento][j];
		}
	}
	
	return menorElemento;
}





