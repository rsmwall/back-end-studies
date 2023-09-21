// Crie um programa que imprima a série de Fibonacci até o décimo termo. A série de Fibonacci começa com 0 e 1, e 
// os termos subsequentes são a soma dos dois termos anteriores.

#include <stdio.h>

int main() {
    int termo_atual = 0;
    int termo_anterior = 1;
    int proximo_termo;

    printf("Serie de Fibonacci ate o decimo termo:\n");

    for (int i = 0; i < 10; i++) {
        if (i <= 1) {
            proximo_termo = i;
        } else {
            proximo_termo = termo_atual + termo_anterior;
            termo_anterior = termo_atual;
        }

        termo_atual = proximo_termo;

        printf("%d ", termo_atual);
    }

    printf("\n");

    return 0;
}
