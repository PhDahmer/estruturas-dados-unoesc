#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tabela {
    int numero;    
    struct Tabela *prox;
} TABELA;

int menu() {
    int opcao;

    printf("\n");
    printf("=====================================================\n");
    printf("=                     ATIVIDADE                     =\n");
    printf("=                  Insertion Sort                   =\n");
    printf("=====================================================\n\n");

    printf("=====================================================\n");
    printf("|                      MENU                         |\n");
    printf("-----------------------------------------------------\n");
    printf("|  1 - Inserir REGISTRO                             |\n");
    printf("|  2 - Excluir REGISTRO                             |\n");
    printf("|  3 - Mostrar LISTA                                |\n");
    printf("|  4 - Ordenar LISTA                                |\n");
    printf("|  5 - Sair                                         |\n");
    printf("-----------------------------------------------------\n");

    do {
        printf("|  Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 5) {
            printf("|  Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 5);

    printf("-----------------------------------------------------\n\n");
    return opcao;
}

void inserirRegistro(TABELA **inicio, int numero) {
    TABELA *novo = (TABELA *)malloc(sizeof(TABELA));
    if (!novo) return;

    novo->numero = numero;
    novo->prox = *inicio;

    *inicio = novo;
}

void excluirRegistro(TABELA **inicio, int numero) {
    TABELA *atual = *inicio;
    TABELA *anterior = NULL;

    while (atual != NULL && atual->numero != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return; 

    if (anterior == NULL) {
        *inicio = atual->prox; 
    } else {
        anterior->prox = atual->prox; 
    }

    free(atual);
}

void mostrarLista(TABELA *inicio) {
    TABELA *atual = inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->numero);
        atual = atual->prox;
    }
    printf("NULL\n");
}

    void insertionSort(TABELA **inicio) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    TABELA *ordenada = *inicio;  // primeira parte da lista já "ordenada"
    TABELA *atual = (*inicio)->prox;
    ordenada->prox = NULL;       // termina a parte ordenada aqui

    while (atual != NULL) {
        TABELA *proximo = atual->prox;

        // Se o elemento atual deve ir no início
        if (atual->numero < ordenada->numero) {
            atual->prox = ordenada;
            ordenada = atual;
        } 
        else {
            // Percorre a parte ordenada para achar o lugar certo
            TABELA *temp = ordenada;
            while (temp->prox != NULL && temp->prox->numero < atual->numero) {
                temp = temp->prox;
            }

            // Insere o elemento na posição correta
            atual->prox = temp->prox;
            temp->prox = atual;
        }

        atual = proximo; // passa para o próximo nó da lista original
    }

    *inicio = ordenada;
}

int main() {
    TABELA *tabela = NULL;
    int opcao;

    while(1){
        opcao = menu();
        
        switch(opcao){
            
            case 1: {
                int numero;
                printf("Digite o número a ser inserido: ");
                scanf("%d", &numero);
                inserirRegistro(&tabela, numero);
                printf("Número inserido com sucesso!\n");
                break;
            }
            case 2: {
                int numero;
                printf("Digite o número a ser excluído: ");
                scanf("%d", &numero);
                excluirRegistro(&tabela, numero);
                printf("Número excluído com sucesso (se encontrado)!\n");
                break;
            }
            case 3: {
                mostrarLista(tabela);
                break;
            }
            case 4: {
                insertionSort(&tabela);
                printf("Lista ordenada com sucesso!\n");
                break;
            }
            case 5: {
                printf("Saindo do programa...\n");
                TABELA *atual = tabela;
                while (atual != NULL) {
                    TABELA *temp = atual;
                    atual = atual->prox;
                    free(temp);
                }
                return 0;
            }
        }

    }

}