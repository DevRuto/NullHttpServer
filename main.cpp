#include <iostream>
#include "network/packets/httppacket.h"

int main() {
    httppacket *h = new httppacket("command");


    std::cout << "Test server" << std::endl;
    std::cout << h->serialize() << std::endl;
    return 0;
}