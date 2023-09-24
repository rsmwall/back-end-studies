// Declare uma variável dentro de uma função e outra fora de todas as funções (global). 
// Tente acessar essas variáveis de diferentes funções e observe como o escopo afeta a visibilidade das variáveis.

#include <stdio.h>

int number = 2; // Variável global

int function() {
    int number2 = 3; // Variável local à função function
    return number2;
}

int function2() {
    int a = number; // Acessando a variável global 'number'
    int b = function(); // Chamando a função 'function' para acessar 'number2'
    return a + b; // Retornando a soma de 'a' e 'b'
}

int main(void) {
    int localVar = 4; // Variável local à função main

    // Acessando variáveis de diferentes escopos
    printf("Variável global 'number': %d\n", number);
    printf("Variável local 'localVar': %d\n", localVar);
    printf("Variável local de 'function()': %d\n", function());
    printf("Variável local de 'function2()': %d\n", function2());

    return 0;
}
