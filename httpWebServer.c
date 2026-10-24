#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int cliente;
  char buffer[1024]= {0};
  // Estrutura.
  struct sockaddr_in SK;
  
  SK.sin_family = AF_INET;//IPv4
  SK.sin_port = htons(8080);//Porta
  SK.sin_addr.s_addr = INADDR_ANY;//Ouve em qualquer IP local
  //Criando o socket do servidor
  int servidor = socket(AF_INET, SOCK_STREAM, 0);
  //valida se a conexão foi bem sucedida.
  if(servidor < 0){
    perror("Erro ao criar o socket\n");
    exit(EXIT_FAILURE);
  }
  
  int opt = 1;
  setsockopt(servidor,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  
  if(bind(servidor, (struct sockaddr *) &SK, sizeof(SK))){
    perror("Error no bind");
    close(servidor);
    exit(EXIT_FAILURE);
  }
  //socket em modo de escuta esperando conexão.
  if (listen(servidor, 4) < 0) {
    perror("Error no listen");
    close(servidor);
    exit(EXIT_FAILURE);
  }
  printf("Aguardando conexão.\n");
  while (1) {
    socklen_t tamanho = sizeof(SK);
    cliente = accept(servidor, (struct sockaddr *)&SK, &tamanho);
    if (cliente < 0) {
      perror("Error no accept\n");
      continue;
    }
    memset(buffer, 0, sizeof(buffer));

    recv(cliente, buffer, sizeof(buffer) - 1, 0);
    printf("Requisição recebida %s\n", buffer);
  
    char *resposta = 
      "HTTP/1.1 200 OK\r\n"
      "Content-Type: text/html; charset=UTF-8\r\n"
      "Connection: close\r\n"
      "\r\n" // A linha em branco OBRIGATÓRIA que separa cabeçalho do corpo
      "<h1>Hello world.</h1>\n";
  
    send(cliente, resposta, strlen(resposta), 0);
  
    close(cliente);
  }
  
  printf("Cliente conectado %d\n", cliente);
  //Fecha a conexão
  close(servidor);
  return 0;
}