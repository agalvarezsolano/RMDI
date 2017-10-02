
#ifndef REMOTEMEMORY_CLIENTRMLIB_H
#define REMOTEMEMORY_CLIENTRMLIB_H

#include <netinet/in.h>

class ClientRmlib{
public:
    int sock;
    struct sockaddr_in mainServer;
    struct sockaddr_in serverHA;
    char *mainIP, *IPHA;
    int mainPort, portHA;
    ClientRmlib();
    ClientRmlib(char*, int , char*, int );
    int connectClient();
    char* sendMessage(char*, int );

};

#endif //REMOTEMEMORY_CLIENTRMLIB_H
