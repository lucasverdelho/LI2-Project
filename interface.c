#include <stdio.h>
#include "dados.h"
#include "logica.h"


// Função que deve ser completada e colocada na camada de interface
void mostrar_tabuleiro(ESTADO *e) {
    for(int linha = 0; linha < 8; linha++){
        printf("%d ",8-linha);
        for(int coluna = 0; coluna < 8; coluna++){
            COORDENADA c = {linha, coluna};
            switch(obter_estado_casa(e,c)){
                case UM : 
                    putchar('1');
                    break;
                case DOIS : 
                    putchar('2');
                    break;
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
    printf("  abcdefgh\n");
}

void print_erro(ERROS e){
    char *lista_erros[] = {
        "OK",
        "Coordenada invalida",
        "Jogada invalida",
        "Erro de leitura do tabuleiro",
        "Erro ao abrir o ficheiro"
    };
    if(e != OK)
        printf("%s\n",lista_erros[e]);
}

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    e->num_comando++;
    printf("# %02d Player%d (%d)",e->num_comando,e->jogador_atual,e->num_jogadas);
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        ERROS validar;
        if(validar = jogar(e, coord) == OK)
            mostrar_tabuleiro(e);
    }
    else print_erro()
    return 1;
}
