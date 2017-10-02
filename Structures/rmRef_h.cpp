
#include <cstdio>
#include "rmRef_h.h"
///@brief constructor con datos exactos
///@tparam key clave de la instancia
///@tparam value informacion que va a guardar
///@tparam value_size tamano del dato guardado
rmRef_h::rmRef_h(char * key, void * value, int value_size)
{
    this->key = key;
    this->value = value;
    this->value_size = value_size;
    this->referencias = 1;
}
///@brief constructor vacio
rmRef_h::rmRef_h()
{
    this->key = NULL;
    this->value = NULL;
    this->value_size = 0;
    this->referencias = 0;

}
