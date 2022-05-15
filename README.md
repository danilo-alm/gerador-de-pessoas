# Gerador de Pessoas
Gera dados pessoais aleatórios sobre pessoas fictícias. <br/>
## Uso:
```
pessoa [quantidade de pessoas]
```
Exemplo:
```
./pessoa 4

Nome: Valdiner Sántos de Pinho
Idade: 75 anos
Sexo: Masculino
CPF: 499.584.046-05
Regiões fiscais: MG

Nome: Elemar Fontes da Luz
Idade: 36 anos
Sexo: Masculino
CPF: 452.350.037-13
Regiões fiscais: ES, RJ

Nome: Rubes Gouveia de Lima
Idade: 98 anos
Sexo: Masculino
CPF: 678.738.333-99
Regiões fiscais: CE, MA, PI

Nome: Erisson Carneiro da Veiga
Idade: 69 anos
Sexo: Masculino
CPF: 794.049.245-47
Regiões fiscais: BA, SE

```

## Compilação
Compile com `make`:
```
make pessoas
```
ou compile manualmente com:
```
clang -Wall -Werror -o pessoa pessoa.c helpers.c
```