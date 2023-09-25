#include <stdio.h>

int main(void) {
    // operadores ternarios
    // retornam um valor com base em uma condicao
    // expressao ? se_verdadeiro : se_falso
    int numero = 2;

    (numero % 2 == 0) ? printf("O número é par.\n") : printf("O número é ímpar.\n");

    return 0;
}