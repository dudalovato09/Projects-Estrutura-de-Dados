#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no* ant;
	struct no* prox;
};

typedef struct no No;

typedef struct {
	No* cabeca;
} DEQUE;

DEQUE* cria(void)
{
      DEQUE* d = (DEQUE*) malloc(sizeof(DEQUE));
      d->cabeca = (No*) malloc(sizeof(No));
      d->cabeca->prox = d->cabeca;
	  d->cabeca->ant = d->cabeca;
      return d;
}


No* exibirDequeInicio(DEQUE* d, int posicoes) {
	int contador = 0;
	
	No* end = d->cabeca->prox;
	printf("Deque partindo do fim: \" ");
	while (contador < posicoes) {
		end = end->prox;
		contador++;
	}
	return end;
}

No* exibirDequeApartirPosicao(No* d, int posicoes) {
	int contador = 0;
	No* end = d;
	printf("Deque partindo do fim: \" ");
	while (contador < posicoes) {
		end = end->prox;
		contador++;
	}
	return end;
}

bool inserirDequeFim(DEQUE* d, int valor) {
	No* novo = (No*) malloc(sizeof(No));
	novo->valor = valor;
	novo->prox = d->cabeca;
	novo->ant = d->cabeca->ant;
	d->cabeca->ant = novo;
	novo->ant->prox = novo;
	return true;
}


void reinicializarDeque(DEQUE* d) {
	No* end = d->cabeca->prox;
	while (end != d->cabeca) {
		No* apagar = end;
		end = end->prox;
		free(apagar);
	}
	d->cabeca->prox = d->cabeca;
	d->cabeca->ant = d->cabeca;
}

int main (void)
{
	int valorRemovido;
	int i, op, movimentoRoda;
	No* end = NULL;
	DEQUE* roda_fortuna;
	
	roda_fortuna = cria();
	
	//Inicializa a Roda
	for (i = 0; i < 15; i++)
	{
	    inserirDequeFim(roda_fortuna, rand() % 1000);
	}
	
	do{
  		system("cls");
  		printf("Escolha uma Opcao\n\n");
  		printf("1 - Girar a Roda\n");
  		printf("2 - Sair\n");  
	  	printf("Digite sua escolha: ");	 
		scanf("%d",&op);
		switch (op)	{ 
		 	case 1:    	
				  //Gira a roda
				  movimentoRoda = rand() % 15;
				  
				  //Movimenta a roda
				  //Armazena a referencia do movimento
				  if (end == NULL){
				  	end = exibirDequeInicio(roda_fortuna, movimentoRoda);
				  }
				  else{
				  	end = exibirDequeApartirPosicao(end, movimentoRoda);
				  }
				  
				  //Escreve o resultado 
				  printf("O resultado da Roda eh %d\n", end->valor);

				  break;
	 	    default:
	     	      printf("ESCOLHA INCORRETA\n\n");
  		}
  		system("pause");
 	}
	while(op!=2);
	reinicializarDeque(roda_fortuna);
}
