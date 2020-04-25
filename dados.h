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
  POSICAO_INVALIDA,
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

/**
\brief Obtem número de comando
@param e Apontador para o estado
@returns num_comando
*/
int obter_num_comando(ESTADO *e);

/**
\brief Obtem jogador atual
@param e Apontador para o estado
@returns O Jogador atual
*/
int obter_jogador_atual(ESTADO *e);

/**
\brief Obtem números de jogadas até ao momento
@param e Apontador para o estado
@returns O númro de jogadas
*/
int obter_num_jogadas(ESTADO *e);

/**
\brief Obtem a jogada
@param e Apontador para o estado
@returns A jogada
*/
JOGADA obter_jogada(ESTADO *e, int indice);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Devolve a coordenada da última jogada
@param e Apontador para o estado
@returns A coordenada
*/
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

/**
\brief Adiciona valor um ao número de jogadas
@param e Apontador para o estado
*/
void add_num_jogadas(ESTADO *e);

/**
\brief Altera a última jogada
@param e Apontador para o estado
@param c A coordenada
*/
void mudar_ultima_jogada(ESTADO *e,COORDENADA c);

/**
\brief Altera o jogador atual
@param e Apontador para o estado
@param jogador Número do jogador
*/
void mudar_jogador_atual(ESTADO *e, int jogador);

/**
\brief Altera o número de jogadas
@param e Apontador para o estado
@param jogada Número da jogada
*/
void mudar_num_jogadas(ESTADO *e, int jogada);

/**
\brief Altera o tabuleiro
@param e Apontador para o estado
*/
void mudar_tabuleiro(ESTADO *e);

/**
\brief Altera o jogador
@param e Apontador para o estado
@param jogador Número do jogador
*/
void altera_jogador(ESTADO *e,int jogador);

/**
\brief Atualiza a jogada
@param e Apontador para o estado
@param c A coordenada
*/
void atualizar_jogada(ESTADO *e,COORDENADA c);

/**
\brief Armazena a jogada
@param e Apontador para o estado
@param jog Jogada
@param num_jog Número do jogador
*/
void armazenar_jogada(ESTADO *e, JOGADA jog, int num_jog);

/**
\brief Armazena a última jogada
@param e Apontador para o estado
@param num_jog Número do jogador
*/
void armazenar_ultima_jogada(ESTADO *e,int num_jog);

COORDENADA *duplica_coordenada(COORDENADA c);

#endif
