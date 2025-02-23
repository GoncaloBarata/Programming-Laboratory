/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALOR_INVALIDO "O valor inserido é inválido."

/**
 * Valida opção 
 * @param txt texto que pede a opção
 * @param Val_min valor minimo aceite
 * @param Val_max valor maximo aceite
 * @return opção 
 */
int validarInt(char * txt, int Val_min, int Val_max) {
    int opcao;
    do {
        printf("%s ", txt);
        scanf("%d", &opcao);
        if (opcao < Val_min || opcao > Val_max)
            printf("O valor tem de pertencer ao intervalo [%d-%d].\n", Val_min, Val_max);
    } while (opcao < Val_min || opcao > Val_max);

    return opcao;
}

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Obter valores do tipo int
 * @param minValor valor mínimo aceite
 * @param maxValor valor máximo aceite
 * @param msg mensagem que pede o valor
 * @return valor
 */
int obterInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf("%s", msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf("%s", msg); // colocar %s\n
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Obter valores do tipo float
 * @param minValor valor mínimo aceite
 * @param maxValor valor máximo aceite
 * @param msg mensagem que pede o valor
 * @return valor
 */
float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf("%s", msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf("%s\n", msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Lê a string e armazena 
 * @param string local onde é armazenada a string
 * @param tamanho tamanho máximo da string
 * @param msg mensagem que pede a string
 */
void lerString(char *string, unsigned int tamanho, char *msg) {
    printf("%s", msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}

/**
 * Imprime uma linha para separar conteudos que são apresentados no output
 */
void printLinha() {
    printf("\n-------------------------\n");
}