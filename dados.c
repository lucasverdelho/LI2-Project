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

int obter_jogador_atual(ESTADO *estado){
    int jogador;
    jogador = estado -> jogador_atual;
    return jogador;
}

int obter_numero_de_jogadas(ESTADO *estado){
    int n_jogadas;
    n_jogadas = estado -> num_jogadas;
    return n_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int linha, coluna;
    linha = c.linha;
    coluna = c.coluna;
    CASA e_casa = e->tab[linha][coluna];
    return e_casa;
}

void mete_casa_branca(ESTADO *e,COORDENADA c)
{
    e->tab[7-c.linha][c.coluna] = BRANCA;
}

void mete_casa_preta(ESTADO *e)
{
    COORDENADA atual = e->ultima_jogada;
    e->tab[7-atual.linha][atual.coluna] = PRETA;
}

void set_casa(ESTADO *e, COORDENADA c, CASA valor){
    e->tab[c.linha][c.coluna] = valor;
}

void add_num_comando(ESTADO *e){
    e->num_comando++;
}

void mudar_ultima_jogada(ESTADO *e,COORDENADA c)
{
    e->ultima_jogada = c;
}