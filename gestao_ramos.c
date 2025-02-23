/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_ramos.h"
#include "input.h"

/**
 * Verifica o código do ramo de atividade 
 * @param apt_verificar apondador para a struct RamosAtividade
 * @param codigo recebe o código a verificar
 * @return a posição do ramo de atividade caso exista ou -1 caso não exista
 */
int verificar_codigo(RamosAtividade *apt_verificar, int codigo) {
    int i;

    for (i = 0; i < apt_verificar->conta_ramos; i++) {
        if (apt_verificar->ramos[i].codigo_ramo == codigo) {
            return i;
        }
    }
    return -1; // NÃO EXISTE (O ramo de atividade não está associado)  
}

/**
 * Cria um ramo de atividade
 * @param apt_ramo apontador para a struct RamosAtividade
 * @return número de ramos de atividade atualizado
 */
int criar_ramo(RamosAtividade *apt_ramo) {
    char nome_ramo[TAM_STRING];

    RamoAtividade ramo;

    if (apt_ramo->conta_ramos == apt_ramo->max_ramos) {
        apt_ramo->max_ramos <<= 1; // multiplica o numero por dois
        apt_ramo->ramos = realloc(apt_ramo->ramos, sizeof (RamoAtividade) * apt_ramo->max_ramos);
    }

    static int codigo_ramo = 0;
    codigo_ramo++;

    ramo.codigo_ramo = codigo_ramo;

    printf("Insira o nome do ramo de atividade: ");
    scanf(" %[^\n]s", nome_ramo);
    strcpy(ramo.nome_ramo, nome_ramo);

    ramo.estado_r = ATIVO;

    apt_ramo->ramos[apt_ramo->conta_ramos] = ramo;


    return apt_ramo->conta_ramos++;
}

/**
 * Lê os dados guardados em "ramos.txt"
 * @param array_ramos apontador para a struct RamosAtividade
 */
void ler_data_ramos(RamosAtividade *array_ramos) {
    FILE *ramos = fopen("ramos.txt", "r");

    if (ramos != NULL) {
        while (fscanf(ramos, "%d %s %d\n",
                &(array_ramos->ramos[array_ramos->conta_ramos].codigo_ramo),
                (array_ramos->ramos[array_ramos->conta_ramos].nome_ramo),
                &(array_ramos->ramos[array_ramos->conta_ramos].estado_r)) != EOF) {

            array_ramos->conta_ramos++;
        }
        fclose(ramos);
    }
}

/**
 * Aloca memória para os ramos de atividade
 * @return array_ramos
 */
RamosAtividade *inic_ramos() {
    RamosAtividade *array_ramos;
    array_ramos = (RamosAtividade *) malloc(sizeof (RamosAtividade));
    if (array_ramos == NULL) {
        perror("Erro a alocar memória para vendedores!"); // perror faz printf e exit
    }
    array_ramos->max_ramos = RAMOS_TAM_INICIAL;
    array_ramos->conta_ramos = 0;

    array_ramos->ramos = (RamoAtividade *) malloc(sizeof (RamoAtividade) * array_ramos->max_ramos);
    if (array_ramos->ramos == NULL) {
        perror("Erro a alocar memória para vendedores!"); // perror faz printf e exit
    }

    return array_ramos;
}

/**
 * Função que mete as variáveis nulas
 * @param ramo apontador para a struct RamoAtividade
 */
void apagar_dados_ramo(RamoAtividade *ramo) {
    ramo->codigo_ramo = 0;
    strcpy(ramo->nome_ramo, "");
}

/**
 * Função que revome o ramo de atividade caso não existe nenhuma empresa associada
 * Caso exista alguma empresa associada altera o estado do ramo de atividade para inativo
 * @param r_ramos apontador para a struct RamosAtividade
 * @param apt_empresas apontador para a struct Empresas
 */
void remover_ramos(RamosAtividade *r_ramos, Empresas *apt_empresas) {
    int numero, cod_r, i, associado = 0;

    cod_r = obterInt(0, 999, "Insira o código do ramo: ");
    numero = verificar_codigo(r_ramos, cod_r);

    if (numero != -1) {
        for (i = 0; i < apt_empresas->conta_empresas; i++) {
            if (apt_empresas->empresas[i].codigo_ramo == cod_r) {
                associado = 1;
                break;
            }
        }

        if (!associado) {
            for (i = numero; i < r_ramos->conta_ramos - 1; i++) {
                r_ramos->ramos[i] = r_ramos->ramos[i + 1];
            }
            apagar_dados_ramo(&r_ramos->ramos[i]);
            r_ramos->conta_ramos--;
            printf("Ramo de atividade removido com sucesso!\n");
        } else if (r_ramos->ramos[numero].estado_r == ATIVO) {
            r_ramos->ramos[numero].estado_r = INATIVO;
            printf("O ramo de atividade ficou inativo!\n");
        } else {
            printf("O ramo de atividade já está inativo!\n");
        }
    } else {
        printf("Este ramo de atividade não existe!\n");
    }
}

/**
 * Edita o ramo de atividade
 * @param apt_editar apontador para a struct RamoAtividade
 */
void editar_ramo(RamoAtividade *apt_editar) {
    lerString(apt_editar->nome_ramo, TAM_STRING, "Insira o novo nome do ramo de atividade: ");
}

/**
 * Edita o ramo de atividade caso ele exista
 * @param apt_editar apontador para a struct RamosAtividade
 */
void editar_ramos(RamosAtividade *apt_editar) {
    int cod_ramo;

    cod_ramo = verificar_codigo(apt_editar, obterInt(0, 999, "Insira o código do ramo de atividade: "));

    if (cod_ramo != -1) {
        editar_ramo(&apt_editar->ramos[cod_ramo]);
    } else {
        printf("Este ramo de atividade não existe!\n");
    }
}

/**
 * Faz uma listagem dos ramos de atividade ativos
 * @param listar apontador para a struct RamosAtividade
 */
void listar_ramos_ativos(RamosAtividade *listar) {
    if (listar->conta_ramos > 0) {
        for (int i = 0; i < listar->conta_ramos; i++) {
            char *estado;
            if (listar->ramos[i].estado_r == ATIVO) {
                estado = "Ativo";

                printf("%3d %s %s\n", listar->ramos[i].codigo_ramo, listar->ramos[i].nome_ramo, estado);
            }
        }
    } else {
        printf("Sem ramos ativos!\n");
    }
}

