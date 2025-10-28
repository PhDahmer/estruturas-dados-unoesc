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
    printf("=                    Bubble Sort                    =\n");
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

void bubbleSort(TABELA **inicio) {
    if (inicio == NULL || *inicio == NULL) return;
    int troca;
    TABELA *atual;
    TABELA *proximo = NULL;
    do {
        troca = 0;
        atual = *inicio;
        while (atual->prox != proximo) {
            if (atual->numero > atual->prox->numero) {
                // Trocar os valores
                int temp = atual->numero;
                atual->numero = atual->prox->numero;
                atual->prox->numero = temp;
                troca = 1;
            }
            atual = atual->prox;
        }
        proximo = atual;
    } while (troca);
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
                bubbleSort(&tabela);
                printf("Lista ordenada com sucesso!\n");
                break;
            }
            case 5: {
                printf("Saindo do programa...\n");
                // Liberar memória antes de sair
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