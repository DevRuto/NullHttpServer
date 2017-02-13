//
// Created by Ruto on 2/11/2017.
//

#ifndef NULLHTTPSERVER_PACKET_H
#define NULLHTTPSERVER_PACKET_H


class packet {

public:
    packet();
    packet(const char *);
    void command(const char *);
    const char *command();

private:
    const char *cmd = "\0";

};


#endif //NULLHTTPSERVER_PACKET_H
