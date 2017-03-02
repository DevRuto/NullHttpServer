//
// Created by Ruto on 2/11/2017.
//

#include "server.h"
#include "packets/httppacket.h"
#include "parsers/httpparser.h"
#include <cstdio>


server::server(unsigned short port, unsigned int maxconnections, httphandler *handler) {
    this->handler = handler;
    this->port = port;
    this->maxconn = maxconnections;
}

int server::start() {
    this->serversocket.ncreate();
    int code;
    if ((code = this->serversocket.nbind("*", this->port)) < 0) {
        return code;
    }
    this->serversocket.nlisten(this->maxconn);

    puts("Listening");

    struct sockaddr_in addr;
    int len;
    SOCKET clientsocket;
    while(1) {
        if ((clientsocket = this->serversocket.naccept((struct sockaddr *) &addr, &len)) != INVALID_SOCKET) {
            this->handle(clientsocket, &addr);
        }
    }

    return 1;
}

void server::handle(SOCKET client, struct sockaddr_in *addr) {
    nr_socket s(client);
    httpparser p(this->handler, &s);
    int bufferSize = 512;
    char buffer[bufferSize];
    int read;
    while ((read = s.nread(buffer, bufferSize)) != 0) {
        buffer[read] = 0;
        p.parse(buffer);
    }
    s.nshutdown();
}
