// Crie um programa que solicite ao usuário seu nome e, em seguida, imprima uma mensagem de boas-vindas usando o nome fornecido.

#include <stdio.h>

int main() {
    char nome[20];

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Bem-vindo(a) %s\n", nome);

    return 0;
}