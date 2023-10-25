#include <stdio.h>
#include <stdbool.h>

typedef void (*Func)()

void ola(char * nome) {
    printf("\nOlá,\n%s\n\n", nome);
}

void telas(char * titulo, Func opcoes[10]) {
    printf("%s\n\n", titulo);
}

bool confirmar() {
    int n;
    printf("[ 0 ] - Voltar\n[ 1 ] - Confirmar\n\n");
    printf("Selecione uma opção: ");
    scanf("%d", &n);

    return n == 1;
}