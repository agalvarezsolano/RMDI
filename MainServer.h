//
// Created by adrian on 24/09/17.
//

#ifndef REMOTEMEMORY_MAINSERVER_H
#define REMOTEMEMORY_MAINSERVER_H


#include "memoryManager.h"

class MainServer{
public:
    MemoryManager *storage;
  //  int port,portA;
    //char* ip, ipA;
    int socket_desc , client_sock , c;
    int *new_sock;
    struct sockaddr_in *server , *client;
    MainServer();
};

#endif //REMOTEMEMORY_MAINSERVER_H
