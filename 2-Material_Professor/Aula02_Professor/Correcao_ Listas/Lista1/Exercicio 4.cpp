/*
 	Escreva um programa em linguagem C que solicita ao usuário a quantidade de elementos inteiros que deseja ordenar.  
	 Depois de ler os valores em uma função, ordene em ordem crescente(em outra função). 
	 Desenvolva um módulo para imprimir o vetor ordenado.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
 
int *Aloca_Vetor(int posicoes);
void Libera_Vetor(int *vetor);
void LeVetor (int *vetor, int posicoes);
void ImprimirVetor (int *vetor, int posicoes);
void OrdenarVetor (int *vetor, int posicoes);

main (void)
{
	int posicoes;
	int  *vetor;
	
	
	system("cls");
	printf("Digite a quantidade de elementos para ordenar: ");
	scanf("%d" ,&posicoes);
	
	vetor = Aloca_Vetor(posicoes);
	
	LeVetor(vetor,posicoes);
	
	OrdenarVetor(vetor,posicoes);
	
	ImprimirVetor(vetor,posicoes);

	Libera_Vetor(vetor);
	getch();
} 	// fim main

int *Aloca_Vetor(int posicoes)
{
	int *vet;
	int i, k;
	
	vet = (int *) calloc(posicoes, sizeof(int *)); 

	if (vet == NULL) {
		printf("Memoria insuficiente.\n");
		exit(1);
	}
	return vet;
}

void Libera_Vetor(int *vetor)
{
	free(vetor); 
}

void LeVetor (int *vetor, int posicoes)
{
	int i;

	for (i=0; i<posicoes; i++)
	{	
		printf("\n Digite o elemento da posicao %d \n", i);
		scanf("%d", &vetor[i]);
	}	
}

void ImprimirVetor (int *vetor, int posicoes)
{
	int i;
	printf("\n Os elementos ordenados do vetor sao: \n");
	for (i=0; i< posicoes; i++)
	{
		printf("%d \n", vetor[i]);
	}
}

void OrdenarVetor (int *vetor, int posicoes)
{
	int valorTroca, i,j;
	for(i=0; i < posicoes; i++)
	{
		for(j=0;j<posicoes;j++)
		{
			if (vetor[i] < vetor[j])
			{
				valorTroca = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = valorTroca;
			}
		}
	}
}




