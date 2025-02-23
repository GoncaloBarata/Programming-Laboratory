/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Utilizador
 *
 * Created on 27 de novembro de 2023, 15:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_empresas.h"
#include "gestao_ramos.h"
#include "utilizadores.h"
#include "funcionalidades.h"
#include "struct.h"
#include "input.h"

/*
 * 
 */
int main() {
    int i, opcao_ler = 0, opcao_MA = 0, opcao_GE = 0, opcao_GRA = 0, opcao_GR = 0, opcao_perfil = 0,
            opcao_ler_u = 0, opcao_MU = 0, opcao_MU1 = 0;

    Empresas *lista_empresas = inic_empresas();
    RamosAtividade *lista_ramos = inic_ramos();
    Utilizadores *lista_utilizadores = inic_utilizadores();

    printf("Pretende ler/gravar dados?\n");
    printf("1- Sim 2- Não\n");
    opcao_ler = validarInt(MSG_OBTER_OPCAO, 1, 2);
    printLinha();

    FILE *empresas;
    FILE *ramos;

    if (opcao_ler == 1) {

        ler_data_empresas(lista_empresas);
        ler_data_ramos(lista_ramos);
        ler_data_utilizadores(lista_utilizadores);
        ler_data_comentarios(lista_empresas);
    }

    printf("Escolha o seu perfil?\n");
    printf("1 - Administrador\n");
    printf("2 - Utilizador\n");
    opcao_perfil = validarInt(MSG_OBTER_OPCAO, 1, 2);

    if (opcao_perfil == 1) {
        do {
            printLinha();
            printf("Menu Administrador");
            printLinha();
            printf("1 - Gestão de Empresas");
            printf("\n2 - Gestão de Ramos de Atividades");
            printf("\n3 - Funcionalidades");
            printf("\n0 - Sair");
            printLinha();
            opcao_MA = validarInt(MSG_OBTER_OPCAO, 0, 3);

            switch (opcao_MA) {
                case 1:
                    do {
                        printLinha();
                        printf("Gestão de Empresas");
                        printLinha();
                        printf("1 - Criar Empresa");
                        printf("\n2 - Editar Empresa");
                        printf("\n3 - Remover Empresa");
                        printf("\n4 - Listar Empresas");
                        printf("\n0 - Voltar ao Menu Inicial");
                        printLinha();
                        opcao_GE = validarInt(MSG_OBTER_OPCAO, 0, 4);

                        switch (opcao_GE) {
                            case 1:
                                printLinha();
                                printf("Criar Empresa");
                                printLinha();
                                criar_empresa(lista_empresas, lista_ramos);
                                break;
                            case 2:
                                printLinha();
                                printf("Editar Empresa");
                                printLinha();
                                editar_empresas(lista_empresas);
                                break;
                            case 3:
                                printLinha();
                                printf("Remover Empresa");
                                printLinha();
                                remover_empresas(lista_empresas);
                                break;
                            case 4:
                                printLinha();
                                printf("Listar Empresas");
                                printLinha();
                                listar_empresas_ativos(lista_empresas);
                                break;
                        }
                    } while (opcao_GE != 0);
                    break;
                case 2:
                    do {
                        printLinha();
                        printf("Gestão de Ramos de Atividades");
                        printLinha();
                        printf("1 - Criar Ramo de Atividade");
                        printf("\n2 - Editar Ramo de Atividade");
                        printf("\n3 - Remover Ramo de Atividade");
                        printf("\n4 - Listar Ramos de Atividades");
                        printf("\n0 - Voltar ao Menu Inicial");
                        printLinha();
                        opcao_GRA = validarInt(MSG_OBTER_OPCAO, 0, 4);

                        switch (opcao_GRA) {
                            case 1:
                                printLinha();
                                printf("Criar Ramo de Atividade");
                                printLinha();
                                criar_ramo(lista_ramos);
                                break;
                            case 2:
                                printLinha();
                                printf("Editar Ramo de Atividade");
                                printLinha();
                                editar_ramos(lista_ramos);
                                break;
                            case 3:
                                printLinha();
                                printf("Remover Ramo de Atividade");
                                printLinha();
                                remover_ramos(lista_ramos, lista_empresas);
                                break;
                            case 4:
                                printLinha();
                                printf("Listar Ramos de Atividades");
                                printLinha();
                                listar_ramos_ativos(lista_ramos);
                                break;
                        }
                    } while (opcao_GRA != 0);
                    break;
                case 3:
                    do {
                        printLinha();
                        printf("Funcionalidades");
                        printLinha();
                        printf("1 - Ativar empresa");
                        printf("\n2 - Ativar ramo de atividade");
                        printf("\n3 - Listar comentários");
                        printf("\n4 - Eliminar comentários");
                        printf("\n5 - Ocultar comentários");
                        printf("\n6 - Empresa com mais comentários");
                        printf("\n7 - Listar empresas com ratings");
                        printf("\n0 - Voltar ao Menu Inicial");
                        printLinha();
                        opcao_GR = validarInt(MSG_OBTER_OPCAO, 0, 7);

                        switch (opcao_GR) {
                            case 1:
                                printLinha();
                                printf("Ativar empresa");
                                printLinha();
                                ativar_empresas(lista_empresas);
                                break;
                            case 2:
                                printLinha();
                                printf("Ativar ramo de atividade");
                                printLinha();
                                ativar_ramo(lista_ramos);
                                break;
                            case 3:
                                printLinha();
                                printf("Listar comentários");
                                printLinha();
                                listar_comentarios_empresas(lista_empresas);
                                break;
                            case 4:
                                printLinha();
                                printf("Eliminar comentários");
                                printLinha();
                                eliminar_comentario(lista_empresas);
                                break;
                            case 5:
                                printLinha();
                                printf("Ocultar comentários");
                                printLinha();
                                ocultar_comentario(lista_empresas);
                                break;
                            case 6:
                                printLinha();
                                printf("Empresa com mais comentários");
                                printLinha();
                                encontrar_empresa_mais_comentarios(lista_empresas);
                                break;
                            case 7:
                                printLinha();
                                printf("Listar empresas com ratings");
                                printLinha();
                                listar_empresas_com_ratings(lista_empresas);
                                break;
                        }
                    } while (opcao_GR != 0);
                    break;
            }
        } while (opcao_MA != 0);
    } else {
        printLinha();
        printf("Já tem conta?\n");
        printf("1- Sim 2- Não\n");
        opcao_ler_u = validarInt(MSG_OBTER_OPCAO, 1, 2);

        if (opcao_ler_u == 1) {
            char nome, senha;

            printf("\nDigite o nome de utilizador: ");
            scanf(" %s", &nome);

            printf("Digite a senha: ");
            scanf(" %s", &senha);
            autenticar_utilizador(lista_utilizadores, &nome, &senha);

            int indice_empresa = autenticar_utilizador(lista_utilizadores, &nome, &senha);

            if (indice_empresa != 0) {

                do {
                    printLinha();
                    printf("Menu Utilizador");
                    printLinha();
                    printf("1 - Pesquisar empresas por nome");
                    printf("\n2 - Pesquisar empresas por categoria");
                    printf("\n3 - Pesquisar empresas por localidade");
                    printf("\n4 - Classificar empresa");
                    printf("\n5 - Comentar empresa");
                    printf("\n0 - Voltar ao Menu Inicial");
                    printLinha();
                    opcao_MU = validarInt(MSG_OBTER_OPCAO, 0, 5);

                    switch (opcao_MU) {
                        case 1:
                            printLinha();
                            printf("Pesquisar empresas por nome");
                            printLinha();
                            pesquisar_nome_empresa(lista_empresas);
                            break;
                        case 2:
                            printLinha();
                            printf("Pesquisar empresas por categoria");
                            printLinha();
                            pesquisar_categoria_empresa(lista_empresas);
                            break;
                        case 3:
                            printLinha();
                            printf("Pesquisar empresas por localidade");
                            printLinha();
                            pesquisar_localidade_empresa(lista_empresas);
                            break;
                        case 4:
                            printLinha();
                            printf("Classificar empresa");
                            printLinha();
                            classificar_empresa(lista_empresas);
                            break;
                        case 5:
                            printLinha();
                            printf("Comentar empresa");
                            printLinha();

                            break;
                    }
                } while (opcao_MU != 0);
            } else {
                printf("Utilizador não encontrado!");
            }
        } else {
            do {
                printLinha();
                printf("Menu Utilizador");
                printLinha();
                printf("1 - Registar");
                printf("\n2 - Comentar empresa");
                printf("\n0 - Voltar ao Menu Inicial");
                printLinha();
                opcao_MU1 = validarInt(MSG_OBTER_OPCAO, 0, 2);

                switch (opcao_MU1) {
                    case 1:
                        printLinha();
                        printf("Registar");
                        printLinha();
                        registar_utilizador(lista_utilizadores);
                        break;
                    case 2:
                        printLinha();
                        printf("Comentar empresa");
                        printLinha();
                        comentar_empresa(lista_empresas);
                        break;
                }
            } while (opcao_MU1 != 0);
        }

        listar_comentarios_empresas(lista_empresas);

    }


    if (opcao_ler == 1) {

        empresas = fopen("empresas.txt", "w");

        for (i = 0; i < lista_empresas->conta_empresas; i++) {
            fprintf(empresas, "%d %s %s %s %s %s %d %d\n",
                    (lista_empresas->empresas[i].nif),
                    (lista_empresas->empresas[i].nome_empresa),
                    (lista_empresas->empresas[i].categoria),
                    (lista_empresas->empresas[i].rua),
                    (lista_empresas->empresas[i].localidade),
                    (lista_empresas->empresas[i].codigo_postal),
                    (lista_empresas->empresas[i].codigo_ramo),
                    (lista_empresas->empresas[i].estado_e));

        }

        fclose(empresas);


        ramos = fopen("ramos.txt", "w");

        for (i = 0; i < lista_ramos->conta_ramos; i++) {
            fprintf(ramos, "%d %s %d\n",
                    (lista_ramos->ramos[i].codigo_ramo),
                    (lista_ramos->ramos[i].nome_ramo),
                    (lista_ramos->ramos[i].estado_r));

        }
        fclose(ramos);

        guardar_comentarios(lista_empresas);

        guardar_utilizadores(lista_utilizadores);

    }

    for (int i = 0; i < lista_empresas->conta_empresas; i++) {
        free(lista_empresas->empresas[i].comentarios);
    }

    free(lista_empresas->empresas);
    free(lista_empresas);

    free(lista_ramos->ramos);
    free(lista_ramos);

    free(lista_utilizadores->utilizadores);
    free(lista_utilizadores);

    return 0;
}

