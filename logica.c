#include <stdio.h>
#include <math.h>
#include "dados.h"
#include "interface.h"


int jogada_valida(ESTADO *e, COORDENADA c_jogada){
    COORDENADA c_atual = {e->ultima_jogada.linha,e->ultima_jogada.coluna};
    if(abs(c_jogada.linha-c_atual.linha) <= 1 && abs(c_jogada.coluna-c_atual.coluna) <= 1)
        return 1;
    return 0;
}

int casas_livres(ESTADO *e, COORDENADA c)
{
    COORDENADA c_norte = {c.linha-1,c.coluna};
    COORDENADA c_nordeste = {c.linha-1,c.coluna+1};
    COORDENADA c_noroeste = {c.linha-1,c.coluna-1};
    COORDENADA c_este = {c.linha,c.coluna+1};
    COORDENADA c_oeste = {c.linha,c.coluna-1};
    COORDENADA c_sudoeste = {c.linha+1,c.coluna-1};
    COORDENADA c_sudeste = {c.linha+1,c.coluna+1};
    COORDENADA c_sul = {c.linha+1,c.coluna};

    if ((c.linha-1) < 0) // o jogador encontra-se na linha mais acima
    {
        if ((obter_estado_casa(e,c_este) == PRETA) &&
            (obter_estado_casa(e,c_oeste) == PRETA) &&
            (obter_estado_casa(e,c_sul) == PRETA) &&
            (obter_estado_casa(e,c_sudeste) == PRETA) &&
            (obter_estado_casa(e,c_sudoeste) == PRETA))
        {
            return 0;
        }
    }

    if ((c.linha+1) > 8) // linha mais abaixo
    {
        if ((obter_estado_casa(e,c_norte) == PRETA) &&
            (obter_estado_casa(e,c_nordeste) == PRETA) &&
            (obter_estado_casa(e,c_este) == PRETA) &&
            (obter_estado_casa(e,c_oeste) == PRETA) &&
            (obter_estado_casa(e,c_nordeste) == PRETA))
        {
            return 0;
        }
    }

    if ((c.linha-1 < 0) && (c.coluna-1 < 0)) // Canto superior esquerdo do mapa
    {
        if ((obter_estado_casa(e,c_este) == PRETA) &&
            (obter_estado_casa(e,c_sul) == PRETA) &&
            (obter_estado_casa(e,c_sudeste) == PRETA))
        {
            return 0;
        }
    }

    if ((c.linha+1 > 8) && (c.coluna+1 > 8)) // Canto inferior direito do mapa
    {
        if ((obter_estado_casa(e,c_norte) == PRETA) &&
            (obter_estado_casa(e,c_noroeste) == PRETA) &&
            (obter_estado_casa(e,c_este) == PRETA))
        {
            return 0;
        }
    }

    if ((c.coluna-1) < 0) // Coluna a
    {
        if ((obter_estado_casa(e,c_norte) == PRETA) &&
            (obter_estado_casa(e,c_nordeste) == PRETA) &&
            (obter_estado_casa(e,c_este) == PRETA) &&
            (obter_estado_casa(e,c_sul) == PRETA) &&
            (obter_estado_casa(e,c_sudeste) == PRETA))
        {
            return 0;
        }
    }

    if ((c.coluna+1) > 8) // Coluna h
    {
        if ((obter_estado_casa(e,c_norte) == PRETA) &&
            (obter_estado_casa(e,c_noroeste) == PRETA) &&
            (obter_estado_casa(e,c_oeste) == PRETA) &&
            (obter_estado_casa(e,c_sul) == PRETA) &&
            (obter_estado_casa(e,c_sudoeste) == PRETA))
        {
            return 0;
        }
    }
    
    if ((obter_estado_casa(e,c_norte) == PRETA) &&
        (obter_estado_casa(e,c_nordeste) == PRETA) &&
        (obter_estado_casa(e,c_noroeste) == PRETA) &&
        (obter_estado_casa(e,c_este) == PRETA) &&
        (obter_estado_casa(e,c_oeste) == PRETA) &&
        (obter_estado_casa(e,c_sul) == PRETA) &&
        (obter_estado_casa(e,c_sudeste) == PRETA) &&
        (obter_estado_casa(e,c_sudoeste) == PRETA))
        return 0;
    return 1;
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
    if (casas_livres(e,c) == 0)
        printf("O Jogador %d e o vencedor", obter_jogador_atual(e));
    if(obter_estado_casa(e,c) == UM || obter_estado_casa(e,c) == DOIS)
        printf("O Jogador %d e o vencedor", obter_estado_casa(e,c));
    e->tab[c.linha][c.coluna] = BRANCA;
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
    return OK;
}

