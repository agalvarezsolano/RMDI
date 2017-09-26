//
// Created by adrian on 24/09/17.
//

#include "memoryManager.h"



MemoryManager* MemoryManager::instance = 0;

MemoryManager *MemoryManager::getInstance() {
    if (instance == 0){
        instance = new MemoryManager();
    }
    return instance;
}

MemoryManager::MemoryManager() {

}
