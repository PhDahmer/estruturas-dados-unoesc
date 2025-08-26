//Média de notas Leia as notas de 5 alunos (float) em um array, calcule a média e mostre quais
//alunos ficaram acima da média.

#include <stdio.h>

typedef struct{ // criado uma struct para armazenar as notas dos alunos, num array de 5 alunos, possuira 15 notas.
    float nota1,nota2,nota3;
} aluno;


int main (){
aluno alunos[5]; // iniciando o array de structs, com 5 alunos
float soma = 0, media; // variaveis para armazenar a soma e a media das notas

for (int i = 0; i < 5; i++) {
    printf("Digite a nota 1 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota1); // armazenando a nota1 de aluno[i] no endereço aluno[i].nota1
    printf("Digite a nota 2 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota2); // armazenando a nota2 de aluno[i] no endereço aluno[i].nota2
    printf("Digite a nota 3 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota3); // armazenando a nota3 de aluno[i] no endereço aluno[i].nota3
    soma += (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3; // soma das notas, cada repetição do for incrementando a variavel soma.
}

media = soma / 5;

printf("Média: %.2f\n", media);
printf("Alunos acima da média:\n");
for (int i = 0; i < 5; i++) {
    float media_aluno = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3; // calculando a média de cada aluno.
    if (media_aluno > media) { // verificando se a média do aluno é maior que a média geral.
        printf("Aluno %d: %.2f\n", i + 1, media_aluno); // retornando na tela quais alunos estão acima da média geral.
    }
}

 return 0;
}