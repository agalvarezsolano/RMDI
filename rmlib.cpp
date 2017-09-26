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

    char* message;
    rmRef_h instance = rmRef_h(this->key,this->value, this->value_size);
    message = generateMessage(instance, 'n');
    int state = this->client.connectClient();

    if (state > 0)
    {
        cout << "Conectado al Main server" << endl;
        this->client.sendMessage(message, sizeof(message));

    } else if(state < 0)
    {
        cout << "Conectado al server HA" << endl;
        this->client.sendMessage(message, sizeof(message));

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

bool Rmlib::interpretMessage(char* instance)
{
    return true;
}

char* Rmlib::generateMessage(rmRef_h bd, char type) {
    char* message = nullptr;
    if(type == 'n') {
        sprintf(message, "%c%s@%p@%d@#", type, bd.key, bd.value, bd.value_size);
    }
    if(type == 'g'){
        sprintf(message,"%c%s@#", type,bd.key);
    }
    if (type == 'd'){
        sprintf(message, "%c%s@#", type, bd.key);
    }
    return message;
}

char Rmlib::generateMessage() {
    return 0;
}