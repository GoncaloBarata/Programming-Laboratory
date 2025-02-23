/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionalidades.h"
#include "utilizadores.h"
#include "gestao_ramos.h"
#include "gestao_empresas.h"
#include "input.h"


/**
 * Função para listar os comentários de uma empresa
 * @param empresas apontador para a struct Empresas
 */
void listar_comentarios_empresas(Empresas *empresas) {
    if (empresas->conta_empresas == 0) {
        printf("Nenhuma empresa disponível.\n");
        return;
    }

    for (int i = 0; i < empresas->conta_empresas; i++) {
        printf("%s %d\n", empresas->empresas[i].nome_empresa, empresas->empresas[i].num_comentarios);

        for (int j = 0; j < empresas->empresas[i].num_comentarios; j++) {
            printf("%s %s %s %s\n",
                    empresas->empresas[i].comentarios[j].nome_utilizador,
                    empresas->empresas[i].comentarios[j].email,
                    empresas->empresas[i].comentarios[j].titulo,
                    empresas->empresas[i].comentarios[j].texto);
        }
    }
}

/**
 * Função para eliminar um comentário
 * @param lista_empresas apontador para a struct Empresas
 */
void eliminar_comentario(Empresas *lista_empresas) {
    char nome_empresa;
    printf("Insira o nome da empresa: ");
    scanf(" %s", &nome_empresa);

    int indice_empresa = encontrar_empresa_nome(lista_empresas, &nome_empresa);

    if (indice_empresa != -1) {
        if (lista_empresas->empresas[indice_empresa].estado_e == ATIVO) {
            printf("Comentários disponíveis:\n");
            for (int i = 0; i < lista_empresas->empresas[indice_empresa].num_comentarios; i++) {
                printf("%d. %s - %s\n", i + 1, lista_empresas->empresas[indice_empresa].comentarios[i].nome_utilizador,
                        lista_empresas->empresas[indice_empresa].comentarios[i].titulo);
            }

            int numero_comentario;
            printf("Digite o número do comentário que deseja eliminar: ");
            scanf("%d", &numero_comentario);

            if (numero_comentario > 0 && numero_comentario <= lista_empresas->empresas[indice_empresa].num_comentarios) {
                for (int i = numero_comentario - 1; i < lista_empresas->empresas[indice_empresa].num_comentarios - 1; i++) {
                    lista_empresas->empresas[indice_empresa].comentarios[i] = lista_empresas->empresas[indice_empresa].comentarios[i + 1];
                }
                (lista_empresas->empresas[indice_empresa].num_comentarios)--;

                printf("Comentário eliminado com sucesso.\n");
            } else {
                printf("Número de comentário inválido.\n");
            }
        } else {
            printf("A empresa está inativa. Não é possível eliminar comentários.\n");
        }
    } else {
        printf("Empresa não encontrada.\n");
    }
}

/**
 * Função para ocultar um comentário
 * @param lista_empresas apontador para a struct Empresas
 */
void ocultar_comentario(Empresas *lista_empresas) {
    char nome_empresa[TAM_STRING];
    printf("Insira o nome da empresa: ");
    scanf(" %s", nome_empresa);

    int indice_empresa = encontrar_empresa_nome(lista_empresas, nome_empresa);

    if (indice_empresa != -1) {
        Empresa *empresa = &lista_empresas->empresas[indice_empresa];

        if (empresa->estado_e == ATIVO) {
            printf("Comentários disponíveis:\n");

            for (int i = 0; i < empresa->num_comentarios; i++) {
                printf("%d. %s - %s\n", i + 1, empresa->comentarios[i].nome_utilizador,
                       empresa->comentarios[i].titulo);
            }

            int numero_comentario;
            printf("Digite o número do comentário que deseja ocultar: ");
            scanf("%d", &numero_comentario);

            if (numero_comentario > 0 && numero_comentario <= empresa->num_comentarios) {
                empresa->comentarios[numero_comentario - 1].estado_c = OCULTO;
                printf("Comentário ocultado com sucesso.\n");
            } else {
                printf("Número de comentário inválido.\n");
            }
        } else {
            printf("A empresa está inativa. Não é possível ocultar comentários.\n");
        }
    } else {
        printf("Empresa não encontrada.\n");
    }
}

/**
 * Coloca a empresa no estado ativo 
 * @param apt_editar apontador para a struct Empresas
 */
void ativar_empresas(Empresas *apt_ativar) {
    char nome_empresa;

    printf("Insira o nome da empresa: ");
    scanf(" %s", &nome_empresa);

    int indice_empresa = encontrar_empresa_nome(apt_ativar, &nome_empresa);

    if (indice_empresa != -1) {
        if (apt_ativar->empresas[indice_empresa].estado_e != ATIVO) {
            apt_ativar->empresas[indice_empresa].estado_e = ATIVO;
            printf("Empresa ativada com sucesso!");
        } else {
            printf("Esta empresa já está Ativo.");
        }
    } else {
        printf("Esta empresa não existe!");
    }
}

/**
 * Coloca o ramo de atividade no estado ativo 
 * @param apt_editar apontador para a struct RamosAtividade
 */
void ativar_ramo(RamosAtividade *apt_ativar) {
    int cod_ramo;

    printf("Insira o código do ramo de atividade: ");
    scanf("%d", &cod_ramo);

    int indice_ramo = verificar_codigo(apt_ativar, cod_ramo);

    if (indice_ramo != -1) {
        if (apt_ativar->ramos[indice_ramo].estado_r != ATIVO) {
            apt_ativar->ramos[indice_ramo].estado_r = ATIVO;
            printf("Ramo de atividade ativado com sucesso!");
        } else {
            printf("Este ramo de atividade já está Ativo.");
        }
    } else {
        printf("Este ramo de atividade não existe!");
    }
}

/**
 * Pesquisa e imprime a empresa através do nome
 * @param apt_pesquisar apontador para a struct Empresas
 */
void pesquisar_nome_empresa(Empresas *apt_pesquisar) {
    char nome_empresa[TAM_STRING];

    printf("Insira o nome da empresa: ");
    scanf(" %s", nome_empresa);

    for (int i = 0; i < apt_pesquisar->conta_empresas; i++) {
        if (strcmp(apt_pesquisar->empresas[i].nome_empresa, nome_empresa) == 0) {
            imprimir_empresa(&apt_pesquisar->empresas[i]);
        }
    }
}

/**
 * Pesquisa e imprime a/s empresa/s através da categoria
 * @param apt_pesquisar apontador para a struct Empresas
 */
void pesquisar_categoria_empresa(Empresas *apt_pesquisar) {
    char categoria_empresa[TAM_STRING];

    printf("Insira a categoria da empresa: ");
    scanf(" %s", categoria_empresa);

    for (int i = 0; i < apt_pesquisar->conta_empresas; i++) {
        if (strcmp(apt_pesquisar->empresas[i].categoria, categoria_empresa) == 0) {
            imprimir_empresa(&apt_pesquisar->empresas[i]);
        }
    }
}

/**
 * Pesquisa e imprime a/s empresa/s através da localidade
 * @param apt_pesquisar apontador para a struct Empresas
 */
void pesquisar_localidade_empresa(Empresas *apt_pesquisar) {
    char localidade_empresa[TAM_STRING];

    printf("Insira a categoria da empresa: ");
    scanf(" %s", localidade_empresa);

    for (int i = 0; i < apt_pesquisar->conta_empresas; i++) {
        if (strcmp(apt_pesquisar->empresas[i].localidade, localidade_empresa) == 0) {
            imprimir_empresa(&apt_pesquisar->empresas[i]);
        }
    }
}

/**
 * Função para encontrar a empresa com o maior número de comentários
 * @param apt_empresas apontador para a struct Empresas
 * @return o indice da empresa com mais comentários
 */
int encontrar_empresa_mais_comentarios(Empresas *apt_empresas) {
    int indice_maior_comentarios = -1;
    int max_comentarios = -1;

    for (int i = 0; i < apt_empresas->conta_empresas; i++) {
        if (apt_empresas->empresas[i].num_comentarios > max_comentarios) {
            max_comentarios = apt_empresas->empresas[i].num_comentarios;
            indice_maior_comentarios = i;
        }
    }

    return indice_maior_comentarios;
}
