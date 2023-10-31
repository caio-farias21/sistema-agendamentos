#include "tipos.h"
#include "helpers.h"
#include "usuario.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int opcao, limite, cod_sala, cod_horario, quantidade_de_salas;
int main(int argc, string args[]) {

    string username = NULL;
    string senha = NULL;

    if (argc == 1) {
        limpar_tela();

        printf("\nLogin\n\n");
        username = get_string("Digite seu username: ");
        if (username == NULL)
            goto garbage;

        senha = get_string("Digite sua senha: ");
        if (senha == NULL)
            goto garbage;
    }

    else if (argc == 2 || argc > 3) {
        printf("uso: <arquivo> <username> <senha>\n");
        goto garbage;
    }
    else {
        username = strdup(args[1]);
        senha = strdup(args[2]);
    }

    int tipo_do_usuario = login(username, senha);
    if (tipo_do_usuario == -1) {
        printf("Credenciais inválidas!\n");
        goto garbage;
    }

    // Loop infinito
    while (1 == 1) {

        limpar_tela();

        // Menu inicial
        printf("\nMenu\n\n");
        printf("[ 0 ] - Sair\n");
        printf("[ 1 ] - Reservar sala\n");
        printf("[ 2 ] - Ver minhas reservas\n");
        limite = 3;

        // Se administrador
        if (tipo_do_usuario == 1) {
            printf("\nFunções de administração:\n\n");
            printf("    [ 3 ] - Cadastrar sala\n");
            printf("    [ 4 ] - Cadastrar aluno\n");
            limite = 5;
        }
        
        printf("\n");
        opcao = get_opcao(limite);

        // Encerra o programa caso o usuário digite 0 no menu inicial
        if (opcao == 0) {
            break;
        }

        // Reservar sala
        else if (opcao == 1) {

            limpar_tela();
            quantidade_de_salas = numero_de_salas();

            // Menu de salas
            printf("\nSelecione a sala\n\n");
            printf("[ 0 ] - Voltar\n");
            
            for (int i = 1; i <= quantidade_de_salas; i++) {
                printf("[ %d ] - %s\n", i, procurar_sala(i));
            }
            printf("\n");

            opcao = get_opcao(quantidade_de_salas + 1);
            
            if (opcao == 0) {
                continue;
            }
            else {
                cod_sala = opcao;

                limpar_tela();

                printf("\nHorários\n\n");

                printf("[ 00 ]   Voltar\n");
                for (int i = 1; i <= 12; i++) {
                    printf("[ %02d ]   %s\n", i, horarios(i));
                }

                printf("\n");
                opcao = get_opcao(13);

                if (opcao == 0) {
                    continue;
                }

                else {
                    cod_horario = opcao;

                    if (reservar_sala(cod_sala, username, cod_horario))
                        printf("Reserva feita com sucesso!\n\n");
                    else
                        printf("Reserva falhou!\n\n");

                    printf("[ 0 ] - Continuar\n\n");
                    get_opcao(1);
                    continue;
                }
            }
        }

        // Ver detalhes da reserva
        else if (opcao == 2) {

            limpar_tela();

            printf("\nSuas reservas\n\n");
            imprimir_detalhes_reserva(username);
            printf("\n");
            printf("[ 0 ] - Continuar\n\n");

            get_opcao(1);
            continue;
        }

        // Cadastrar sala
        else if (opcao == 3) {
            while(1) {
                limpar_tela();

                printf("\nCadastrar sala\n\n");
                string nome_sala = get_string("Digite o nome da sala: ");
                if (nome_sala == NULL) {
                    free(nome_sala);
                    goto garbage;
                }

                printf("\n[ 0 ] - Voltar\n");
                printf("[ 1 ] - Refazer\n");
                printf("[ 2 ] - Confirmar\n\n");

                opcao = get_opcao(3);
                if (opcao == 0) {
                    free(nome_sala);
                    break;
                }

                else if (opcao == 1) {
                    free(nome_sala);
                    continue;
                }
                else {
                    if (cadastrar_sala(nome_sala))
                        printf("Cadastro feito com sucesso!\n\n");
                    else
                        printf("Cadastro falhou!\n\n");

                    free(nome_sala);
                    printf("[ 0 ] - Continuar\n\n");
                    get_opcao(1);
                    break;
                }
            }
            continue;
        }

        // Cadastrar aluno
        else if (opcao == 4) {
            while (1) {
                limpar_tela();
                printf("\nCadastrar aluno\n\n");
                string cadastro_username = get_string("Digite o username: ");
                if (cadastro_username == NULL) {
                    free(cadastro_username);
                    goto garbage;
                }

                string cadastro_senha = get_string("Digite a senha: ");
                if (cadastro_senha == NULL) {
                    free(cadastro_senha);
                    free(cadastro_username);
                    goto garbage;
                }

                string cadastro_nome = get_string("Digite o nome completo: ");
                if (cadastro_nome == NULL) {
                    free(cadastro_nome);
                    free(cadastro_senha);
                    free(cadastro_username);
                    goto garbage;
                }

                printf("\n[ 0 ] - Voltar\n");
                printf("[ 1 ] - Refazer\n");
                printf("[ 2 ] - Confirmar\n\n");

                opcao = get_opcao(3);
                if (opcao == 0) {
                    free(cadastro_username);
                    free(cadastro_senha);
                    free(cadastro_nome);
                    break;
                }

                else if (opcao == 1) {
                    free(cadastro_username);
                    free(cadastro_senha);
                    free(cadastro_nome);
                    continue;
                }
                else {
                    if (cadastrar_usuario(cadastro_username, cadastro_senha, cadastro_nome))
                        printf("Cadastro feito com sucesso!\n\n");
                    else
                        printf("Cadastro falhou!\n\n");

                    free(cadastro_username);
                    free(cadastro_senha);
                    free(cadastro_nome);
                    printf("[ 0 ] - Continuar\n\n");
                    get_opcao(1);
                    break;
                }
            }
        }
    }

    garbage:
        if (username != NULL) {
            free(username);
        }
        if (senha != NULL) {
            free(senha);
        }
        return 0;
}