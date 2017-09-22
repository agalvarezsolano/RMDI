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
    */

}
