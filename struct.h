/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   struct.h
 * Author: Utilizador
 *
 * Created on 27 de novembro de 2023, 15:30
 */

#define TAM_STRING 100
#define EMPRESAS_TAM_INICIAL 10
#define MIN_NIF 100000000
#define MAX_NIF 999999999
#define RAMOS_TAM_INICIAL 2
#define UTILIZADORES_TAM_INICIAL 10
#define TAM_INICIAL_COMENTARIOS 10

#ifndef STRUCT_H
#define STRUCT_H

typedef enum estado {
    ATIVO, INATIVO, OCULTO
} estado;

typedef struct {
    char nome_utilizador[TAM_STRING];
    char titulo[TAM_STRING];
    char texto[TAM_STRING];
    char email[TAM_STRING];
    estado estado_c;
} Comentario;

typedef struct {
    int nif;
    char nome_empresa[TAM_STRING];
    char categoria[TAM_STRING];
    char rua[TAM_STRING];
    char localidade[TAM_STRING];
    char codigo_postal[TAM_STRING];
    int codigo_ramo;
    int total_rating;
    int num_ratings;
    Comentario *comentarios; //ponteiro para uma lista dinâmica de comentários
    int num_comentarios;
    int max_comentarios;
    estado estado_e;
} Empresa;

typedef struct {
    int conta_empresas;
    int max_empresas;
    Empresa *empresas;
} Empresas;

typedef struct {
    int codigo_ramo;
    char nome_ramo[TAM_STRING];
    estado estado_r;
} RamoAtividade;

typedef struct {
    int conta_ramos;
    int max_ramos;
    RamoAtividade *ramos;
} RamosAtividade;

typedef struct {
    char nome_utilizador[TAM_STRING];
    char email[TAM_STRING];
    char senha[TAM_STRING];
} Utilizador;

typedef struct {
    int conta_utilizadores;
    int max_utilizadores;
    Utilizador *utilizadores;
} Utilizadores;

#endif /* STRUCT_H */

