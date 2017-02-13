//
// Created by Ruto on 2/11/2017.
//

#include "packet.h"

packet::packet() {

}

packet::packet(const char *command) {
    this->cmd = command;
}

void packet::command(const char *cmd) {
    this->cmd = cmd;
}

const char *packet::command() {
    return this->cmd;
}