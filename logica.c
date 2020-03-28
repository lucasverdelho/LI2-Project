#include <stdio.h>
#include <math.h>
#include "dados.h"
#include "interface.h"

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
    for (int linhas = c_atual.linha - 1 ; linhas <= c_atual.linha + 1; linhas++)
    {
        if (linhas == -1);
        else if (linhas == 8)
            break;
        else 
        {
            for (int colunas = c_atual.coluna-1; colunas <= c_atual.coluna + 1; colunas++)
            {
                if (colunas == -1);
                else if (colunas == 8)
                    break;
                else 
                {
                    COORDENADA validar = {linhas,colunas};
                    if (obter_estado_casa(e,validar) == PRETA);
                    else if (obter_estado_casa(e,validar) == BRANCA)
                        return OK;
                }
            }
        }
    }
    return JOGADA_INVALIDA;
}

int jogar(ESTADO *e, COORDENADA c,int *vence_j1, int *vence_j2)
{
    if (casas_livres(e) == OK)
    {
        if (jogada_valida(e,c) && (obter_estado_casa(e,c)!= PRETA) && (obter_estado_casa(e,c)!= BRANCA))
        {
            int linha = 7-c.linha;
            int coluna = c.coluna;
            mete_casa_branca(e,c);
            mete_casa_preta(e);
            atualizar_jogada(e,c);
            mudar_ultima_jogada(e,c);
            if (linha == 0 && coluna == 7) *vence_j2 = 1; // ganha jogador 2
            else if (linha == 7 && coluna == 0) *vence_j1 = 1; // ganha jogador 1
        }
    }
    else *vence_j1 = 1; // ganha o jogador que bloqueou o outro
    return 0;
}


