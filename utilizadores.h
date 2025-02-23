/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   utilizadores.h
 * Author: Utilizador
 *
 * Created on 4 de dezembro de 2023, 18:26
 */

#include "struct.h"

#ifndef UTILIZADORES_H
#define UTILIZADORES_H

void classificar_empresa(Empresas *apt_empresas);
void listar_empresas_com_ratings(Empresas *apt_empresas);
int registar_utilizador(Utilizadores *apt_utilizador);
int autenticar_utilizador(Utilizadores *lista_utilizadores, char *nome, char *senha);
void guardar_utilizadores(Utilizadores *apt_utilizador);
void ler_data_utilizadores(Utilizadores *apt_utilizador);
Utilizadores *inic_utilizadores();
void comentar_empresa(Empresas *lista_empresas);
void guardar_comentarios(Empresas *lista_empresas);
void ler_data_comentarios(Empresas *lista_empresas);

#endif /* UTILIZADORES_H */

