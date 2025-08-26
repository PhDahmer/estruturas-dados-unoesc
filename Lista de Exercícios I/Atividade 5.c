// Inverter string: Leia uma palavra e mostre-a invertida (ex.: “casa” → “asac”)

#include <stdio.h>
#include <string.h>

int main(void){

    char palavra[100]; // cria um array de caracteres (string) com até 99 letras + '\0'
    printf("Digite uma palavra: ");
    scanf("%s", palavra); // lê a palavra digitada e armazena em 'palavra'

    int tamanho = strlen(palavra); // calcula o tamanho da palavra (número de letras)

    printf("Palavra invertida: ");
    // Laço para percorrer a string de trás pra frente
    for(int i = tamanho - 1; i >= 0; i--){  
        // começa no índice tamanho-1 (última letra, pois arrays começam no índice 0)
        // continua enquanto i >= 0 (ou seja, até a primeira letra)
        // a cada volta faz i-- (decrementa 1, voltando uma letra na palavra)

        printf("%c", palavra[i]); // imprime o caractere atual da posição i
    }

    printf("\n"); // quebra de linha no final

    return 0;
}
