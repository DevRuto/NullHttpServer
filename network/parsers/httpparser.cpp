//
// Created by Ruto on 2/11/2017.
//

#include "httpparser.h"
#include <cstdio>
#include "../packets/httppacket.h"
#include "../../nr_func.h"

httpparser::httpparser(httphandler *handler, nr_socket *sock) : parser(handler) {
    this->sock = sock;
    this->PARSER_STATE = PARSER_STATE_COMMAND;
}

void httpparser::parse(const char *data) {
    unsigned int index,
                buffindex = 0,
                datalen = strlen(data),
                kindex;
    index = nr_func::nr_indexof(data, "\r\n");
    char *key, *value;
    if (this->PARSER_STATE == PARSER_STATE_COMMAND && index) {
        this->curPacket = new httppacket((const char *)nr_func::nr_substr(data, buffindex, index));
        this->payload_length = 0;
        buffindex += index + 2;
        this->PARSER_STATE = PARSER_STATE_HEADER;
    }
    index = nr_func::nr_indexof(data, "\r\n\r\n");
    if (this->PARSER_STATE == PARSER_STATE_HEADER && index) {
        char *buffer = nr_func::nr_substr(data, buffindex, buffindex+index);
        char *delimeter = "\r\n";
        char *token = strtok(buffer, delimeter); //first element
        while (token != NULL) {
            // handle first element
            key = nr_func::nr_substr(token, 0, kindex = nr_func::nr_indexof(token, ":"));
            value = nr_func::nr_substr(token, kindex + 2, strlen(token));
            this->curPacket->addheader(key, value);
            if (nr_func::nr_equals((const char *)key, "content-length")) {
                this->payload_length = atoi(value);
            }
            buffindex += strlen(token) + 2;
            token = strtok(NULL, delimeter);
        }
        buffindex += 4;
        if (this->payload_length > 0) {
            this->PARSER_STATE = PARSER_STATE_PAYLOAD;
        } else {
            this->PARSER_STATE = PARSER_STATE_COMMAND;
            this->packethandler->handle(this->curPacket, this->sock);
        }
    }
    if (this->PARSER_STATE == PARSER_STATE_PAYLOAD && (datalen >= this->payload_length)) {
        this->curPacket->payload((const char *)nr_func::nr_substr(data, buffindex, this->payload_length));
        this->packethandler->handle(this->curPacket, this->sock);
        this->PARSER_STATE = PARSER_STATE_COMMAND;
        buffindex += this->payload_length;
    }
    if (buffindex < datalen-1) { // more buffer
        this->parse((const char *)nr_func::nr_substr(data, buffindex, buffindex+datalen));
    }
}
