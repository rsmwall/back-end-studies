#include <stdio.h>

// prototipo de funcao
// declara-se uma funcao antes da sua definicao ou chamada
// permite ao compilador saber da existencia da funcao antes de encontra-la no codigo
// podendo ser feita no codigo-fonte ou em um arquivo cabecalho separado (.h)
// tipo_retorno nome_funcao(tipo_parametro parametro,...);
int funcao_teste(int a, float b);    

// definicao de funcao
// tipo_retorno nome_funcao(tipo_paramentro parametro,...){}
int funcao_teste(int a, float b) {}

// retorno de funcao
int soma(int a, int b) {
    return a +b;
}

int main() {
    // chamada de funcao
    // tipo_retorno resultado = nome_funcao(arg1, arg2,...);
    int teste = funcao_teste(2, 3.5);

    return 0;
}