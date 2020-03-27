/**
@file interface.h
Interpretador de comandos e mostra Tabuleiro
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

/**
\brief Função que devolve o erro correspondente
@param erro Erro possível
*/
void print_erro(ERROS erro);

/**
\brief Função que devolve o tabuleiro
@param f Apontador para o ficheiro
@param e Apontador para o estado
*/
void mostrar_tabuleiro(FILE *f,ESTADO *e);

/**
\brief Função que grava o tabuleiro e os movimentos
@param e Apontador para o estado
@param filename Apontador para o nome do ficheiro
@returns ERRO_GRAVAR_FICHEIRO se o ficheiro não existir e OK se estiver tudo em ordem
*/
ERROS gravar(ESTADO *e, char *filename);

/**
\brief Função que grava o tabuleiro e os movimentos
@param e Apontador para o estado
@param f Apontador para o ficheiro
@returns ERRO_LER_TAB se o formato do ficheiro estiver mal configurado e OK e se estiver tudo em ordem
*/
ERROS ler_tabuleiro(ESTADO *e,FILE *f);

/**
\brief Função que grava o tabuleiro e os movimentos
@param e Apontador para o estado
@param filename Apontador para o nome do ficheiro
@returns ERRO_LER_TAB se o ficheiro não exitir e OK e se estiver tudo em ordem
*/
ERROS ler(ESTADO *e, char *filename);

/**
\brief Função que interpreta os comandos
@param e Apontador para o estado
*/
int interpretador(ESTADO *e);

#endif
