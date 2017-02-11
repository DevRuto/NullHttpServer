cmake_minimum_required(VERSION 3.6)
project(NullHttpServer)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp network/packet.cpp network/packet.h)
add_executable(NullHttpServer ${SOURCE_FILES})