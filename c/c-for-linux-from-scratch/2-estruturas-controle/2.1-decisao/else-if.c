#include <stdio.h>

int main() {
    int numero = 5;

    if (numero > 5) {
        printf("O numero eh maior que 5.\n");
    } else if (numero == 5) {
        printf("O numero eh igual a 5.\n");
    } else {
        printf("O numero eh menor que 5.\n");
    }

    return 0;
}