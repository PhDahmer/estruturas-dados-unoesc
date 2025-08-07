#include <stdio.h>

int main(void)
{
   char c = 'A';
   char *ptr;  // declarar variaveis de ponteiros utilizar * antes do nome da variavel
   ptr = &c;

    printf("o conteudo de c eh: %c\n", c);
    printf("o endereco de c eh: %d\n",ptr);
}