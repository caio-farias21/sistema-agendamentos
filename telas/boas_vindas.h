#include <stdio.h>

void tela_boas_vindas(char * nome) {
    printf("Olá,\n");
    printf("%s\n\n", *nome);
    printf("----------------------\n\n");
}

void tela_menu() {
    
}

/*
Olá,
<Nome completo>

----------------------

Menu

[ 0 ] - Sair
[ 1 ] - Reservar sala
[ 2 ] - Ver detalhes

se ADMIN:
[ 3 ] - Cadastrar novo usuario
[ 4 ] - Cadastro de salas

Selecione uma opçao: 
*/