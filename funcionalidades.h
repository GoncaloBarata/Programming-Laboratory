/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   funcionalidades.h
 * Author: Utilizador
 *
 * Created on 11 de janeiro de 2024, 18:54
 */

#include "struct.h"

#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

void listar_comentarios_empresas(Empresas *empresas);
void eliminar_comentario(Empresas *lista_empresas);
void ocultar_comentario(Empresas *lista_empresas);
void ativar_empresas(Empresas *apt_ativar);
void ativar_ramo(RamosAtividade *apt_ativar);
void pesquisar_nome_empresa (Empresas *apt_pesquisar);
void pesquisar_categoria_empresa (Empresas *apt_pesquisar);
void pesquisar_localidade_empresa (Empresas *apt_pesquisar);
int encontrar_empresa_mais_comentarios(Empresas *apt_empresas);

#endif /* FUNCIONALIDADES_H */

