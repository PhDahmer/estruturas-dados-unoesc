#include <stdio.h>

char* enderposi(char *pos_ini, char ch) {
    for (int i = 0; *(pos_ini+i) != '\0'; i++) {
        if (*(pos_ini+i) == ch) {
            return pos_ini+i;
        }
    }
    return NULL; 
}

int main(void) {
    char frase[50];
    char ch, *ptr;
    int i;  

    printf("Digite uma string: ");
    scanf("%s", frase);
    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    ptr = enderposi(frase, ch);

    if (ptr != NULL){
        for (i=0; *(ptr+i) != '\0'; i++) { // Tudo esse FOR pode ser substituido por printf(ptr)
            printf("%c", *(ptr+i));
        }
        printf("\n");
    }

    else {
        printf("O caractere '%c' nao foi encontrado na string.\n", ch);
    }

    return 0;
}