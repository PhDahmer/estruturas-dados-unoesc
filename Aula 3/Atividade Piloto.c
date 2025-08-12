#include <stdio.h>

typedef struct{
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
    printf("3. Remover Registro\n");
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
    REGISTRO lista[10] = {0};
    int opcao;

    while (1) { 
        opcao = mostrarMenu();

        switch (opcao) {
            case 1: {
                int registroAInserir;
                do {
                    printf("\nQual registro deseja inserir (Escolha entre 1 a 10): ");
                    scanf("%i", &registroAInserir);
                    if (registroAInserir < 1 || registroAInserir > 10) {
                        printf("Registro inválido.\n");
                    }
                } while (registroAInserir < 1 || registroAInserir > 10);

                printf("Digite a altura (cm): ");
                scanf("%f", &lista[registroAInserir - 1].altura);
                printf("Digite a largura (cm): ");
                scanf("%f", &lista[registroAInserir - 1].largura);
                printf("Digite a profundidade (cm): ");
                scanf("%f", &lista[registroAInserir - 1].profundidade);
                printf("Registro %d inserido com sucesso.\n", registroAInserir);
                break;
            }

            case 2: {
                int registroAAlterar;
                do {
                    printf("\nQual registro deseja alterar? (1 a 10): ");
                    scanf("%i", &registroAAlterar);
                    if (registroAAlterar < 1 || registroAAlterar > 10) {
                        printf("Registro inválido.\n");
                    }
                } while (registroAAlterar < 1 || registroAAlterar > 10);

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
                int registroARemover;
                do {
                    printf("\nQual registro deseja remover? (1 a 10): ");
                    scanf("%i", &registroARemover);
                    if (registroARemover < 1 || registroARemover > 10) {
                        printf("Registro inválido.\n");
                    }
                } while (registroARemover < 1 || registroARemover > 10);

                lista[registroARemover - 1] = (REGISTRO){0, 0, 0}; // Remove o registro
                printf("Registro %d removido com sucesso.\n", registroARemover);
                break;
            }
            
            case 4: {
                int registroAMostrar;
                do {
                    printf("\nQual registro deseja mostrar? (1 a 10): ");
                    scanf("%i", &registroAMostrar);
                    if (registroAMostrar < 1 || registroAMostrar > 10) {
                        printf("Registro inválido.\n");
                    }
                } while (registroAMostrar < 1 || registroAMostrar > 10);

                printf("\nRegistro %d:\n", registroAMostrar);
                printf("Altura: %.2f cm\n", lista[registroAMostrar - 1].altura);
                printf("Largura: %.2f cm\n", lista[registroAMostrar - 1].largura);
                printf("Profundidade: %.2f cm\n", lista[registroAMostrar - 1].profundidade);
                break;
            }

            case 5:
                printf("\nSaindo...\n");
                return 0; 
        }
    }
}