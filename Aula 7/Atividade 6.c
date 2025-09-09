#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    int valor;
    struct Registro *prox;
} REGISTRO;

void inserir(REGISTRO **inicio, int valor) {
    REGISTRO *novo = (REGISTRO *)malloc(sizeof(REGISTRO));
    novo->valor = valor;
    novo->prox = *inicio;
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

void excluir(REGISTRO **inicio, int valor) {
    REGISTRO *atual = *inicio;
    REGISTRO *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return; // Valor não encontrado

    if (anterior == NULL) {
        *inicio = atual->prox; // Remove o primeiro elemento
    } else {
        anterior->prox = atual->prox; // Remove o elemento do meio ou final
    }
    free(atual);
}

int main() {
    REGISTRO *inicio = NULL;

    inserir(&inicio, 10);
    inserir(&inicio, 20);
    inserir(&inicio, 30);
    imprimir(inicio);

    excluir(&inicio, 20);
    imprimir(inicio);

    excluir(&inicio, 10);
    imprimir(inicio);
    return 0;
}