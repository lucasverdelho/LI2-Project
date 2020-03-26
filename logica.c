#include <stdio.h>
#include <math.h>
#include "dados.h"
#include "interface.h"

// int jogada_valida(ESTADO *e, COORDENADA c_jogada)
// {
//     COORDENADA c_atual = obter_ultima_jogada(e);
//     if(abs(c_jogada.linha-c_atual.linha) <= 1 && abs(c_jogada.coluna-c_atual.coluna) <= 1)
//         return 1;
//     return 0;
// }

ERROS casas_livres(ESTADO *e) {return OK;}
// {
//     COORDENADA c_atual = {e->ultima_jogada.linha,e->ultima_jogada.coluna};
//     for (int linhas = c_atual.linha - 1 ; linhas <= c_atual.linha + 1; linhas++)
//     {
//         if (linhas == -1);
//         else if (linhas == 8)
//             break;
//         else 
//         {
//             for (int colunas = c_atual.coluna-1; colunas <= c_atual.coluna + 1; colunas++)
//             {
//                 if (colunas == -1);
//                 else if (colunas == 8)
//                     break;
//                 else 
//                 {
//                     COORDENADA validar = {linhas,colunas};
//                     if (obter_estado_casa(e,validar) == PRETA);
//                     else if (obter_estado_casa(e,validar) == BRANCA)
//                         return OK;
//                 }
//             }
//         }
//     }
//     return JOGADA_INVALIDA;
// }

int jogar(ESTADO *e, COORDENADA c)
{
    if (casas_livres(e) == OK)
    {
        if ((obter_estado_casa(e,c)!= PRETA) && (obter_estado_casa(e,c)!= BRANCA))
        {
            int linha = c.linha;
            int coluna = c.coluna;
            //atualizar_jogada(e,c,obter_jogador_atual (e));
            mete_casa_branca(e,c);
            mete_casa_preta(e);
            if (linha == 0 && coluna == 7) {} // ganha jogador 2
            else if (linha == 7 && coluna == 0) {} // ganha jogador 1
        }
    }
    else {}; // ganha o jogador que bloqueou o outro
    return 1;
}


// {
//     if (casas_livres(e) == OK)
//     {
//         if ((obter_estado_casa(e,c)!= PRETA) && (obter_estado_casa(e,c)!= BRANCA))
//         {
//             int linha = c.linha;
//             int coluna = c.coluna;
//             atualizar_jogada(e,c);
//             mete_casa_branca(e,c);
//             mete_casa_preta(e);
//             if (linha == 0 && coluna == 7) {} // ganha jogador 2
//             else if (linha == 7 && coluna == 0) {} // ganha jogador 1
//         }
//     else {}; // ganha o jogador que bloqueou o outro
//     return 1;
// }








// ERROS casas_livres(ESTADO *e)
// {
//     COORDENADA c_atual = {e->ultima_jogada.linha,e->ultima_jogada.coluna};
//     for (int linhas = c_atual.linha - 1 ; linhas <= c_atual.linha + 1; linhas++)
//     {
//         if (linhas == -1);
//         else if (linhas == 8)
//             break;
//         else 
//         {
//             for (int colunas = c_atual.coluna-1; colunas <= c_atual.coluna + 1; colunas++)
//             {
//                 if (colunas == -1);
//                 else if (colunas == 8)
//                     break;
//                 else 
//                 {
//                     COORDENADA validar = {linhas,colunas};
//                     if (obter_estado_casa(e,validar) == PRETA);
//                     else if (obter_estado_casa(e,validar) == BRANCA)
//                         return OK;
//                 }
//             }
//         }
//     }
//     return JOGADA_INVALIDA;
// }

// // Função que deve ser completada e colocada na camada da lógica do programa

// // Modificar o estado ao jogar na casa correta se a jogada for válida.

// ERROS jogar(ESTADO *e, COORDENADA c) {
//     if (casas_livres(e) != OK)
//         printf("O Jogador %d e o vencedor", obter_jogador_atual(e));
//     else if(obter_estado_casa(e,c) == PRETA || obter_estado_casa(e,c) == BRANCA)
//         return COORDENADA_INVALIDA;
//     else if (obter_jogador_atual(e) == 1 && jogada_valida(e,c))
//         e->jogador_atual = 2;
//     else if (obter_jogador_atual(e) == 2 && jogada_valida(e,c))
//     {
//          e->jogador_atual = 1;
//          e->num_jogadas++;
//     }
//     else
//         return JOGADA_INVALIDA;
//     if(obter_estado_casa(e,c) == UM || obter_estado_casa(e,c) == DOIS)
//         printf("O Jogador %c e o vencedor", obter_estado_casa(e,c));
//     e->tab[c.linha][c.coluna] = BRANCA;
//     e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;
//     return OK;
// }

