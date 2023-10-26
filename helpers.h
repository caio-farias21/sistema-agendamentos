#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int states[10];

void limpar_buffer() {
    char c;
    while (c = getchar() != '\n' && c != EOF);
}

int hash_function(char * str) {
    if (strcmp(str, "cod_sala"))
        return 0;
    else if (strcmp(str, "num_horario"))
        return 1;
    else
        return -1;
}

int get_state(char * str) {
    int idx = hash_function(str);
    if (idx == -1)
        return -1;
    return states[idx];
}

int set_state(char * str, int n) {
    int idx = hash_function(str);
    if (idx == -1)
        return -1;
    states[idx] = n;
    return 0;
}

int get_int(int limite) {
    int n;
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &n);
        if (n >= 0 && n < limite)
            return n;
    } while (1);
}

char * get_string(char * message) {
    char * str = (char*) malloc(0);
    long unsigned int tamanho_str = 0;
    char letra = 42;
    do {
        printf("%s", message);
        while (letra != '\n') {
            scanf("%c", &letra);
            str = (char*) realloc(str, (tamanho_str+1) * sizeof(char));
            if (str == NULL)
                return NULL;
            str[tamanho_str] = letra;
            tamanho_str++;
        }
    } while (tamanho_str == 0);

    str[tamanho_str - 1] = '\0';
    return str;
}