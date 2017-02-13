//
// Created by Ruto on 2/11/2017.
//

#include "httpparser.h"

httpparser::httpparser(void (*handler)(httppacket)) : parser(handler) {
}

void httpparser::parse(const char *data) {

}
