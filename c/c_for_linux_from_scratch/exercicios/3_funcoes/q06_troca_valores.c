// Escreva uma função chamada trocar que recebe duas variáveis inteiras como parâmetros e troca seus valores. 
// Chame a função e imprima os valores antes e depois da chamada.

#include <stdio.h>

// Protótipo da função
void troca(int *a, int *b);

int main(void) {
    int num1 = 2, num2 = 3;

    printf("Os números são: %d e %d\n", num1, num2);

    // Chamando a função
    troca(&num1, &num2);

    printf("Os números trocados são: %d e %d\n", num1, num2);
    
    return 0;
}

// Implementação da função
void troca(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
