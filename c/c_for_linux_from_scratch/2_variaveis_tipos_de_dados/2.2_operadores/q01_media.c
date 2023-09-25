// Escreva um programa que calcule a média de três notas de um aluno. Use nomes de variáveis descritivos para as notas e a média.

#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("A media do aluno eh %.1f\n", media);

    return 0;
}