//
// Created by Ruto on 2/11/2017.
//

#include <cstring>
#include "httppacket.h"

void httppacket::addheader(const char *key, const char *value) {
    this->headers[key] = value;
    this->totallength += (strlen(key) + strlen(value) + 4);
}

void httppacket::removeheader(const char *key) {
    if ((iterator = this->headers.find(key)) != this->headers.end())
        return;
    this->totallength -= (strlen(key) + strlen(iterator->second) + 4); // delimeter and crlf
    this->headers.erase(iterator);
}

const char *httppacket::getheader(const char *key) {
    if ((iterator = this->headers.find(key)) != this->headers.end())
        return iterator->second;
    return NULL;
}

void httppacket::payload(const char *payload) {
    this->p_payload = payload;
    this->totallength += strlen(payload);
}

const char *httppacket::payload() {
    return this->p_payload;
}

char *httppacket::serialize() {
    char *buffer = new char[this->totallength];
    int index = 0, i;
    const char *placeholder;
    for (i = 0;i < strlen(command()); ++i) {
        buffer[index++] = command()[i];
    }
    buffer[index++] = '\r';
    buffer[index++] = '\n';
    for (const auto& kv : this->headers) {
        placeholder = (char *)kv.first;
        for(i = 0; i < strlen(placeholder); ++i) {
            buffer[index++] = placeholder[i];
        }

        buffer[index++] = ':';
        buffer[index++] = ' ';

        placeholder = kv.second;
        for(i = 0; i < strlen(placeholder); ++i) {
            buffer[index++] = placeholder[i];
        }
        buffer[index++] = '\r';
        buffer[index++] = '\n';
    }
    buffer[index++] = '\r';
    buffer[index++] = '\n';
    if (p_payload) {
        for (i = 0; i < strlen(p_payload); ++i) {
            buffer[index++] = p_payload[i];
        }
    }
    buffer[index] = '\0';
    return buffer;
}

httppacket::httppacket(const char *cmd) : packet(cmd) {

}
