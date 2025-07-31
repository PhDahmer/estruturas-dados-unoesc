#include <stdio.h>
#include <stdlib.h> 

int instring(char string[], char c){
    for (int i=0; string[i] != '\0'; i++){
        if (string[i] == c){
            return 1;
        }
    }
    return 0;
    
}

int main(){
    char string[100];
    char c;
    
    puts("Digite uma palavra:");
    scanf("%s", string);
    puts("Digite um caractere:");
    scanf(" %c", &c);
    puts("\n");
    
    if (instring(string, c)){
        puts("O caractere está na palavra.");
    } else {
        puts("O caractere não está na palavra.");
    }
    return 0;
}