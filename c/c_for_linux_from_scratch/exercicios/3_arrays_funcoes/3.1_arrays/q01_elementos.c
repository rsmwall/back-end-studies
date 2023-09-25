/*
    Escreva um programa em C que calcule a soma de todos os elementos de um array de inteiros. 
    O tamanho do array e os valores dos elementos devem ser inseridos pelo usuário.
*/

#include <stdio.h>

int main(void) {
    int tamanho = 0;

    // receber o tamanho
    printf("Digite quantos numeros quer somar: ");
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

    //somar
    int soma = 0;
    indice = 0;

    while (indice < tamanho) {
        soma += array[indice];
        indice++;
    }

    printf("A soma dos numeros digitados eh: %d\n", soma);

    return 0;
}