// Crie um programa que peça ao usuário para adivinhar um número secreto entre 1 e 100. Dê dicas ao usuário se o número fornecido é muito 
// alto ou muito baixo, e continue pedindo adivinhações até que o número correto seja encontrado.

#include <stdio.h>

int main() {
    int numero = 10, chute_usuario = -1;

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