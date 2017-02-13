#ifndef NR_SOCKET_H
#define NR_SOCKET_H

#include "nr_platform.h"

class nr_socket
{
public:
    nr_socket();
    virtual ~nr_socket();
    int create(void);
    int shutdown(void);
    int connect(char*, int);
    int nr_socket_bind(char*, int);
    int nr_socket_listen(int);
    int nr_socket_accept(struct sockaddr *, int*);
    int nr_socket_read(char *, int);
    int nr_socket_send(char *, size_t);

protected:

private:
    SOCKET sock;

};

#endif // NR_SOCKET_H
