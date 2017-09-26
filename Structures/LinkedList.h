//
// Created by adrian on 21/09/17.
//

#ifndef REMOTEMEMORY_LINKEDLIST_H
#define REMOTEMEMORY_LINKEDLIST_H

#include "Node.h"

class LinkedList
{
public:
    Node* head;
    LinkedList();

    void insertFirst(rmRef_h);
    void insertLast(rmRef_h);
    bool findKey(char*);
    void deleteKey(char*);
    rmRef_h getRef(char*);
    void freeMemory();
    int size;
    void insertFirstCache(rmRef_h dato);
    void deleteLast();
};

#endif //REMOTEMEMORY_LINKEDLIST_H
