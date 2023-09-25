// Escreva um programa que peça ao usuário para inserir dois números inteiros e, em seguida, calcule a soma e a média desses números, exibindo os resultados.

#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    printf("A soma dos numeros digitados eh %d e a media eh %d\n", numero1 + numero2, (numero1 + numero2) / 2);

    return 0;
}