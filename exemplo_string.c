#include "tipos.h"
#include "helpers.h"
#include "auth.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    string texto = get_string("Digite o que está pensando: ");
    printf("O que você digitou foi: %s\n", texto);
}