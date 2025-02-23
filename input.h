/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   input.h
 * Author: Utilizador
 *
 * Created on 27 de novembro de 2023, 15:58
 */

#ifndef INPUT_H
#define INPUT_H

#define MSG_OBTER_OPCAO "Insira a opção: "

int validarInt(char * txt, int Val_min, int Val_max);
int obterInt(int minValor, int maxValor, char *msg);
float obterFloat(float minValor, float maxValor, char *msg);    
void lerString(char *string, unsigned int tamanho, char *msg);
void printLinha();


#endif /* INPUT_H */

