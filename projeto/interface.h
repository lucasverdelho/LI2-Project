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
\brief Função que permite o utilizador aceder a uma jogada anterior
@param e Apontador para o estado
@param jogada Número da jogada
@param n_jog Número de jogadas
@returns POSICAO_INVALIDA se a posição introduzida for inválida e OK se estiver tudo em ordem
*/
ERROS pos(ESTADO *e, int jogada, int n_jog);

/**
\brief Função que permite ao jogador atual peça ao jogador para jogar por si
Nesta função usamos a eurística da distância menor usando a distância Euclidiana.
@param e Apontador para o estado
@param vencedor_j1 Apontador para o jogador vencedor 1
@param vencedor_j2 Apontador para o jogador vencedor 2 
*/
void jog(ESTADO *e,int *vencedor_j1,int *vencedor_j2);

/**
\brief Função que permite ao jogador atual peça ao jogador para jogar por si
Nesta função usamos a eurística da escolha aleatória.
@param e Apontador para o estado
@param vencedor_j1 Apontador para o jogador vencedor 1
@param vencedor_j2 Apontador para o jogador vencedor 2 
*/
void jog2(ESTADO *e,int *vencedor_j1,int *vencedor_j2);

/**
\brief Função que interpreta os comandos
@param e Apontador para o estado
@returns Quando o jogo acabar
*/
int interpretador(ESTADO *e);

#endif
