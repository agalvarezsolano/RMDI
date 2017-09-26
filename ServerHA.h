//
// Created by adrian on 25/09/17.
//

#ifndef REMOTEMEMORY_SERVERHA_H
#define REMOTEMEMORY_SERVERHA_H


#include "memoryManager.h"

class ServerHA{
public:
    MemoryManager *storage;
    //  int port,portA;
    //char* ip, ipA;
    int socket_desc , client_sock , c;
    int *new_sock;
    struct sockaddr_in *server , *client;
    ServerHA();
};


#endif //REMOTEMEMORY_SERVERHA_H
