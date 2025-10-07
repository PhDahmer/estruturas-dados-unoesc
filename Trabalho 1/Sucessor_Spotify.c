#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Playlist {
    char nome[50];     
    char artista[50];
    int tempoTotal;    
    struct Playlist *prox;
    struct Playlist *ant;
} PLAYLIST;

int menu() {
    int opcao;

    printf("\n");
    printf("=====================================================\n");
    printf("=                 Sucessor Spotify                  =\n");
    printf("=   Programa para gerenciar uma lista de músicas.   =\n");
    printf("=        (ainda não toca músicas, infelizmente)     =\n");
    printf("=            Pedro H. Dahmer - 442582               =\n");
    printf("=====================================================\n\n");

    printf("=====================================================\n");
    printf("|                      MENU                         |\n");
    printf("-----------------------------------------------------\n");
    printf("|  1 - Mudar nome da playlist                       |\n");
    printf("|  2 - Adicionar música                             |\n");
    printf("|  3 - Remover primeira música                      |\n");
    printf("|  4 - Remover qualquer música                      |\n");
    printf("|  5 - Alterar música                               |\n");
    printf("|  6 - Listar playlist                              |\n");
    printf("-----------------------------------------------------\n");

    do {
        printf("|  Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 6) {
            printf("|  Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 6);

    printf("-----------------------------------------------------\n\n");
    return opcao;
}

char* nomePlaylist() {
    char temp[100];
    printf("Digite o nome da playlist: ");
    scanf(" %99[^\n]", temp);  // lê até o ENTER (permite espaços)
    
    // aloca memória do tamanho certo
    char *nome = malloc(strlen(temp) + 1);
    if (nome == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    
    strcpy(nome, temp);  // copia o texto
    return nome;
}

void inserirInicio(PLAYLIST **inicio, char *nome[], char *artista[], int tempo) {
    PLAYLIST *novo = (PLAYLIST *)malloc(sizeof(PLAYLIST));
    if (!novo) return;

    strcpy(novo->nome, nome);
    strcpy(novo->artista, artista);
    novo->tempoTotal = tempo;

    novo->prox = *inicio;
    novo->ant = NULL;

    if (*inicio != NULL)
        (*inicio)->ant = novo;

    *inicio = novo;
}

void inserirFim(PLAYLIST **inicio, char *nome[], char *artista[], int tempo) {
    PLAYLIST *novo = (PLAYLIST *)malloc(sizeof(PLAYLIST));
    if (!novo) return;

    strcpy(novo->nome, nome);
    strcpy(novo->artista, artista);
    novo->tempoTotal = tempo;
    novo->prox = NULL;

    if (*inicio == NULL) {
        novo->ant = NULL;
        *inicio = novo;
        return;
    }

    PLAYLIST *atual = *inicio;
    while (atual->prox != NULL)
        atual = atual->prox;

    atual->prox = novo;
    novo->ant = atual;
}


int main() {
PLAYLIST *playlist = NULL;

    menu();
    // Implementar o código do sucessor do Spotify aqui
    return 0;
}