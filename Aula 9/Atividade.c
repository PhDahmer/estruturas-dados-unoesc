#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    int valor;
    struct Registro *prox;
} REGISTRO;

// Push = insere no topo
void push(REGISTRO **topo, int valor) {
    REGISTRO *novo = (REGISTRO *)malloc(sizeof(REGISTRO));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Pop = remove do topo
int pop(REGISTRO **topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // código de erro
    }
    REGISTRO *remover = *topo;
    int valor = remover->valor;
    *topo = remover->prox;
    free(remover);
    return valor;
}

// Alterar = troca o primeiro valor encontrado
void alterar(REGISTRO *topo, int valorAntigo, int valorNovo) {
    REGISTRO *atual = topo;
    while (atual != NULL) {
        if (atual->valor == valorAntigo) {
            atual->valor = valorNovo;
            return;
        }
        atual = atual->prox;
    }
}

void imprimir(REGISTRO *topo) {
    REGISTRO *atual = topo;
    printf("Topo -> ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    REGISTRO *pilha = NULL;

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    imprimir(pilha);

    printf("Pop: %d\n", pop(&pilha));
    imprimir(pilha);

    alterar(pilha, 10, 99);
    imprimir(pilha);

    pop(&pilha);
    pop(&pilha);
    pop(&pilha); // pilha já vazia
    imprimir(pilha);

    return 0;
}
