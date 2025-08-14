/*
O que h� de errado com o seguinte trecho de c�digo?

char *a, *b;
a = "abacate";
b = "uva";
if (a < b)
   printf ("%s vem antes de %s no dicion�rio", a, b);
else
   printf ("%s vem depois de %s no dicion�rio", a, b);
*/

/*
Apesar do resultado mostrar corretamente que abacate vem antes da uva no dicionario,
a compara��o est� sendo feita por endereco de memoria na verdade a compara��o
esta sendo feita em rela��o a qual aloca��o de memoria vem antes da outra e n�o a palavra no dicionario
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

main(void)
{
	char *a, *b;
	a = "abacade";
	b = "uva";
	
	if (a < b)
   		printf ("%s vem antes de %s no dicion�rio", a, b);
	else
   		printf ("%s vem depois de %s no dicion�rio", a, b);
}
