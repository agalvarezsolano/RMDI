//
// Created by adrian on 21/09/17.
//

#ifndef REMOTEMEMORY_RMREF_H_H
#define REMOTEMEMORY_RMREF_H_H


class rmRef_h {
public:
    char* key;
    void* value;
    int value_size;
    int referencias;
    rmRef_h(char*, void*, int);
    rmRef_h();

};


#endif //REMOTEMEMORY_RMREF_H_H
