//
// Created by adrian on 21/09/17.
//

#include <cstdio>
#include "LinkedList.h"


LinkedList::LinkedList()
{
    this->head =  NULL;
}

void LinkedList::insertFirst(rmRef_h dato)
{
    Node* newNode = new Node(dato);
    if(this->head == NULL)
    {
        this->head = newNode;
    } else {
        newNode->next = this->head;
        this->head = newNode;
    }
}

void LinkedList::insertLast(rmRef_h dato)
{
    Node* newNode = new Node(dato);
    if(this->head == NULL)
    {
        this->head = newNode;
    } else{
        Node* temp = this->head;
        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void LinkedList::deleteKey(char * key)
{
    if(this->head == NULL) {
        Node *current = this->head;
        Node *previous;
        while(current->next != NULL){
            if (current->dato.key == key){
                current->dato.referencias = 0;
            }
            previous = current;
            current =  current->next;
        }
        if (current->dato.key == key) {
            current->dato.referencias = 0;
        }
    }
}

void LinkedList::freeMemory()
{
    if(this->head == NULL) {
        Node *current = this->head;
        Node *previous;
        while(current->next != NULL){
            if (current->dato.referencias == 0){
                previous->next=current->next;
            }
            previous = current;
            current =  current->next;
        }
        if (current->dato.referencias == 0) {
            previous->next=current->next;
        }
    }
}


rmRef_h LinkedList::getRef(char * key)
{

    if(this->head == NULL) {
        Node *current = this->head;
        while(current->next != NULL){
            if (current->dato.key == key){
                return current->dato;
            }
            current =  current->next;
        }
        if (current->dato.key == key) {
            return  current->dato;
        }
    }
    sizeof("8");
    return rmRef_h();

}

bool LinkedList::findKey(char * key) {
    if(this->head == NULL) {
        Node *temp = this->head;
        while(temp->next != NULL){
            if (temp->dato.key == key){
                return true;
            }
            temp = temp->next;
        }
        if (temp->dato.key == key){
            return true;
        }else {
            return false;
        }
    }
    return false;
}
