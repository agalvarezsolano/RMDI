//
// Created by adrian on 21/09/17.
//

#include "rmlib.h"
#include "clientRmlib.h"
#include <iostream>

using namespace std;

Rmlib::Rmlib()
{

}

void Rmlib::rm_init(char* ip, int port, char* ipHA, int portHA)
{
    this->ip = ip;
    this->port = port;
    this->ipHA = ipHA;
    this->portHA = portHA;

    this->client = ClientRmlib(this->ip, this->port, this->ipHA, this->portHA);

}

void Rmlib::rm_new(char *key, void *value, int value_size)
{
    this->key = key;
    this->value = value;
    this->value_size = value_size;

    char message = generateMessage();
    int state = this->client.connect(0, nullptr, 0);

    if (state > 0)
    {
        cout << "Conectado al Main server" << endl;
        this->client.sendMessage(message);

    } else if(state < 0)
    {
        cout << "Conectado al server HA" << endl;
        this->client.sendMessage(message);

    } else if (state == 0)
    {
        cout << "Sin conexion a los servidores" << endl;

    }


}

rmRef_h Rmlib::rm_get(char *key)
{
    return rmRef_h();
}

void Rmlib::rm_delete(rmRef_h *handler)
{
    this->handler = handler;
    this->key = handler->key;
}

bool Rmlib::interpretMessage()
{
    return false;
}

char Rmlib::generateMessage(char*) {
    return 0;
}

char Rmlib::generateMessage() {
    return 0;
}