#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

// Função que deve ser colocada no ficheiro main.c
int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
