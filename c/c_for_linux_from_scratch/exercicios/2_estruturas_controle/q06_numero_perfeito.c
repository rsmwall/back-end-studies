// Escreva um programa que leia um número inteiro e determine se ele é um número perfeito. 
// Um número perfeito é aquele cuja soma de seus divisores (excluindo ele mesmo) é igual ao próprio número.

#include <stdio.h>

int main() {
    int numero, somaDivisores = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Verifique os divisores do número
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            somaDivisores += i;
        }
    }

    // Verifique se o número é perfeito
    if (somaDivisores == numero) {
        printf("%d eh um numero perfeito.\n", numero);
    } else {
        printf("%d nao eh um numero perfeito.\n", numero);
    }

    return 0;
}
