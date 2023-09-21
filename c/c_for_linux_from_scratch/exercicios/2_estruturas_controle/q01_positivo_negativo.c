// Escreva um programa que determine se um número é positivo, negativo ou zero. Peça ao usuário para inserir um número e, em seguida, imprima a classificação.

#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Numero eh negativo.\n");
    } else if (numero > 0) {
        printf("Numero eh positivo.\n");
    } else {
        printf("Numero eh igual a 0.\n");
    }

    return 0;
}