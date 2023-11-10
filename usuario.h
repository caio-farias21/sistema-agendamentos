#include "tipos.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Função que verifica se há credenciais válidas no arquivo users.txt
int login(string username, string senha) {
    FILE * data = fopen("./database/users.csv", "r");
    if (data == NULL)
        return -1;

    char data_username[100], data_senha[100], data_tipo_usuario[100];
    while (fscanf(data, "%[^,],%[^,],%[^,],%*[^\n]\n", data_username, data_senha, data_tipo_usuario) != EOF) {
        if (strcmp(data_username, username) == 0 && strcmp(data_senha, senha) == 0) {
            fclose(data);
            if (strcmp(data_tipo_usuario, "1") == 0)
                return 1;
            else if (strcmp(data_tipo_usuario, "0") == 0)
                return 0;
            else
                return -1;
        }
    }
    fclose(data);
    return -1;
}

string procurar_nome(string username) {
    FILE * data = fopen("./database/users.csv", "r");
    if (data == NULL)
        return NULL;

    char data_username[100], data_nome[100];
    string str = malloc(100);
    if (str == NULL)
        return NULL;

    while (fscanf(data, "%[^,],%*[^,],%*[^,],%[^\n]\n", data_username, data_nome) != EOF) {
        if (strcmp(data_username, username) == 0) {
            fclose(data);
            strcpy(str, data_nome);
            return str;
        }
    }
    free(str);
    fclose(data);
    return NULL;
}

// Insere credenciais no arquivo users.txt
bool cadastrar_usuario(string username, string senha, string nome){
    // Função que verifica se uma string contém caracteres sensiveis (virgula e quebra de linha)
    bool validate(string str) {
        return !(strstr(str, ",") || strstr(str, "\n"));
    }

    FILE * data = fopen("./database/users.csv", "a");
    if (data == NULL) {
        fclose(data);
        return false;
    }

    string nome = procurar_nome(username);
    if (procurar_nome(username) != NULL) {
        free(nome);
        printf("NOME DE USUÁRIO EM USO!\n");
        return false;
    }

    if (!validate(username) || !validate(senha) || !validate(nome)) {
        fclose(data);
        printf("CARACTER INVÁLIDO (não utilize vírgulas)\n");
        return false;
    }

    char template[300];
    sprintf(template, "%s,%s,0,%s\n", username, senha, nome);
    fputs(template, data);
    fclose(data);
    return true;
}

// Insere salas disponiveis no arquivo salas.txt
bool cadastrar_sala(string nome){
    FILE * data = fopen("./database/salas.csv", "a");
    if (data == NULL) {
        return false;
    }

    FILE * idx_in = fopen("./database/configs/salas_idx.txt", "r");
    if (idx_in == NULL) {
        fclose(data);
        return false;
    }


    int n;
    fscanf(idx_in, "%d", &n);
    fclose(idx_in);

    char template[500];
    sprintf(template, "%d,%s\n", n + 1, nome);
    fputs(template, data);
    fclose(data);

    FILE * idx_out = fopen("./database/configs/salas_idx.txt", "w");
    if (idx_out == NULL) {
        fclose(idx_out);
        return false;
    }

    fprintf(idx_out, "%d", n + 1);
    fclose(idx_out);

    return true;
}

int numero_de_salas() {
    FILE * idx_in = fopen("./database/configs/salas_idx.txt", "r");
    if (idx_in == NULL)
        return 0;


    int n;
    fscanf(idx_in, "%d", &n);
    fclose(idx_in);

    return n;
}

string procurar_sala(int idx) {
    int n = numero_de_salas();

    if (idx < 1 || idx > n) {
        if (n == 1)
            printf("Erro de sistema: A sala '%d' não existe, temos apenas uma sala nos arquivos! Revise o código.\n", idx);
        else
            printf("Erro de sistema: A sala '%d' não existe, temos apenas as salas de '1' até '%d' nos arquivos! Revise o código.\n", idx, n);

        return NULL;
    }

    FILE * data = fopen("./database/salas.csv", "r");
    if (data == NULL)
        return NULL;

    char data_idx[100], data_nome[100];
    string str = malloc(100);
    if (str == NULL) {
        fclose(data);
        return NULL;
    }

    int data_idx_int;

    while (fscanf(data, "%[^,],%[^\n]\n", data_idx, data_nome) != EOF) {
        data_idx_int = atoi(data_idx);
        if (data_idx_int == idx) {
            fclose(data);
            strcpy(str, data_nome);
            return str;
        }
    }
    free(str);
    fclose(data);
    return NULL;
}

string horarios(int idx) {
    switch (idx) {
        case 1:
            return "07:10 - 08:00";
        case 2:
            return "08:01 - 08:50";
        case 3:
            return "08:51 - 09:40";
        case 4:
            return "10:00 - 10:50";
        case 5:
            return "10:51 - 11:40";
        case 6:
            return "11:41 - 12:30";
        case 7:
            return "13:10 - 14:00";
        case 8:
            return "14:01 - 14:50";
        case 9:
            return "14:51 - 15:40";
        case 10:
            return "16:00 - 16:50";
        case 11:
            return "16:51 - 17:40";
        case 12:
            return "17:41 - 18:30";
        default:
            printf("Horário inválido! Revise o código\n");
            return "00:00";
    }
}

bool reservar_sala(int cod_sala, string username, int cod_horario) {
    string sala = procurar_sala(cod_sala);
    string nome = procurar_nome(username);
    string horario = horarios(cod_horario);

    if (horario == NULL)
        return false;

    if (nome == NULL) {
        printf("Usuário '%s' não existe, revise o código!\nFunção: 'reservar_sala'\n", username);
        return false;
    }

    if (sala == NULL) {
        printf("Sala '%d' não existe, revise o código!\nFunção: 'reservar_sala'\n", cod_sala);
        return false;
    }

    if (strcmp(horario, "00:00") == 0) {
        printf("Horário '%d' não existe! Revise o código\nFunção: 'reservar_sala'\n", cod_horario);
        return false;
    }

    FILE * data_r = fopen("./database/reservas.csv", "r");
    if (data_r == NULL)
        return false;

    char data_cod_sala[100], data_username[100], data_cod_horario[100];
    int data_cod_sala_int, data_cod_horario_int;
    while (fscanf(data_r, "%[^,],%[^,],%[^\n]\n", data_cod_sala, data_username, data_cod_horario) != EOF) {

        data_cod_horario_int = atoi(data_cod_horario);
        data_cod_sala_int = atoi(data_cod_sala);

        if (strcmp(data_username, username) == 0) {
            printf("Você já possui reservas!\n");
            
            fclose(data_r);
            return false;
        }

        if (data_cod_horario_int == cod_horario && data_cod_sala_int == cod_sala) {
            printf("Horário já reservado!\n");
            
            fclose(data_r);
            return false;
        }
    }
    
    fclose(data_r);

    FILE * data_in = fopen("./database/reservas.csv", "a");
    if (data_in == NULL)
        return false;

    char template[300];
    sprintf(template, "%d,%s,%d\n", cod_sala, username, cod_horario);
    fputs(template, data_in);
    fclose(data_in);
    return true;
}

void imprimir_detalhes_reserva(string username) {
    FILE * data_r = fopen("./database/reservas.csv", "r");
    if (data_r == NULL)
        return;

    char data_cod_sala[100], data_username[100], data_cod_horario[100];
    while (fscanf(data_r, "%[^,],%[^,],%[^\n]\n", data_cod_sala, data_username, data_cod_horario) != EOF) {
        if (strcmp(data_username, username) == 0) {
            int data_cod_sala_int = atoi(data_cod_sala);
            int data_cod_horario_int = atoi(data_cod_horario);

            printf("\e[0;34m%s,\n\nDetalhes da reserva\e[0m\n\e[0;37mSala: %s\nHorário: %s\n\e[0m", procurar_nome(username), procurar_sala(data_cod_sala_int), horarios(data_cod_horario_int));
            fclose(data_r);
            return;
        }
    }
    printf("Você ainda não reservou uma sala!\n");
    fclose(data_r);
}

bool esta_reservado(int cod_sala, int cod_horario) {
    FILE * data_r = fopen("./database/reservas.csv", "r");
    if (data_r == NULL)
        return false;

    char data_cod_sala[100], data_cod_horario[100];
    int data_cod_sala_int, data_cod_horario_int;
    while (fscanf(data_r, "%[^,],%*[^,],%[^\n]\n", data_cod_sala, data_cod_horario) != EOF) {
        data_cod_sala_int = atoi(data_cod_sala);
        data_cod_horario_int = atoi(data_cod_horario);
        if (data_cod_sala_int == cod_sala && data_cod_horario_int == cod_horario) {
            fclose(data_r);
            return true;
        }
    }
    fclose(data_r);
    return false;
}