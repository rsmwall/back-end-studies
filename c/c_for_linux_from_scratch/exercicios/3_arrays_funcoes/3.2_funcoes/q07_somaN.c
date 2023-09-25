// Escreva uma função chamada somaN que aceita um número variável de argumentos inteiros e retorna a soma de todos eles. 
// Chame a função com diferentes números de argumentos.

#include <stdio.h>
#include <stdarg.h>

// Função que aceita um número variável de argumentos inteiros e retorna a soma
int somaN(int num_args, ...) {
    va_list args; // Declara uma lista de argumentos variável
    va_start(args, num_args); // Inicializa a lista de argumentos

    int soma = 0;
    for (int i = 0; i < num_args; i++) {
        int valor = va_arg(args, int); // Obtém o próximo argumento da lista
        soma += valor;
    }

    va_end(args); // Finaliza a lista de argumentos
    return soma;
}

int main(void) {
    // Chamando a função com diferentes números de argumentos
    int resultado1 = somaN(3, 1, 2, 3); // Soma de 1 + 2 + 3
    int resultado2 = somaN(4, 10, 20, 30, 40); // Soma de 10 + 20 + 30 + 40

    printf("Resultado 1: %d\n", resultado1);
    printf("Resultado 2: %d\n", resultado2);

    return 0;
}
