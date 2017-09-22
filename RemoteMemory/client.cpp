//
// Created by adrian on 20/09/17.
//

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>


using  namespace std;

int main()
{
    int sock;
    struct sockaddr_in server;
    char message[1024], server_replay[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        cout << "Error al crear socket" << endl;
    }

    cout << "Socket creado" << endl;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);


    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        cout << "Error al conectar" << endl;
        return 1;
    }

    cout << "Conectado" << endl;

    while(1)
    {


        cout << "Client: ";
        cin >> message;

        if (send(sock, message, strlen(message), 0) < 0)
        {
            cout << "Error al enviar" << endl;
            return 1;
        }

        if (recv(sock, server_replay, 1024, 0) < 0)
        {
            cout << "Recv fallido" << endl;
            break;
        }
        cout << "Server reply: " << endl;
        cout << server_replay << endl;


    }






















    /*
    int server, client;
    int portNum = 8080;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char *ip = "127.0.0.1";


    struct sockaddr_in server_addr;

    // init socket

    client = socket(AF_INET, SOCK_STREAM, 0);

    if(client < 0)
    {
        cout << "Error al crear socket" << endl;
        exit(1);
    }

    cout << "Socket del cliente creado" << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    //conexion con server

    if (connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        cout << "Conectando con server..." << endl;

        const char* hola = "hola server";
        send(client,hola,bufsize,0);
    }


    /*
    recv(client, buffer,  bufsize, 0);
    cout << "Conexion realizada" << endl;

    cout << "Enter # para desconectar" << endl;




    do{
        cout << "Client: ";

        do{
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#')
            {
                send(client,buffer,bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        }while(*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << "";
            if (*buffer == '#')
            {
                *buffer = '*';
                isExit = true;
            }
        }while (*buffer != 42);

        cout << endl;
    }while (!isExit);

    cout << " Conexion terminada..." << endl;
*/
    close(sock);

    return 0;
}
