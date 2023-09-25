/*
    Escreva um programa em C que solicite ao usuário que insira o tamanho de um array e, 
    em seguida, insira os elementos desse array. O programa deve, então, solicitar ao usuário 
    que insira um valor para verificar se ele existe no array. O programa deve imprimir uma 
    mensagem informando se o valor existe ou não no array.
*/

#include <stdio.h>

int main(void) {
    int tamanho = 0;

    // Receber o tamanho do array
    printf("Digite quantos elementos terá o array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    // Receber os valores do array
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int valorProcurado;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valorProcurado);

    int encontrado = 0; // Variável para indicar se o valor foi encontrado

    // Verificar se o valor existe no array
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valorProcurado) {
            encontrado = 1;
            break; // Valor encontrado, não é necessário continuar a busca
        }
    }

    // Imprimir mensagem de acordo com o resultado
    if (encontrado) {
        printf("O valor %d existe no array.\n", valorProcurado);
    } else {
        printf("O valor %d não existe no array.\n", valorProcurado);
    }

    return 0;
}
