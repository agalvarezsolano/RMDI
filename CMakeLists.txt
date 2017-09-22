cmake_minimum_required(VERSION 3.8)
project(RemoteMemory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rmlib.cpp rmlib.h rmRef_h.h rmRef_h.cpp Structures/Node.h Structures/LinkedList.cpp Structures/LinkedList.h Structures/Node.cpp clientRmlib.cpp clientRmlib.h)
add_executable(RemoteMemory ${SOURCE_FILES})