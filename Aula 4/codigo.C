#include <stdio.h>
#include <stdlib.h> // importante para malloc/realloc/free

typedef struct {
    float altura;
    float largura;
    float profundidade;
} REGISTRO;

int mostrarMenu(){ 
    int opcao;
    printf("\n");
    printf("-=-=-=-=-= MENU =-=-=-=-=-\n");
    printf("1. Inserir Registro\n");
    printf("2. Alterar Registro\n");
    printf("3. Remover Ultimo Registro\n");
    printf("4. Listar Registros\n");
    printf("5. Sair\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    do {
        printf("\nEscolha uma opcao: ");
        scanf("%i", &opcao);
        if (opcao < 1 || opcao > 5) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 5);
    return opcao;
}

int main(void) {
    REGISTRO *lista = NULL; 
    int quantidade = 0; 
    int opcao;

    while (1) { 
        opcao = mostrarMenu();

        switch (opcao) {
            case 1: {
                quantidade++;
                lista = (REGISTRO *) realloc(lista, quantidade * sizeof(REGISTRO));
                if (lista == NULL) {
                    printf("Erro ao alocar memoria.\n");
                    return 1; 
                }

                printf("Digite a altura (cm): ");
                scanf("%f", &lista[quantidade - 1].altura);
                printf("Digite a largura (cm): ");
                scanf("%f", &lista[quantidade - 1].largura);
                printf("Digite a profundidade (cm): ");
                scanf("%f", &lista[quantidade - 1].profundidade);
                printf("Registro %d inserido com sucesso.\n", quantidade);
                break;
            }

            case 2: {
                int registroAAlterar;
                do {
                    printf("\nQual registro deseja alterar? (1 a %d): ", quantidade);
                    scanf("%i", &registroAAlterar);
                    if (registroAAlterar < 1 || registroAAlterar > quantidade) {
                        printf("Registro invalido.\n");
                    }
                } while (registroAAlterar < 1 || registroAAlterar > quantidade);

                printf("Digite a nova altura (cm): ");
                scanf("%f", &lista[registroAAlterar - 1].altura);
                printf("Digite a nova largura (cm): ");
                scanf("%f", &lista[registroAAlterar - 1].largura);
                printf("Digite a nova profundidade (cm): ");
                scanf("%f", &lista[registroAAlterar - 1].profundidade);
                printf("Registro %d alterado com sucesso.\n", registroAAlterar);
                break;
            }

            case 3: {
                if (quantidade == 0) {
                    printf("Nenhum registro para remover.\n");
                    break;
                }

                quantidade--;
                REGISTRO *temp = (REGISTRO *) realloc(lista, quantidade * sizeof(REGISTRO));
                if (temp == NULL && quantidade > 0) {
                    printf("Erro ao realocar memoria.\n");
                    return 1;
                }
                lista = temp;

                printf("Registro %d removido com sucesso.\n", quantidade + 1);
                break;
            }
            
            case 4: {
                if (quantidade == 0) {
                    printf("Nenhum registro para mostrar.\n");
                    break;
                }

                int registroAMostrar;
                do {
                    printf("\nQual registro deseja mostrar? (1 a %d): ", quantidade);
                    scanf("%i", &registroAMostrar);
                    if (registroAMostrar < 1 || registroAMostrar > quantidade) {
                        printf("Registro invalido.\n");
                    }
                } while (registroAMostrar < 1 || registroAMostrar > quantidade);

                printf("\nRegistro %d:\n", registroAMostrar);
                printf("Altura: %.2f cm\n", lista[registroAMostrar - 1].altura);
                printf("Largura: %.2f cm\n", lista[registroAMostrar - 1].largura);
                printf("Profundidade: %.2f cm\n", lista[registroAMostrar - 1].profundidade);
                break;
            }

            case 5:
                printf("\nSaindo...\n");
                free(lista);
                return 0; 
        }
    }
}
