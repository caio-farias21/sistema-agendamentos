#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool login(char * username, char * senha) {
    FILE * data = fopen("./database/users.txt", "r");//no ponteiro data armazene o arquivo no caminho no modo read
    char a[100];
    char b[100];
    char c[100];
    while (fscanf(data, "%[^,],%[^,],%[^\n]\n", a, b, c) != EOF) {
        if (strcmp(a, username) == 0 && strcmp(b, senha) == 0) {
            //boas_vindas(c);
            fclose(data);
            return true;
        }
    }
    fclose(data);
    return false;
}

//a fazer
//verificar se alguma das entradas tem virgula
//verificar se já existe username igual
bool cadastrar_usuario(char * username, char * senha, char * nome){
    FILE * data = fopen("./database/users.txt", "a");
    char template[300];
    sprintf(template, "%s,%s,%s\n", username, senha, nome);
    fputs(template, data);
    fclose(data);
    return true;
}

bool cadastrar_sala(char * nome){
    FILE * data = fopen("./database/salas.txt", "a");
    FILE * idx = fopen("./database/configs/salas_idx.txt", "w");
    int n = 0;
    fscanf(idx, "%i", &n);
    printf("%d\n", n);
    fprintf(idx, "%i", n + 1);
    fclose(data);
    fclose(idx);
    
}

