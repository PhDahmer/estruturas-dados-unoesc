//Recursão – Fibonacci Implemente uma função recursiva que retorne o n-ésimo termo da
//sequência de Fibonacci. Peça ao usuário n e mostre os n primeiros termos.

#include <stdio.h>

// Função que calcula o número de Fibonacci na posição n
int fibonacci(int n) {
    if (n <= 0) return 0; // Se n for 0 ou negativo, retorna 0
    if (n == 1) return 1; // Se n for 1, retorna 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Soma os dois números anteriores
}

int main(void) {
    int n;

    printf("Digite um número inteiro: "); // Pede para o usuário digitar um número
    scanf("%d", &n);

    // Mostra os primeiros n números de Fibonacci
    for (int i = 0; i <= n; i++) {
        printf("Fibonacci de %d é %d\n", i, fibonacci(i)); // Calcula e mostra o número
    }

    return 0; 
}
