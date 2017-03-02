//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_PARSER_H
#define NULLHTTPSERVER_PARSER_H

#include "../packets/httppacket.h"
#include "../httphandler.h"
#include "../nr_socket.h"

class parser {
public:
    httphandler *packethandler;
    void parse();
    parser(httphandler *handler) {
        this->packethandler = handler;
    }

};

#endif //NULLHTTPSERVER_PARSER_H
