#include <stdio.h>
#include "dados.h"
#include "interface.h"


int jogada_valida(ESTADO *e, COORDENADA c_jogada){
    COORDENADA c_atual = {e->ultima_jogada.linha,e->ultima_jogada.coluna};
    if(abs(c_jogada.linha-c_atual.linha) <= 1 && abs(c_jogada.coluna-c_atual.coluna) <= 1)
        return 1;
    return 0;
}


// Função que deve ser completada e colocada na camada da lógica do programa

// Modificar o estado ao jogar na casa correta se a jogada for válida.

ERROS jogar(ESTADO *e, COORDENADA c) {
    if(obter_estado_casa(e,c) == PRETA || obter_estado_casa(e,c) == BRANCA)
        return COORDENADA_INVALIDA;
    if (obter_jogador_atual(e) == 1 && jogada_valida(e,c))
        e->jogador_atual = 2;
    else if (obter_jogador_atual(e) == 2 && jogada_valida(e,c)){
        e->jogador_atual = 1;
        e->num_jogadas++;
    }
    else 
        return JOGADA_INVALIDA;
    if(obter_estado_casa(e,c) == UM || obter_estado_casa == DOIS)
        
    e->tab[c.linha][c.coluna] = BRANCA;
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
    return OK;
}

