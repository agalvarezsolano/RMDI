//
// Created by adrian on 24/09/17.
//

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include "MainServer.h"
using namespace std;

void *connection_handler(void *);

MainServer::MainServer(int port)
{
    this->storage = MemoryManager::MMSingleton();
    this->socket_desc = socket(AF_INET, SOCK_STREAM,0);
    if (socket_desc == -1){
        cout << "Error al crea el socket del Main Server" << endl;
    }
    cout << "Main Socket creado" << endl;

    server->sin_family = AF_INET;
    server->sin_port = htons(port);
    server->sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_desc,(struct sockaddr*)&server, sizeof(server)) < 0)
    {
       cout << "Error en Main Bind" << endl;
        exit(1);
    }
    cout << "Escuchando" << endl;

    listen(socket_desc, 20);

    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)))
    {
        cout << "Cliente aceptado" << endl;
        pthread_t sniffer_thread;
        new_sock = static_cast<int *>(malloc(1));
        *new_sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*) new_sock) < 0)
        {
            cout << "Hilo no creado" << endl;
            exit(1);
        }
        if (client_sock < 0){
            cout << "Cliente no aceptado" << endl;
            exit(1);
        }
    }

}

void *connection_handler(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    int read_size;
    char* message, clientMessage[2000];

    while((read_size = recv(sock, clientMessage, 2000, 0)) > 0)
    {

    }
}
