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

}

ClientRmlib::ClientRmlib(char *ip, int port, char *ipHA, int portHA)
{
    this->mainIP = ip;
    this->mainPort = port;
    this->IPHA = ipHA;
    this->portHA = portHA;

    mainServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    mainServer.sin_family = AF_INET;
    mainServer.sin_port = htons(8888);

    serverHA.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverHA.sin_family = AF_INET;
    serverHA.sin_port = htons(5555);

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cout << "Error al crear socket del cliente" << endl;
    }
    cout << "Sock creado" << endl;

}

int ClientRmlib::connectClient(){
    if(connect(this->sock, (struct sockaddr *) &this->mainServer, sizeof(this->mainServer)) != -1)
    {
        return 1;

    } else if(connect(this->sock,(struct sockaddr*)&this->serverHA, sizeof(this->serverHA)) != -1) {
        return -1;
    }
}

void ClientRmlib::sendMessage(char* message, int messageSize)
{
    if (send(this->sock, &message, messageSize, 0) < 0)
    {
        cout << "Error al enviar" << endl;
    } else{
        cout << "Mensaje enviado correctamente" << endl;
    }


}
