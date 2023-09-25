/*
    Escreva um programa em C que solicite ao usuário que insira o tamanho de um array e, 
    em seguida, insira os elementos desse array. O programa deve encontrar e imprimir o maior e o menor valor no array.
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

    int maximo = array[0],
        minimo = array[0];
    indice = 1; // Comece a verificar a partir do segundo elemento

    while (indice < tamanho) {
        if (array[indice] > maximo) {
            maximo = array[indice];
        } else {
            minimo = array[indice];
        }
        indice++;
    }

    printf("O numero maximo do array eh: %d, e o minimo eh %d\n", maximo, minimo);

    return 0;
}
