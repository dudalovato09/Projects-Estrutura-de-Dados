/*
	Escreva uma função que receba um caractere c e transforme c em uma string (cadeia de caracteres), 
	ou seja, devolva uma string de comprimento 1 tendo c como único elemento.

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

char *converte(char ch);

main (void)
{
	char ch;
	char *palavra;
	
	
	system("cls");
	printf("Digite um caracter: ");
	scanf("%c" ,&ch);
	
	palavra = converte(ch);
	
	printf("Caracter convertido em string %s: \n", palavra);
	
	getch();
}

char *converte(char ch)
{
	char *palavra;
	
	palavra = (char *) calloc(2, sizeof(char *)); 
	
	palavra[0] = ch;
	palavra[1] = '\0';
	
	return palavra;
	
}

