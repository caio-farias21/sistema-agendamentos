#include <stdio.h>

typedef void (*Func)();

typedef struct Opcao {
    Func func;
    struct Opcao *next;
} Opcao;