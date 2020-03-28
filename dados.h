/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___
#define ___DADOS_H___
#define BUF_SIZE 1024

/**
\brief Tipo de dados para erros
*/
typedef enum {
  OK,
  JOGADA_INVALIDA,
  COORDENADA_INVALIDA,
  ERRO_LER_TAB,
  ERRO_ABRIR_FICHEIRO,
  ERRO_GRAVAR_FICHEIRO,
} ERROS;

/**
\brief Tipo de dados para a casa
*/
typedef enum {
  UM = '1',
  DOIS = '2',
  VAZIO = '.',
  BRANCA = '*',
  PRETA = '#'
} CASA;

/**
\brief  Tipos de dados para as coordenadas
*/
typedef struct {
    int linha;
    int coluna;
} COORDENADA;

/**
\brief  Tipos de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O nº de comando, usado no prompt */
    int num_comando;
    /** O jogador atual */
    int jogador_atual;
} ESTADO;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

int obter_num_comando(ESTADO *e);
/**
\brief Obtem jogador atual
@param e Apontador para o estado
*/
int obter_jogador_atual(ESTADO *e);

/**
\brief Obtem números de jogadas até ao momento
@param e Apontador para o estado
*/
int obter_num_jogadas(ESTADO *e);

JOGADA obter_jogada(ESTADO *e, int indice);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

COORDENADA obter_ultima_jogada(ESTADO *e);

/**
\brief Coloca a peça Branca
@param e Apontador para o estado
@param c A coordenada
*/
void mete_casa_branca(ESTADO *e,COORDENADA c);

/**
\brief Coloca a peça Preta
@param e Apontador para o estado
*/
void mete_casa_preta(ESTADO *e);

/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@param valor O novo valor para a casa
*/
void set_casa(ESTADO *e, COORDENADA c, CASA valor);

/**
\brief Adiciona valor um ao número de comando
@param e Apontador para o estado
*/
void add_num_comando(ESTADO *e);

void add_num_jogadas(ESTADO *e);

/**
\brief Altera a última jogada
@param e Apontador para o estado
@param c A coordenada
*/
void mudar_ultima_jogada(ESTADO *e,COORDENADA c);

void altera_jogador(ESTADO *e,int jogador);

void atualizar_jogada(ESTADO *e,COORDENADA c);

#endif
