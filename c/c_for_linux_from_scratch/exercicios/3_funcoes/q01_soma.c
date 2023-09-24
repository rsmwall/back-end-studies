// Escreva uma função chamada soma que recebe dois números inteiros como parâmetros 
// e retorna a soma deles. Em seguida, chame a função soma com alguns valores e imprima o resultado.

#include <stdio.h>

// prototypes
int sum(int number1, int number2);

int main() {
    int result;

    result = sum(2, 4);

    printf("A soma eh %d\n", result);

    return 0;
}

// function sum
int sum(int number1, int number2) {
    return number1 + number2;
}