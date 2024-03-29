#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_comando = 0;
    COORDENADA j1 = {3,4};
    COORDENADA j2 = {4,4};
    JOGADA jogada0 = {j1,j2};
    e->jogadas[0] = jogada0;
    e->ultima_jogada = j2;
    for (int linha = 0; linha < 8; linha++){
        for (int coluna = 0; coluna < 8; coluna++){
            if (linha == 3 && coluna == 4) 
                e->tab[linha][coluna] = BRANCA;
            else if (linha == 0 && coluna == 7)
                e->tab[linha][coluna] = DOIS;
            else if (linha == 7 && coluna == 0)
                e->tab[linha][coluna] = UM;
            else e->tab[linha][coluna] = VAZIO;
        }
    }
    return e;
}

int obter_num_comando(ESTADO *e)
{
    return e->num_comando;
}


int obter_jogador_atual(ESTADO *e){
    return e->jogador_atual;
}

int obter_num_jogadas(ESTADO *e){
    return e->num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int linha, coluna;
    linha = c.linha;
    coluna = c.coluna;
    CASA e_casa = e->tab[linha][coluna];
    return e_casa;
}

COORDENADA obter_ultima_jogada(ESTADO *e)
{
    return e->ultima_jogada;
}

JOGADA obter_jogada(ESTADO *e, int indice){
    return e->jogadas[indice];
}

void set_casa(ESTADO *e, COORDENADA c, CASA valor){
    e->tab[c.linha][c.coluna] = valor;
}

void add_num_comando(ESTADO *e){
    e->num_comando++;
}

void add_num_jogadas(ESTADO *e){
    e->num_jogadas++;
}

void mudar_ultima_jogada(ESTADO *e, COORDENADA c){
    e->ultima_jogada = c;
}

void mudar_jogador_atual(ESTADO *e, int jogador){
    e->jogador_atual = jogador;
}

void mudar_num_jogadas(ESTADO *e, int jogada){
    e->num_jogadas = jogada;
}

void mudar_tabuleiro(ESTADO *e){
    for (int linha = 0; linha < 8; linha++){
        for (int coluna = 0; coluna < 8; coluna++){
            if (linha == 3 && coluna == 4) 
                e->tab[linha][coluna] = BRANCA;
            else if (linha == 0 && coluna == 7)
                e->tab[linha][coluna] = DOIS;
            else if (linha == 7 && coluna == 0)
                e->tab[linha][coluna] = UM;
            else e->tab[linha][coluna] = VAZIO;
        }
    }
    for(int i = 0; i < obter_num_jogadas(e); i++){
        e->tab[7-e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
        e->tab[7-e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = PRETA;
    }
    if(obter_num_jogadas(e) > 0){
        e->tab[3][4] = PRETA;
        e->tab[7-e->jogadas[obter_num_jogadas(e)-1].jogador2.linha][e->jogadas[obter_num_jogadas(e)-1].jogador2.coluna] = BRANCA;
    }
}

void atualizar_jogada(ESTADO *e,COORDENADA c){
    if(obter_jogador_atual(e) == 1)
    {
        e->jogadas[obter_num_jogadas(e)].jogador1 = c;
        e->jogador_atual = 2;
    }
    else
    { 
        e->jogadas[obter_num_jogadas(e)].jogador2 = c;
        e->jogador_atual = 1;
        add_num_jogadas(e);
    }
}

void armazenar_jogada(ESTADO *e, JOGADA jog, int num_jog){
    e->jogadas[num_jog-1] = jog;
}

void armazenar_ultima_jogada(ESTADO *e,int num_jog){
    COORDENADA ultima = e->jogadas[num_jog-1].jogador2;
    if(ultima.coluna == -1){
        e->ultima_jogada = e->jogadas[num_jog-1].jogador1;
        e->jogador_atual = 2;
        e->num_jogadas = num_jog-1;
    }
    else{
        e->ultima_jogada = e->jogadas[num_jog-1].jogador2;
        e->num_jogadas = num_jog;
    }
}

COORDENADA *duplica_coordenada(COORDENADA c){
    COORDENADA *aux = (COORDENADA *) malloc(sizeof(COORDENADA));
    *aux = c;
    return aux;
}
