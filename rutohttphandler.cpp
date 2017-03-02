#include "rutohttphandler.h"

#include <cstdio>

void rutohttphandler::handle(httppacket *packet, nr_socket *sock) {
    const char *buff = "HTTP/1.1 200 OK\r\nCONTENT-LENGTH: 5\r\nConnection: Closed\r\n\r\nHELLO";
    sock->nsend(buff, strlen(buff));
    printf("Received: %s\n", packet->command());
}
