/*
Um ponteiro pode ser usado para dizer a uma fun��o onde ela deve depositar o resultado de seus c�lculos.
  Escreva uma fun��o hm que converta minutos em horas-e-minutos.
  A fun��o recebe um inteiro mnts e os endere�os de duas vari�veis inteiras, digamos h e m, 
  e atribui valores a essas vari�veis de modo que m seja menor que 60 e que 60*h + m seja igual a mnts.   
  Escreva tamb�m uma fun��o main que use a fun��o hm. 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

void hm(int mnts, int *h, int *m);

main (void)
{
	int minutos, h, m;
	
	system("cls");
	printf("Digite um tempo em minutos: ");
	scanf("%d" ,&minutos);
	
	hm(minutos, &h, &m);
	
	printf("Tempo em horas %d: \n", h);
	printf("Tempo em minutos %d: \n", m);
	
	getch();
}

void hm(int mnts, int *h, int *m)
{
	*h = (mnts / 60);
	*m = (mnts - (*h * 60));
}

