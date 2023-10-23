#include "auth.h"
#include <stdio.h>
#include <stdbool.h>

char opcoes[3][10] = {"Opcao 1", "Opcao 2", "Opcao 3"};

void limpar_buffer() {
    char c;
    while (c = getchar() != '\n' && c != EOF);
}

int main() {
    /* LOGIN */
    char username[100], senha[100];
    printf("Nome de usuario: ");
    scanf("%s", username);

    printf("Senha: ");
    scanf("%s", senha);

    login(username, senha);

    /* CADASTRAR USUARIO */
    /*
    char username[100], senha[100], nome[100];
    scanf("%s", username);
    scanf("%s", senha);

    limpar_buffer();
    scanf("%[^\n]", nome);

    if (cadastrar_usuario(username, senha, nome))
        printf("CADASTRADO!\n");
    else
        printf("FALHA NO CADASTRO!\n");
    */
}