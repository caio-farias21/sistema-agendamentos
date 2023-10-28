#include "tipos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_opcao(int limite) {
    int n;
    while (1) {
        printf("Selecione uma opção: ");
        scanf("%d%*c", &n);
        char c;
        if (n >= 0 && n < limite)
            return n;
    }
}

string get_string(string mensagem) {
    char c;
    string str = malloc(0);
    long unsigned int tamanho = 0;

    do {
        printf("%s", mensagem);
        while ((c = fgetc(stdin)) != '\n' && c != EOF) {
            str = realloc(str, tamanho + 1);
            if (str == NULL) {
                free(str);
                return NULL;
            }
            str[tamanho++] = c;
        }
    } while (tamanho == 0);

    str[tamanho] = '\0';
    return str;
}

void limpar_tela() {
    system("clear");
}