#include <stdio.h>
#include <math.h>

#include "dados.h"
#include "interface.h"
#include "lista.h"

int jogada_valida(ESTADO *e, COORDENADA c_jogada)
{
    COORDENADA c_atual = obter_ultima_jogada(e);
    if(abs(c_jogada.linha-c_atual.linha) <= 1 && abs(c_jogada.coluna-c_atual.coluna) <= 1)
        return 1;
    return 0;
}

ERROS casas_livres(ESTADO *e)
{
    COORDENADA c_atual = obter_ultima_jogada(e);
    for (int linhas = 7 - c_atual.linha - 1 ; linhas <= 7 - c_atual.linha + 1 && linhas < 8; linhas++)
    {
        if (linhas < 0);
        else 
        {
            for (int colunas = c_atual.coluna-1; (colunas <= c_atual.coluna + 1) && colunas < 8; colunas++)
            {
                if (colunas < 0);
                else 
                {
                    COORDENADA validar = {linhas,colunas};
                    if (obter_estado_casa(e,validar) == PRETA);
                    else if (obter_estado_casa(e,validar) == VAZIO)
                        return OK;
                }
            }
        }
    }
    return JOGADA_INVALIDA;
}

ERROS jogar(ESTADO *e, COORDENADA c,int *vence_j1, int *vence_j2)
{
    COORDENADA normalizada = {7-c.linha,c.coluna};
    if (jogada_valida(e,c) && (obter_estado_casa(e,normalizada) != PRETA) && (obter_estado_casa(e,normalizada)!= BRANCA))
    {
        COORDENADA ult_jogada = obter_ultima_jogada(e);
        ult_jogada.linha = 7 - ult_jogada.linha; // normalizar ultima jogada
        set_casa(e,normalizada,BRANCA);
        set_casa(e,ult_jogada,PRETA);
        atualizar_jogada(e,c);
        mudar_ultima_jogada(e,c);
        if (normalizada.linha == 0 && normalizada.coluna == 7) 
            *vence_j2 = 1;                  // ganha jogador 2
        else if (normalizada.linha == 7 && normalizada.coluna == 0) 
            *vence_j1 = 1;                  // ganha jogador 1
        else if (casas_livres(e) != OK)     // ganha o jogador que bloqueou o outro
        {
            if (obter_jogador_atual(e) == 1) *vence_j2 = 1;
            else *vence_j1 = 1;
        }
    }
    else 
        return JOGADA_INVALIDA;
    return OK;
}

double distancia(COORDENADA c1, COORDENADA c2)
{
    int quadrado = pow(c2.linha - (7-c1.linha),2) + pow(c2.coluna - c1.coluna,2);
    double dist = sqrt(quadrado);
    return dist;
}

COORDENADA coord_jog(LISTA casas_livres, int jogador)
{
    double temp, menor_dist = 50;
    COORDENADA menor, aux;
    if(jogador == 1){ //coord casa 1
        aux.linha = 7; 
        aux.coluna = 0;  
    }
    else{               //coord casa 2
        aux.linha = 0; 
        aux.coluna = 7; 
    }
    for(LISTA T = casas_livres; !lista_esta_vazia(T); T = proximo(T))
    {
        COORDENADA *c = (COORDENADA *) devolve_cabeca(T);
        if ((temp = distancia(*c,aux)) < menor_dist)
        {
            menor = *c;
            menor_dist = temp;
        }
    }
    return menor;
}

LISTA lista_livres(ESTADO *e,int *dim){
    LISTA livres = criar_lista();
    COORDENADA c_atual = obter_ultima_jogada(e);
    for (int linhas = 7 - c_atual.linha - 1; (linhas <= 7 - c_atual.linha + 1) && linhas < 8; linhas++){
        if (linhas < 0);
        else {
            for (int colunas = c_atual.coluna-1; (colunas <= c_atual.coluna + 1) && colunas < 8; colunas++){
                if (colunas < 0);
                else {
                    COORDENADA validar = {linhas,colunas};
                    if (obter_estado_casa(e,validar) == VAZIO){
                        COORDENADA c = {abs (7-linhas),colunas};
                        livres = insere_cabeca(livres,duplica_coordenada(c)); 
                        *dim = *dim + 1;
                    }
                }
            }
        }
    }
    return livres;
}
