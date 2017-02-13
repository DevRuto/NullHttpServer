//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_HTTPPARSER_H
#define NULLHTTPSERVER_HTTPPARSER_H


#include "parser.h"
#include "../../nulldef.h"

class httpparser : parser {
public:
    httpparser(void (*)(httppacket));
    void parse(const char *);

private:
    httppacket *curPacket;
    char buffer[PARSE_BUFFER_SIZE];
    unsigned int payload_length = 0;
};


#endif //NULLHTTPSERVER_HTTPPARSER_H
