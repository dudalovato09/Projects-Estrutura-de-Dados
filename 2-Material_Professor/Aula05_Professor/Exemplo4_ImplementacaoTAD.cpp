//programa que gerencia uma FILA em memoria 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define max 50
typedef char TEXTO[max];

typedef struct DADOS{
 int codigo;
 TEXTO nome; 
}DADOS;

typedef struct NODO{
 int codigo;
 TEXTO nome;
 NODO *proximo; 
}NODO;

typedef struct FILA{
 int tamanho;
 NODO *primeiro,*ultimo; 
}FILA;

FILA *cria();
void aloca(FILA *elemento, DADOS info);
void usa(FILA *elemento, DADOS *info);
void mostraFILA(FILA *elemento);
int quantidade(FILA *elemento);
DADOS lerElemento();
char menu();

main(){
   FILA *recurso;
   DADOS informa;
   char conf;
   char op='Z';
   recurso=NULL;
   while(op!='F'){
     op=menu();
     switch (op){
     case 'I': printf("\nI - inicializa FILA\n");
               recurso = cria();//aloca o início da FILA                        
               break;
     case 'N': printf("\nN - novo elemento\n");
               if(recurso==NULL){
                 printf("\nFILA nao inicializada\n");
                 }
               else{
                   informa=lerElemento(); 
                   aloca(recurso,informa);
               } 
               break;
     case 'M':      
               printf("\nM - mostra FILA\n");
               if (recurso == NULL)
                  printf("\n FILA Vazia \n ");
               else
                  mostraFILA(recurso); 
               break;
     case 'U': 
               printf("\nUsar Elemento da FILA\n");
               usa(recurso,&informa);
               printf("PRIMEIRO\n");
               printf("Codigo: %d \n",informa.codigo);
               printf("Nome: %s \n",informa.nome);               
               break;
     case 'T': 
               printf("\nTamanho da FILA\n");
               printf("A fila tem %d elementos \n",quantidade(recurso));
               break;			                   
     case 'F': free(recurso);
               printf("\nfinalizando sistema\n");
               break;            
                         
     default: printf("\n opcao invalida \n");            
     }  
	printf("\n");
    system("pause");          
   }

}

char menu(){
 system("cls");
 printf("\nI - inicializa FILA");
 printf("\nN - novo elemento");
 printf("\nM - mostra FILA"); 
 printf("\nU - usar FILA");
 printf("\nT - tamanho da FILA");  
 printf("\nF - fim");
 printf("\nDigite opcao: "); 
 fflush(stdin);
 return(toupper(getche()));    
}


//função que cria a FILA
FILA *cria(){
    FILA *p;
    p=(FILA *)malloc(sizeof(FILA)); 
    p->tamanho=0;
    p->primeiro=NULL;
    p->ultimo=NULL;    
    return(p);
}

//aloca novo elemento na FILA
void aloca(FILA *elemento, DADOS info){
    NODO *p,*n;//n é o ponteiro para alocar o novo elemento
    p=elemento->ultimo;//p é o ponteiro para navegação na FILA
    n=(NODO *)malloc(sizeof(NODO));
    n->codigo=info.codigo;
    strcpy(n->nome,info.nome);
    n->proximo=NULL;//o novo elemento não aponta para ninguem, por isso atribui-se NULL     
    elemento->ultimo=n;//o novo elemento é o último da FILA 
	if (p==NULL){//para guardar o primeiro elemento da FILA 
      elemento->primeiro=n;
      elemento->tamanho=1;
    }
    else{//para alocar os outros nodos da FILA
      p->proximo=n;
      elemento->tamanho = elemento->tamanho + 1;
    }     
}

//usa e retorna o elemento do recurso da FILA
void usa(FILA *elemento, DADOS *info){
    NODO *p;
    p=elemento->primeiro;
    if (p==NULL){//não há elementos na FILA 
      info->codigo=0;
      strcpy(info->nome,"FILA VAZIA");
    }
    else{//obtem primeiro da FILA
      info->codigo=p->codigo;
      strcpy(info->nome,p->nome);
      //remover o primeiro elemento da FILA
      elemento->primeiro=p->proximo;
      free(p);
      elemento->tamanho = elemento->tamanho - 1;
      if (elemento->primeiro == NULL){//foi removido o ultimo elemento
      	  elemento->ultimo=NULL;
      	  elemento->tamanho=0;
	  }
    }     
}

//aloca novo elemento na FILA
void mostraFILA(FILA *elemento){
    NODO *p;
    int conta=0;
    p=elemento->primeiro;//p é o ponteiro para navegação na FILA
    while(p!=NULL){
       conta++;
       printf("DADOS[%d]\n",conta);
       printf("Codigo: %d \n",p->codigo);
       printf("Nome: %s \n",p->nome);
       p=p->proximo;//navegação na FILA, p recebe o ponteiro do próximo
    }     
}

DADOS lerElemento(){
   DADOS info;
   printf("\nDigite o codigo: ");
   scanf("%d",&info.codigo);
   printf("\nDigite o nome: ");
   fflush(stdin);
   gets(info.nome);
   return(info);    
}

int quantidade(FILA *elemento){
	return(elemento->tamanho);
}

