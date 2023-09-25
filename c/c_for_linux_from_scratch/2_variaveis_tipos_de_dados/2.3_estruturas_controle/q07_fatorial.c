// Desenvolva um programa que calcule o fatorial de um número inteiro não negativo fornecido pelo usuário usando um loop.

#include <stdio.h>

int main() {
    int numero, fatorial_resultado;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    fatorial_resultado = numero;

    for (int i = numero - 1; i >= 1; i--) {
        fatorial_resultado *= i;
    }

    printf("O fatorial de %d! eh %d\n", numero, fatorial_resultado);

    return 0;
}