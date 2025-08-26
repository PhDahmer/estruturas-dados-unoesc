//Maior e menor elemento Leia 10 inteiros em um array e mostre o maior e o menor valor.

#include <stdio.h>

int main(void){

int array[10]; // declarando um array para 10 inteiros
int maior, menor;

for(int i = 0; i < 10; i++){
    printf("Digite um número: ");
    scanf("%d", &array[i]); // armazenando o numero na posição i do array
}

maior = menor = array[0]; // inicializando maior e menor com o primeiro elemento do array

for(int i = 1; i < 10; i++){ // laço de repetic
    if(array[i] > maior)
        maior = array[i];
    if(array[i] < menor)
        menor = array[i];
}

printf("Maior: %d\n", maior);
printf("Menor: %d\n", menor);

    return 0;
}