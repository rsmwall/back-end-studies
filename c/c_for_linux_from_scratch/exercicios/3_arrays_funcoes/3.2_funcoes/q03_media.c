// Crie um protótipo de função para a função calcularMedia que recebe três números de ponto flutuante como parâmetros 
// e retorna a média deles. Em seguida, defina a função calcularMedia e chame-a.

#include <stdio.h>

// prototype
float calcularMedia(float a, float b, float c);

float calcularMedia(float a, float b, float c) {
    return (a + b + c) / 3;
}

int main(void) {
    printf("A media eh %.2f\n", calcularMedia(2.3, 5.7, 14.2));
    return 0;
}