/* Crie uma estrutura utilizando um vetor inteiro onde será realizada as 
   operações de leitura, escrita, encontrar o maior valor, encontrar o menor valor, 
   a média. 
   Imprimir os resultados encontrados.(utilizar módulos e alocação dinâmica). 
   Utilizar os seguinte módulos: alocar memória, 
   leitura do vetor, escrita do vetor, encontrar elementos maior e menor, 
   desalocar memória.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
 
int *Aloca_Vetor(int tam);
void Libera_Vetor (int *vet);
void Ler_Vetor(int *vet, int tamanho);
int Maior_Valor(int *vet, int tamanho);
int Menor_Valor(int *vet, int tamanho);
float Media_Valor(int *vet, int tamanho);

main (void)
{
	int tamanho, *vetor, maiorValor, menorValor;
	float media;
	
	
	system("cls");
	printf("Digite o tamanho do vetor: ");
	scanf("%d" ,&tamanho);
	
	vetor = Aloca_Vetor(tamanho);
	
	Ler_Vetor(vetor, tamanho);
	
	maiorValor = Maior_Valor(vetor, tamanho);
	menorValor = Menor_Valor(vetor, tamanho);
	media = Media_Valor(vetor, tamanho);
	
	printf("O maior valor do vetor eh %d: \n", maiorValor);
	printf("O menor valor do vetor eh %d: \n", menorValor);
	printf("A media do vetor eh %.2f: \n", media);
	
	Libera_Vetor(vetor);
	getch();
} 	// fim main

int *Aloca_Vetor(int tam)
{
	int * v; 	// ponteiro para o vetor
	v = (int *) calloc(tam, sizeof(int) );   //Aloca tam números inteiros; v pode agora ser tratado como um vetor com tam posições.
	if (!v) 		//(v == NULL)
	{
		printf ("** Erro: Memória Insuficiente **");
		exit(1);
	}
	return v; 	// retorna o ponteiro para o vetor
}

void Libera_Vetor (int *vet)
{
	free(vet); 
}

void Ler_Vetor(int *vet, int tamanho)
{
	int i;
	for(i = 0; i < tamanho; i++)
	{
		system("cls");
		printf("Digite o valor da posicao %d: ", (i+1));
		scanf("%d" ,&*(vet + i));
	}
}

int Maior_Valor(int *vet, int tamanho)
{
	int i, maiorValor;
	
	maiorValor = *(vet);
	
	for(i = 0; i < tamanho; i++)
	{
		if (maiorValor < *(vet + i) )
		{
			maiorValor = *(vet + i);
		}
	}
	
	return maiorValor;
}

int Menor_Valor(int *vet, int tamanho)
{
	int i, menorValor;
	
	menorValor = *(vet);
	
	for(i = 0; i < tamanho; i++)
	{
		if (menorValor > *(vet + i) )
		{
			menorValor = *(vet + i);
		}
	}
	
	return menorValor;
}

float Media_Valor(int *vet, int tamanho)
{
	int i;
	float media = 0.0;
	

	for(i = 0; i < tamanho; i++)
	{
		media = media + *(vet + i);
	}
	
	return (media / tamanho);
}


