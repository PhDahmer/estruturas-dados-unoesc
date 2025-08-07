#include <stdio.h>

char* enderposi(char *str, char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return &str[i]; 
        }
    }
    return NULL; 
}

int main(void) {
    char str[50], ch;
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    char *ptr = enderposi(str, ch);
    if (ptr != NULL) {
        printf("Caracteres a partir do caractere '%c': %s", ch, ptr);
    } else {
        printf("Caractere '%c' nao encontrado na string.\n", ch);
    }

    return 0;
}