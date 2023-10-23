#ifndef CONTATOS_H
#define CONTATOS_H

void menu();
void paraMinuscula(char *string);
void capitalize(char *string);
void voltarMenu();
int buscarContato(char opcao, char *contato);
void receberContato(char *contato, int opcao);
void adicionarContato();
void listarContato();
void excluirContato();
void pesquisarContatos();
void atualizarContato(char *contato_add, int opcao_add);
void atualizar();
void verificacaoNovaAtualizacao();

#endif