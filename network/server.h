//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_SERVER_H
#define NULLHTTPSERVER_SERVER_H

#include "nr_socket.h"
#include "httphandler.h"

class server {

public:
    server(unsigned short, unsigned int, httphandler *);
    int start();

private:
    unsigned short port;
    unsigned int maxconn;
    nr_socket serversocket;
    httphandler *handler;
    void handle(SOCKET, struct sockaddr_in *);
};


#endif //NULLHTTPSERVER_SERVER_H
