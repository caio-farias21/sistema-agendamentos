#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Credenciais que estão no sistema para testar:
//
// (Administrador)  Username: caio_farias | Senha: 1234
// (Usuario)        Username: acsa_santos | Senha: 1234
//
// Invente algum usuário ou senha para testar o caso de login errado!

int main() {
    string username = get_string("Digite seu username: ");
    string senha = get_string("Digite a senha: ");

    int resultado = login(username, senha);
    if (resultado == 1) {
        printf("Você é administrador!\n");
    }
    else if (resultado == 0) {
        printf("Você é um usuário!\n");
    }
    else if (resultado == -1) {
        printf("Credenciais inválidas!\n");
        return 0; // Encerra o programa, nada após essa linha é executado mais!
    }

    string nome_completo = procurar_nome(username);
    printf("Seu nome completo é: %s\n", nome_completo);

}