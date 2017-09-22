//
// Created by adrian on 21/09/17.
//

#ifndef REMOTEMEMORY_RMLIB_H
#define REMOTEMEMORY_RMLIB_H

#include "rmRef_h.h"

class Rmlib
{
public:
    Rmlib();
    void rm_init(char*, int , char* , int );
    void rm_new(char* , void* ,int );
    rmRef_h rm_get(char* );
    void rm_delete(rmRef_h* );

private:
    int port, portHA, value_size;
    rmRef_h* handler;
    char* key;
    char* ipHA;
    char* ip;
    void* value;

};

#endif //REMOTEMEMORY_RMLIB_H
