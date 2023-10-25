#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>

void func1() {
    printf("Impresso com essa função 1!\n");
}
 void func2() {
   printf("Impresso com essa função 2!\n");
}

void wrapper(Func a[], int n) {
    for (int i = 0; i < 2; i++)
        a[i]();
}

int main() {
    Opcao *a = malloc(sizeof(Opcao));
    Opcao *b = malloc(sizeof(Opcao));

    b->func = func2;
    b->next = NULL;

    a->func = func1;
    a->next = b;

    a->func();
    a = a->next;
    a->func();

    
}