#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int opcao;
int main() {
    limpar_tela(); // Essa função também é uma função criada para o projeto, ao ser chamada, ela limpa tudo o que estiver no terminal!

    printf("Cardápio\n\n");
    printf("[ 0 ] - Peixe cozido\n");
    printf("[ 1 ] - Lasanha\n");
    printf("[ 2 ] - Torta de frango\n\n");

    opcao = get_opcao(3); // Essa função irá pedir por uma opção até que o usuário digite uma opção válida!

    if (opcao == 0) {
        printf("Você selecionou: Peixe cozido!\n");
    }
    else if (opcao == 1) {
        printf("Você selecionou: Lasanha!\n");
    }
    else { // Como get_opcao(3) só pode retornar os valores 0, 1, 2, podemos afirmar com certeza que caso opcao não seja 0 e nem 1, é com certeza 2!
        printf("Você selecionou: Torta de frango!\n");
    }
}