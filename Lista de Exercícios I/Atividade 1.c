// Operações básicas com inteiros Leia dois inteiros e mostre: soma, subtração, multiplicação,
// divisão inteira, resto da divisão e resultado da divisão real.

#include <stdio.h>

int main() {

int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &a, &b);

    printf("\n");
    printf("Soma: %d\n", a + b);
    printf("Subtração: %d\n", a - b);
    printf("Multiplicação: %d\n", a * b);
    printf("Divisão inteira: %d\n", a / b); // retorna a parte inteira da divisão, no caso de 2,3 vai retornar 0, pois o resultado é 0,67
    printf("Resto da divisão: %d\n", a % b); // retorna o resto da divisão, no caso de 2,3 vai retornar 2, pois 2 dividido por 3 é 0 e o resto é 2
    printf("Divisão real: %.2f\n", (float)a / b); // retorna o resultado real da divisão como na calculadora.

    return 0;
}