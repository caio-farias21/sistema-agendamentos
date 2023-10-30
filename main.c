#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int opcao, limite, sala_selecionada;
int main() {
    // Implementar as coisas!

    // Login
    limpar_tela();

    printf("Login\n\n");
    string username = get_string("Digite seu username: ");
    string senha = get_string("Digite sua senha: ");

    int tipo_do_usuario = login(username, senha);
    if (tipo_do_usuario == -1) {
        printf("Credenciais inválidas!\n");
        return 0;
    }

    // O que foi feito na reunião
    while (1 == 1) {
        limpar_tela();
        printf("Menu\n\n");
        printf("[ 0 ] - Sair\n");
        printf("[ 1 ] - Reservar sala\n");
        printf("[ 2 ] - Ver minhas reservas\n");
        limite = 3;

        // Se administrador
        if (tipo_do_usuario == 1) {
            printf("[ 3 ] - Cadastrar sala\n");
            printf("[ 4 ] - Cadastrar aluno\n");
            limite = 5;
        }
        
        printf("\n");
        opcao = get_opcao(limite);

        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            limpar_tela();
            printf("Selecione a sala\n\n");
            printf("[ 0 ] - Voltar\n");
            
            for (int i = 1; i <= numero_de_salas(); i++) {
                printf("[ %d ] - %s\n", i, procurar_sala(i));
            }
            printf("\n");
        
            opcao = get_opcao(numero_de_salas() + 1);
            
            if (opcao == 0) {
                continue;
            }
            else {
                sala_selecionada = opcao;
                for (int i = 1; i <= 12; i++) {
                    printf("Horários\n");
                }

            }
        }
        if (opcao == 2) {
            imprimir_detalhes_reserva(username);
            printf("Você selecionou a Sala de computadores\n");
            printf("Você selecionou a sala 2\n");
            printf("[ 0 ] - Voltar\n");
            limpar_tela();
        }

    }   
}