
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
///@brief constructor vacio
ClientRmlib::ClientRmlib()
{

}
///@brief constructor de la clase clientRmlib
///@tparam ip, ipHA son los ip de los servidores
///@tparam port, portHA son los puestos de cada server
ClientRmlib::ClientRmlib(char *ip, int port, char *ipHA, int portHA)
{
    this->mainIP = ip;
    this->mainPort = port;
    this->IPHA = ipHA;
    this->portHA = portHA;

    mainServer.sin_addr.s_addr = inet_addr(this->mainIP);
    mainServer.sin_family = AF_INET;
    mainServer.sin_port = htons(this->mainPort);

    serverHA.sin_addr.s_addr = inet_addr(this->IPHA);
    serverHA.sin_family = AF_INET;
    serverHA.sin_port = htons(this->portHA);

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cout << "Error al crear socket del cliente" << endl;
    }
    cout << "Sock creado" << endl;

}
///@brief conecta la libreria con el server disponible en el momento
int ClientRmlib::connectClient(){

    if(connect(this->sock, (struct sockaddr *) &this->mainServer, sizeof(this->mainServer)) != -1)
    {
        return 1;

    } else if(connect(this->sock,(struct sockaddr*)&this->serverHA, sizeof(this->serverHA)) != -1) {
        return 2;
    } else{
        return 0;
    }

}
///@brief envia el mensaje al server previamente conectado
/// y espera la respuesta del server
char* ClientRmlib::sendMessage(char* message, int messageSize)
{
    int read_size;
    char* serverMessage;
    if (send(this->sock, &message, messageSize, 0) < 0)
    {
        cout << "Error al enviar" << endl;
    }else{
        cout << "Mensaje enviado correctamente" << endl;
    }
    if((read_size = recv(this->sock, serverMessage , 2000, 0)) > 0){
        cout << "Respuesta del server recibida" << endl;
        return serverMessage;
    }else{
        cout << "Error al recibir respuesta del server" << endl;
    }
}
