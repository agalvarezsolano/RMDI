

#ifndef REMOTEMEMORY_NODE_H
#define REMOTEMEMORY_NODE_H


#include "rmRef_h.h"

class Node {
public:
    Node(rmRef_h);
    rmRef_h dato;
    Node* next;
};




#endif //REMOTEMEMORY_NODE_H
