#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "logica.h"
void print_erro(ERROS e){
    char *lista_erros[] = {
        "OK",
        "Coordenada invalida",
        "Jogada invalida",
        "Erro de leitura do tabuleiro",
        "Erro ao abrir o ficheiro",
        "Erro ao gravar o ficheiro"
    };
    if(e != OK)
        printf("%s\n",lista_erros[e]);
}

void mostrar_tabuleiro(FILE *f, ESTADO *e) {
    for(int linha = 0; linha < 8; linha++){
        if(f == stdout) 
            fprintf(f,"%d ",8-linha);
        for(int coluna = 0; coluna < 8; coluna++){
            COORDENADA c = {linha, coluna};
            fputc(obter_estado_casa(e,c),f);
        }
        fputc('\n',f);
    }
    if(f == stdout)
        fprintf(f,"  abcdefgh\n");
}

ERROS gravar(ESTADO *e, char *filename){
    FILE *f = fopen(filename,"w");
    if(f == NULL)
        return ERRO_GRAVAR_FICHEIRO;
    mostrar_tabuleiro(f,e);
    return OK;
}

ERROS ler_tabuleiro(ESTADO *e,FILE *f){
    return OK;
}

ERROS ler(ESTADO *e, char *filename){
    FILE *f = fopen(filename,"r");
    if(f == NULL)
        return ERRO_ABRIR_FICHEIRO;
    return ler_tabuleiro(e,f);
}

// Função que deve ser completada e colocada na camada de interface

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char filename[BUF_SIZE];

    e->num_comando++;
    printf("# %02d Player%d (%d)> ",e->num_comando,e->jogador_atual,e->num_jogadas);
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        ERROS validar;
        if((validar = jogar(e, coord)) == OK)
            mostrar_tabuleiro(stdout,e);
        else 
            print_erro(validar);
        return 1;
    }
    if(sscanf(linha, "gr %s", filename) == 1){
        ERROS erro_gravar;
        if((erro_gravar = gravar(e,filename)) == OK);
        else 
            print_erro(erro_gravar);
        

    }
    if(sscanf(linha, "ler %s", filename) == 1){
        ERROS erro_ler;
        if((erro_ler = ler(e,filename)) == OK)
            mostrar_tabuleiro(stdout,e);
        else 
            print_erro(erro_ler);
    }
}
