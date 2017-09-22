//
// Created by adrian on 21/09/17.
//

#ifndef REMOTEMEMORY_NODE_H
#define REMOTEMEMORY_NODE_H


#include "../rmRef_h.h"

class Node {
public:
    Node(rmRef_h);
    rmRef_h dato;
    Node* next;
};

Node::Node(rmRef_h dato)
{
    this->dato = dato;
    this->next = NULL;
}


#endif //REMOTEMEMORY_NODE_H
