#include <stdio.h>

int main(void) {
    // declaracao de array
    // tipo nome[tamanho];
    int numero[5];

    // inicializacao de array
    int numeros[] = {1, 2, 3, 4, 5}; // array de 5 elementos

    // acesso a elementos de array, usando os indices
    int num1 = numeros[0];

    // o tamanho eh definido apos a declaracao e nao pode ser alterado
    // para saber o tamanho em bytes podemos usar
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("%d", tamanho);

    return 0;
}