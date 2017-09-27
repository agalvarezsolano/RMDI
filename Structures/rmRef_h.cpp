
#include <cstdio>
#include "rmRef_h.h"

rmRef_h::rmRef_h(char * key, void * value, int value_size)
{
    this->key = key;
    this->value = value;
    this->value_size = value_size;
    this->referencias = 1;
}

rmRef_h::rmRef_h()
{
    this->key = NULL;
    this->value = NULL;
    this->value_size = 0;
    this->referencias = 0;

}
