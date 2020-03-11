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