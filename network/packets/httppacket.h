//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_HTTPPACKET_H
#define NULLHTTPSERVER_HTTPPACKET_H


#include <map>
#include "packet.h"

class httppacket : public packet {

public:
    httppacket();
    httppacket(const char *);

    char *serialize();
    void command(const char *);
    const char *command();
    void addheader(char *, const char *);
    void removeheader(char *);
    const char *getheader(char *);

private:
    const char *cmd = NULL;
    int totallength = 0;
    std::map<const char *, const char *> headers;
    std::map<const char *, const char *>::iterator iterator;
};


#endif //NULLHTTPSERVER_HTTPPACKET_H
