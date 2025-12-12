#include <stdio.h>
// Definição da struct
struct Livros {
  int codigo;
  char titulo[50];
  char autor[30];
  char area[30];
  int ano;
  char editora[30];
};
// Declaração da constante
#define TAMANHO_ACERVO 20

// Prototipos das funções
void cadastrarLivros(struct Livros acervo[], int *numCadastrados);
void imprimirLivros(struct Livros acervo[], int numCadastrados);
void pesquisarLivro(struct Livros acervo[], int numCadastrados, int codigoBusca);
void ordenarLivros(struct Livros acervo[], int numCadastrados);
int exibirMenu();
// função exibir menu.
int exibirMenu(){
  int opcao;

  printf("\n[1] Cadastrar livros \n");
  printf("[2] Imprimir todos os livros \n");
  printf("[3] Pesquisar livro por código \n");
  printf("[4] Ordenar livros por ano de publicação \n");
  printf("[5] Sair do programa \n");
  
  printf("\nEscolha uma opção:");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}
// Função que cadastra os livros.
void cadastrarLivros(struct Livros acervo[], int *numCadastrados){
  printf("\n---Cadastro de livros---\n");
  int i;
  char cadastrar;
  // Essa condição testa se o numero de livros cadastrados for maior ou igual o acervo que é 20
  if(*numCadastrados >= TAMANHO_ACERVO){
    printf("Acervo está cheio maximo de %d livros atingido", TAMANHO_ACERVO);
    return;
  }
  // Esse laço vai percorrer nosso vetor onde vai adicionar um novo livro na proxima posição vazia e retornando para o menu
  for(i = *numCadastrados; i < TAMANHO_ACERVO; i++){
    // 1 Código
    printf(" codigo (inteiro): ");
    scanf("%d", &acervo[i].codigo);
    fflush(stdin);
    // 2 Título
    printf("  Titulo (max 49 caracteres, SEM ESPACOS): ");
    scanf("%s", acervo[i].titulo);
    fflush(stdin);
    // 3 Autor
    printf("  Autor (max 29 caracteres, SEM ESPACOS): ");
    scanf("%s", acervo[i].autor);
    fflush(stdin);
    // 4 Área
    printf("  Area (max 29 caracteres, SEM ESPACOS): ");
    scanf("%s", acervo[i].area);
    fflush(stdin);
    // 5 Ano
    printf("  Ano de publicacao (inteiro): ");
    scanf("%d", &acervo[i].ano);
    fflush(stdin); 
    // 6 Editora 
    printf("  Editora (max 29 caracteres, SEM ESPACOS): ");
    scanf("%s", acervo[i].editora);
    fflush(stdin);
    // Atualiza o contador de livros
    (*numCadastrados)++;
    break;// faz o loop parar e voltar ao menu primcipal.
  }
}
// Função para imprimir livros.
void imprimirLivros(struct Livros acervo[], int numCadastrados){
  int i;

  if(numCadastrados == 0){
    printf("\nLista de livros vazia!\n");
    return;
  }

  for(i = 0; i < numCadastrados; i++){
    printf("-----------------------------------------\n");
    printf("Posição do livro: %d\n", i + 1);
    printf("Codigo: %d\n", acervo[i].codigo);
    printf("Titulo: %s\n", acervo[i].titulo);
    printf("Autor: %s\n", acervo[i].autor);
    printf("Area: %s\n", acervo[i].area);
    printf("Ano: %d\n", acervo[i].ano);
    printf("Editora: %s\n", acervo[i].editora);
    printf("-----------------------------------------\n");
  }
}
// Função para pesquisar por código.
void pesquisarLivro(struct Livros acervo[], int numCadastrados, int codigoBusca){

  if(numCadastrados == 0){
    printf("\nLista de livros vazio! :|\n");
    return;
  }
  printf("Código do livro:.");
  scanf("%d", &codigoBusca);
  fflush(stdin);

  int i = 0;
  int encontrado = 0;

  while(i < numCadastrados){
    if(acervo[i].codigo == codigoBusca){
      printf("---Livro Encontrado na Posicão %d ---\n", i + 1);
      printf("Codigo: %d\n", acervo[i].codigo);
      printf("Titulo: %s\n", acervo[i].titulo);
      printf("Autor: %s\n", acervo[i].autor);
      printf("Área: %s\n", acervo[i].area);
      printf("Ano: %d\n", acervo[i].ano);
      printf("Editora: %s\n", acervo[i].editora);
      encontrado = 1;
      break;
    }
    i++;
  }
  if(!encontrado){
    printf("Livro não encontrado com esse código %d.", codigoBusca);
  }
}

void ordenarLivros(struct Livros acervo[], int numCadastrados){

}


int main(){
  // Vetor de structs
  struct Livros acervo[TAMANHO_ACERVO];

  int numCadastrados = 0;

  int opcao;
  int codigoBusca;

  while(opcao != 5){
    opcao = exibirMenu();

    switch(opcao){
      case 1: 
        cadastrarLivros(acervo, &numCadastrados);
        break;
      case 2:
        imprimirLivros(acervo, numCadastrados);
        break;
      case 3:
        pesquisarLivro(acervo, numCadastrados, codigoBusca);
        break;
      case 4:
        printf("\n--Opção em desenvolvimento--\n");
        break;
    }
  }
  return 0;
}
