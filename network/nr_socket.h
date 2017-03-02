#ifndef NR_SOCKET_H
#define NR_SOCKET_H

#define NR_NETWORK_INCLUDES
#include "nr_platform.h"

class nr_socket
{
public:
    nr_socket();
    nr_socket(SOCKET);
    virtual ~nr_socket();
    void ncreate(void);
    int nshutdown(void);
    int nconnect(const char *, unsigned short);
    int nbind(const char *, unsigned short);
    int nlisten(unsigned int);
    int naccept(struct sockaddr *, int *);
    int nread(char *, unsigned int);
    int nsend(const char *, unsigned int);

protected:

private:
    SOCKET sock;
    int server = -1;

};

#endif // NR_SOCKET_H
