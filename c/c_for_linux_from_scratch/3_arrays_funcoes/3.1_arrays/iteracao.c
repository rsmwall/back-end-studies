#include <stdio.h>

int main(void) {
    // iterando arrays
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}