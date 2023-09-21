// Escreva um programa que peça ao usuário para inserir um número e, em seguida, determine se ele é um número Armstrong (também conhecido como número narcisista). 
// Um número Armstrong é aquele cuja soma dos cubos de seus dígitos é igual ao próprio número.

#include <stdio.h>
#include <math.h>

int main() {
    int numero, numero_original, soma_cubos = 0;
    int num_digitos = 0, digito;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    numero_original = numero;

    // Contar o número de dígitos no número
    while (numero != 0) {
        numero /= 10;
        num_digitos++;
    }

    numero = numero_original;  // Restaurar o valor original

    // Calcular a soma dos cubos dos dígitos
    while (numero != 0) {
        digito = numero % 10;
        soma_cubos += pow(digito, num_digitos);
        numero /= 10;
    }

    if (soma_cubos == numero_original) {
        printf("%d eh um numero Armstrong.\n", numero_original);
    } else {
        printf("%d nao eh um numero Armstrong.\n", numero_original);
    }

    return 0;
}
