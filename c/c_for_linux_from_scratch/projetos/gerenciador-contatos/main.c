#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> // funcao sleep
#include <ctype.h> // funcao tolower, isspace e toupper

#include "contatos.h" // header personalizado

// estrutura de contato
struct Contato {
    int chave; // chave incrementada a cada adicao
    char *nome;
    char *telefone;
};

// array de estrutura
struct Contato listaContatos[10];
struct Contato novoContato; // estrutura do tipo contato para receber o novo contato

int tamanho = sizeof(listaContatos) / sizeof(listaContatos[0]); // tamanho do array
int tamanho_atual = 0; // qtd de contatos cadastrados

char *mensagem = NULL; // mensagem usada para alertas

// menu principal
void menu() {
    int opcao = 0;

    system("clear");

    printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");

    printf("\e[1mNumero de contatos: \033[32m%02d\033[0m\e[1m contatos\n\n", tamanho_atual);

    printf("1. Adicionar Contatos\n");
    printf("2. Excluir Contatos\n");
    printf("3. Listar Contatos\n");
    printf("4. Pesquisar Contatos\n");
    printf("5. Atualizar Contatos\n");
    printf("6. Sair\n\n");

    printf("Opcao:\e[m ");
    scanf("%d", &opcao);

    getchar(); // consumir o caractere de nova linha residual do scanf

    switch (opcao) {
    case 1:
        receberContato('\0', -1);
        break;
    
    case 2:
        excluirContato();
        break;

    case 3:
        listarContato();
        break;

    case 4:
        pesquisarContatos();
        break;

    case 5:
        atualizarContato('\0', -1);
        break;

    case 6:
        system("clear");
        printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
        sleep(1);
        system("clear");
        break;

    default:
        system("clear");
        printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
        break;
    }
}

void atualizarContato(char *contato_add, int opcao_add) {
    char contato[50];
    char dado[50];
    int opcao;
    int indice_buscado;

    if (opcao_add == -1) {
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ ATUALIZAR CONTATOS\033[0m\n\n");
        printf("\e[1mDigite o contato a ser atualizado:\e[m ");
        fgets(contato, sizeof(contato), stdin);

        // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
        if (contato[strlen(contato) - 1] == '\n') {
            contato[strlen(contato) - 1] = '\0'; // coloca \0 para encerrar a string
        }

        paraMinuscula(contato);

        indice_buscado = buscarContato(1, contato);   
    } else if (opcao_add == 1) {
        strcpy(contato, contato_add);

        // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
        if (contato[strlen(contato) - 1] == '\n') {
            contato[strlen(contato) - 1] = '\0'; // coloca \0 para encerrar a string
        }

        paraMinuscula(contato);
        indice_buscado = buscarContato(1, contato);
    } else if (opcao_add == 2) {
        strcpy(contato, contato_add);

        indice_buscado = buscarContato(2, contato);
    }

    // verifica o resultado do indice
    if (indice_buscado != -1) {
        // for para capitalizar os nomes apos verificacao
        for (int i = 0; i < tamanho_atual; i++) {
            capitalize(listaContatos[i].nome);
        }

        if (opcao_add == -1) {
            system("clear");

            // mostrar contato encontrado
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ATUALIZAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ENCONTRADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_buscado].chave ,listaContatos[indice_buscado].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_buscado].telefone);

            printf("\e[1mO que deseja atualizar no contato:\n\n");
            printf("1. Nome\n");
            printf("2. Telefone\n");
            printf("3. Cancelar\n\n");

            printf("Opcao:\e[m ");
            scanf("%d", &opcao);
            getchar();
        } else if (opcao_add == 1) {
            system("clear");

            // mostrar contato encontrado
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ATUALIZAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ENCONTRADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_buscado].chave ,listaContatos[indice_buscado].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_buscado].telefone);

            opcao = 2;
        } else if (opcao_add == 2) {
            system("clear");

            // mostrar contato encontrado
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ATUALIZAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ENCONTRADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_buscado].chave ,listaContatos[indice_buscado].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_buscado].telefone);

            opcao = 1;
        }

        if (opcao == 1) {
            printf("\e[1mDigite o novo nome do contato:\e[m ");
            fgets(dado, sizeof(dado), stdin);

            // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
            if (dado[strlen(dado) - 1] == '\n') {
                dado[strlen(dado) - 1] = '\0'; // coloca \0 para encerrar a string
            }

            paraMinuscula(dado);

            // adicionar atualizacao de contato por nome como novo contato
            novoContato.nome = dado;
            novoContato.telefone = listaContatos[indice_buscado].telefone;

            // excluir contato desatualizado
            for (int i = indice_buscado; i < tamanho_atual; i++) {
                listaContatos[i] = listaContatos[i + 1];
                if (listaContatos[i].chave > 0) {
                    listaContatos[i].chave--;
                }
            }
            tamanho_atual--;

            atualizar();
        } else if (opcao == 2) {
            printf("\e[1mDigite o novo telefone do contato:\e[m ");
            scanf("%s", dado);
            getchar();

            listaContatos[indice_buscado].telefone = strdup(dado);

            verificacaoNovaAtualizacao();
        } else if (opcao == 3) {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            atualizarContato('\0', -1);
        }
    } else {
        system("clear");
        printf("\e[1m\033[31mCONTATO NAO ENCONTRADO!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        atualizarContato('\0', -1);
    }
}

void atualizar() {
    if (tamanho_atual != 0) {
        // verificar ordem alfabetica
        int i, j, indice_contato;
        int meio = -1; // variavel de controle para saber se o novo contato vai ser adicionado no meio do array

        for (i = 0; i < tamanho_atual; i++) {
            paraMinuscula(listaContatos[i].nome);
            if (strcmp(novoContato.nome, listaContatos[i].nome) < 0) { // compara se o contato vem antes que o comparado em ordem alfabetica
                indice_contato = i;
                meio = 1;
                break;
            } else {
                meio = 0;
            }
        }

        // for para capitalizar os nomes apos verificacao
        for (i = 0; i < tamanho_atual; i++) {
            capitalize(listaContatos[i].nome);
        }

        capitalize(novoContato.nome);

        // verifica se o elemento vai ser adicioando no meio ou no final da lista
        if (meio == 1) {
            // mover os elementos 1 indice a frente
            for (j = tamanho_atual; j > indice_contato; j--) { // roda os elementos de tras pra frente para movimentacao
                listaContatos[j] = listaContatos[j - 1];
                listaContatos[j].chave++; // acrescenta um em cada chave existente
            }

            listaContatos[indice_contato] = novoContato;
            listaContatos[indice_contato].chave = indice_contato + 1;
            tamanho_atual++;

            verificacaoNovaAtualizacao();
        } else if (meio == 0) {
            listaContatos[tamanho_atual] = novoContato;
            tamanho_atual++;
            verificacaoNovaAtualizacao();
        }

    } else {
        capitalize(novoContato.nome);
        listaContatos[tamanho_atual] = novoContato;
        listaContatos[tamanho_atual].chave = 1;
        tamanho_atual++;
        verificacaoNovaAtualizacao();
    }
}

void verificacaoNovaAtualizacao() {
    char confirmacao;
    system("clear");
    printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
    printf("\e[1m\033[36m⊷ ATUALIZAR CONTATOS\033[0m\n\n");
    printf("\e[1m\033[32mCONTATO ATUALIZADO COM SUCESSO!\033[0m\e[m\n\n");
    printf("\e[1mDeseja atualizar mais algum contato? (s / n):\e[m ");
    scanf("%c", &confirmacao);
    getchar();

    if (confirmacao == 's' || confirmacao == 'S') {
        atualizarContato('\0', -1);
    } else if (confirmacao == 'n' || confirmacao == 'N') {
        system("clear");
        printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    } else {
        system("clear");
        printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    }
}

// pesquisar contatos
void pesquisarContatos() {
    char contato[50];
    int opcao;
    int indice_buscado;

    system("clear");
    printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
    printf("\e[1m\033[36m⊷ PESQUISAR CONTATOS\033[0m\n\n");
    printf("\e[1mDeseja pesquisar o contato atraves de:\n\n");
    printf("1. Nome\n");
    printf("2. Telefone\n");
    printf("3. Cancelar\n\n");

    printf("Opcao:\e[m ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1) {
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ PESQUISAR CONTATOS\033[0m\n\n");
        printf("\e[1mDigite o nome do contato que deseja buscar:\e[m ");
        fgets(contato, sizeof(contato), stdin);

        // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
        if (contato[strlen(contato) - 1] == '\n') {
            contato[strlen(contato) - 1] = '\0'; // coloca \0 para encerrar a string
        }

        paraMinuscula(contato);

        indice_buscado = buscarContato(1, contato);
    } else if (opcao == 2) {
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ PESQUISAR CONTATOS\033[0m\n\n");
        printf("\e[1mDigite o telefone do contato que deseja buscar:\e[m ");
        scanf("%s", contato);
        getchar();

        indice_buscado = buscarContato(2, contato);
    } else if (opcao == 3) {
        system("clear");
        printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    } else {
        system("clear");
        printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        pesquisarContatos();
    }

    for (int i = 0; i < tamanho_atual; i++) {
        capitalize(listaContatos[i].nome);
    }

    // verifica o resultado do indice
    if (indice_buscado != -1) {
        char confirmacao;
        // mostrar contato encontrado
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ PESQUISAR CONTATOS\033[0m\n\n");
        printf("\e[1m\033[32mCONTATO ENCONTRADO!\033[0m\e[m\n\n");
        printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_buscado].chave ,listaContatos[indice_buscado].nome);
        printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_buscado].telefone);

        printf("\e[1mDeseja pesquisar mais algum contato? (s / n):\e[m ");
        scanf("%c", &confirmacao);
        getchar();

        if (confirmacao == 's' || confirmacao == 'S') {
            pesquisarContatos();
        } else if (confirmacao == 'n' || confirmacao == 'N') {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        }
    } else {
        char confirmacao;
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ PESQUISAR CONTATOS\033[0m\n\n");
        printf("\e[1m\033[31mCONTATO NAO ENCONTRADO!\033[0m\e[m\n\n");
        printf("\e[1mDeseja adicionar este contato? (s / n):\e[m ");
        scanf("%c", &confirmacao);
        getchar();

        if (confirmacao == 's' || confirmacao == 'S') {
            receberContato(contato, opcao);
        } else if (confirmacao == 'n' || confirmacao == 'N') {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        }
    }
}

// passar todas as strings para minusculas
void paraMinuscula(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

// passar as strings para capitalize
void capitalize(char *string) {
    int proximo = 1; // variavel de controle para indicar se o proximo caractere vai ser colocado como maiusculo (inicia sendo maiuscula)

    for (int i = 0; string[i]; i++) {
        if (isspace(string[i])) { // se o caractere for espaco, o proximo sera capitalizado
            proximo = 1;
        } else if (proximo) {
            string[i] = toupper(string[i]);
            proximo = 0; // letra foi capitalizada, vai para falso (minuscula)
        } else {
            string[i] = tolower(string[i]);
        }
    }
}

// solicita o novo contato e adiciona na estrutura temporaria
void receberContato(char *contato, int opcao) {
    char nome[50] = "";
    char telefone[15];
    
    if (tamanho_atual < tamanho) { 
        if (opcao == -1) {
            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1mDigite o nome do contato:\e[m ");
            // fgets para receber nome (scanf nao le espacos)
            fgets(nome, sizeof(nome), stdin);

            printf("\n\e[1mDigite o telefone do contato (apenas numeros):\e[m ");
            // sugerido uso de apenas numeros para telefone
            scanf("%s", telefone);
            getchar();
        } else if (opcao == 1) {
            strcpy(nome, contato);

            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1mNome:\e[m \033[32m%s\033[0m\n", nome);

            printf("\n\e[1mDigite o telefone do contato (apenas numeros):\e[m ");
            // sugerido uso de apenas numeros para telefone
            scanf("%s", telefone);
            getchar();
        } else if (opcao == 2) {
            strcpy(telefone, contato);

            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1mTelefone:\e[m \033[32m%s\033[0m\n", telefone);

            printf("\n\e[1mDigite o nome do contato:\e[m ");
            // fgets para receber nome (scanf nao le espacos)
            fgets(nome, sizeof(nome), stdin);
        }

        // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
        if (nome[strlen(nome) - 1] == '\n') {
            nome[strlen(nome) - 1] = '\0'; // coloca \0 para encerrar a string
        }

        paraMinuscula(nome);

        novoContato.chave = tamanho_atual + 1;

        novoContato.nome = strdup(nome);
        novoContato.telefone = strdup(telefone);

        adicionarContato();
    } else {
        system("clear");
        printf("\e[1m\033[31mNUMERO DE CONTATOS MAXIMO ATINGIDO!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    }
}

// adiciona o novo contato ao array principal
void adicionarContato() {
    // procurar se o contato que esta sendo adicionado ja existe
    int contato_achado_nome = buscarContato(1, novoContato.nome);
    int contato_achado_telefone = buscarContato(2, novoContato.telefone);
    int indice_achado = 0;

    char contato[50];
    int opcao;

    if (contato_achado_nome != -1) {
        indice_achado = contato_achado_nome;
        strcpy(contato, novoContato.nome);
        opcao = 1;
    } else if (contato_achado_telefone != -1){
        indice_achado = contato_achado_telefone;
        strcpy(contato, novoContato.telefone);
        opcao = 2;
    } else if ((contato_achado_nome + contato_achado_telefone) != -2){
        indice_achado = contato_achado_nome;
        strcpy(contato, novoContato.nome);
        opcao = 1;
    } else {
        indice_achado = -1;
        opcao = -1;
    }

    if (indice_achado == -1) {
        if (tamanho_atual != 0) {
        // verificar ordem alfabetica
        int i, j, indice_contato;
        int meio = -1; // variavel de controle para saber se o novo contato vai ser adicionado no meio do array

        for (i = 0; i < tamanho_atual; i++) {
            paraMinuscula(listaContatos[i].nome);
            if (strcmp(novoContato.nome, listaContatos[i].nome) < 0) { // compara se o contato vem antes que o comparado em ordem alfabetica
                indice_contato = i;
                meio = 1;
                break;
            } else {
                meio = 0;
            }
        }

        // for para capitalizar os nomes apos verificacao
        for (i = 0; i < tamanho_atual; i++) {
            capitalize(listaContatos[i].nome);
        }

        capitalize(novoContato.nome);

        // verifica se o elemento vai ser adicioando no meio ou no final da lista
        if (meio == 1) {
            // mover os elementos 1 indice a frente
            for (j = tamanho_atual; j > indice_contato; j--) { // roda os elementos de tras pra frente para movimentacao
                listaContatos[j] = listaContatos[j - 1];
                listaContatos[j].chave++; // acrescenta um em cada chave existente
            }

            listaContatos[indice_contato] = novoContato;
            listaContatos[indice_contato].chave = indice_contato + 1;
            tamanho_atual++;

            // mostrar contato encontrado
            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ADICIONADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_contato].chave ,listaContatos[indice_contato].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_contato].telefone);
        } else if (meio == 0) {
            listaContatos[tamanho_atual] = novoContato;
            tamanho_atual++;

            // mostrar contato encontrado
            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ADICIONADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[tamanho_atual - 1].chave ,listaContatos[tamanho_atual - 1].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[tamanho_atual - 1].telefone);
        }

        } else {
            capitalize(novoContato.nome);
            listaContatos[tamanho_atual] = novoContato;
            tamanho_atual++;

            // mostrar contato encontrado
            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO ADICIONADO!\033[0m\e[m\n\n");
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[tamanho_atual - 1].chave ,listaContatos[tamanho_atual - 1].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[tamanho_atual - 1].telefone);
        }
        char escolha;

        printf("\e[1mDeseja adicionar mais algum contato? (s / n):\e[m ");
        scanf("%c", &escolha);
        getchar();

        if (escolha == 's' || escolha == 'S') {
            receberContato('\0', -1);
        } else if (escolha == 'n' || escolha == 'N') {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        }
    } else {
        capitalize(listaContatos[indice_achado].nome);
        // mostrar contato encontrado
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ ADICIONAR CONTATOS\033[0m\n\n");
        printf("\e[1m\033[31mCONTATO JA EXISTENTE!\033[0m\e[m\n\n");
        printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_achado].chave ,listaContatos[indice_achado].nome);
        printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_achado].telefone);

        char confirmacao;
        printf("\e[1mDeseja atualizar este contato? (s / n):\e[m ");
        scanf("%c", &confirmacao);
        getchar();

        if (confirmacao == 's' || confirmacao == 'S') {
            atualizarContato(contato, opcao);
        } else if (confirmacao == 'n' || confirmacao == 'N') {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        }
    }
}

int buscarContato(char opcao, char *contato) {   
    int indice_contato = -1;
    int i = 0;
    if (opcao == 1) {
        // percorrer o array
        for (i = 0; i < tamanho_atual; i++) {
            paraMinuscula(listaContatos[i].nome);
            if (strcmp(listaContatos[i].nome, contato) == 0) {
                indice_contato = i;
                return indice_contato;
            }
        }
    } else if (opcao == 2) {
        // percorrer o array
        for (i = 0; i < tamanho_atual; i++) {
            paraMinuscula(listaContatos[i].nome);
            if (strcmp(listaContatos[i].telefone, contato) == 0) {
                indice_contato = i;
                return indice_contato;
            }
        }
    }

    return indice_contato;
}

void excluirContato() {
    char contato[50];
    int opcao;
    int indice_buscado;

    system("clear");
    printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
    printf("\e[1m\033[36m⊷ EXCLUIR CONTATOS\033[0m\n\n");
    printf("\e[1mDeseja excluir o contato atraves de:\n\n");
    printf("1. Nome\n");
    printf("2. Telefone\n");
    printf("3. Cancelar\n\n");

    printf("Opcao:\e[m ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1) {
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ EXCLUIR CONTATOS\033[0m\n\n");
        printf("\e[1mDigite o nome do contato a ser excluido:\e[m ");
        fgets(contato, sizeof(contato), stdin);

        // fgets le a quebra de linha e a adiciona na string como \n, if para remove-lo
        if (contato[strlen(contato) - 1] == '\n') {
            contato[strlen(contato) - 1] = '\0'; // coloca \0 para encerrar a string
        }

        paraMinuscula(contato);

        indice_buscado = buscarContato(1, contato);
    } else if (opcao == 2) {
        system("clear");
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ EXCLUIR CONTATOS\033[0m\n\n");
        printf("\e[1mDigite o telefone do contato a ser excluido:\e[m ");
        scanf("%s", contato);
        getchar();

        indice_buscado = buscarContato(2, contato);
    } else if (opcao == 3) {
        system("clear");
        printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    } else {
        system("clear");
        printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        excluirContato();
    }

    for (int i = 0; i < tamanho_atual; i++) {
        capitalize(listaContatos[i].nome);
    }

    // verifica o resultado do indice
    if (indice_buscado != -1) {
        char confirmacao;
        system("clear");

        // mostrar contato encontrado
        printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
        printf("\e[1m\033[36m⊷ EXCLUIR CONTATOS\033[0m\n\n");
        printf("\e[1m\033[32mCONTATO ENCONTRADO!\033[0m\e[m\n\n");
        printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice_buscado].chave ,listaContatos[indice_buscado].nome);
        printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice_buscado].telefone);

        printf("\e[1mDeseja exclui-lo permanentemente? (s / n):\e[m ");
        scanf("%c", &confirmacao);
        getchar();

        if (confirmacao == 's' || confirmacao == 'S') {
            for (int i = indice_buscado; i < tamanho_atual; i++) {
                listaContatos[i] = listaContatos[i + 1];
                if (listaContatos[i].chave > 0) {
                    listaContatos[i].chave--;
                }
            }
            tamanho_atual--;

            system("clear");
            printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
            printf("\e[1m\033[36m⊷ EXCLUIR CONTATOS\033[0m\n\n");
            printf("\e[1m\033[32mCONTATO EXCLUIDO COM SUCESSO!\033[0m\e[m\n\n");

            char nova_exclusao;

            printf("\e[1mDeseja excluir mais algum contato? (s / n):\e[m ");
            scanf("%c", &nova_exclusao);

            // verificar se o usuario quer fazer uma nova exclusao
            if (nova_exclusao == 's' || nova_exclusao == 'S') {
                excluirContato();
            } else if (nova_exclusao == 'n' || nova_exclusao == 'N') {
                system("clear");
                printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
                sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

                menu();
            } else {
                system("clear");
                printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
                sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

                menu();
            }
        } else if (confirmacao == 'n' || confirmacao == 'N') {
            system("clear");
            printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        } else {
            system("clear");
            printf("\e[1m\033[31mOPCAO INVALIDA!\033[0m\e[m\n\n");
            sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

            menu();
        }
    } else {
        system("clear");
        printf("\e[1m\033[31mCONTATO NAO ENCONTRADO!\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        excluirContato();
    }
}

void voltarMenu() {
    char escolha;

    do {
        printf("\e[1mVoltar ao menu principal (S): \e[m");
        scanf(" %c", &escolha); // incluso um espaço antes de %c para ignorar espaços em branco
        getchar(); // consumir o caractere de nova linha
    } while (escolha != 's' && escolha != 'S');

    if (escolha == 's' || escolha == 'S') {
        system("clear");
        printf("\e[1m\033[33mSAINDO...\033[0m\e[m\n\n");
        sleep(1); // tempo de espera ate que apareca o menu novamente apos a mensagem

        menu();
    }
}

// exibe todos os contatos da lista
void listarContato() {  
    system("clear");
    printf("\e[1m\033[34m═══════════════ CONTATOS ═══════════════\033[0m\e[m\n\n");
    printf("\e[1m\033[36m⊷ LISTAR CONTATOS\033[0m\n\n");
    printf("\e[1mNumero de contatos: \033[32m%02d\033[0m\e[1m contatos\n\n", tamanho_atual);
    if (tamanho_atual != 0) {
        int indice = 0;

        while (indice < tamanho_atual) {
            printf("\e[1m%02d - Nome:\e[m \033[32m%s\033[0m\n", listaContatos[indice].chave ,listaContatos[indice].nome);
            printf("\e[1m     Fone:\e[m \033[32m%s\033[0m\n\n", listaContatos[indice].telefone);
            indice++;
        }
    }
    voltarMenu();
}

int main(void) {
    menu();
    return 0;
}
