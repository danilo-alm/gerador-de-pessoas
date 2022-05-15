#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#include "helpers.h"

// Quantidade máxima de pessoas permitida
#define QUANTIDADEPESSOAS 100

int main(int argc, char **argv)
{
    // Checar uso incorreto
    if (argc > 2)
    {
        printar_uso();
        return 1;
    }

    // Quantidade pessoas que serão criadas
    long int quantidade = 1;

    if (argc == 2)
    {
        // Validar argv[1]
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Quantidade inválida.\n");
                printar_uso();
                return 1;
            }
        }

        // Converter argv para numero
        quantidade = strtol(argv[1], (char **)NULL, 10);
        if (errno == ERANGE)
        {
            printf("Integer overflow\n");
            return 1;
        }
        else if (quantidade > QUANTIDADEPESSOAS)
        {
            printf("Quantidade de pessoas muito alta. Use uma quantidade "
            "menor do que %d\n", QUANTIDADEPESSOAS);
            return 1;
        }
    }

    srand(time(NULL));

    /* ----------- INCIAR VARIÁVEIS ----------- */
    int nomesMasculinosQuantidade = 0;
    node *nomesMasculinos = alocar_lista(NOMESMASCULINOS, &nomesMasculinosQuantidade);

    int nomesFemininosQuantidade = 0;
    node *nomesFemininos = alocar_lista(NOMESFEMININOS, &nomesFemininosQuantidade);

    int sobrenomesQuantidade = 0;
    node *sobrenomes = alocar_lista(SOBRENOMES, &sobrenomesQuantidade);

    int finsDeNomeQuantidade = 0;
    node *finsDeNome = alocar_lista(FINSDENOME, &finsDeNomeQuantidade);

    char regioesFiscais[REGIOESFISCAISTAMANHO + 1];
    char nomeCompleto[(TAMANHONOME * 3) + 1];
    char cpf[NUMEROSCPF + 1];
    int idade;
    char sexo;

    putchar('\n');

    for (int i = 0; i < quantidade; i++)
    {
        /* ----------- SEXO ----------- */
        sexo = gerar_sexo();

        /* ----------- NOME ----------- */
        if (sexo == 'M')
            nome_aleatorio(nomeCompleto, nomesMasculinos, nomesMasculinosQuantidade,
            sobrenomes, sobrenomesQuantidade, finsDeNome, finsDeNomeQuantidade);
        else
            nome_aleatorio(nomeCompleto, nomesFemininos, nomesFemininosQuantidade,
            sobrenomes, sobrenomesQuantidade, finsDeNome, finsDeNomeQuantidade);

        /* ----------- IDADE ----------- */
        idade = gerar_idade();

        /* ----------- CPF ----------- */
        gerar_cpf(cpf);

        /* ----------- REGIÃO FISCAL ----------- */
        obter_regioes_fiscais(cpf, regioesFiscais);

        /* ----------- PRINTAR INFORMAÇÕES ----------- */
        printf("Nome: %s\n", nomeCompleto);
        printf("Idade: %d anos\n", idade);
        printar_sexo(sexo);
        printar_cpf(cpf);
        printar_regioes_fiscais(regioesFiscais);

        putchar('\n');
    }

    /* ----------- DESALOCAR MEMÓRIA ----------- */
    desalocar_lista(nomesMasculinos);
    desalocar_lista(nomesFemininos);
    desalocar_lista(sobrenomes);
    desalocar_lista(finsDeNome);

    return 0;
}