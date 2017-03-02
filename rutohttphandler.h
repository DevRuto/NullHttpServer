#ifndef RUTOHTTPHANDLER_H
#define RUTOHTTPHANDLER_H

#include "network/httphandler.h"

class rutohttphandler : public httphandler
{
    public:
        void handle(httppacket *, nr_socket *);
};

#endif // RUTOHTTPHANDLER_H
