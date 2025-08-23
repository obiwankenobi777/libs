#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_ok_header(int client);
void send_file(int client, const char* path);

int main(void) {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd < 0) {
    perror("socket\n");
    exit(1);
  }

  int opt = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("bind\n");
    close(server_fd);
    exit(1);
  }

  if (listen(server_fd, 5) < 0) {
    perror("listen");
    close(server_fd);
    exit(1);
  }

  printf("Listening oh http://localhost:%d\n", PORT);

  while (1) {
    struct sockaddr_in cli;
    socklen_t len = sizeof(cli);
    int client = accept(server_fd, (struct sockaddr*)&cli, &len);

    if (client < 0) {
      perror("accept");
      continue;
    }

    printf("Client connected\n");
    send_ok_header(client);
    send_file(client, "index.html");
    printf("Client disconnected\n");
    
    close(client);
  }

  return 0;
}

void send_file(int client, const char* path) {
  FILE *f = fopen(path, "r");

  if (!f) {
    perror ("Open HTML\n");
    return;
  }

  char buf[BUFFER_SIZE];
  size_t n;

  while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
    send(client, buf, n, 0);
  }

  fclose(f);
}

void send_ok_header(int client) {
  const char *hdr = "HTTP/1.1 200 OK\r\n"
  "Content-Type: text/html\r\n"
  "\r\n";

  send(client, hdr, strlen(hdr), 0);
}
