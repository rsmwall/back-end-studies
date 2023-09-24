/*
    Escreva uma função chamada mediaPonderada que calcule a média ponderada de um conjunto de números, 
    onde cada número tem um peso associado. A função deve receber dois arrays: um array de números e outro 
    array de pesos. A média ponderada é calculada multiplicando cada número pelo seu peso correspondente, 
    somando esses produtos e dividindo pela soma dos pesos. Chame a função com diferentes conjuntos de números e pesos.
*/

#include <stdio.h>
#include <stdlib.h>

// prototypes
float mediaPonderada(float valores[], float pesos[], int val_tam, int pes_tam);
int verificaValores(float val_tam, float pes_tam);

int verificaValores(float val_tam, float pes_tam) {
        // verificacao
        if (val_tam == pes_tam) {
            return val_tam;
        }

        return -1;
}

float mediaPonderada(float valores[], float pesos[], int val_tam, int pes_tam) {
    // verificar se o numero de pesos corresponde ao numero de valores
    int tamanho = verificaValores(val_tam, pes_tam);
    float somas = 0.0,
          resultado = 0.0;
    
    if (tamanho == -1) {
        perror("Numero de valores e pesos nao correspondentes");
        exit(EXIT_FAILURE);
    } else {
        // calculo
        for (int i = 0; i < tamanho; i++) {
            somas += valores[i] * pesos[i];
        }
        resultado = somas / tamanho;
    }
    return resultado;
}

int main(void) {
    float val1[] = {2.3, 4.1, 6.3, 9.5, '\0'};
    float pes1[] = {2, 5, 7, 2, '\0'};
    int val_tam1 = sizeof(val1) / sizeof(val1[0]);
    int pes_tam1 = sizeof(pes1) / sizeof(pes1[0]);
    float res1 = mediaPonderada(val1, pes1, val_tam1, pes_tam1);

    float val2[] = {5.3, 4.9, 3.3, '\0'};
    float pes2[] = {9, 4, 10, '\0'};
    int val_tam2 = sizeof(val2) / sizeof(val2[0]);
    int pes_tam2 = sizeof(pes2) / sizeof(pes2[0]);
    float res2 = mediaPonderada(val2, pes2, val_tam2, pes_tam2);

    printf("A media ponderada dos valores 01 eh: %.2f\n", res1);
    printf("A media ponderada dos valores 02 eh: %.2f\n", res2);

    return 0;
}