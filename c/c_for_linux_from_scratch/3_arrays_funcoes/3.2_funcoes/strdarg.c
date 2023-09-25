// Em C, você pode criar uma função que aceita um número indefinido de argumentos usando a biblioteca 
// de cabeçalho stdarg.h e as macros va_list, va_start, va_arg, e va_end. Essas macros permitem que você 
// processe argumentos variáveis passados para a função. Aqui está um exemplo de como fazer isso

#include <stdio.h>
#include <stdarg.h>

int somar(int num_args, ...) {
    int soma = 0;
    va_list args;
    
    va_start(args, num_args);

    for (int i = 0; i < num_args; i++) {
        int arg = va_arg(args, int);
        soma += arg;
    }

    va_end(args);

    return soma;
}

int main() {
    int resultado1 = somar(3, 10, 20, 30);
    int resultado2 = somar(5, 5, 10, 15, 20, 25);

    printf("Resultado 1: %d\n", resultado1);
    printf("Resultado 2: %d\n", resultado2);

    return 0;
}

/*
    Neste exemplo, a função somar aceita um número indefinido de argumentos inteiros. O primeiro argumento, 
    num_args, especifica quantos argumentos adicionais serão passados. A função usa va_list, va_start, va_arg 
    e va_end para processar os argumentos variáveis e calcular a soma.

    Observe que, ao usar esse método, você precisa fornecer o número de argumentos como o primeiro argumento. 
    Portanto, é importante que a função conheça antecipadamente quantos argumentos espera receber.
*/