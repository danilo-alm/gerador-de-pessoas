#include "helpers.h"

char *gerar_cpf(char *cpf)
{
    /* --------- Gerar 9 primeiros dígitos do CPF --------- */
    for (int i = 0; i < 9; i++)
    {
        cpf[i] = (rand() % 10) + '0';
    }

    /* --------- Como gerar dígitos verificadores ---------

    - Primeiro multiplicamos os 9 primeiros dígitos pela sequência decrescente
    de números de 10 à 2 e somamos os resultados;
    - O primeiro dígito verificador será a sobra do resultado multiplicado por 10
    e dividido por 11 (digito = resultado * 10 % 11);
    OBSERVAÇÃO IMPORTANTE: Se o resto da divisão for igual a 10, nós o consideramos como 0.

    Para o segundo dígito, faremos o mesmo, com a excessão de que no primeiro passo, adicionaremos
    o primeiro verificador no cálculo e multiplicaremos os dígitos pela sequência decrescente de
    números de 11 à 2

    ----------------- */

    /* Vamos utilizar um looping que irá gerar o primeiro dígito verificador
    na primeira iteração e o segundo dígito na segunda iteração */

    // Número de dígitos que serão somados
    unsigned short int numeroDeDigitos = 9;

    // Contador que irá de 10 à 2 no primeiro dígito/looping e 11 à 2 no segundo
    unsigned short int contador = 10;
    unsigned short int soma = 0;

    for (int i = 0; i < 2; i++)
    {
        if (i == 1)
        {
            // Atualizar os valores para o segundo dígito
            numeroDeDigitos++;
            contador = 11;
            soma = 0;
        }

        for (int j = 0; j < numeroDeDigitos; j++)
        {
            soma += (cpf[j] - '0') * contador;
            contador--;
        }

        unsigned short int resto = soma * 10 % 11;
        if (resto == 10)
        {
            resto = 0;
        }
        cpf[i + 9] = resto + '0';
    }
    cpf[11] = '\0';

    return cpf;
}

void printar_cpf(char *cpf)
{
    printf("CPF: ");
    for (int i = 0, j = NUMEROSCPF; i < j; i++)
    {
        if (i == 3 || i == 6)
            putchar('.');
        else if (i == 9)
            putchar('-');

        printf("%c", cpf[i]);
    }
    putchar('\n');
}

char *obter_regioes_fiscais(char *cpf, char *regioesFiscais)
{
    char *nonoDigito = &cpf[8];
    switch (*nonoDigito)
    {
        case '1':
            strcpy(regioesFiscais, "DFGOMSMTTO");
            break;
        case '2':
            strcpy(regioesFiscais, "ACAMAPPARORR");
            break;
        case '3':
            strcpy(regioesFiscais, "CEMAPI");
            break;
        case '4':
            strcpy(regioesFiscais, "ALPBPERN");
            break;
        case '5':
            strcpy(regioesFiscais, "BASE");
            break;
        case '6':
            strcpy(regioesFiscais, "MG");
            break;
        case '7':
            strcpy(regioesFiscais, "ESRJ");
            break;
        case '8':
            strcpy(regioesFiscais, "SP");
            break;
        case '9':
            strcpy(regioesFiscais, "PRSC");
            break;
        case '0':
            strcpy(regioesFiscais, "RS");
            break;
    }
    return regioesFiscais;
}

void printar_regioes_fiscais(char *regioesFiscais)
{
    // Tamanho da sigla de cada região fiscal
    #define TAMANHHOREGIAO 2

    printf("Regiões fiscais: ");
    for (int i = 0; regioesFiscais[i] != '\0'; i++)
    {
        if (i != 0 && i % 2 == 0)
            printf(", ");
        putchar(regioesFiscais[i]);
    }
    putchar('\n');
}

node *alocar_lista(char *nomeArquivo, int *tamanhoLista)
{
    FILE *f = fopen(nomeArquivo, "r");
    if (f == NULL)
        return NULL;

    // Buffer que irá armazenar a palavra lida
    char buffer[TAMANHONOME + 1];

    // Quantidade de palavras lidas
    int palavras = 0;

    // Node raiz da linked list
    node *raiz = NULL;

    // Node que será adicionado à linked list
    node *temp = NULL;

    // Pointer que indicará o último Node adicionado
    node *lastnode = NULL;

    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        // Remover newline de buffer
        buffer[strcspn(buffer, "\n")] = '\0';

        // Popular node que será adicionado à lista
        temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Malloc falhou\n");
            exit(1);
        }
        strcpy(temp -> nome, buffer);
        temp -> proximo = NULL;

        if (raiz == NULL)
        {
            raiz = temp;
            lastnode = raiz;
        }
        else
        {
            lastnode -> proximo = temp;
            lastnode = lastnode -> proximo;
        }
        palavras++;
    }
    fclose(f);

    if (tamanhoLista != NULL)
        *tamanhoLista = palavras;

    return raiz;
}

char gerar_sexo()
{
    char sexo;
    unsigned short int num = rand() % 2;
    switch (num)
    {
        case 0:
            sexo = 'M';
            break;
        case 1:
            sexo = 'F';
            break;
    }
    return sexo;
}

void printar_sexo(char sexo)
{
    printf("Sexo: ");
    switch (sexo)
    {
        case 'M':
            printf("Masculino\n");
            break;
        case 'F':
            printf("Feminino\n");
            break;
    }
}

char *buscarNome(node *lista, int index)
{
    node *nodeAtual = lista;
    for (int i = 0; i < index; i++)
        nodeAtual = nodeAtual -> proximo;

    return nodeAtual -> nome;
}

char *nome_aleatorio(char *nomeCompleto, node *nomes, int nomesQuantidade, node *sobrenomes,
int sobrenomesQuantidade, node *finsDeNome, int finsDeNomeQuantidade)
{
    // Obter o index de cada nome
    int nomeIndex = rand() % nomesQuantidade;
    int sobrenomeIndex = rand() % sobrenomesQuantidade;
    int fimDeNomeIndex = rand() % finsDeNomeQuantidade;

    // Buscar o nome correspondente à cada index nas listas
    char *nome = buscarNome(nomes, nomeIndex);
    char *sobrenome = buscarNome(sobrenomes, sobrenomeIndex);
    char *fimDeNome = buscarNome(finsDeNome, fimDeNomeIndex);

    // Criar nome completo
    int index = 0;
    for (int i = 0; nome[i] != '\0'; i++)
        nomeCompleto[index++] = nome[i];

    nomeCompleto[index++] = ' ';

    for (int i = 0; sobrenome[i] != '\0'; i++)
        nomeCompleto[index++] = sobrenome[i];

    nomeCompleto[index++] = ' ';

    for (int i = 0; fimDeNome[i] != '\0'; i++)
        nomeCompleto[index++] = fimDeNome[i];

    nomeCompleto[index] = '\0';

    return nomeCompleto;
}

int gerar_idade()
{
    unsigned short int num = rand() % 101;
    if (num == 0)
        num = 1;
    int idade;

    // Menor idade
    int maior;
    // Maior idade
    int menor;

    // 50% de chance -> 18-39 anos
    if (num <= 50)
    {
        menor = 18;
        maior = 39;
    }
    // 30% de chance -> 40-69 anos
    else if (num < 80)
    {
        menor = 40;
        maior = 69;
    }
    // 15% de chance -> 70-89
    else if (num < 95)
    {
        menor = 70;
        maior = 89;
    }
    // 5% de chance  -> 90 - 100
    else
    {
        menor = 90;
        maior = 100;
    }

    idade = (rand() % (maior - menor + 1)) + menor;
    return idade;
}

void desalocar_lista(node *raiz)
{
    if (raiz != NULL)
    {
        node *atual = raiz;
        node *proximo = NULL;

        while (atual != NULL)
        {
            proximo = atual -> proximo;
            free(atual);
            atual = proximo;
        }
    }
}

void printar_uso()
{
    printf("Uso: pessoa [quantidade de pessoas]\n");
}