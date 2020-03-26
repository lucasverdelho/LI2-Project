/**
@file logica.h
Lógica do progama
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

/**
\brief Função que verifica se uma jogada é válida
@param e Apontador para o estado
@param c_jogada A coordenada da jogada
@returns Verdadeiro (valor diferente de zero) se for válida e Falso (zero) se não for
*/
int jogada_valida(ESTADO *e, COORDENADA c_jogada);

/**
\brief Função que modifica o estado ao jogar na casa correta se a jogada for válida
@param e Apontador para o estado
@param c A coordenada
@returns Verdadeiro (valor diferente de zero) se for possível jogar e Falso (zero) caso não seja possível
*/
int jogar(ESTADO *e, COORDENADA c, int *vencedor_1, int *vencedor_2);


#endif