<<<<<<< HEAD
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
=======
#include <stdio.h>
#include "dados.h"

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->jogadas = {{5,5},{5,5}};
    e->ultima_jogada = {0,0};
    e->tab[5][5] = '*';
    return e;
}

int obter_jogador_atual(ESTADO *estado){}
int obter_numero_de_jogadas(ESTADO *estado){}
int obter_estado_casa(ESTADO *e, COORDENADA c){}
>>>>>>> 820c42990d7fbb2579676b811ca3c3c7c803f0f3
