#include <stdio.h>
#include <stdlib.h>

typedef struct Registro { // Define a estrutura do nó da lista duplamente encadeada
    int valor; // Valor do nó
    struct Registro *prox; // Ponteiro para o próximo nó
    struct Registro *ant; // Ponteiro para o nó anterior
} REGISTRO;

void inserir(REGISTRO **inicio, int valor) { // Insere um novo nó no início da lista
    REGISTRO *novo = (REGISTRO *)malloc(sizeof(REGISTRO)); // Aloca memória para o novo nó
    novo->valor = valor; // Define o valor do novo nó
    novo->prox = *inicio; // Aponta o novo nó para o início atual
    novo->ant = NULL; // O novo nó não tem nó anterior
    if (*inicio != NULL) { // Se a lista não está vazia
        (*inicio)->ant = novo; // Atualiza o nó anterior do antigo início
    }
    *inicio = novo;
}

void imprimir(REGISTRO *inicio) {
    REGISTRO *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void excluir(REGISTRO **inicio, int valor) { // Remove um nó com o valor especificado
    REGISTRO *atual = *inicio;
    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }
    if (atual == NULL) return;
    if (atual->ant == NULL) { // Primeiro elemento
        *inicio = atual->prox; // Atualiza o início da lista
        if (atual->prox != NULL) // Se houver um próximo nó
            atual->prox->ant = NULL; // Atualiza o nó anterior do próximo nó
    } else {
        atual->ant->prox = atual->prox; // Atualiza o próximo do nó anterior
        if (atual->prox != NULL) // Se houver um próximo nó
            atual->prox->ant = atual->ant; // Atualiza o nó anterior do próximo nó
    }
    free(atual);
}

void alterar(REGISTRO *inicio, int valorAntigo, int valorNovo) {
    REGISTRO *atual = inicio;
    while (atual != NULL) {
        if (atual->valor == valorAntigo) {
            atual->valor = valorNovo;
            return;
        }
        atual = atual->prox;
    }
}

int main() {
    REGISTRO *inicio = NULL;

    inserir(&inicio, 10);
    inserir(&inicio, 20);
    inserir(&inicio, 30);
    inserir(&inicio, 40);
    inserir(&inicio, 50);
    printf("Lista após inserções:\n");
    imprimir(inicio);

    excluir(&inicio, 30);
    printf("Lista após excluir 30:\n");
    imprimir(inicio);

    excluir(&inicio, 50);
    printf("Lista após excluir 50 (primeiro):\n");
    imprimir(inicio);

    excluir(&inicio, 10);
    printf("Lista após excluir 10 (último):\n");
    imprimir(inicio);

    alterar(inicio, 40, 99);
    printf("Lista após alterar 40 para 99:\n");
    imprimir(inicio);

    alterar(inicio, 100, 77);
    printf("Lista após tentar alterar 100 para 77 (não existe):\n");
    imprimir(inicio);

    excluir(&inicio, 100);
    printf("Lista após tentar excluir 100 (não existe):\n");
    imprimir(inicio);

    excluir(&inicio, 20);
    excluir(&inicio, 99);
    printf("Lista após excluir todos os elementos:\n");
    imprimir(inicio);

    return 0;
}
