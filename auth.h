#include "telas.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Função que verifica se há credenciais válidas no arquivo users.txt
bool login(char * username, char * senha) {
    FILE * data = fopen("./database/users.txt", "r");
    if (data == NULL)
        return false;

    char a[100], b[100], c[100];
    while (fscanf(data, "%[^,],%[^,],%[^\n]\n", a, b, c) != EOF) {
        if (strcmp(a, username) == 0 && strcmp(b, senha) == 0) {
            ola(c);
            fclose(data);
            return true;
        }
    }
    printf("CREDENCIAIS INVÁLIDAS!\n");
    fclose(data);
    return false;
}

bool validate(char * str) {
    return !(strstr(str, ",") || strstr(str, "\n"));
}

// Verifica se o username está em users.txt
bool existe_usuario(char * username) {
    FILE * data = fopen("./database/users.txt", "r");
    if (data == NULL)
        return false; // Configurar erro

    char a[100], b[100], c[100];

    for (;fscanf(data, "%[^,],%[^,],%[^\n]\n", a, b, c) != EOF;) {
        if (strcmp(a, username) == 0) {
            fclose(data);
            return true;
        }
    }

    while (fscanf(data, "%[^,],%[^,],%[^\n]\n", a, b, c) != EOF) {
        if (strcmp(a, username) == 0) {
            fclose(data);
            return true;
        }
    }
    fclose(data);
    return false;
}

// Insere credenciais no arquivo users.txt
bool cadastrar_usuario(char * username, char * senha, char * nome){
    FILE * data = fopen("./database/users.txt", "a");

    if (existe_usuario(username)) {
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
    sprintf(template, "%s,%s,%s\n", username, senha, nome);
    fputs(template, data);
    fclose(data);
    return true;
}

// Insere salas disponiveis no arquivo salas.txt
// TODO: Finalizar função
bool cadastrar_sala(char * nome){
    FILE * data = fopen("./database/salas.txt", "a");
    FILE * idx = fopen("./database/configs/salas_idx.txt", "w+");
    int n;
    fscanf(idx, "%d", &n);
    printf("%d\n", n);
    //fprintf(idx, "%d", n + 1);
    fclose(data);
    fclose(idx);
}

