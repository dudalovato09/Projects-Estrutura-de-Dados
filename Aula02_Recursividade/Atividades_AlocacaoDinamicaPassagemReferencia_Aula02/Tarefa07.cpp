/*7. Escreva uma função que receba um caractere c e transforme c em uma string (cadeia de caracteres), ou seja,
devolva uma string de comprimento 1 tendo c como único elemento. */

#include <stdio.h>
#include <locale.h>
#include <string.h>

// Função que recebe um char e devolve ma string
void charParaString(char c, char str[])
{
    str[0] = c;    // Primeiro caractere da string
    str[1] = '\0'; // Terminador da String
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");

    char caractere, resultado[2]; // Tamanho 2 pois 1 é para o char e outro para o terminador '\0'
    char linha[100];              // Buffer para armazenar a entrada do usuário

    printf("Digite um caractere: ");
    // Pode ser lido também com "scanf ("%c", &nome da variável)" ou "caractere = getchar();""

    fgets(linha, sizeof(linha), stdin); // lê a linha inteira
    caractere = linha[0];               // pega apenas o primeiro caractere digitado

    charParaString(caractere, resultado);

    printf("String gerada: \"%s\"\n", resultado);

    return 0;
}