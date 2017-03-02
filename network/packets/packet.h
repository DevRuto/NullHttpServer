//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_PACKET_H
#define NULLHTTPSERVER_PACKET_H


class packet {

public:
    packet(const char *);
    packet();

    void payload(const char *);
    const char *payload();
    unsigned int getPayloadLength();

private:
    const char *p_payload = 0;
    unsigned int length = 0;
};


#endif //NULLHTTPSERVER_PACKET_H
