// Faça um programa que calcule a soma dos números pares de 1 a 100.

#include <stdio.h>

int main() {
    int soma = 0;

    for (int i = 2; i <= 100; i += 2) {
        soma += i;
    }

    printf("A soma de todos os numeros pares entre 1 e 100 eh %d\n", soma);

    return 0;
}