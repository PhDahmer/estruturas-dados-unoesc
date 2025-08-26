// Troca com ponteiros: Escreva uma função void troca(int *a, int *b) que troque os valores de duas
// variáveis inteiras. Teste na main.

#include <stdio.h>

void troca(int *a, int *b) { // função que troca os valores de duas variáveis inteiras
    int temp = *a; // armazena o valor de a em uma variável temporária
    *a = *b; // atribui o valor de b a a
    *b = temp; // atribui o valor armazenado em temp a b
}

int main(void) {
    int x = 5, y = 10;
    printf("Antes da troca: x = %d, y = %d\n", x, y);
    troca(&x, &y); // chama a função troca, passando os endereços de x e y
    printf("Depois da troca: x = %d, y = %d\n", x, y);
    return 0;
}