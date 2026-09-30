#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  //Estruturas.
  struct sockaddr_in alvo;
  struct timeval timeout;

  
  timeout.tv_sec = 0;
  timeout.tv_usec = 200000;
  //Valida se o argumento foi passado.
  if (argc < 2) {
    printf("Uso correto: %s <IP_ALVO>\n", argv[0]);
    return 1;
  }
  //Valida se o IP é valido.
  if (inet_pton(AF_INET, argv[1], &alvo.sin_addr) <= 0) {
    printf("Endereço IP inválido!!\n");
    return 1;
  }
  //Leitura de portas dinâmicas com tratamento de valores.
  int porta_inicial = argc >= 3 ? atoi(argv[2]) : 1;
  int porta_final = argc >= 4 ? atoi(argv[3]) : 1024;
  //Ativação do modo verbose.
  int verbose = 0;
  if (argc >= 5 && strcmp(argv[4], "-v") == 0 || argc >= 4 && strcmp(argv[3], "-v") == 0) {
    verbose = 1;
  }
  //familia de endereço IPv4
  alvo.sin_family = AF_INET;
  
  for (int i = porta_inicial; i <= porta_final; i++) {
    // cria um novo socket para cada porta.
    int meu_socket = socket(alvo.sin_family, SOCK_STREAM, 0);
    int porta = i;
    // Validação de segurança.
    if (meu_socket < 0) {
      printf("Error ao criar o socket!!\n");
      return 1;
    }
    //Configura o tempo limite.
    setsockopt(meu_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(meu_socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    //Configura a porta atual.
    alvo.sin_port = htons(porta);
    //Tenta o aperto de mão, Handshake.
    int resultado = connect(meu_socket, (struct sockaddr *)&alvo, sizeof(alvo));
    //Exibi os resultados do connect.
    if (resultado == 0) {
      printf("[+] Porta %d ABERTA\n", porta);
    }else if (verbose) {
      printf("[-] Porta %d FECHADA / FILTRADA\n", porta);
    }
    close(meu_socket);
  }

  
  return 0;
}