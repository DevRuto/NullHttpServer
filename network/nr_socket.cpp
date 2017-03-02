#include "nr_socket.h"
#include <cstdio>

nr_socket::nr_socket()
{
    //ctor
}

nr_socket::nr_socket(SOCKET s) {
    this->sock = s;
}

nr_socket::~nr_socket()
{
    //dtor
}

void nr_socket::ncreate(void) {
#ifdef _WIN32
    WSADATA wsa_data;
    int result = WSAStartup(MAKEWORD(1, 1), &wsa_data);
    if (result != 0) {
        puts("WSAStartup Failed\n");
        return;
    }
#endif
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
}

int nr_socket::nshutdown(void) {
    int status = 0;
#ifdef _WIN32
    status = shutdown((SOCKET)this->sock, SD_BOTH);
    if (status == 0)
        closesocket((SOCKET)this->sock);
    if (server)
        status = WSACleanup();
#else
    status = shutdown(this->sock, SHUT_RDWR);
	if (status == 0)
		status = close(this->sock);
#endif
    return status;
}

int nr_socket::nconnect(const char *hostname, unsigned short port) {
    struct hostent *host;
    if ((host = gethostbyname(hostname)) == NULL) {
        puts("Failed to resolve hostname\n");
        return 0;
    }

    struct sockaddr_in addr;
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    int result = 0;
    if ((result = connect((SOCKET) this->sock, (const struct sockaddr *) &addr, sizeof(addr))) != 0) {
        puts("Failed to connect to server\n");
        return nshutdown();
    }
    return result;
}

int nr_socket::nbind(const char *hostname, unsigned short port) {
    struct sockaddr_in service;
    service.sin_family = AF_INET;
    //service.sin_addr.s_addr = inet_addr(hostname);
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port);

    int result = bind((SOCKET)this->sock, (const struct sockaddr*)&service, sizeof(service));
    if (result == SOCKET_ERROR) {
        puts("Bind failed\n");
        printf("Error %d\n", WSAGetLastError());
        return nshutdown();
    }
    this->server = 1;
    return result;
}

int nr_socket::nlisten(unsigned int maxcon) {
    return listen((SOCKET)this->sock, maxcon);
}

int nr_socket::naccept(struct sockaddr *addr, int *addrlen) {
    return accept((SOCKET)this->sock, NULL, NULL);
}

int nr_socket::nread(char *buffer, unsigned int bufferSize) {
#ifdef _WIN32
    return recv(this->sock, buffer, bufferSize, 0);
#else
    return read(this->sock, buffer, bufferSize);
#endif
}

int nr_socket::nsend(const char *buffer, unsigned int bufferSize) {
    return send((SOCKET)this->sock, buffer, bufferSize, 0);
}
