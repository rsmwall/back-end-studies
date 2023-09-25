#include <stdio.h>

// declarao da funcao (prototipo)
int soma(int a, int b);

int main() {
    int resultado;

    // chamada funcao
    resultado = soma(2, 3);

    printf("%d\n", resultado);

    return 0;
}

// definicao de funcao
int soma(int a, int b) {
    return a + b;
}
