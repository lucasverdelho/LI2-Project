#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA criar_lista(){
    LISTA l = malloc(sizeof(NODO));
    l->valor = NULL;
    l->proximo = NULL;
    return l;
}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA r = malloc(sizeof(NODO));
    r->valor = valor;
    r->proximo = L;
    return r;
}

void *devolve_cabeca(LISTA L){
    return (L->valor);
}

LISTA proximo(LISTA L){
    LISTA r = L->proximo;
    return r;
}

LISTA remove_cabeca(LISTA L){
  LISTA r = L->proximo;
  free(L);
  return r;
}

int lista_esta_vazia(LISTA L){
  if(L->valor == NULL)
    return 1;
  return 0;
}