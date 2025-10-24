#include <stdio.h>

int main(){
  int cod,numeroNotas, alunosAprovados = 0, alunosReprovados = 0;
  float notas[20], soma, mediaNotas;

  printf("---------------------------------------\n");
  printf("Informe o codigo do aluno:\n");
  scanf("%d", &cod);

  while(cod != 0){
    soma = 0.0;

    printf("---------------------------------------\n");
    printf("Informe os numeros de notas do aluno:\n");
    scanf("%d", &numeroNotas);
    // Loop para pecorre a contidade de notas a ser armazenada.
    for(int i = 0;i < numeroNotas;i++){
      printf("Nota:\n");
      scanf("%f", &notas[i]);

    }
    // Um loop para pecorrer o array de notas.
    for(int i = 0;i < numeroNotas; i++){
      soma += notas[i];
    }
    mediaNotas = soma / numeroNotas;

    if(mediaNotas >= 6.00){
      printf("--------------------------------------\n");
      printf("Aluno com codigo: %d aprovado! \n", cod);
      printf("Média %.2f \n", mediaNotas);
      alunosAprovados += 1;
    }else {
      printf("Aluno codigo: %d reprovado! \n", cod);
      printf("Média %.2f \n", mediaNotas);
      alunosReprovados += 1;
    }
    printf("--------------------------------------\n");
    printf("Alunos aprovados: %d \n", alunosAprovados);
    printf("--------------------------------------\n");
    printf("Alunos Reprovados: %d \n", alunosReprovados);

    printf("--------------------------------------\n");
    printf("Informe o codigo do aluno:\n");
    scanf("%d", &cod);
  }

  return 0;
}
