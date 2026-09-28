#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Conta {
  int numeroConta; 
  char titular[50];
  float saldo;
  int ativo;
};
// Prototipo
int buscarConta(struct Conta contas[], int totalContas, int numeroBuscado);
void criarConta(struct Conta contas[], int indice);

int main(){
  // Array contas[]
  struct Conta contas[5];
  int opcao = 0;
  srand(time(NULL));
  int totalContas = 0;
  
  while(opcao != 5){
    printf("\n---MENU BANCO---\n");
    printf("Criar conta [1]\n");
    printf("Procurar    [2]\n");
    printf("Depositar   [3]\n");
    printf("Sacar       [4]\n");
    printf("Sair        [5]\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar();
    
    switch (opcao) {
      case 1:
        if (totalContas < 5) {
          criarConta(contas, totalContas);      
          totalContas++;
        }else {
          printf("Limite de conta (5) atingido\n");
        }
        break;
      case 2:
        int buscar;
        printf("Numero da conta:\n");
        scanf("%d", &buscar);
        int indice = buscarConta(contas, totalContas, buscar);

        if(indice != -1){
          printf("----------------------------------\n");
          printf("Nome: %s\n", contas[indice].titular);
          printf("Numero da Conta: %d\n", contas[indice].numeroConta);
          printf("Saldo: %2.f\n", contas[indice].saldo);
          printf(contas[indice].ativo == 1 ? "Situação: Ativo\n" : "Situação: Inativo\n");
          printf("----------------------------------\n");
        }else {
          printf("Conta: %d não encontrada !!\n", buscar);
        }
        break;
      case 3:
        float deposito = 0;
        int numero;
        char confirmacao[5];
        
        printf("Numero da conta para deposito: \n");
        scanf("%d", &numero);
        getchar();
        int conta = buscarConta(contas, totalContas, numero);
        if(conta != -1){
          printf("Destinatario: %s\n", contas[conta].titular);
          printf("Conta: %d\n", contas[conta].numeroConta);
          printf("Os dados estão corretos (s/n)\n");
          fgets(confirmacao, sizeof(confirmacao), stdin);

          if(confirmacao[0] == 's' || confirmacao[0] == 'S'){
            printf("qual valor do deposito ? ");
            scanf("%f", &deposito);
            getchar();
            contas[conta].saldo += deposito;
            printf("Deposito realizado.\n");
          }else if (confirmacao[0] == 'n' || confirmacao[0] == 'N') {
            printf("Cancelando operação\n");
          }
        }else {
          printf("Conta não encontrada.\n");
        }
        break;
      case 4:
        int contaSaque;
        int saque;

        printf("Numero da conta para saque: \n");
        scanf("%d", &contaSaque);
        getchar();
        int contaExiste = buscarConta(contas, totalContas, contaSaque);
        if(contaExiste != -1){
          printf("Quanto quer sacar dessa conta ?\n");
          scanf("%d", &saque);
          getchar();
          if (saque > 0 && saque <= contas[contaExiste].saldo) {
            contas[contaExiste].saldo -= saque;
            printf("---------------------------------------\n");
            printf("Nome: %s\n", contas[contaExiste].titular);
            printf("Numero da Conta: %d\n", contas[contaExiste].numeroConta);
            printf("Saldo: %2.f\n", contas[contaExiste].saldo);
            printf("----------------------------------------\n");
          }else {
            printf("Saque invalido ou saldo insuficiente!\n");
          }
        }
        break;
      case 5:
        printf("Ate mais!!\n");
        break;
      default:
        printf("Opção invalida!!\n");
        break;
    }
  }
  return 0;
};
void criarConta(struct Conta contas[], int indice){
  printf("Gerando o numero da sua conta...\n");
  //Gera numeros da conta aleatorio.
  int numeroTorio = rand() % 9000 + 1000;
  contas[indice].numeroConta = 1001;
  contas[indice].saldo = 0;
  contas[indice].ativo = 1;
  //Nome do titular da conta.
  printf("Digite o nome do titular:\n");
  fgets(contas[indice].titular, 50, stdin);
  contas[indice].titular[strcspn(contas[indice].titular, "\n")] = '\0';
  //Ao final mostra um feedback do resultado.
  printf("=========================\n");
  printf("Numero da Conta: %d\n", contas[indice].numeroConta);
  printf("Nome do Titular: %s\n", contas[indice].titular);
  printf("=========================\n");
}
int buscarConta(struct Conta contas[], int totalContas, int numeroBuscado){
  for(int i = 0; i < totalContas; i++){
    if(contas[i].numeroConta == numeroBuscado){
      return i;// Retorna a gaveta exata do array.
    }
  }
  return -1;
}