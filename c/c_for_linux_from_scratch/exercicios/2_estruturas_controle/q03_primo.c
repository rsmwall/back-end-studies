// Desenvolva um programa que solicite ao usuário um número e, em seguida, determine se ele é um número primo ou não. Um número primo é aquele que é divisível apenas por 1 e por ele mesmo.

#include <stdio.h>

int main() {
    int numero, i;
    int ehPrimo = 1;  // Assumimos inicialmente que o número é primo

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero <= 1) {
        ehPrimo = 0;  // Números menores ou iguais a 1 não são primos
    } else {
        for (i = 2; i <= numero / 2; i++) {
            if (numero % i == 0) {
                ehPrimo = 0;  // Encontramos um divisor, portanto, não é primo
                break;        // Não é necessário continuar verificando
            }
        }
    }

    if (ehPrimo) {
        printf("%d eh primo.\n", numero);
    } else {
        printf("%d nao eh primo.\n", numero);
    }

    return 0;
}