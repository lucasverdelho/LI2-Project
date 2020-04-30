/**
@file lista.h
Módulo de listas ligadas
*/
#ifndef ___LISTA_H___
#define ___LISTA_H___

/**
\brief Tipo de dados para Listas
*/
typedef struct nodo {
   void *valor;
   struct nodo *proximo;
} NODO, *LISTA;

/**
\brief Cria uma lista vazia
@returns A lista
*/
LISTA criar_lista();

/**
\brief Insere um valor na cabeça da lista
@param L Lista
@param valor Apontador para a cabeça da lista
@returns A lista
*/
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Devolve a cabeça da lista
@param L Lista
@returns A cabeça da lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
@param L Lista
@returns A cauda da lista
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Lista
@returns A cauda da lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Lista
@returns Verdadeiro (valor diferente de zero) se for estiver vazia e Falso (zero) caso contrário
*/
int lista_esta_vazia(LISTA L);

#endif
