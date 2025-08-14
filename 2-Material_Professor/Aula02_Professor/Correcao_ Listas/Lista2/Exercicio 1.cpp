#include<stdio.h>
#include<conio.h>

void le(int a, int b, int c, int *maior, int *menor);

main(void)
{
          int a, b, c, maior, menor;
           printf("\nInforme um valor para A:");
           scanf("%d",&a);
           printf("\nInforme um valor para B:");
           scanf("%d",&b);
           printf("\nInforme um valor para C:");
           scanf("%d",&c);
          le(a, b, c, &maior, &menor);
          printf("\nAposicao do maior eh %d e a posicao do menor eh: %d", maior, menor);
          getch();
          
}
void le(int a, int b, int c, int *maior, int *menor)
{
     int posmai, posmen;
    
     *maior=a;// inicializa o maior e o menor com o primeiro valor do a
     posmai=1;
     *menor=a;
     posmen=1;
     if(b>*maior)
     {
                *maior=b;
                posmai=2;
     }
     if(c>*maior)
     {
                *maior=c;
                posmai=3;
     }
     if(b<*menor)
     {
                *menor=b;
                posmen=2;
     }
     if(c<*menor)
     {
                *menor=c;
                posmen=3;
     }
     *maior=posmai;
     *menor=posmen;
}







