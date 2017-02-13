//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_HTTPPACKET_H
#define NULLHTTPSERVER_HTTPPACKET_H


#include <map>
#include "packet.h"

class httppacket : packet {

public:
    httppacket();
    httppacket(const char *);

    char *serialize();
    void addheader(const char *, const char *);
    void removeheader(const char *);
    const char *getheader(const char *);

    void payload(const char *);
    const char *payload();

private:
    int totallength = 0;
    std::map<const char *, const char *> headers;
    std::map<const char *, const char *>::iterator iterator;
    const char *p_payload = NULL;
};


#endif //NULLHTTPSERVER_HTTPPACKET_H
