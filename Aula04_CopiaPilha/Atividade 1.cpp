#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int dado;
	struct No* prox;
} No;

typedef struct{
	No* topo;
} Pilha;

Pilha* criar(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo=NULL;
	return p;
}

int vazia(Pilha* p){
	return(p->topo==NULL);
}

void push(Pilha* p, int valor){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = valor;
	novo->prox = p->topo;
	p->topo = novo;
}

int pop (Pilha* p){
	if(vazia(p)){
		printf("ERRO!! Pilha está vazia.");
		exit(1);
	}
	
	No* temp = p->topo;
	int valor = temp->dado;
	p->topo = temp->prox;
	free(temp);
	return valor;
}

Pilha* copia_pilha(Pilha* Original){
	Pilha* aux = criar();
	Pilha* destino = criar();
	
	No* atual = Original->topo;
	while(atual != NULL){
		push(aux, atual->dado);
		atual = atual->prox;
	}
	
	while(!vazia(aux)){
		push(destino, pop(aux));
	}
	free (aux);
	return destino;
}

int compara (Pilha* p1, Pilha* p2){
	No* n1 = p1->topo;
	No* n2 = p2->topo;
	
	while(n1 != NULL && n2 != NULL){
		if(n1->dado != n2->dado)
			return 0;
		n1 = n1->prox;
		n2 = n2->prox;
		
	}
		if (n1 != NULL || n2 != NULL){
			return 0;
		}
		
		return 1;
}

void imprime(Pilha* p){
	No* atual = p->topo;
	while(atual!= NULL){
		printf("%d ", atual->dado);
		atual = atual->prox;
	}
	printf("\n");
}



int main(){
	Pilha* p1 = criar();
	push(p1,10);
	push(p1,15);
	push(p1,20);
	
	printf("Pilha original: ");
	imprime(p1);
	Pilha* p2 = copia_pilha(p1);
	printf("Pilha copiada: ");
	imprime(p2);
	
	if(compara(p1, p2)){
		printf("As pilhas sao iguais \n");
	}else{
		printf("As pilhas sao diferentes \n");
	}
	
	push(p2, 40);
		
	printf("Depois da altercao: \n");
	if(compara(p1, p2)){
		printf("As pilhas sao iguais \n");
	}else{
		printf("As pilhas sao diferentes \n");
	}
	printf("Pilha original: ");
	imprime(p1);
	printf("Pilha copiada: ");
	imprime(p2);
	
	return 0;
}

