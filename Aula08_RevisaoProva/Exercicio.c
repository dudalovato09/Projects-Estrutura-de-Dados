#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura para Data
typedef struct
{
    int dia;
    int mes;
} Data;

// Estrutura para Contato
typedef struct
{
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data dataAniversario;
} Contato;

// Estrutura do elemento da lista
struct elemento
{
    Contato info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

// Protótipos das funções
Elemento *cria_agenda();
Elemento *insere_contato(Elemento *agenda, Contato contato);
void lista_contatos(Elemento *agenda);
Elemento *busca_contato(Elemento *agenda, char *nome);
Elemento *remove_contato(Elemento *agenda, char *nome);
Elemento *atualiza_contato(Elemento *agenda, char *nome);
Elemento *remove_duplicados(Elemento *agenda);
void libera_agenda(Elemento *agenda);

// Funções auxiliares
void limpa_buffer();
int valida_email(char *email);
int valida_data(int dia, int mes);
void to_upper_case(char *str);
int le_string_segura(char *buffer, int tamanho, const char *prompt);
int le_inteiro_seguro(int *valor, const char *prompt);

// Implementação das funções principais

Elemento *cria_agenda()
{
    return NULL;
}

Elemento *insere_contato(Elemento *agenda, Contato contato)
{
    // Aloca memória para novo elemento
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (novo == NULL)
    {
        printf("Erro: Falha na alocação de memória!\n");
        return agenda;
    }

    novo->info = contato;
    novo->prox = NULL;

    // Lista vazia ou inserção no início
    if (agenda == NULL || strcmp(contato.nome, agenda->info.nome) < 0)
    {
        novo->prox = agenda;
        return novo;
    }

    // Busca posição correta para inserção ordenada
    Elemento *atual = agenda;
    while (atual->prox != NULL && strcmp(contato.nome, atual->prox->info.nome) > 0)
    {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return agenda;
}

void lista_contatos(Elemento *agenda)
{
    if (agenda == NULL)
    {
        printf("\n=== AGENDA VAZIA ===\n");
        printf("Não há contatos cadastrados.\n\n");
        return;
    }

    printf("\n=== LISTA DE CONTATOS ===\n");
    Elemento *atual = agenda;
    int contador = 1;

    while (atual != NULL)
    {
        printf("\n--- Contato %d ---\n", contador);
        printf("Nome: %s\n", atual->info.nome);
        printf("Telefone: %s\n", atual->info.telefone);
        printf("Celular: %s\n", atual->info.celular);
        printf("Email: %s\n", atual->info.email);
        printf("Aniversário: %02d/%02d\n",
               atual->info.dataAniversario.dia,
               atual->info.dataAniversario.mes);

        atual = atual->prox;
        contador++;
    }
    printf("\nTotal de contatos: %d\n\n", contador - 1);
}

Elemento *busca_contato(Elemento *agenda, char *nome)
{
    if (agenda == NULL || nome == NULL)
    {
        return NULL;
    }

    Elemento *atual = agenda;
    while (atual != NULL)
    {
        if (strcmp(atual->info.nome, nome) == 0)
        {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

Elemento *remove_contato(Elemento *agenda, char *nome)
{
    if (agenda == NULL)
    {
        printf("Erro: Agenda vazia!\n");
        return NULL;
    }

    Elemento *encontrado = busca_contato(agenda, nome);
    if (encontrado == NULL)
    {
        printf("Erro: Contato '%s' não encontrado!\n", nome);
        return agenda;
    }

    // Remoção do primeiro elemento
    if (strcmp(agenda->info.nome, nome) == 0)
    {
        Elemento *temp = agenda;
        agenda = agenda->prox;
        free(temp);
        printf("Contato '%s' removido com sucesso!\n", nome);
        return agenda;
    }

    // Busca o elemento anterior
    Elemento *anterior = agenda;
    while (anterior->prox != NULL && strcmp(anterior->prox->info.nome, nome) != 0)
    {
        anterior = anterior->prox;
    }

    if (anterior->prox != NULL)
    {
        Elemento *temp = anterior->prox;
        anterior->prox = temp->prox;
        free(temp);
        printf("Contato '%s' removido com sucesso!\n", nome);
    }

    return agenda;
}

Elemento *atualiza_contato(Elemento *agenda, char *nome)
{
    Elemento *encontrado = busca_contato(agenda, nome);

    if (encontrado == NULL)
    {
        printf("Erro: Contato '%s' não encontrado!\n", nome);
        return agenda;
    }

    printf("\n=== ATUALIZANDO CONTATO: %s ===\n", nome);
    printf("Deixe em branco para manter o valor atual.\n\n");

    char temp[100];
    int dia, mes;

    // Atualizar telefone
    printf("Telefone atual: %s\n", encontrado->info.telefone);
    if (le_string_segura(temp, sizeof(temp), "Novo telefone: "))
    {
        if (strlen(temp) <= 15)
        {
            strcpy(encontrado->info.telefone, temp);
        }
        else
        {
            printf("Aviso: Telefone muito longo (máx 15 caracteres). Não alterado.\n");
        }
    }

    // Atualizar celular
    printf("Celular atual: %s\n", encontrado->info.celular);
    if (le_string_segura(temp, sizeof(temp), "Novo celular: "))
    {
        if (strlen(temp) <= 15)
        {
            strcpy(encontrado->info.celular, temp);
        }
        else
        {
            printf("Aviso: Celular muito longo (máx 15 caracteres). Não alterado.\n");
        }
    }

    // Atualizar email
    printf("Email atual: %s\n", encontrado->info.email);
    if (le_string_segura(temp, sizeof(temp), "Novo email: "))
    {
        if (strlen(temp) <= 40 && valida_email(temp))
        {
            strcpy(encontrado->info.email, temp);
        }
        else
        {
            printf("Aviso: Email inválido ou muito longo (máx 40 caracteres). Não alterado.\n");
        }
    }

    // Atualizar data de aniversário
    printf("Aniversário atual: %02d/%02d\n",
           encontrado->info.dataAniversario.dia,
           encontrado->info.dataAniversario.mes);

    if (le_inteiro_seguro(&dia, "Novo dia do aniversário (1-31): "))
    {
        if (le_inteiro_seguro(&mes, "Novo mês do aniversário (1-12): "))
        {
            if (valida_data(dia, mes))
            {
                encontrado->info.dataAniversario.dia = dia;
                encontrado->info.dataAniversario.mes = mes;
            }
            else
            {
                printf("Aviso: Data inválida. Não alterada.\n");
            }
        }
    }

    printf("Contato atualizado com sucesso!\n\n");
    return agenda;
}

Elemento *remove_duplicados(Elemento *agenda)
{
    if (agenda == NULL)
    {
        printf("Agenda vazia - nada para remover.\n");
        return NULL;
    }

    int removidos = 0;
    Elemento *atual = agenda;

    while (atual != NULL && atual->prox != NULL)
    {
        if (strcmp(atual->info.nome, atual->prox->info.nome) == 0)
        {
            Elemento *duplicado = atual->prox;
            atual->prox = duplicado->prox;
            free(duplicado);
            removidos++;
        }
        else
        {
            atual = atual->prox;
        }
    }

    if (removidos > 0)
    {
        printf("Removidos %d contato(s) duplicado(s).\n", removidos);
    }
    else
    {
        printf("Nenhum contato duplicado encontrado.\n");
    }

    return agenda;
}

void libera_agenda(Elemento *agenda)
{
    Elemento *atual = agenda;
    while (atual != NULL)
    {
        Elemento *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

// Implementação das funções auxiliares

void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int valida_email(char *email)
{
    if (email == NULL || strlen(email) == 0)
        return 0;

    int tem_arroba = 0;
    int tem_ponto_apos_arroba = 0;
    int pos_arroba = -1;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            if (tem_arroba)
                return 0; // Mais de um @
            tem_arroba = 1;
            pos_arroba = i;
            if (i == 0)
                return 0; // @ no início
        }
        else if (email[i] == '.' && tem_arroba && i > pos_arroba + 1)
        {
            tem_ponto_apos_arroba = 1;
        }
    }

    return tem_arroba && tem_ponto_apos_arroba && email[strlen(email) - 1] != '.';
}

int valida_data(int dia, int mes)
{
    if (mes < 1 || mes > 12)
        return 0;
    if (dia < 1 || dia > 31)
        return 0;

    // Validação básica de dias por mês
    int dias_por_mes[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dia <= dias_por_mes[mes - 1];
}

void to_upper_case(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int le_string_segura(char *buffer, int tamanho, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(buffer, tamanho, stdin) != NULL)
    {
        // Remove quebra de linha
        buffer[strcspn(buffer, "\n")] = '\0';
        return strlen(buffer) > 0;
    }
    return 0;
}

int le_inteiro_seguro(int *valor, const char *prompt)
{
    char buffer[100];
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0)
            return 0; // String vazia

        char *endptr;
        *valor = strtol(buffer, &endptr, 10);
        return *endptr == '\0'; // Conversão bem-sucedida
    }
    return 0;
}

// Função para cadastrar novo contato
Elemento *cadastrar_contato(Elemento *agenda)
{
    Contato novo_contato;
    char buffer[100];
    int dia, mes;

    printf("\n=== CADASTRAR NOVO CONTATO ===\n");

    // Nome (obrigatório)
    do
    {
        if (!le_string_segura(novo_contato.nome, sizeof(novo_contato.nome), "Nome (obrigatório): "))
        {
            printf("Erro: Nome é obrigatório!\n");
            continue;
        }
        to_upper_case(novo_contato.nome);
        break;
    } while (1);

    // Verificar se já existe
    if (busca_contato(agenda, novo_contato.nome) != NULL)
    {
        printf("Erro: Contato '%s' já existe!\n", novo_contato.nome);
        return agenda;
    }

    // Telefone
    if (!le_string_segura(novo_contato.telefone, sizeof(novo_contato.telefone), "Telefone: "))
    {
        strcpy(novo_contato.telefone, "");
    }

    // Celular
    if (!le_string_segura(novo_contato.celular, sizeof(novo_contato.celular), "Celular: "))
    {
        strcpy(novo_contato.celular, "");
    }

    // Email
    do
    {
        if (!le_string_segura(novo_contato.email, sizeof(novo_contato.email), "Email: "))
        {
            strcpy(novo_contato.email, "");
            break;
        }
        if (valida_email(novo_contato.email))
        {
            break;
        }
        printf("Erro: Email inválido! Tente novamente.\n");
    } while (1);

    // Data de aniversário
    do
    {
        if (!le_inteiro_seguro(&dia, "Dia do aniversário (1-31): "))
        {
            dia = 1;
        }
        if (!le_inteiro_seguro(&mes, "Mês do aniversário (1-12): "))
        {
            mes = 1;
        }

        if (valida_data(dia, mes))
        {
            novo_contato.dataAniversario.dia = dia;
            novo_contato.dataAniversario.mes = mes;
            break;
        }
        printf("Erro: Data inválida! Tente novamente.\n");
    } while (1);

    agenda = insere_contato(agenda, novo_contato);
    printf("Contato '%s' cadastrado com sucesso!\n\n", novo_contato.nome);

    return agenda;
}

// Função principal
int main()
{
    Elemento *agenda = cria_agenda();
    int opcao;
    char nome_busca[41];

    printf("=== AGENDA TELEFÔNICA ===\n");
    printf("Sistema de gerenciamento de contatos\n\n");

    do
    {
        printf("=== MENU PRINCIPAL ===\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Remover Contatos Duplicados\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Erro: Entrada inválida!\n");
            limpa_buffer();
            continue;
        }
        limpa_buffer();

        switch (opcao)
        {
        case 1:
            agenda = cadastrar_contato(agenda);
            break;

        case 2:
            lista_contatos(agenda);
            break;

        case 3:
            printf("\n=== BUSCAR CONTATO ===\n");
            if (le_string_segura(nome_busca, sizeof(nome_busca), "Nome do contato: "))
            {
                to_upper_case(nome_busca);
                Elemento *encontrado = busca_contato(agenda, nome_busca);

                if (encontrado != NULL)
                {
                    printf("\n--- Contato Encontrado ---\n");
                    printf("Nome: %s\n", encontrado->info.nome);
                    printf("Telefone: %s\n", encontrado->info.telefone);
                    printf("Celular: %s\n", encontrado->info.celular);
                    printf("Email: %s\n", encontrado->info.email);
                    printf("Aniversário: %02d/%02d\n\n",
                           encontrado->info.dataAniversario.dia,
                           encontrado->info.dataAniversario.mes);
                }
                else
                {
                    printf("Contato '%s' não encontrado!\n\n", nome_busca);
                }
            }
            break;

        case 4:
            printf("\n=== EDITAR CONTATO ===\n");
            if (le_string_segura(nome_busca, sizeof(nome_busca), "Nome do contato: "))
            {
                to_upper_case(nome_busca);
                agenda = atualiza_contato(agenda, nome_busca);
            }
            break;

        case 5:
            printf("\n=== REMOVER CONTATO ===\n");
            if (le_string_segura(nome_busca, sizeof(nome_busca), "Nome do contato: "))
            {
                to_upper_case(nome_busca);
                agenda = remove_contato(agenda, nome_busca);
            }
            break;

        case 6:
            printf("\n=== REMOVER DUPLICADOS ===\n");
            agenda = remove_duplicados(agenda);
            break;

        case 7:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Erro: Opção inválida! Escolha entre 1-7.\n\n");
        }

    } while (opcao != 7);

    // Libera memória antes de sair
    libera_agenda(agenda);
    printf("Memória liberada. Obrigado por usar a agenda!\n");

    return 0;
}