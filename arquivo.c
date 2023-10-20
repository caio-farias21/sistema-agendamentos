#include <stdio.h>
#include <stdbool.h>

char opcoes[3][10] = {"Opcao 1", "Opcao 2", "Opcao 3"};

void ola(char * nome) {
    printf("Olá,\n%s\n\n", nome);
}

void telas(char * titulo, char opcoes[3][10]) {
    printf("%s\n\n", titulo);
    for (int i = 0; i < 3; i++) {
        printf("[ %d ] - %s\n", i + 1, opcoes[i]);
    }
}

bool confirmar() {
    int n;
    printf("[ 0 ] - Voltar\n[ 1 ] - Confirmar\n\n");
    printf("Selecione uma opção: ");
    scanf("%d", &n);

    return n == 1;
}

int main() {
    ola("Acsa Mendes Santos");
    telas("Menu", opcoes);
}