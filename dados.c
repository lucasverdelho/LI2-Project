#include <stdio.h>
#include "dados.h"

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->jogadas = {};
    e->ultima_jogada = {0,0};
    e->tab[4][4] = BRANCA;
    return e;
}

int obter_jogador_atual(ESTADO *estado){
    int k;
    k = estado -> jogador_atual;
    return k;
}

int obter_numero_de_jogadas(ESTADO *estado){
    int k;
    k = estado -> num_jogadas;
    return k;
}

int obter_estado_casa(ESTADO *e, COORDENADA c){

}
