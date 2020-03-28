#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "logica.h"

void print_erro(ERROS erro){
    char *lista_erros[] = {
        "OK",
        "Coordenada invalida",
        "Jogada invalida",
        "Erro de leitura do tabuleiro",
        "Erro ao abrir o ficheiro",
        "Erro ao gravar o ficheiro"
    };
    if(erro != OK)
        printf("%s\n",lista_erros[erro]);
}

void mostrar_tabuleiro(FILE *f, ESTADO *e) {
    for(int linha = 0; linha < 8; linha++){
        if(f == stdout) 
            printf("%d ",8-linha);
        for(int coluna = 0; coluna < 8; coluna++){
            COORDENADA c = {linha, coluna};
            fputc(obter_estado_casa(e,c),f);
        }
        fputc('\n',f);
    }
    if(f == stdout)
        printf("  abcdefgh\n");
}

void print_jogadas(FILE *f,ESTADO *e){
    for(int i = 1; i <= obter_num_jogadas(e); i++){
        JOGADA j = obter_jogada(e);
        char cj1 = j.jogador1.coluna + 'a';
        char lj1 = j.jogador1.linha + '1';
        char cj2 = j.jogador2.coluna + 'a';
        char lj2 = j.jogador2.linha + '1';
        fprintf(f,"%02d: %c%c %c%c\n",i,cj1,lj1,cj2,lj2);
    }
}

ERROS gravar(ESTADO *e, char *filename){
    FILE *f = fopen(filename,"w");
    if(f == NULL)
        return ERRO_GRAVAR_FICHEIRO;
    mostrar_tabuleiro(f,e);
    print_jogadas(f,e);
    return OK;
}

ERROS ler_tabuleiro(ESTADO *e,FILE *f){
    char buffer[BUF_SIZE];
    for(int l = 0; l < 8; l++){
        if(fgets(buffer,BUF_SIZE,f) == NULL)
            return ERRO_LER_TAB;
        for(int c = 0; c < 8; c++){
            COORDENADA cor = {l,c};
            set_casa(e,cor,(CASA) buffer[c]);
        }          
    }
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
    char col[2], lin[2], sair;
    char filename[BUF_SIZE];
    int vencedor_j1 = 0, vencedor_j2 = 0;
    while (!vencedor_j1 && !vencedor_j2) // Condiçao dos jogadores
    {
        add_num_comando(e); 
        printf("# %02d Player%d (%d)> ",e->num_comando,e->jogador_atual,e->num_jogadas);
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*lin - '1', *col - 'a'};
            jogar(e,coord,&vencedor_j1, &vencedor_j2);
            mostrar_tabuleiro(stdout,e);
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
        if(sscanf(linha, "%[Q]", sair) == 1)
            return 0;
    }
    if (vencedor_j1)
        printf("O Jogador 1 e o vencedor");
    else 
        printf("O Jogador 2 e o vencedor");
}