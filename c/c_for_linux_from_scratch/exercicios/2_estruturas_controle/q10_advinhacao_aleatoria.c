// Desenvolva um programa que simule um jogo de adivinhação. O programa deve gerar um número aleatório e pedir ao 
// usuário que adivinhe qual é esse número. Forneça dicas para ajudar o usuário a adivinhar.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = 1 + (rand() % 100), chute_usuario = -1;

    while (chute_usuario != numero) {
        printf("Digite o numero que voce acha que eh: ");
        scanf("%d", &chute_usuario);

        if (chute_usuario != -1) {
            if (chute_usuario > numero) {
                printf("O numero eh menor do que seu chute\n");
            } else {
                printf("O numero eh maior que seu chute\n");
            }
        }
    }

    printf("Voce acertou o numero, era %d\n", numero);
    

    return 0;
}