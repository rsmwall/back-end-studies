// Crie um programa que peça ao usuário para digitar dois números inteiros e, em seguida, determine se o primeiro número é divisível pelo segundo. Exiba uma mensagem apropriada.

#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    if (numero2 != 0) {
        if (numero1 % numero2 == 0) {
            printf("%d eh divisivel por %d\n", numero1, numero2);
        } else {
            printf("%d nao eh divisivel por %d\n", numero1, numero2);
        }
    } else {
        printf("Nao eh possivel dividir por 0.\n");
    }

    return 0;
}