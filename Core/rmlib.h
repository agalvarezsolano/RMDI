//
// Created by adrian on 21/09/17.
//

#ifndef REMOTEMEMORY_RMLIB_H
#define REMOTEMEMORY_RMLIB_H

#include "../Structures/rmRef_h.h"
#include "../Connection/clientRmlib.h"

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
    char * generateMessage(rmRef_h,char);
    bool interpretMessage(char* instance);
};

#endif //REMOTEMEMORY_RMLIB_H
