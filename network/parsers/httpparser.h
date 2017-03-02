//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_HTTPPARSER_H
#define NULLHTTPSERVER_HTTPPARSER_H

#define PARSER_STATE_COMMAND 0
#define PARSER_STATE_HEADER 1
#define PARSER_STATE_PAYLOAD 2

#include "parser.h"
#include "../../nulldef.h"

class httpparser : public parser {
public:
    httpparser(httphandler *, nr_socket *);
    void parse(const char *);

private:
    int PARSER_STATE = PARSER_STATE_COMMAND;
    nr_socket *sock;
    httppacket *curPacket = NULL;
    char buffer[PARSE_BUFFER_SIZE];
    unsigned int payload_length = 0;
};


#endif //NULLHTTPSERVER_HTTPPARSER_H
