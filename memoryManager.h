//
// Created by adrian on 24/09/17.
//

#ifndef REMOTEMEMORY_MEMORYMANAGER_H
#define REMOTEMEMORY_MEMORYMANAGER_H

#include "Structures/LinkedList.h"

class MemoryManager{

    static MemoryManager* instance;
public:
    LinkedList cacheMemory;
    LinkedList mainMemory;
    LinkedList HAMemory;

    static MemoryManager *MMSingleton(){
        if(!instance){
            instance = new MemoryManager;
        }
        return instance;
    }

};

#endif //REMOTEMEMORY_MEMORYMANAGER_H
