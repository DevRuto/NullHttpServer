#ifndef HTTPHANDLER_H_INCLUDED
#define HTTPHANDLER_H_INCLUDED

#include "packets/httppacket.h"
#include "nr_socket.h"

class httphandler {
public:
    virtual void handle(httppacket *, nr_socket *) = 0;
};

#endif // HTTPHANDLER_H_INCLUDED
