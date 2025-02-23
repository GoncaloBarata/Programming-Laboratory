/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilizadores.h"
#include "gestao_empresas.h"
#include "input.h"

/**
 * Verifica o nome da empresa 
 * @param apt_empresas apondador para a struct Empresas
 * @param nome_empresa recebe o nome a verificar
 * @return a posição da empresa caso exista ou -1 caso não exista
 */
int encontrar_empresa_nome(Empresas *apt_empresas, char *nome_empresa) {
    for (int i = 0; i < apt_empresas->conta_empresas; i++) {
        if (strcmp(apt_empresas->empresas[i].nome_empresa, nome_empresa) == 0) {
            return i; // Found the company with the specified name
        }
    }
    return -1; // NÃO EXISTE (O nome não está associado)
}

/**
 * Classifica uma empresa
 * @param apt_empresas apondador para a struct Empresas
 */
void classificar_empresa(Empresas *apt_empresas) {
    char nome_empresa;

    printf("Insira o nome da empresa: ");
    scanf(" %s", &nome_empresa);

    int indice_empresa = encontrar_empresa_nome(apt_empresas, &nome_empresa);

    if (indice_empresa != -1) {

        int rating = obterInt(0, 5, "Insira a classificação (de 0 a 5): ");

        if (rating >= 0 && rating <= 5) {
            apt_empresas->empresas[indice_empresa].total_rating += rating;
            apt_empresas->empresas[indice_empresa].num_ratings++;
            printf("Empresa classificada com sucesso!\n");
        } else {
            printf("Classificação inválida! A classificação deve ser um valor entre 0 e 5.\n");
        }
    } else {
        printf("Empresa não encontrada!\n");
    }
}

/**
 * Lista o nome das empresas e o seu respetivo rating
 * @param apt_empresas apondador para a struct Empresas
 */
void listar_empresas_com_ratings(Empresas *apt_empresas) {

    for (int i = 0; i < apt_empresas->conta_empresas; i++) {

        printf("Empresa: %s\n", apt_empresas->empresas[i].nome_empresa);

        if (apt_empresas->empresas[i].num_ratings > 0) {
            double average_rating = (double) apt_empresas->empresas[i].total_rating / apt_empresas->empresas[i].num_ratings;
            printf("Classificação Média: %.2f\n", average_rating);
        } else {
            printf("Esta empresa ainda não foi classificada.\n");
        }

        printf("\n");
    }
}

/**
 * Cria um utilizador
 * @param apt_utilizador apontador para a struct Utilizadores
 * @return número de utilizadores atualizado
 */
int registar_utilizador(Utilizadores *apt_utilizador) {
    char nome_utilizador[TAM_STRING];
    char email[TAM_STRING];
    char senha[TAM_STRING];

    Utilizador utilizador;

    if (apt_utilizador->conta_utilizadores == apt_utilizador->max_utilizadores) {
        apt_utilizador->max_utilizadores <<= 1; // multiplica o numero por dois
        apt_utilizador->utilizadores = realloc(apt_utilizador->utilizadores, sizeof (Utilizador) * apt_utilizador->max_utilizadores);
    }

    printf("Insira o nome de utilizador: ");
    scanf(" %[^\n]s", nome_utilizador);
    strcpy(utilizador.nome_utilizador, nome_utilizador);

    printf("Insira o seu email: ");
    scanf(" %[^\n]s", email);
    strcpy(utilizador.email, email);

    printf("Insira o titulo do comentario: ");
    scanf(" %[^\n]s", senha);
    strcpy(utilizador.senha, senha);

    apt_utilizador->utilizadores[apt_utilizador->conta_utilizadores] = utilizador;


    return apt_utilizador->conta_utilizadores++;
}

/**
 * Autentica um utilizador
 * @param lista_utilizadores apontador para a struct Utilizadores
 * @param nome recebe o nome para a autenticação
 * @param senha recebe a senha para a autenticação
 * @return a posição do utilizador caso exista ou -1 caso não exista
 */
int autenticar_utilizador(Utilizadores *lista_utilizadores, char *nome, char *senha) {

    for (int i = 0; i < lista_utilizadores->conta_utilizadores; i++) {
        if (strcmp(lista_utilizadores->utilizadores[i].nome_utilizador, nome) == 0 &&
                strcmp(lista_utilizadores->utilizadores[i].senha, senha) == 0) {
            return i; // Autenticação bem-sucedida
        }
    }
    return -1; // Autenticação falhou
}

/**
 * Guarda a informação relacionada com um utilizador em "utilizadores.txt"
 * @param apt_utilizador apontador para a struct Utilizadores
 */
void guardar_utilizadores(Utilizadores *apt_utilizador) {
    FILE *arquivo = fopen("utilizadores.txt", "w");

    if (arquivo != NULL) {
        for (int i = 0; i < apt_utilizador->conta_utilizadores; i++) {
            fprintf(arquivo, "%s %s %s\n",
                    apt_utilizador->utilizadores[i].nome_utilizador,
                    apt_utilizador->utilizadores[i].email,
                    apt_utilizador->utilizadores[i].senha);
        }

        fclose(arquivo);
    }
}

/**
 * Lê os dados guardados em "utilizadores.txt"
 * @param apt_utilizador apontador para a struct Utilizadores
 */
void ler_data_utilizadores(Utilizadores *apt_utilizador) {
    FILE *arquivo = fopen("utilizadores.txt", "r");

    if (arquivo != NULL) {
        while (fscanf(arquivo, "%s %s %s\n",
                (apt_utilizador->utilizadores[apt_utilizador->conta_utilizadores].nome_utilizador),
                (apt_utilizador->utilizadores[apt_utilizador->conta_utilizadores].email),
                (apt_utilizador->utilizadores[apt_utilizador->conta_utilizadores].senha)) != EOF) {

            apt_utilizador->conta_utilizadores++;
        }
        fclose(arquivo);
    }
}

/**
 * Aloca memória para os utilizadores
 * @return array_utilizadores
 */
Utilizadores *inic_utilizadores() {
    Utilizadores *array_utilizadores;
    array_utilizadores = (Utilizadores *) malloc(sizeof (Utilizadores));
    if (array_utilizadores == NULL) {
        perror("Erro a alocar memória para utilizadores!"); // perror faz printf e exit
    }
    array_utilizadores->max_utilizadores = UTILIZADORES_TAM_INICIAL;
    array_utilizadores->conta_utilizadores = 0;

    array_utilizadores->utilizadores = (Utilizador *) malloc(sizeof (Utilizador) * array_utilizadores->max_utilizadores);
    if (array_utilizadores->utilizadores == NULL) {
        perror("Erro a alocar memória para utilizadores!"); // perror faz printf e exit
    }

    return array_utilizadores;
}

/**
 * Permite ao utilizador comentar uma empresa
 * @param lista_empresas apontador para a struct Empresas
 */
void comentar_empresa(Empresas *lista_empresas) {
    char nome_empresa;
    char nome_utilizador[TAM_STRING];
    char titulo[TAM_STRING];
    char texto[TAM_STRING];
    char email[TAM_STRING];

    printf("Insira o nome da empresa que deseja comentar: ");
    scanf(" %s", &nome_empresa);

    int indice_empresa = encontrar_empresa_nome(lista_empresas, &nome_empresa);

    if (indice_empresa != -1) {
        // Verifica se a empresa está ativa
        if (lista_empresas->empresas[indice_empresa].estado_e == ATIVO) {
            Comentario comentario;

            if (lista_empresas->empresas[indice_empresa].num_comentarios == lista_empresas->empresas[indice_empresa].max_comentarios) {
                lista_empresas->empresas[indice_empresa].max_comentarios *= 2;
                lista_empresas->empresas[indice_empresa].comentarios = realloc(
                        lista_empresas->empresas[indice_empresa].comentarios,
                        sizeof (Comentario) * lista_empresas->empresas[indice_empresa].max_comentarios);
            }

            printf("Insira o nome de utilizador: ");
            scanf(" %[^\n]s", nome_utilizador);
            strcpy(comentario.nome_utilizador, nome_utilizador);

            printf("Insira o seu email: ");
            scanf(" %[^\n]s", email);
            strcpy(comentario.email, email);

            printf("Insira o titulo do comentario: ");
            scanf(" %[^\n]s", titulo);
            strcpy(comentario.titulo, titulo);

            printf("Insira o texto do comentario: ");
            scanf(" %[^\n]s", texto);
            strcpy(comentario.texto, texto);

            comentario.estado_c = ATIVO;

            lista_empresas->empresas[indice_empresa].comentarios[lista_empresas->empresas[indice_empresa].num_comentarios] = comentario;
            printf("Comentário adicionado com sucesso.\n");

            lista_empresas->empresas[indice_empresa].num_comentarios++;
        } else {
            printf("A empresa está inativa. Não é possível comentar.\n");
        }
    } else {
        printf("Empresa não encontrada.\n");
    }
}

/**
 * Guarda a informação relacionada com um comentario em "comentarios.txt"
 * @param lista_empresas apontador para a struct Empresas
 */
void guardar_comentarios(Empresas *lista_empresas) {
    FILE *comentarios_file = fopen("comentarios.txt", "w");

    if (comentarios_file == NULL) {
        printf("Erro ao abrir o ficheiro de comentários para escrita.\n");
        return;
    }

    for (int i = 0; i < lista_empresas->conta_empresas; i++) {
        if (lista_empresas->empresas[i].num_comentarios > 0) {
            fprintf(comentarios_file, "%s %d\n", lista_empresas->empresas[i].nome_empresa, lista_empresas->empresas[i].num_comentarios);

            for (int j = 0; j < lista_empresas->empresas[i].num_comentarios; j++) {
                fprintf(comentarios_file, "%s %s %s %s\n",
                        lista_empresas->empresas[i].comentarios[j].nome_utilizador,
                        lista_empresas->empresas[i].comentarios[j].email,
                        lista_empresas->empresas[i].comentarios[j].titulo,
                        lista_empresas->empresas[i].comentarios[j].texto);
            }
        }
    }

    fclose(comentarios_file);
}

/**
 * Lê os dados guardados em "comentarios.txt"
 * @param lista_empresas apontador para a struct Empresas
 */
void ler_data_comentarios(Empresas * lista_empresas) {
    FILE *arquivo = fopen("comentarios.txt", "r");

    if (arquivo != NULL) {
        for (int i = 0; i < lista_empresas->conta_empresas; i++) {
            fscanf(arquivo, "%s %d", lista_empresas->empresas[i].nome_empresa, lista_empresas->empresas[i].num_comentarios);

            for (int j = 0; j < lista_empresas->empresas[i].num_comentarios; j++) {
                fscanf(arquivo, "%s %s %s %s", lista_empresas->empresas[i].comentarios[j].nome_utilizador,
                        lista_empresas->empresas[i].comentarios[j].email,
                        lista_empresas->empresas[i].comentarios[j].titulo,
                        lista_empresas->empresas[i].comentarios[j].texto);
            }
        }

        fclose(arquivo);
    }
}
