cmake_minimum_required(VERSION 3.6)
project(NullHttpServer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp network/packets/packet.cpp network/packets/packet.h network/packets/httppacket.cpp network/packets/httppacket.h network/server.cpp network/server.h network/parsers/parser.h network/parsers/httpparser.cpp network/parsers/httpparser.h nulldef.h)
add_executable(NullHttpServer ${SOURCE_FILES})