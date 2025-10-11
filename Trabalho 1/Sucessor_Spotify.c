#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Playlist {
    char nome[80];     
    char artista[80];
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
    printf("|  7 - Fechar o programa                            |\n");
    printf("-----------------------------------------------------\n");

    do {
        printf("|  Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 7) {
            printf("|  Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 7);

    printf("-----------------------------------------------------\n\n");
    return opcao;
}

void inserirInicio(PLAYLIST **inicio, char *nome, char *artista, int tempo) {
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

void inserirFim(PLAYLIST **inicio, char *nome, char *artista, int tempo) {
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

void removerInicio(PLAYLIST **inicio) {
    if (*inicio == NULL) return;

    PLAYLIST *temp = *inicio;
    *inicio = (*inicio)->prox;

    if (*inicio != NULL)
        (*inicio)->ant = NULL;

    free(temp);
}

void removerQualquer(PLAYLIST **inicio, char *nome) {
    if (*inicio == NULL) return;

    PLAYLIST *atual = *inicio;
    while (atual != NULL && strcmp(atual->nome, nome) != 0)
        atual = atual->prox;

    if (atual == NULL) return; 

    if (atual->ant != NULL)
        atual->ant->prox = atual->prox;
    else
        *inicio = atual->prox; 

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;

    free(atual);
}

void alterarMusica(PLAYLIST *inicio, char *nome, char *novoNome, char *novoArtista, int novoTempo) {
    PLAYLIST *atual = inicio;
    while (atual != NULL && strcmp(atual->nome, nome) != 0)
        atual = atual->prox;

    if (atual == NULL) {
        printf("Música não encontrada.\n");
        return;
    }

    strcpy(atual->nome, novoNome);
    strcpy(atual->artista, novoArtista);
    atual->tempoTotal = novoTempo;
}

void listarPlaylist(PLAYLIST *inicio, char *nomePlaylist) {
    printf("\n==================== Playlist: %s =======================\n", nomePlaylist);

    if (inicio == NULL) {
        printf("A playlist está vazia.\n");
    } else {
        PLAYLIST *atual = inicio;
        int i = 1;
        while (atual != NULL) {
            printf("\n%d - Música: %s | Artista: %s \n", i, atual->nome, atual->artista);
            printf("Duração: %02d:%02d\n", atual->tempoTotal / 60, atual->tempoTotal % 60);
            atual = atual->prox;
            i++;
        }
    }

    printf("\n===================================================================\n\n");
}

int main() {
    PLAYLIST *playlist = NULL;
    char nomePlaylistAtual[100] = "Minha Playlist";
    int opcao;

    while(1){
        opcao = menu();
        
        switch(opcao){

            case 1: {
                char temp[100];
                printf("Digite o nome da playlist: ");
                scanf(" %99[^\n]", temp);  // lê até o ENTER (permite espaços)
                strncpy(nomePlaylistAtual, temp, sizeof(nomePlaylistAtual)-1);
                nomePlaylistAtual[sizeof(nomePlaylistAtual)-1] = '\0';
                printf("Nome da playlist alterado para: %s\n", nomePlaylistAtual);
                break;
            }
            case 2: {
                char nome[80], artista[80], escolha[3];
                int tempo, minutos, segundos;
                
                printf("Digite o nome da música: ");
                scanf(" %79[^\n]", nome);
                printf("Digite o nome do artista: ");
                scanf(" %79[^\n]", artista);
                printf("Digite a duração da música (minutos): ");
                scanf("%d", &minutos);
                printf("Digite a duração da música (segundos): ");
                scanf("%d", &segundos);
                tempo = minutos * 60 + segundos;
                printf("Deseja inserir no começo da playlist, ou no fim? (C or F)\n");
                scanf(" %2s", escolha);
                if (escolha[0] == 'C' || escolha[0] == 'c'){
                    inserirInicio(&playlist, nome, artista, tempo);
                    printf("Música adicionada com sucesso!\n");}
                else {   
                inserirFim(&playlist, nome, artista, tempo);
                printf("Música adicionada com sucesso!\n");}
                break;
            }
            case 3: {
                removerInicio(&playlist);
                printf("Primeira música removida com sucesso!\n");
                break;
            }
            case 4: {
                char nome[80];
                printf("Digite o nome da música a ser removida: ");
                scanf(" %79[^\n]", nome);
                
                removerQualquer(&playlist, nome);
                printf("Música removida com sucesso (se encontrada)!\n");
                break;
            }
            case 5: {
                char nome[80], novoNome[80], novoArtista[80];
                int novoTempo;
                
                printf("Digite o nome da música a ser alterada: ");
                scanf(" %79[^\n]", nome);
                
                printf("Digite o novo nome da música: ");
                scanf(" %79[^\n]", novoNome);
                printf("Digite o novo nome do artista: ");
                scanf(" %79[^\n]", novoArtista);
                printf("Digite a nova duração da música (em segundos): ");
                scanf("%d", &novoTempo);
                
                alterarMusica(playlist, nome, novoNome, novoArtista, novoTempo);
                printf("Música alterada com sucesso (se encontrada)!\n");
                break;
            }
            case 6: {
                listarPlaylist(playlist, nomePlaylistAtual);
                break;
            }
            case 7: {
                // Libera memória antes de sair
                while (playlist != NULL) {
                    removerInicio(&playlist);
                }
                printf("Programa encerrado.\n");
                return 0;
                }
        }
    }
}
