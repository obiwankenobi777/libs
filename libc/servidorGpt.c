#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#define PORTA 8080
#define MAX_CLIENTES 10
#define BUFFER_SIZE 1024

int main() {
    int servidor_fd, cliente_fd, max_fd, atividade, i;
    int clientes[MAX_CLIENTES] = {0};
    char buffer[BUFFER_SIZE];

    struct sockaddr_in endereco;

    // Cria o socket
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Permite reusar a porta
    int opt = 1;
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configura o endereço
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    // Associa o socket à porta
    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Começa a escutar por conexões
    if (listen(servidor_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor escutando na porta %d...\n", PORTA);

    fd_set fds;

    while (1) {
        FD_ZERO(&fds);
        FD_SET(servidor_fd, &fds);
        max_fd = servidor_fd;

        // Adiciona os clientes ao conjunto
        for (i = 0; i < MAX_CLIENTES; i++) {
            if (clientes[i] > 0)
                FD_SET(clientes[i], &fds);
            if (clientes[i] > max_fd)
                max_fd = clientes[i];
        }

        // Espera por atividade
        atividade = select(max_fd + 1, &fds, NULL, NULL, NULL);

        if ((atividade < 0) && (errno != EINTR)) {
            perror("select");
        }

        // Nova conexão
        if (FD_ISSET(servidor_fd, &fds)) {
            socklen_t tam = sizeof(endereco);
            cliente_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &tam);
            if (cliente_fd < 0) {
                perror("accept");
                continue;
            }

            // Adiciona cliente à lista
            for (i = 0; i < MAX_CLIENTES; i++) {
                if (clientes[i] == 0) {
                    clientes[i] = cliente_fd;
                    printf("Novo cliente conectado: %d\n", cliente_fd);
                    break;
                }
            }
        }

        // Verifica dados dos clientes
        for (i = 0; i < MAX_CLIENTES; i++) {
            int fd = clientes[i];
            if (FD_ISSET(fd, &fds)) {
                int bytes = read(fd, buffer, BUFFER_SIZE);
                if (bytes <= 0) {
                    // Cliente desconectado
                    printf("Cliente %d desconectou\n", fd);
                    close(fd);
                    clientes[i] = 0;
                } else {
                    buffer[bytes] = '\0';
                    printf("Cliente %d disse: %s", fd, buffer);
                }
            }
        }
    }

    return 0;
}

