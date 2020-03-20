/**
@file interface.h
Interpretador de comandos e mostra Tabuleiro
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

/**
\brief Função que devolve o tabuleiro
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Função que devolve o erro correspondente
*/
void print_erro(ERROS e);

/**
\brief Função que interpreta os comandos
*/
int interpretador(ESTADO *e);

#endif
