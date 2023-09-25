/*
    Escreva um programa em C que calcule e imprima a média dos valores em um array de números inteiros. 
    O programa deve pedir ao usuário o tamanho do array e, em seguida, solicitar os valores. Em seguida, 
    ele deve calcular a média desses valores e imprimi-la na tela.
*/

#include <stdio.h>

int main(void) {
    int tamanho = 0;

    // receber o tamanho
    printf("Digite quantos elementos terá o array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    int indice = 0;
    int num = 0;

    // receber os valores
    do {
        printf("Digite um valor: ");
        scanf("%d", &num);
        array[indice] = num;
        indice++;
    } while (indice < tamanho);

    int soma = 0;
    indice = 0;

    while (indice < tamanho) {
        soma += array[indice];
        indice++;
    }

    float resultado = (float)soma / tamanho;

    printf("A média dos valores do array é: %.2f\n", resultado);

    return 0;
}
