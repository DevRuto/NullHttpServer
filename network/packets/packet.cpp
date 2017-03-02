//
// Created by Ruto on 2/11/2017.
//

#include "packet.h"
#include <string.h>

packet::packet() {

}

packet::packet(const char *payload) {
    this->p_payload = payload;
    this->length = strlen(payload);
}

void packet::payload(const char *payload) {
    this->p_payload = payload;
    this->length = strlen(payload);
}

const char *packet::payload() {
    return this->p_payload;
}

unsigned int packet::getPayloadLength() {
    return this->length;
}
