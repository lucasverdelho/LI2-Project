#include <stdio.h>
#include "dados.h"

// Função que deve ser completada e colocada na camada da lógica do programa

// modificar o estado ao jogar na casa correta se a jogada for válida.

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab[c.linha][c.coluna] = BRANCA;
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
    return 1;
}

