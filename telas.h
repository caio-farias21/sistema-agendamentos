#include "helpers.h"
#include <stdio.h>
#include <stdbool.h>

void ola(char * nome) {
    printf("\nOlá,\n%s\n", nome);
}

void limpar_tela() {
    system("clear");
}

int tela_padrao(char * titulo, char * opcoes[], int n) {
    printf("\n%s\n\n", titulo);
    printf("[ 0 ] - Voltar\n");
    for (int i = 0; i < n; i++) {
        printf("[ %d ] - %s\n", i + 1, opcoes[i]);
    }
    printf("\n");
    return n + 1;
}

int tela_inicial(bool admin) {
    char * opcoes[1] = {"Reservar"};
    int limit = tela_padrao("Menu", opcoes, 1);

    if (admin) {
        printf("[ 2 ] - Ver detalhes\n");
        printf("[ 3 ] - Cadastrar usuário\n");
        limit = 4;
        printf("\n");
    }
    return limit;
}

bool confirmar() {
    printf("\n[ 0 ] - Voltar\n");
    printf("[ 1 ] - Confirmar\n");
    printf("\n");

    return get_int(2) == 1;
}