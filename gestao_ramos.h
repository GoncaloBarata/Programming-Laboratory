/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   gestao_ramos.h
 * Author: Utilizador
 *
 * Created on 30 de novembro de 2023, 17:38
 */

#include "struct.h"

#ifndef GESTAO_RAMOS_H
#define GESTAO_RAMOS_H

int verificar_codigo(RamosAtividade *apt_verificar, int codigo);
int criar_ramo(RamosAtividade *apt_ramo);
void ler_data_ramos(RamosAtividade *array_ramos);
RamosAtividade *inic_ramos();
void remover_ramos(RamosAtividade *r_ramos, Empresas *apt_empresas);
void editar_ramos(RamosAtividade *apt_editar);
void listar_ramos_ativos(RamosAtividade *listar);

#endif /* GESTAO_RAMOS_H */

