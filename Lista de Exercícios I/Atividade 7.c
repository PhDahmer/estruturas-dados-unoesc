// Matriz 3x3 – soma de linhas Leia uma matriz 3x3 e mostre a soma de cada linha.

#include <stdio.h>

int main(void) {
    int matriz[3][3]; // declara uma matriz 3x3
    int somaLinhas[3] = {0, 0, 0}; // array para armazenar a soma de cada linha, inicializado com zeros

    // Leitura da matriz
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) { // percorre as linhas
        for (int j = 0; j < 3; j++) { // percorre as colunas
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]); // lê o elemento da matriz
            somaLinhas[i] += matriz[i][j]; // acumula a soma da linha i
        }
    }

    // Exibição da soma de cada linha
    printf("\nSoma de cada linha:\n");
    for (int i = 0; i < 3; i++) {
        printf("Soma da linha %d: %d\n", i + 1, somaLinhas[i]);
    }

    return 0;
}