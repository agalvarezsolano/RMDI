//
// Created by adrian on 20/09/17.
//

#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread

void *connection_handler(void *);

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);


    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
           return 1;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];

    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock , message , strlen(message));

    message = "Now type something and i shall repeat what you type \n";
    write(sock , message , strlen(message));

    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //Send the message back to client
        write(sock , client_message , strlen(client_message));
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);

    return 0;
}
/*
/*
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


using  namespace std;

int main()
{
    int server, client;
    int portNum = 8080;
    bool isExit = false;
    int bufsize;
    char buffer[20000];
    int read_size;
    socklen_t lenrecv;
    struct sockaddr addr;

    struct sockaddr_in server_addr;
    socklen_t size;

    //init socket

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        cout << "Error al establecer conexion." << endl;
        exit(1);
    }

    cout << "Conexion de server creada..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    //binding

    if (bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        cout << "Error en el binding" << endl;
        exit(1);
    }

    size = sizeof(server_addr);
    cout << "Esperando Clientes..." << endl;


    //Listening

    listen(client,20);


    //accept clients

    server = accept(client, (struct sockaddr*)&server_addr, (socklen_t*)&size);

    if (server < 0)
    {
        cout << "Error al aceptar" << endl;
        exit(1);
    }
    while(1) {
        cout << "Esperando mensaje" << endl;

        lenrecv = sizeof(addr);
        read_size = recvfrom(server, buffer, 20000, 0, &addr, &lenrecv);
        cout << "Bytes Recibidos: " << endl;
        cout << read_size << endl;

        bufsize = read_size;

        if (read_size > 0) {
            char buf_read[read_size];
            buf_read = "" + buffer;
            cout << buf_read << endl;

            write(server, buf_read, read_size);


        }
        if (read_size == 0)
        {
            cout << "Cliente desconectado" << endl;
            break;
        }

        if (read_size == -1) {
            cout << "recv fallido" << endl;
            exit(1);
        }
    }

    return 0;


    /*

    while (server > 0)
    {
        strcpy(buffer, "Server conectando...\n");
        send(server, buffer, bufsize, 0);

        cout << "Conectando con cliente..." << endl;
        cout << "Enter # para finalizar coneccion" << endl;

        cout << "cliente: ";
        do{
            recv(server,buffer,bufsize,0);
            cout << "buffer" << "";
            if(*buffer == '#')
            {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        do{
            cout << "\nServer: ";
            do{
                cin >> buffer;
                send(server, buffer, bufsize, 0);
                if (*buffer == '#')
                {
                    send(server, buffer, bufsize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            }while (*buffer != '*');

            cout << "Client: ";
            do{
                recv(server, buffer,bufsize, 0);
                cout << buffer << "";
                if(*buffer == '#')
                {
                    *buffer = '*';
                    isExit = true;
                }
            }while (*buffer != '*');
        }while (!isExit);

        cout << "Conexion terminada... " << endl;

        isExit = false;
        exit(1);
    }

    close(client);


}
*/