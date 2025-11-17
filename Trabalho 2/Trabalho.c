#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tabela {
    int numero;
    struct Tabela *prox;
} TABELA;

int menu() {
    int opcao;

    printf("\n");
    printf("=====================================================\n");
    printf("=                   ATIVIDADE                       =\n");
    printf("=            Benchmark de Ordenações                =\n");
    printf("=====================================================\n");
    printf("|                     MENU                          |\n");
    printf("-----------------------------------------------------\n");
    printf("|  1 - Inserir Vários Dados                         |\n");
    printf("|  2 - Excluir Todos os Dados                       |\n");
    printf("|  3 - Mostrar Lista                                |\n");
    printf("|  4 - Ordenar (Bubble Sort)                        |\n");
    printf("|  5 - Ordenar (Insertion Sort)                     |\n");
    printf("|  6 - Ordenar (Merge Sort)                         |\n");
    printf("|  7 - Ordenar (Quick Sort)                         |\n");
    printf("|  8 - Sair                                         |\n");
    printf("-----------------------------------------------------\n");

    do {
        printf("|  Escolha uma opção: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 8) {
            printf("|  Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 8);

    printf("-----------------------------------------------------\n\n");
    return opcao;
}

TABELA* gerar_tabela_aleatoria(int qtd) {
    TABELA *inicio = NULL, *atual = NULL, *novo = NULL;

    for (int i = 0; i < qtd; i++) {
        novo = (TABELA*) malloc(sizeof(TABELA));
        if (novo == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1);
        }

        novo->numero = rand() % 2147483647;
        novo->prox = NULL;

        if (inicio == NULL)
            inicio = novo;
        else
            atual->prox = novo;

        atual = novo;
    }

    return inicio;
}

void mostrarLista(TABELA *inicio) {
    if (inicio == NULL) {
        printf("\n[!] Lista vazia.\n");
        printf("--------------------------------------\n");
        return;
    }

    printf("\n================== LISTA ATUAL ==================\n");
    TABELA *atual = inicio;
    int contador = 0;

    while (atual != NULL) {
        printf("%5d ", atual->numero);
        contador++;

        // Quebra linha a cada 10 números
        if (contador % 10 == 0)
            printf("\n");

        atual = atual->prox;
    }

    printf("\n===============================================\n\n");
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

void insertionSort(TABELA **inicio) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    TABELA *ordenada = *inicio;
    TABELA *atual = (*inicio)->prox;
    ordenada->prox = NULL;

    while (atual != NULL) {
        TABELA *proximo = atual->prox;

        if (atual->numero < ordenada->numero) {
            atual->prox = ordenada;
            ordenada = atual;
        } else {
            TABELA *temp = ordenada;
            while (temp->prox != NULL && temp->prox->numero < atual->numero) {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }

        atual = proximo;
    }

    *inicio = ordenada;
}

// Encontra o nó do meio da lista (para dividir em duas)
TABELA *encontrarMeio(TABELA *inicio)
{
    TABELA *lento = inicio;
    TABELA *rapido = inicio->prox;

    while (rapido != NULL && rapido->prox != NULL)
    {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
}

// Intercala duas listas ligadas ordenadas (a e b)
TABELA *merge(TABELA *a, TABELA *b)
{
    TABELA temp;
    TABELA *atual = &temp;
    temp.prox = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->numero <= b->numero)
        {
            atual->prox = a;
            a = a->prox;
        }
        else
        {
            atual->prox = b;
            b = b->prox;
        }
        atual = atual->prox;
    }

    if (a != NULL)
        atual->prox = a;
    else if (b != NULL)
        atual->prox = b;

    return temp.prox;
}

// Função recursiva do Merge Sort. Retorna o ponteiro para o início da lista ordenada.
TABELA *_mergeSort_recursivo(TABELA *inicio)
{
    if (inicio == NULL || inicio->prox == NULL)
    {
        return inicio;
    }

    TABELA *meio = encontrarMeio(inicio);
    TABELA *lista_direita = meio->prox;
    meio->prox = NULL; 

    TABELA *lista_esquerda_ordenada = _mergeSort_recursivo(inicio);
    TABELA *lista_direita_ordenada = _mergeSort_recursivo(lista_direita);

    return merge(lista_esquerda_ordenada, lista_direita_ordenada);
}

// Função wrapper (invólucro) para ser chamada pelo main
void mergeSort(TABELA **inicio)
{
    *inicio = _mergeSort_recursivo(*inicio);
}

// Insere nó no final
void insereFim(TABELA **head, TABELA **tail, TABELA *n) {
    n->prox = NULL;
    if (*head == NULL) {
        *head = *tail = n;
    } else {
        (*tail)->prox = n;
        *tail = n;
    }
}

void particionaNos(TABELA *inicio, TABELA **menorH, TABELA **menorT,
                   TABELA **igualH, TABELA **igualT,
                   TABELA **maiorH, TABELA **maiorT) {

    int pivo = inicio->numero;

    while (inicio != NULL) {
        TABELA *prox = inicio->prox;
        inicio->prox = NULL;

        if (inicio->numero < pivo)
            insereFim(menorH, menorT, inicio);

        else if (inicio->numero == pivo)
            insereFim(igualH, igualT, inicio);

        else
            insereFim(maiorH, maiorT, inicio);

        inicio = prox;
    }
}

TABELA* quickSort_nos(TABELA *inicio) {
    if (!inicio || !inicio->prox)
        return inicio;

    TABELA *menorH = NULL, *menorT = NULL;
    TABELA *igualH = NULL, *igualT = NULL;
    TABELA *maiorH = NULL, *maiorT = NULL;

    particionaNos(inicio, &menorH, &menorT, &igualH, &igualT, &maiorH, &maiorT);

    // Ordena recursivamente a parte menor
    if (menorH)
        menorH = quickSort_nos(menorH);

    // Ordena recursivamente a parte maior
    if (maiorH)
        maiorH = quickSort_nos(maiorH);

    // Junta menor + igual + maior
    TABELA *resultado = NULL;
    TABELA *tail = NULL;

    if (menorH) {
        resultado = menorH;
        tail = menorH;
        while (tail->prox) tail = tail->prox;
        tail->prox = igualH;
    } else {
        resultado = igualH;
        tail = igualT;
    }

    if (maiorH)
        tail->prox = maiorH;

    return resultado;
}

void quickSort(TABELA **inicio) {
    *inicio = quickSort_nos(*inicio);
}

void apagarTabela(TABELA **inicio) {
    TABELA *atual = *inicio;
    while (atual != NULL) {
        TABELA *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}

int main() {
    srand(time(NULL));

    TABELA *tabela = NULL;
    int opcao;

    while (1) {
        opcao = menu();

        switch (opcao) {
            case 1: {
                printf("Quantos números deseja inserir? ");
                int numero;
                scanf("%d", &numero);
                printf("\n");

                apagarTabela(&tabela); // limpa se já houver dados
                tabela = gerar_tabela_aleatoria(numero);

                printf("Números inseridos com sucesso!\n");
                printf("--------------------------------------\n");
                break;
            }
            case 2: {
                apagarTabela(&tabela);
                printf("\nTodos os números foram excluídos!\n");
                printf("--------------------------------------\n");
                break;
            }
            case 3: {
                mostrarLista(tabela);
                break;
            }
            case 4: {
                clock_t inicio, fim;
                double tempo_execucao;

                inicio = clock();
                bubbleSort(&tabela);
                fim = clock();

                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                printf("\nLista ordenada com sucesso usando Bubble Sort!\n");
                printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
                printf("--------------------------------------\n");
                break;
            }
            case 5: {
                clock_t inicio, fim;
                double tempo_execucao;

                inicio = clock();
                insertionSort(&tabela);
                fim = clock();

                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                printf("\nLista ordenada com sucesso usando Insertion Sort!\n");
                printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
                printf("--------------------------------------\n");
                break;
            }
            case 6: {
                clock_t inicio, fim;
                double tempo_execucao;

                inicio = clock();
                mergeSort(&tabela);
                fim = clock();

                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                printf("\nLista ordenada com sucesso usando Merge Sort!\n");
                printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
                printf("--------------------------------------\n");
                break;
            }
            case 7: {
                clock_t inicio, fim;
                double tempo_execucao;

                inicio = clock();
                quickSort(&tabela);
                fim = clock();

                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

                printf("\nLista ordenada com sucesso usando Quick Sort!\n");
                printf("Tempo de execução: %.6f segundos\n", tempo_execucao);
                printf("--------------------------------------\n");
                break;
            }

            case 8: {
                apagarTabela(&tabela);
                printf("\nSaindo do programa...\n");
                printf("======================================\n");
                return 0;
            }
            default:
                printf("Função ainda não implementada!\n");
                printf("--------------------------------------\n");
                break;
        }
    }
}
