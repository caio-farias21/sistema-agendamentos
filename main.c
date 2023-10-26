#include "auth.h"
#include "tipos.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int opcao;

void tela_selecionar_sala_reserva() {
    limpar_tela();

    Funcao opcoes_selecionar_sala[2] = {};
    char * opcoes[2] = {
        "Oládsakldjou owiq", 
        "ola"
    };
    int limite = tela_padrao("Selecione uma sala", opcoes, 2);
    opcao = get_int(limite);
    if (opcao == 0)
        return;
    else
        opcoes_selecionar_sala[opcao]();
}

void tela_ver_detalhes() {
    limpar_tela();

    int n = 0;
    char * opcoes[2] = {};
    int limite = tela_padrao("Detalhes", opcoes, n);
    opcao = get_int(limite);
    if (opcao == 0)
        return;
    else {
        return;
    }
}

void tela_cadastrar_usuario() {
    limpar_tela();
    while (1) {
        limpar_buffer();

        char * username = get_string("Username: ");
        char * senha = get_string("Senha: ");
        char * nome = get_string("Nome completo: ");

        if (confirmar() && cadastrar_usuario(username, senha, nome))
            return;
    }
}


int main() {
    limpar_tela();

    char * username = get_string("Nome de usuario: ");
    char * senha = get_string("Senha: ");

    // Tipos
    //  1 = Admin
    //  0 = Usuario
    // -1 = Erro
    int user_type = login(username, senha);

    // Erro
    if (user_type == -1)
        return -1;

    while (true) {
        Funcao opcoes_tela_inicial[4] = {
            NULL, 
            tela_selecionar_sala_reserva,
            tela_ver_detalhes,
            tela_cadastrar_usuario
        };

        opcao = get_int(tela_inicial(user_type));
        if (opcao == 0)
            return 0;
        else {
            opcoes_tela_inicial[opcao]();
            limpar_tela();
        }

        
    }
}