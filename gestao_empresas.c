/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_empresas.h"
#include "gestao_ramos.h"
#include "input.h"

/**
 * Verifica o nif da empresa 
 * @param apt_verificar apondador para a struct Empresas
 * @param nif_empresa recebe o nif a verificar
 * @return a posição da empresa caso exista ou -1 caso não exista
 */
int verificar_nif(Empresas *apt_verificar, int nif_empresa) {
    int i;

    for (i = 0; i < apt_verificar->conta_empresas; i++) {
        if (apt_verificar->empresas[i].nif == nif_empresa) {
            return i;
        }
    }
    return -1; // NÃO EXISTE (O nif não está associado)  
}

/**
 * Cria uma empresa
 * @param apt_empresa apontador para a struct Empresas
 * @param apt_ramos apontador para a struct RamosAtividade
 * @return número de empresas atualizado
 */
int criar_empresa(Empresas *apt_empresa, RamosAtividade *apt_ramos) {

    int nif, indice_n, codigo_r, indice_r;

    nif = obterInt(MIN_NIF, MAX_NIF, "Insira o nif da empresa: ");
    indice_n = verificar_nif(apt_empresa, nif);

    if (apt_ramos->conta_ramos != 0) {
        codigo_r = obterInt(0, 9999, "Insira o código do ramo de atividade: ");
        indice_r = verificar_codigo(apt_ramos, codigo_r);
    } else {
        printf("Não existe ramos de atividades!\n");
    }

    if (indice_n == -1) {
        if (indice_r != -1) {
            Empresa empresa;

            if (apt_empresa->conta_empresas == apt_empresa->max_empresas) {
                apt_empresa->max_empresas <<= 1; // multiplica o numero por dois
                apt_empresa->empresas = realloc(apt_empresa->empresas, sizeof (Empresa) * apt_empresa->max_empresas);
            }

            empresa.nif = nif;
            empresa.codigo_ramo = codigo_r;

            lerString(empresa.nome_empresa, TAM_STRING, "Insira o nome da empresa: ");
            lerString(empresa.categoria, TAM_STRING, "Insira a categoria da empresa: ");
            lerString(empresa.rua, TAM_STRING, "Insira a rua da empresa: ");
            lerString(empresa.localidade, TAM_STRING, "Insira a localidade da empresa: ");
            lerString(empresa.codigo_postal, TAM_STRING, "Insira o código postal da empresa: ");

            empresa.estado_e = ATIVO;
            empresa.total_rating = 0;
            empresa.num_ratings = 0;
            
            empresa.num_comentarios = 0;
            empresa.max_comentarios = TAM_INICIAL_COMENTARIOS;
            empresa.comentarios = malloc(sizeof(Comentario) * empresa.max_comentarios);
            
            if (empresa.comentarios == NULL) {
                perror("Erro a alocar memória para comentários!");
                return -1;
            }

            apt_empresa->empresas[apt_empresa->conta_empresas] = empresa;

            return apt_empresa->conta_empresas++;
        } else {
            printf("Este ramo de atividade não existe!\n");
        }
    } else {
        printf("Esta empresa já existe!\n");
    }

    return -1;
}

/**
 * Lê os dados guardados em "empresas.txt"
 * @param array_empresas apontador para a struct Empresas
 */
void ler_data_empresas(Empresas *array_empresas) {
    FILE *empresas = fopen("empresas.txt", "r");

    if (empresas != NULL) {
        while (fscanf(empresas, "%d %s %s %s %s %s %d %d\n",
                &(array_empresas->empresas[array_empresas->conta_empresas].nif),
                (array_empresas->empresas[array_empresas->conta_empresas].nome_empresa),
                (array_empresas->empresas[array_empresas->conta_empresas].categoria),
                (array_empresas->empresas[array_empresas->conta_empresas].rua),
                (array_empresas->empresas[array_empresas->conta_empresas].localidade),
                (array_empresas->empresas[array_empresas->conta_empresas].codigo_postal),
                &(array_empresas->empresas[array_empresas->conta_empresas].codigo_ramo),
                &(array_empresas->empresas[array_empresas->conta_empresas].estado_e)) != EOF) {

            array_empresas->conta_empresas++;
        }
        fclose(empresas);
    }
}

/**
 * Aloca memória para as Empresas
 * @return array_empresas
 */
Empresas *inic_empresas() {
    Empresas *array_empresas;
    array_empresas = (Empresas *) malloc(sizeof (Empresas));
    if (array_empresas == NULL) {
        perror("Erro a alocar memória para vendedores!"); // perror faz printf e exit
    }
    array_empresas->max_empresas = EMPRESAS_TAM_INICIAL;
    array_empresas->conta_empresas = 0;
    
    array_empresas->empresas = (Empresa *) malloc(sizeof (Empresa) * array_empresas->max_empresas);
    if (array_empresas->empresas == NULL) {
        perror("Erro a alocar memória para vendedores!"); // perror faz printf e exit
    }

    return array_empresas;

}

/**
 * Edita a empresa
 * @param apt_editar apontador para a struct Empresa
 */
void editar_empresa(Empresa *apt_editar) {
    lerString(apt_editar->nome_empresa, TAM_STRING, "Insira o novo nome da empresa: ");
    lerString(apt_editar->categoria, TAM_STRING, "Insira a nova categoria da empresa: ");
    lerString(apt_editar->rua, TAM_STRING, "Insira a nova rua da empresa: ");
    lerString(apt_editar->localidade, TAM_STRING, "Insira a nova localidade da empresa: ");
    lerString(apt_editar->codigo_postal, TAM_STRING, "Insira o novo código postal da empresa: ");
}

/**
 * Edita a empresa caso ela exista
 * @param apt_editar apontador para a struct Empresas
 */
void editar_empresas(Empresas *apt_editar) {
    int nif;

    nif = verificar_nif(apt_editar, obterInt(MIN_NIF, MAX_NIF, "Insira o nif da empresa: "));

    if (nif != -1) {
        editar_empresa(&apt_editar->empresas[nif]);
    } else {
        printf("Esta empresa não existe!\n");
    }
}

/**
 * Função que mete as variáveis nulas
 * @param empresa apontador para a struct Empresa
 */
void apagar_dados_empresa(Empresa *empresa) {
    empresa->nif = 0;
    strcpy(empresa->nome_empresa, "");
    strcpy(empresa->categoria, "");
    strcpy(empresa->rua, "");
    strcpy(empresa->localidade, "");
    strcpy(empresa->codigo_postal, "");
}

/**
 * Função que revome a empresa
 * @param r_empresas apontador para a struct Empresas
 */
void remover_empresas(Empresas *r_empresas) {
    int numero, nif, i;

    nif = obterInt(MIN_NIF, MAX_NIF, "Insira o nif da empresa: ");
    numero = verificar_nif(r_empresas, nif);

    if (numero != -1) {

        for (i = numero; i < r_empresas->conta_empresas - 1; i++) {
            r_empresas->empresas[i] = r_empresas->empresas[i + 1];
        }
        apagar_dados_empresa(&r_empresas->empresas[i]);
        r_empresas->conta_empresas--;
        printf("Empresa removida com sucesso!");

    } else {
        printf("Esta empresa não existe!\n");
    }
}

/**
 * Imprime a empresa
 * @param apt_imprimir apontador para a struct Empresa
 */
void imprimir_empresa(Empresa *apt_imprimir) {
    char *estado;
    if (apt_imprimir->estado_e == INATIVO)
        estado = "Inativo";
    else
        estado = "Ativo";

    printf("\n%d %s %s %s %s %s %s", apt_imprimir->nif, apt_imprimir->nome_empresa,
            apt_imprimir->categoria, apt_imprimir->rua, apt_imprimir->localidade, apt_imprimir->codigo_postal, estado);
}

/**
 * Faz uma listagem das empresas ativas
 * @param listar apontador para a struct Empresas
 */
void listar_empresas_ativos(Empresas *listar) {
    if (listar->conta_empresas > 0) {
        for (int i = 0; i < listar->conta_empresas; i++) {
            char *estado;
            if (listar->empresas[i].estado_e == ATIVO) {
                estado = "Ativo";

                printf("%d %s %d %s\n", listar->empresas[i].nif, listar->empresas[i].nome_empresa, listar->empresas[i].codigo_ramo, estado);
            }
        }
    } else {
        printf("Sem empresas ativas!\n");
    }
}