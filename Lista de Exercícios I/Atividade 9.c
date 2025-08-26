// Alocação dinâmica simples Leia um valor n, aloque dinamicamente um array de inteiros de
// tamanho n, leia os valores e mostre a soma de todos.

#include <stdio.h>
#include <stdlib.h> // Biblioteca para alocação dinâmica

int main(void) {
    int n; // variavel para o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int)); // aloca dinamicamente um array de inteiros

    if (array == NULL) { // verifica se a alocação foi bem-sucedida
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Leitura dos valores
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Cálculo da soma
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += array[i];
    }

    printf("Soma de todos os elementos: %d\n", soma);

    free(array); // libera a memória alocada
    return 0;
}
