// Escreva uma função recursiva chamada fatorial que calcula 
// o fatorial de um número inteiro não negativo. Teste a função com diferentes valores.

#include <stdio.h>

int fatorial(int numero);

int fatorial(int numero) {
    if (numero <= 1) {
        return 1; // Caso base: fatorial de 0 ou 1 é 1
    } else {
        return numero * fatorial(numero - 1); // Chamada recursiva
    }
}

int main(void) {
    int numero = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("O fatorial de %d! eh %d\n", numero, fatorial(numero));
    return 0;
}
