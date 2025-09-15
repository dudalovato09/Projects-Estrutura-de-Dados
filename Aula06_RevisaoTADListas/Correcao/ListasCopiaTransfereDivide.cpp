#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 50

typedef char TEXTO[max];

typedef struct DADO{
 int codigo;
 TEXTO nome; 
 int dia;
 int mes;
}DADO;

typedef struct nodo {
   int codigo;
   TEXTO nome; 
   int dia;
   int mes;
   nodo* proximo;
   nodo* anterior;
}nodo;

typedef struct lista{
 int tamanho;
 nodo* inicio;
 nodo* fim;
}lista;

typedef struct lista LISTA;

LISTA* cria ();
int vazia (LISTA* l);
int tamanho(LISTA* l);
void libera(LISTA* l);
void mostra(LISTA* l);
void insere(LISTA* l, DADO v);
int remove(LISTA* l, DADO* v);
void copia(LISTA* b1, LISTA* b2);
void transfere(LISTA* b1, LISTA* b2);
void divide(LISTA* b1, LISTA* b2);
void inverte(LISTA* b1, LISTA* b2);

int main(){
	LISTA *base1, *base2;
  	DADO info;
  	int op;
  	int achou;
  	base1=cria();
  	
	do{
  		system("cls");
  		printf("GESTAO DE LISTA\n\n");
  		printf("1 - Incluir Elemento - BASE 1\n");
  		printf("2 - Mostrar Lista - BASE 1\n");  
  		printf("3 - Remover Elemento - BASE 1\n");	 
  		printf("4 - Tamanho da Lista - BASE 1 \n");
  		printf("5 - Copiar Lista - BASE 1 para BASE 2\n");  
  		printf("6 - Transferir Lista - BASE 1 para BASE 2\n");
  		printf("7 - Dividir Lista - BASE 1 \n");
  		printf("8 - Inverte Lista - BASE 1 para BASE 2 \n");	  			
  		printf("0 - Finalizar\n");
  		printf("Digite sua escolha: ");	 
		scanf("%d",&op);
		switch (op)	{ 
	 		case 1:    	
			  	printf("Digite um codigo:");
			    scanf("%d",&info.codigo);
			  	printf("Digite o dia do nascimento:");    
			    scanf("%d",&info.dia);
			  	printf("Digite o mes do nascimento:");    
			    scanf("%d",&info.mes);    
			  	printf("Digite um nome:"); 
				fflush(stdin);
			    gets(info.nome);  	
			  	insere(base1,info);
			  	break;
	 		case 2:  printf("ELEMENTOS DA LISTA:\n");  
	        	mostra(base1);
	          	break;
     		case 3: 
			  	printf("Digite um codigo:");
			    scanf("%d",&info.codigo);
				achou = remove(base1,&info);
				if (achou == 0)
					printf("ELEMENTO NAO EXISTE\n\n");
				else {
	  	            printf("Dados: %d\n",info.codigo);
	  	            printf("Nome: %s\n",info.nome);
	  	            printf("Nascimento: %d/%d\n",info.dia,info.mes);					
				}
              	break;
     		case 4:
     	      	printf("TAMANHO DA LISTA: %d ELEMENTOS\n",tamanho(base1));
     	      	break;
     		case 5:
     	      	printf("COPIAR LISTA\n");
     	      	base2=cria();
     	      	copia(base1,base2);
     	      	printf("\nLISTA ORIGINAL\n");
			  	mostra(base1);      	      
     	      	printf("\nNOVA LISTA\n");
			  	mostra(base2);   	      
     	      	break;    
     		case 6:
     	      	printf("TRANSFERIR LISTA\n");
     	      	base2=cria();   
     	      	transfere(base1,base2);
     	      	printf("\nLISTA ORIGINAL\n");
			  	mostra(base1);      	      
     	      	printf("\nNOVA LISTA\n");
			  	mostra(base2); 			     	      
     	      	break; 
     		case 7:
     	      	printf("DIVIDIR LISTA\n");
     	      	base2=cria();
     	      	divide(base1,base2);
     	      	printf("\nLISTA ORIGINAL\n");
			  	mostra(base1);      	      
     	      	printf("\nNOVA LISTA\n");
			  	mostra(base2); 			        	      
     	      	break;  			    			    	      
     		case 8:
     	      	printf("INVERTE LISTA\n");
     	      	base2=cria();
     	      	inverte(base1,base2);
     	      	printf("\nLISTA ORIGINAL\n");
			  	mostra(base1);      	      
     	      	printf("\nNOVA LISTA\n");
			  	mostra(base2); 			        	      
     	      	break; 
     		case 0:
     	      	break;
     		default:
     	      	printf("ESCOLHA INCORRETA\n\n");
  		}
  		system("pause");
	}
	while(op!=0);
}

LISTA* cria (){
	LISTA* N = (LISTA*) malloc(sizeof(LISTA)); 
 	N->tamanho = 0;
 	N->inicio=NULL;
 	N->fim=NULL;
 	return(N);
}

int vazia (LISTA* l){
    if (l->inicio == NULL)
      	return(1);
    else
      	return(0);
}

int tamanho (LISTA* l){ 
    if (l != NULL)
      	return(l->tamanho);
    else
      	return(0);
}

void libera (LISTA* l){ 
    if (l != NULL)
      	free(l);
}

void mostra (LISTA* l){ 
	nodo* p;
    if (l != NULL){
      	p=l->inicio;
	  	while(p!=NULL){
	  		printf("Dados: %d\n",p->codigo);
	  		printf("Nome: %s\n",p->nome);
	  		printf("Nascimento: %d/%d\n",p->dia,p->mes);		  	  	
	  		p=p->proximo;//navegar nos ponteiros
	  	}	
	}
}
//insere em ordem crescente de código
void insere (LISTA * l, DADO v){
 	nodo* novo;
 	nodo* anterior;
 	nodo* corrente;
 
 	novo=(nodo*)malloc(sizeof(nodo)); 
 	novo->codigo = v.codigo;
 	strcpy(novo->nome,v.nome);
 	novo->dia = v.dia;
 	novo->mes = v.mes; 
 	novo->proximo=NULL;
	
	printf("Dados: %d\n",novo->codigo);
	printf("Nome: %s\n",novo->nome);
	printf("Nascimento: %d/%d\n",novo->dia,novo->mes);
 
 	if (vazia(l)){
   		l->inicio = novo;
   		l->fim = novo;  
	}
 	else { 
	 	corrente = l->inicio;
   		if (novo->codigo < corrente->codigo){
    		novo->proximo = l->inicio;
     		l->inicio = novo;    
		}
   		else {
			while((corrente !=NULL)&&(novo->codigo>=corrente->codigo)){
     			anterior = corrente; 
     			corrente = anterior->proximo;    
			}
			anterior->proximo = novo;
			novo->proximo = corrente;
			if (corrente == NULL)
         		l->fim = novo;    
		}   
	}
  	l->tamanho = l->tamanho + 1; 
}

void insereDec (LISTA * l, DADO v){
 	nodo* novo;
 	nodo* anterior;
 	nodo* corrente;
 
 	novo=(nodo*)malloc(sizeof(nodo)); 
 	novo->codigo = v.codigo;
 	strcpy(novo->nome,v.nome);
 	novo->dia = v.dia;
 	novo->mes = v.mes; 
 	novo->proximo=NULL;
 	
	if (vazia(l)){
   		l->inicio = novo;
   		l->fim = novo;  
	}
 	else { 
	 	corrente = l->inicio;
   		if (novo->codigo > corrente->codigo){
     		novo->proximo = l->inicio;
     		l->inicio = novo;    
		}
   		else {
			while((corrente !=NULL)&&(novo->codigo<corrente->codigo)){
     			anterior = corrente; 
     			corrente = anterior->proximo;    
			}
			anterior->proximo = novo;
			novo->proximo = corrente;
			if (corrente == NULL)
         		l->fim = novo;    
		}   
	}
  	l->tamanho = l->tamanho + 1; 
}

int remove (LISTA * l, DADO* v){
 	int codigo = v->codigo;
 	nodo* anterior;
 	nodo* corrente;
 
 	if (vazia(l))  { 
     	return(0);
  	}
 	else 
  	{
   		corrente = l->inicio;
		if (codigo == corrente->codigo){
    		strcpy(v->nome,corrente->nome);
     		v->dia=corrente->dia;
     		v->mes=corrente->mes;
     		l->inicio = corrente->proximo;
     		free(corrente);
     		l->tamanho = l->tamanho -1;
     		return(1);
   		}
   		else
		{
     		while((corrente != NULL) && 
           			(codigo != corrente->codigo)&&
           			(codigo > corrente->codigo)) 
			{
       			anterior = corrente;
       			corrente = anterior->proximo;
     		}
     		if (corrente == NULL){
        		return(0);
      		}
     		else {
       			strcpy(v->nome,corrente->nome);
       			v->mes=corrente->mes;
       			v->dia=corrente->dia;       
       			anterior->proximo = corrente->proximo;
       			if (l->fim == corrente) 
				{
          			l->fim = anterior;   
				}
       			l->tamanho = l->tamanho - 1;
       			free(corrente);
       			return(1);
      		}   
		}   
	}  
}

void inverte(LISTA* b1, LISTA* b2){
	nodo *p;
  	DADO info;
    
	if (b1 != NULL){
      	p=b1->inicio;
	  	while(p!=NULL){
	  		info.codigo= p->codigo;
	  		strcpy(info.nome,p->nome);
	  		info.dia= p->dia;
	  		info.mes= p->mes;
			insereDec(b2,info);  		  	  	
	  		p=p->proximo;
	  	}	
	}	
}

//essa função deve receber um ponteiro para lista b1 e
//copiar todos os elementos de b1 para a lista b2
//ao final da função as duas listas terão os mesmos elementos (na mesma ordem)	
void copia(LISTA* b1, LISTA* b2){
	nodo *p;
  	DADO info;
    if (b1 != NULL){
      	p=b1->inicio;
	  	while(p!=NULL){
	  		info.codigo= p->codigo;
	  		strcpy(info.nome,p->nome);
	  		info.dia= p->dia;
	  		info.mes= p->mes;
			insere(b2,info);  		  	  	
	  		p=p->proximo;
	  	}	
	}	
}

void transfere(LISTA* b1, LISTA* b2){
//essa função deve receber um ponteiro para lista b1 e
//transferir todos os elementos de b1 para a lista b2
//ao final da função a lista b1 estará vazia
//e a lista b2 terá os elementos que estavam em b1	
	if (b1 != NULL){
   		b2->inicio=b1->inicio;
   		b2->fim=b1->fim;
   		b2->tamanho=b1->tamanho;
   		b1->tamanho=0;
   		b1->inicio=NULL;
   		b1->fim=NULL;	
  	}	
}

void divide(LISTA* b1, LISTA* b2){
//essa função deve receber um ponteiro para lista b1 e
//determinar o "meio" da lista
//os elementos do início até o meio ficarão em b1
//já os elementos depois do meio, serão transferidos para b2
nodo *p;
int metade, conta;
 if (b1 != NULL){
    p = b1->inicio;
    metade = b1->tamanho / 2;
    for(conta=1;conta < metade;conta++){
  	  p=p->proximo;	
    }
    b2->inicio=p->proximo;
    b2->fim=b1->fim;
    b2->tamanho= b1->tamanho - metade;
    p->proximo = NULL;
    b1->fim=p;
    b1->tamanho=metade;
  }
}
