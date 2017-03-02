//
// Created by Ruto on 2/11/2017.
//

#include <cstring>
#include <cstdio>
#include "httppacket.h"

httppacket::httppacket() : packet() {

}

httppacket::httppacket(const char *cmd) {
    this->command(cmd);
}


void httppacket::addheader(char *key, const char *value) {
    while (*key = tolower(*key)) {
        ++key;
    }
    this->headers[key] = key;
    this->totallength += (strlen(key) + strlen(value) + 4);
    printf("Add Header: %s-%s\n", key, value);
}

void httppacket::removeheader(char *key) {
    while (*key = tolower(*key)) {
        ++key;
    }
    if ((iterator = this->headers.find(key)) != this->headers.end())
        return;
    this->totallength -= (strlen(key) + strlen(iterator->second) + 4); // delimeter and crlf
    this->headers.erase(iterator);
}

const char *httppacket::getheader(char *key) {
    while (*key = tolower(*key)) {
        ++key;
    }
    if ((iterator = this->headers.find(key)) != this->headers.end())
        return iterator->second;
    return NULL;
}

void httppacket::command(const char *command) {
    this->cmd = command;
}

const char *httppacket::command() {
    return this->cmd;
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
    if (payload()) {
        for (i = 0; i < strlen(payload()); ++i) {
            buffer[index++] = payload()[i];
        }
    }
    buffer[index] = '\0';
    return buffer;
}
