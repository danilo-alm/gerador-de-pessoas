#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// Quantidade de números em um CPF
#define NUMEROSCPF 11

// Bytes alocados para cada nome
#define TAMANHONOME 25

// Nome de cada arquivo
#define NOMESMASCULINOS "./recursos/nomes-masculinos.txt"
#define NOMESFEMININOS "./recursos/nomes-femininos.txt"
#define SOBRENOMES "./recursos/sobrenomes.txt"
#define FINSDENOME "./recursos/fins-de-nome.txt"

typedef struct node
{
    char nome[25];
    struct node *proximo;
}
node;

// Retorna um CPF válido
char *gerar_cpf();

// Printa o CPF com pontos e hífen (xxx.xxx.xxx-xx)
void printar_cpf(char *cpf);

/* Recebe como argumento o 9° dígito do CPF e retornaas regiões
fiscais na qual ele foi emitido. Ex: DF, GO, MS, MT e TO será
retornado como DFGOMSMTTO */
char *obter_regioes_fiscais(char nonoDigito);

// Printa as regiões fiscais separadas por vírgula
void printar_regioes_fiscais(char *regioesFiscais);

/* Cria uma lista com cada nome em `nomeArquivo`, coloca seu
tamanho em `tamanhoLista` e retorna o Node raiz da lista */
node *alocar_lista(char *nomeArquivo, int *tamanhoLista);

// Retorna 'M' para masculino e 'F' para feminino
char gerar_sexo();

// Printa "Masculino" para 'M' e "Feminino" para 'F'
void printar_sexo(char sexo);

// Retorna o nome número `index` na lista `lista`
char *buscarNome(node *lista, int index);

// Retorna um nome aleatório
char *nome_aleatorio(node *nomes, int nomesQuantidade, node *sobrenomes,
int sobrenomesQuantidade, node *finsDeNome, int finsDeNomeQuantidade);

// Retorna uma idade
int gerar_idade();

// Desaloca todos os nodes de uma lista
void desalocar_lista(node *raiz);

// Printa como o programa deve ser usado
void printar_uso();
