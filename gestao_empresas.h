/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   gestao_empresas.h
 * Author: Utilizador
 *
 * Created on 27 de novembro de 2023, 15:58
 */

#include "struct.h"

#ifndef GESTAO_EMPRESAS_H
#define GESTAO_EMPRESAS_H

int verificar_nif(Empresas *apt_verificar, int nif_empresa);
int criar_empresa(Empresas *apt_empresa, RamosAtividade *apt_ramos);
void ler_data_empresas(Empresas *array_empresas);
Empresas *inic_empresas();
void editar_empresas(Empresas *apt_editar);
void remover_empresas(Empresas *r_empresas);
void imprimir_empresa(Empresa *apt_imprimir);
void listar_empresas_ativos(Empresas *listar);

#endif /* GESTAO_EMPRESAS_H */

