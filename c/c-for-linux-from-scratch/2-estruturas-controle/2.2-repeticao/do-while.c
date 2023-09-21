#include <stdio.h>

int main() {
    int contador = 0;

    do {
        printf("Contador: %d\n", contador);
        contador++;
    } while (contador < 5);

    return 0;
}