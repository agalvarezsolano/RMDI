//
// Created by adrian on 20/09/17.
//

#ifndef REMOTEMEMORY_SERVER_H
#define REMOTEMEMORY_SERVER_H

class Server{
private:
    int port,portA;
    char* ip, ipA;

public:
    Server(int port, int portA, char* ip, char* ipA);

};
#endif //REMOTEMEMORY_SERVER_H
