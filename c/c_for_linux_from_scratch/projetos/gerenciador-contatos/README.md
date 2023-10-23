# Projeto de Gerenciamento de Contatos Simples em C

Objetivo do Projeto: Criar um programa simples de gerenciamento de contatos em C que permita ao usuário adicionar informações de contato, listar todos os contatos e pesquisar por nome.

## Recursos do Programa:

- Adicionar Contato: O usuário pode adicionar informações de contato, incluindo nome e número de telefone. Os contatos serão armazenados em um array.

- Listar Contatos: O usuário pode listar todos os contatos armazenados. O programa exibirá o nome e o número de telefone de cada contato.

- Pesquisar Contato por Nome: O usuário pode pesquisar um contato por nome. O programa exibirá as informações do contato, incluindo nome e número de telefone, se o contato existir.

- Menu de Opções: O programa deve oferecer um menu de opções que permite ao usuário escolher entre as operações disponíveis, como adicionar, listar ou pesquisar contatos.

## Requisitos Técnicos:

- Use um array de estruturas para armazenar os contatos, com campos para nome e número de telefone.

- Implemente funções separadas para cada operação (adicionar, listar e pesquisar contatos).

- Gerencie a quantidade de contatos armazenados no array.

- Implemente um loop principal que apresente o menu de opções e permita ao usuário interagir com o programa.

- Lide com situações em que o array de contatos está cheio ou vazio.
    
- Limite o número de contatos a um valor razoável, como 10, para manter o programa simples.

Este projeto aborda os conceitos de estruturas, funções, arrays e controle de fluxo que foram ensinados até a aula 3.2 sobre funções.

## Recursos adicionados:

Foram adicionados os recursos solicitados e mais alguns listados abaixo:

### Versao 1.0

- [x] Adicionar Contato
    - [x] Receber e armazenar os contatos
    - [x] Guardar cada contato com um contador unitario e incrementa-lo seguindo a ordem estabelecida
    - [x] Adicionar os contatos em ordem alfabetica
    - [x] Aviso de espaco cheio
    - [x] Questionar atualizacao de contato existente em caso de nova adicao igual (baseada no nome e telefone)

* Alguns pontos sobre recursos adicionados:
    - para evitar erros em relacao a maiusculas e minusculas, o sistema converte tudo para minusculo para comparar e depois capitaliza os nomes
    - eh mostrado uma mensagem de confirmacao quando o contato for adicionado
    
- [x] Listar Contatos

- [x] Pesquisar Contato
    - [x] Pesquisar por nome
    - [x] Pesquisar por telefone
    - [x] Aviso de contato inexistente
    - [x] Solicitacao se deseja adicionar o contato
    - [x] Guardar dado pesquisado para adicao

- [x] Excluir Contato

* Alguns pontos sobre os recursos adicionados:
    - foi adicionado a opcao de exclusao que nao estava no plano original
    - sera permitido excluir atraves do nome ou do telefone
    - ao ser solicitado uma exclusao, se o contato existir, este sera mostrado e ira ser solicitado uma confirmacao
    - se o contato nao existir, havera uma mensagem de erro e um questionamento de excluir outro ou voltar ao menu

- [x] Atualizar Contato

* Alguns pontos sobre os recursos adicionados:
    - quando for alterado o nome o contato sera excluido e cadastrado novamente, para manter a ordem alfabetica
    
- [x] Menu de opcoes

#### Recursos em planejamento

- Verificacao de telefone usando regex
