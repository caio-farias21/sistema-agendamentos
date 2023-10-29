#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int opcao;
int main() {
    // Implementar as coisas!

    // O que foi feito na reunião
    while (1 == 1) {
        limpar_tela();
        printf("Menu\n\n");
        printf("[ 0 ] - Voltar\n");
        printf("[ 1 ] - Reservar sala\n\n");

        opcao = get_opcao(2);
        if (opcao == 0) {
            break;
        }
        if (opcao == 1) {
            printf("Selecione a sala\n\n");
            printf("[ 0 ] - Voltar\n");
            printf("[ 1 ] - Sala de computadores\n");
            printf("[ 2 ] - Biblioteca\n\n");

            opcao = get_opcao(3);
            if (opcao == 0) {
                continue;
            }
            if (opcao == 2) {
            }
        }
    }
}