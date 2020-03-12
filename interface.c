#include <stdio.h>
#include "dados.h"
#include "logica.h"
#define BUF_SIZE 1024

// Função que deve ser completada e colocada na camada de interface
void mostrar_tabuleiro(ESTADO *e) {
    for(int linha = 0; linha < 8; linha++){
        for(int coluna = 0; coluna < 8; coluna++){
            if(linha == 0 && coluna == 7)
                putchar('2');
            if(linha == 7 && coluna == 0)
                putchar ('1');
            switch(e -> tab[linha][coluna]){
                case VAZIO : 
                    putchar('.');
                    break;
                case BRANCA :
                    putchar('*');
                    break;
                case PRETA :
                    putchar('#');
                    break;
            }
        }
        putchar('\n');
    }
}

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
