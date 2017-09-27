cmake_minimum_required(VERSION 3.9)
project(RemoteMemory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp  Core/rmlib.cpp Core/rmlib.h Structures/rmRef_h.h Structures/rmRef_h.cpp Structures/Node.h Structures/LinkedList.cpp Structures/LinkedList.h Structures/Node.cpp Connection/clientRmlib.cpp Connection/clientRmlib.h)
add_executable(RemoteMemory ${SOURCE_FILES})