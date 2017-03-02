#include <iostream>
#include <stdio.h>
#include "network/packets/httppacket.h"
#include "network/server.h"
#include "rutohttphandler.h"
#include "nr_func.h"

int main() {
    rutohttphandler handler;
    server s(1337, 5, &handler);
    s.start();
    return 0;
}
