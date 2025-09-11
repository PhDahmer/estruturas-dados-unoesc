#include <stdio.h>
#include <stdlib.h>

typedef struct Registro { // Define a estrutura do nó da lista
    int valor;
    struct Registro *prox; // ponteiro para o próximo nó
} REGISTRO;

void inserir(REGISTRO **inicio, int valor) { // Insere um novo nó no início da lista
    REGISTRO *novo = (REGISTRO *)malloc(sizeof(REGISTRO)); // Aloca memória para o novo nó
    novo->valor = valor; // Define o valor do novo nó
    novo->prox = *inicio; // Aponta o novo nó para o início atual
    *inicio = novo; // Atualiza o início da lista para o novo nó
}

void imprimir(REGISTRO *inicio) { // Imprime todos os valores da lista
    REGISTRO *atual = inicio; // Começa do início da lista
    while (atual != NULL) { // Percorre até o final da lista
        printf("%d -> ", atual->valor); // Imprime o valor do nó atual
        atual = atual->prox; // Move para o próximo nó
    }
    printf("NULL\n");
}

void excluir(REGISTRO **inicio, int valor) { // Remove um nó com o valor especificado
    REGISTRO *atual = *inicio; // Começa do início da lista
    REGISTRO *anterior = NULL; // Ponteiro para o nó anterior

    while (atual != NULL && atual->valor != valor) { // Procura o valor na lista
        anterior = atual; // Atualiza o nó anterior
        atual = atual->prox; // Move para o próximo nó
    }

    if (atual == NULL) return; // Valor não encontrado

    if (anterior == NULL) {
        *inicio = atual->prox; // Remove o primeiro elemento
    } else {
        anterior->prox = atual->prox; // Remove o elemento do meio ou final
    }
    free(atual);
}

    void alterar(REGISTRO *inicio, int valorAntigo, int valorNovo) { // Altera o valor de um nó
        REGISTRO *atual = inicio; // Começa do início da lista

        while (atual != NULL) { // Percorre a lista
            if (atual->valor == valorAntigo) { // Procura o valor antigo
                atual->valor = valorNovo; // Altera para o novo valor
                return; // Sai da função após a alteração
            }
            atual = atual->prox; // Move para o próximo nó
        }
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
    alterar(inicio, 30, 40);
    imprimir(inicio);
    return 0;
}