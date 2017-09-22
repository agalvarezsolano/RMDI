//
// Created by curso on 22/09/17.
//

#include "clientRmlib.h"
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

ClientRmlib::ClientRmlib()
{
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cout << "Error al crear socket del cliente" << endl;
    }
}

ClientRmlib::ClientRmlib(char *ip, int port, char *ipHA, int portHA)
{
    this->mainIP = ip;
    this->mainPort = port;
    this->IPHA = ipHA;
    this->portHA = portHA;

    mainServer.sin_addr.s_addr = inet_addr(ip);
    mainServer.sin_family = AF_INET;
    mainServer.sin_port = htons(mainPort);

    serverHA.sin_addr.s_addr = inet_addr(ipHA);
    serverHA.sin_family = AF_INET;
    serverHA.sin_port = htons(portHA);

}

int ClientRmlib::connectClient(){
    if(connect(sock, (struct sockaddr *) &this->mainServer, sizeof(this->mainServer)) > 0)
    {
        return 1;

    }else {
        if(connect(sock,(struct sockaddr*)&this->serverHA, sizeof(this->serverHA)) > 0)
        {
            return 2;

        }else{
            return 0;
        }
    }
}

void ClientRmlib::sendMessage(char message)
{

}
