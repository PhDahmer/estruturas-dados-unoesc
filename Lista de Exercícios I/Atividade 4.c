//Contagem de vogais em string Peça ao usuário uma palavra e conte quantas vogais (a, e, i, o, u)
//existem nela.

#include <stdio.h>
#include <ctype.h> // biblioteca para usar a função tolower()
int main(void){

    char palavra[100]; // declarando um array para armazenar a palavra (string)
    int cont = 0; // variável para contar as vogais

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++){ // laço de repetição para contar as vogais
        char letra = tolower(palavra[i]); // convertendo a letra para minúscula
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            cont++; // se encontrar algum desses caracteres, adiciona +1 no contador
        }
    }

    printf("Número de vogais: %d\n", cont); //printa o contador com a quantidade de vogais na palavra escrita

    return 0;
}