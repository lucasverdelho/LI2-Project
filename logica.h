/**
@file logica.h
Lógica do progama
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___
#include "lista.h"
/**
\brief Função que verifica se uma jogada é válida
Esta funcão verifica se a coordenada introduzida é vizinha da peça branca.
@param e Apontador para o estado
@param c_jogada A coordenada da jogada
@returns Verdadeiro (valor diferente de zero) se for válida e Falso (zero) se não for
*/
int jogada_valida(ESTADO *e, COORDENADA c_jogada);

/**
\brief Função que verifica as casas livres 
@param e Apontador para o estado
@returns OK se houver casas disponíveis e JOGADA_INVALIDA caso contrário
*/
ERROS casas_livres(ESTADO *e);

/**
\brief Função que modifica o estado ao jogar na casa correta se a jogada for válida
@param e Apontador para o estado
@param c A coordenada
@param vence_j1 Apontador para o jogador 1 vencedor
@param vence_j2 Apontador para o jogador 2 vencedor
@returns OK se a jogada for válida e JOGADA_INVALIDA caso contrário
*/
ERROS jogar(ESTADO *e, COORDENADA c,int *vence_j1, int *vence_j2);

/**
\brief Função que calcula a distância entre duas coordenadas 
@param c1 Primeira coordenada
@param c2 Segunda coordenada
@returns A distância
*/
double distancia(COORDENADA c1, COORDENADA c2);

/**
\brief Função que calcula a melhor coordenada 
Função que calcula as distâncias das coordenadas para a casa vencedora e devolve a coordenada que se encontra em melhor posição.
@param casas_livres Lista com as casas livres
@param jogador Número do jogador
@returns A coordenada
*/
COORDENADA coord_jog(LISTA casas_livres, int jogador);

/**
\brief Função que cria uma lista com as posições das coordenadas livres
@param e Apontador para o estado
@param dim Apontador para a dimensão 
@returns A lista
*/
LISTA lista_livres(ESTADO *e,int *dim);

#endif