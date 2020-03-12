#include <stdio.h>
#include "dados.h"

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    COORDENADA j1 = {3,4};
    COORDENADA j2 = {4,4};
    JOGADA jogada1 = {j1,j2};
    e->jogadas[0] = jogada1;
    for (int linha = 0; linha < 8; linha++)
    {
        for (int coluna = 0; coluna < 8; coluna++)
        {
            if (linha == 3 && coluna == 4) 
                e->tab[coluna][linha] = BRANCA;
            e->tab[coluna][linha] = VAZIO;
        }
    }
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
