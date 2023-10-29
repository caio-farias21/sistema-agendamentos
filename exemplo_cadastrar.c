#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    limpar_tela(); // Essa função também é uma função criada para o projeto, ao ser chamada, ela limpa tudo o que estiver no terminal!

    printf("Cadastro de usuário\n\n");
    string username = get_string("Digite o username: ");
    string senha = get_string("Digite a senha: ");
    string nome = get_string("Digite o nome completo: ");

    bool resultado = cadastrar_usuario(username, senha, nome);

    if (resultado) {
        printf("Cadastro foi realizado com sucesso!\n");
        printf("Você já consegue fazer login no sistema!\n");
    }
    else {
        printf("O cadastro falhou!\n");
    }
}