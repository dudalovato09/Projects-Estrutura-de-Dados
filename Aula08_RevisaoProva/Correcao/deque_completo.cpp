#include <stdio.h>
#include <malloc.h>

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

int tamanho(DEQUE* d) {
	//Avançando pelo primeiro nodo
	No* end = d->cabeca->prox;
	int tam = 0;
	while (end != d->cabeca) {
		tam++;
		end = end->prox;
	}
	return tam;
}

int tamanho2(DEQUE* d) {
	//Avançando pelo último nodo
	No* end = d->cabeca->ant;
	int tam = 0;
	while (end != d->cabeca) {
		tam++;
		end = end->ant;
	}
	return tam;
}

void exibirDequeFim(DEQUE* d) {
	No* end = d->cabeca->ant;
	printf("Deque partindo do fim: \" ");
	while (end != d->cabeca) {
		printf("%i ", end->valor);
		end = end->ant;
	}
	printf("\"\n");
}

void exibirDequeInicio(DEQUE* d) {
	No* end = d->cabeca->prox;
	printf("Deque partindo do fim: \" ");
	while (end != d->cabeca) {
		printf("%i ", end->valor);
		end = end->prox;
	}
	printf("\"\n");
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

bool inserirDequeInicio(DEQUE* d, int valor) {
	No* novo = (No*) malloc(sizeof(No));
	novo->valor = valor;
	
	novo->prox = d->cabeca->prox;
	novo->ant = d->cabeca;
	
	d->cabeca->prox = novo;
	return true;
}

int excluirElemDequeFim(DEQUE* d) {
	int valorRetorno;
	
	if (d->cabeca->ant == d->cabeca) return false;
	No* apagar = d->cabeca->ant;
	valorRetorno = apagar->valor;
	d->cabeca->ant = apagar->ant;
	apagar->ant->prox = d->cabeca;
	free(apagar);
	return valorRetorno;
}

int excluirElemDequeInicio(DEQUE* d) {
	int valorRetorno;
	
	if (d->cabeca->prox == d->cabeca) return false;
	No* apagar = d->cabeca->prox;
	valorRetorno = apagar->valor;
	d->cabeca->prox = apagar->prox;
	apagar->prox->ant = d->cabeca;
	free(apagar);
	return valorRetorno;
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
	
	DEQUE* deq1;
	
	deq1 = cria();
	
	//inserirDequeFim(deq1, 23);
	//inserirDequeFim(deq1, 15);
	
	inserirDequeInicio(deq1, 23);
	inserirDequeInicio(deq1, 15);
	
	printf("Tamanho do deque: %d\n",tamanho(deq1));
	
	//exibirDequeFim(deq1);
	exibirDequeInicio(deq1);
	
	//valorRemovido = excluirElemDequeInicio(deq1);
	valorRemovido = excluirElemDequeFim(deq1);
	printf("Valor removido: %d\n", valorRemovido);
	
	printf("Tamanho do deque depois da remocao: %d\n",tamanho(deq1));
	
	exibirDequeFim(deq1);
	
	reinicializarDeque(deq1);
}
