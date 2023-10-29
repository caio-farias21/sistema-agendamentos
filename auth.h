#include "tipos.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Função que verifica se há credenciais válidas no arquivo users.txt
int login(string username, string senha) {
    FILE * data = fopen("./database/users.txt", "r");
    if (data == NULL)
        return -1;

    char data_username[100], data_senha[100], data_tipo_usuario[100];
    while (fscanf(
        data, 
        "%[^,],%[^,],%[^,],%*[^\n]\n", 
        data_username, 
        data_senha, 
        data_tipo_usuario
    ) != EOF) {
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
    FILE * data = fopen("./database/users.txt", "r");
    if (data == NULL)
        return NULL;

    char data_username[100], data_nome[100];
    string str = malloc(100);
    if (str == NULL) {
        fclose(data);
        return NULL;
    }

    while (fscanf(data, "%[^,],%*[^,],%*[^,],%[^\n]\n", data_username, data_nome) != EOF) {
        if (strcmp(data_username, username) == 0) {
            fclose(data);
            strcpy(str, data_nome);
            return str;
        }
    }
    fclose(data);
    return NULL;
}

// Insere credenciais no arquivo users.txt
bool cadastrar_usuario(string username, string senha, string nome){
    // Função que verifica se uma string contém caracteres sensiveis (virgula e quebra de linha)
    bool validate(string str) {
        return !(strstr(str, ",") || strstr(str, "\n"));
    }

    FILE * data = fopen("./database/users.txt", "a");

    if (procurar_nome(username) != NULL) {
        fclose(data);
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
// TODO: Finalizar função
bool cadastrar_sala(string nome){
    FILE * data = fopen("./database/salas.txt", "a");
    FILE * idx = fopen("./database/configs/salas_idx.txt", "w+");
    int n;
    fscanf(idx, "%d", &n);
    printf("%d\n", n);
    //fprintf(idx, "%d", n + 1);
    fclose(data);
    fclose(idx);
}