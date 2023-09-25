/*
    Escreva um programa em C que encontre o valor máximo em um array de inteiros. O tamanho do 
    array e os valores dos elementos devem ser inseridos pelo usuário. Por favor, forneça sua resposta quando estiver pronto.
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

    int maximo = array[0]; // Inicialize maximo com o primeiro elemento do array
    indice = 1; // Comece a verificar a partir do segundo elemento

    while (indice < tamanho) {
        if (array[indice] > maximo) {
            maximo = array[indice];
        }
        indice++;
    }

    printf("O numero maximo do array eh: %d\n", maximo);

    return 0;
}
