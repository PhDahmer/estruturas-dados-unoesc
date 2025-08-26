// Struct simples Defina uma struct Pessoa com nome e idade. Leia os dados de 3 pessoas em um
// array e mostre na tela.

#include <stdio.h>
#include <string.h>

struct Pessoa { // Definição da struct Pessoa
    char nome[100];
    int idade;
};

int main(void) {
    struct Pessoa pessoas[3]; // Array para armazenar 3 pessoas

    // Leitura dos dados
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    // Exibição dos dados
    printf("\nDados das pessoas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d: Nome: %s, Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
