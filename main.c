#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "interface.h"

// Função que deve ser colocada no ficheiro main.c
int main(){
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (interpretador(e));
    return 0;
}
