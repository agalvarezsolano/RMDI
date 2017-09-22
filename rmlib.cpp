//
// Created by adrian on 21/09/17.
//

#include "rmlib.h"

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
    this->key = key;
    this->value = value;
    this->value_size = value_size;

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

