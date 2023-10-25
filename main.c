#include "auth.h"
#include "tipos.h"
#include <stdio.h>
#include <stdbool.h>

char opcoes[3][10] = {"Opcao 1", "Opcao 2", "Opcao 3"};

void limpar_buffer() {
    char c;
    while (c = getchar() != '\n' && c != EOF);
}

int main() {
    char username[100], senha[100];
    printf("Nome de usuario: ");
    scanf("%s", username);

    printf("Senha: ");
    scanf("%s", senha);

    if (!login(username, senha))
        return 0;

    /* Árvore de opções */
    /*
        [
            voltar, 
            [selecionar_sala, reservar_sala]
        ]
    */

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