cmake_minimum_required(VERSION 3.9)
project(RemoteMemory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rmlib.cpp rmlib.h rmRef_h.h Structures/Node.h Structures/LinkedList.cpp Structures/LinkedList.h )
add_executable(RemoteMemory ${SOURCE_FILES})