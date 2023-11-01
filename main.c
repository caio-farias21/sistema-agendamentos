#include "tipos.h"
#include "helpers.h"
#include "usuario.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define TEXTO_PRIMARIO "\e[1;34m"
#define NORMAL "\e[0m"
#define VERMELHO "\e[1;91m"
#define VERDE "\e[1;92m"

int opcao, limite, cod_sala, cod_horario, quantidade_de_salas;
int main(int argc, string args[]) {

    string username = NULL;
    string senha = NULL;

    if (argc == 1) {
        limpar_tela();

        printf(TEXTO_PRIMARIO"\n━ Login ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
        username = get_string("Digite seu username:  "NORMAL);
        if (username == NULL)
            goto garbage;

        senha = get_string("\e[1;34mDigite sua senha: "NORMAL);
        if (senha == NULL)
            goto garbage;

        printf(TEXTO_PRIMARIO"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
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
        printf(VERMELHO"!!!Credenciais inválidas!!!\n");
        goto garbage;
    }

    // Loop infinito
    while (1 == 1) {

        limpar_tela();

        // Menu inicial
        printf(TEXTO_PRIMARIO"\n━ Menu ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
        printf("[ 0 ] - Sair\n");
        printf("[ 1 ] - Reservar sala\n");
        printf("[ 2 ] - Ver minhas reservas\n");
        limite = 3;

        // Se administrador
        if (tipo_do_usuario == 1) {
            printf(TEXTO_PRIMARIO"\n━ Funções de Administrador ━━━━━━━━━\n\n");
            printf("[ 3 ] - Cadastrar sala\n");
            printf("[ 4 ] - Cadastrar aluno\n");
            printf(TEXTO_PRIMARIO"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m\n");
            limite = 5;
        } else {
            printf(TEXTO_PRIMARIO"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m\n");   
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
            printf(TEXTO_PRIMARIO"\n━ Selecione a sala ━━━━━━━━━━━━\n\n");
            printf("[ 0 ] - Voltar\n");
            
            for (int i = 1; i <= quantidade_de_salas; i++) {
                printf("[ %d ] - %s\n", i, procurar_sala(i));
            }
            printf(TEXTO_PRIMARIO"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m\n");

            opcao = get_opcao(quantidade_de_salas + 1);
            
            if (opcao == 0) {
                continue;
            }
            else {
                cod_sala = opcao;

                limpar_tela();

                printf(TEXTO_PRIMARIO"\n━ Horários ━━━━━━━━━━━━━━━━━━━━━━━━\n");
 
                printf("[ 00 ]   Voltar\n");
                for (int i = 1; i <= 12; i++) {
                    if (esta_reservado(cod_sala, i))
                        continue;
                    printf("[ %02d ]   %s\n", i, horarios(i));
                }
                printf(TEXTO_PRIMARIO"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m\n");

                opcao = get_opcao(13);

                if (opcao == 0) {
                    continue;
                }

                else {
                    cod_horario = opcao;

                    limpar_tela();
                    printf("\n");
                    
                    if (reservar_sala(cod_sala, username, cod_horario))
                        printf(VERDE"Reserva feita com sucesso!\n\n"NORMAL);
                    else
                        printf(VERMELHO"Reserva falhou!\n\n"NORMAL);
                    
                    printf(TEXTO_PRIMARIO"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                    printf("[ 0 ] - Continuar\n\n"NORMAL);
                    get_opcao(1);
                    continue;
                }
            }
        }

        // Ver detalhes da reserva
        else if (opcao == 2) {

            limpar_tela();

            printf(TEXTO_PRIMARIO"\n━ Suas reservas ━━━━━━━━━━━━━━━━━━━\n\n");
            imprimir_detalhes_reserva(username);
            printf("\n");
            printf(TEXTO_PRIMARIO"[ 0 ] - Continuar");
            printf(TEXTO_PRIMARIO"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NORMAL);

            get_opcao(1);

            continue;
        }

        // Cadastrar sala
        else if (opcao == 3) {
            while(1) {
                limpar_tela();

                printf("\n\n\n");
                printf(TEXTO_PRIMARIO"\n━ Cadastrar sala ━━━━━━━━━━━━━━━━━━\n\n");
                string nome_sala = get_string("Digite o nome da sala: "NORMAL);
                if (nome_sala == NULL) {
                    free(nome_sala);
                    goto garbage;
                }

                printf(VERMELHO"\n[ 0 ] - Cancelar\n");
                printf("[ 1 ] - Refazer\n");
                printf("[ 2 ] - Confirmar\n\n"NORMAL);

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

                    limpar_tela();
                    if (cadastrar_sala(nome_sala))
                        printf(VERDE"Cadastro feito com sucesso!\n\n"NORMAL);
                    else
                        printf(VERMELHO"Cadastro falhou!\n\n"NORMAL);

                    free(nome_sala);
                    printf(TEXTO_PRIMARIO"[ 0 ] - Continuar\n\n"NORMAL);
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
                printf(TEXTO_PRIMARIO"\nCadastrar aluno\n\n");
                string cadastro_username = get_string(TEXTO_PRIMARIO"Digite o username: \e[0m");
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

                printf("\n[ 0 ] - Cancelar\n");
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
                    limpar_tela();
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