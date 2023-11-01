#include "tipos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

#define msg_inicial_linhas  8
#define msg_inicial_colunas 60


char msg_incial[msg_inicial_linhas][msg_inicial_colunas] = {
	"      _____         _____     _____     _____     _____   ",
    "     |         |   |         |     |   |         |        ",
    "     |         |   |         |     |   |         |        ",
    "     |_____    |   |_____    |_____|   |  ___    |_____   ",
    "           |   |         |   |     |   |     |   |        ",
    "           |   |         |   |     |   |     |   |        ",
    "     ______|   |   ______|   |     |   |_____|   |_____   "
};

char matriz_booleana[msg_inicial_linhas][msg_inicial_colunas];

void left_to_right(void);

void zera_matriz_booleana(void){
	int lin, col;
	for(lin = 0; lin < msg_inicial_linhas; lin++){
		for(col = 0; col < msg_inicial_colunas; col++){
			matriz_booleana[lin][col] = 0;
		}
	}
}

void printa_matriz(void){
	int i, j;
	for(i = 0; i < msg_inicial_linhas; i++){
		for(j = 0; j < msg_inicial_colunas; j++){
			if(matriz_booleana[i][j] == 0) printf(" ");
			else printf("%lc", msg_incial[i][j]);
		}
		printf("\n");
	}
}

void left_to_right(void){
	int i, j;
	zera_matriz_booleana();
	
	for(j = 0; j < msg_inicial_colunas; j++){
		for(i = 0; i < msg_inicial_linhas; i++){
			matriz_booleana[i][j] = 1;
		}
	 	system("clear");
		printa_matriz();
		usleep(67000);
	}
}	

int get_opcao(int limite) {
    int n;
    while (1) {
        printf("Selecione uma opção: ");
        scanf("%d%*c", &n);
        if (n >= 0 && n < limite)
            return n;
    }
}

string get_string(string mensagem) {
    char c;
    string str = (char*) malloc(16);
    if (str == NULL) {
        free(str);
        return NULL;
    }
    long unsigned int tamanho = 0;

    do {
        printf("%s", mensagem);
        while ((c = fgetc(stdin)) != '\n' && c != EOF) {
            str = (char*) realloc(str, tamanho + 1);
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