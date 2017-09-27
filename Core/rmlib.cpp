//
// Created by adrian on 21/09/17.
//

#include "rmlib.h"
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



}

void Rmlib::rm_new(char *key, void *value, int value_size)
{
    ClientRmlib client = ClientRmlib(this->ip, this->port, this->ipHA, this->portHA);
    this->key = key;
    this->value = value;
    this->value_size = value_size;

    char* message;
    rmRef_h instance = rmRef_h(this->key,this->value, this->value_size);
    message = generateMessage(instance, 'n');


    int state = client.connectClient();
    cout << state << endl;

    if (state == 1)
    {
        cout << "Conectado al Main server" << endl;
        cout << sizeof(message) << endl;
        client.sendMessage(message, sizeof(message));

    } else if(state == -2)
    {
        cout << "Conectado al server HA" << endl;
        client.sendMessage(message, sizeof(message));

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
    string  word;
    if(type == 'n') {
        string n,m,p,q, o;
        n = type;
        word = word + n;
        m = bd.key;
        word = word + m + '@';
        int* s = (int *)bd.value;
        o = *s;
        word = word +  o + '@';
        q = bd.value_size;
        word = word + q + '@' +'#';
    }
    if(type == 'g'){
        sprintf(message,"%c%s@#", type,bd.key);
    }
    if (type == 'd'){
        sprintf(message, "%c%s@#", type, bd.key);
    }
    cout << "tama;o creado" << endl;

    cout << sizeof(message) << endl;
    return message;
}
