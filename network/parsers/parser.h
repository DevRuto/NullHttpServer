//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_PARSER_H
#define NULLHTTPSERVER_PARSER_H

#include "../packets/httppacket.h"

class parser {
public:
    void (*packethandler)(httppacket);
    void parse();
    parser(void (*handler)(httppacket)) {
        this->packethandler = handler;
    }

};

#endif //NULLHTTPSERVER_PARSER_H
