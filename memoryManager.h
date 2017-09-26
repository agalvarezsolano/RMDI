//
// Created by adrian on 24/09/17.
//

#ifndef REMOTEMEMORY_MEMORYMANAGER_H
#define REMOTEMEMORY_MEMORYMANAGER_H

#include "Structures/LinkedList.h"

class MemoryManager{
public:
    static MemoryManager* getInstance();
    LinkedList cacheMemory;
    LinkedList mainMemory;
    LinkedList HAMemory;
private:
    MemoryManager();
    static MemoryManager* instance;

};



#endif //REMOTEMEMORY_MEMORYMANAGER_H
