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
    rmRef_h();

};

rmRef_h::rmRef_h()
{
    this->referencias = 1;
}


#endif //REMOTEMEMORY_RMREF_H_H
