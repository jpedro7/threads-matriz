# Matriz e Threads

## Atividade 5: Infraestrutura de Software
Aluno: João Pedro Cordeiro Abrantes  
Periodo: 3  
Turma: B  
Professor: Erico Souza Teixeira  
Tutor: Michael Alvez  
  
Este repositório tem um programa em C que soma todos os valores de uma matriz de inteiros, porém, para fazer isso, é criado um thread para cada linha da matriz, cada thread é responsável pela soma de sua respectiva linha, e o resultado é adicionado à uma variável global.  

## Clonar o repositório

Para rodar o programa, primeiro é necessário clonar este repositório e compilar o arquivo .c, para isso, basta rodar os comandos abaixo no seu terminal:  

```bash
$ git clone https://github.com/jpedro7/threads-matriz.git
$ cd threads-matriz
```

## Rodar o programa

Para rodar o programa, rode os seguintes comandos no seu terminal:

```bash
$ make
```
O comando `make` vai compilar o código em um executável  

```bash
$ make run
```
O comando `make run` vai rodar o executável criado

```bash
$ make clean
```
O comando `make clean` vai deletar o executável  

A ideia que eu tive para fazer esse programa foi de criar uma struct com todos os dados necessários para fazer a soma de cada linha, dentro dessa struct eu coloquei a matriz, o id do thread, apenas para debug, a ordem da matriz, ou seja, seu tamanho, e um indice, que é a chave para o funcionamento do progama.  

O que eu fiz foi usar o indice dentro da struct para informar a linha que vai ser somada por cada thread, e ao final da execução da rotina de cada thread, é adicionado 1 ao indice da linha, fazendo com que o proximo thread faça a soma da próxima linha.
