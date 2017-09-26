//
// Created by adrian on 21/09/17.
//

#include <cstdio>
#include <malloc.h>
#include "LinkedList.h"


LinkedList::LinkedList()
{
    this->head =  NULL;
    this->size = 0;
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
    this->size++;
}

void LinkedList::deleteLast()
{
    if(this->head != NULL) {

        Node *current = this->head;
        Node *previous = current;
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next= NULL;
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
        this->size--;
    }

}

void LinkedList::freeMemory()
{
    if(this->head == NULL) {
        Node *current = this->head;
        Node *previous = current;
        while(current->next != NULL){
            if (current->dato.referencias == 0){
                previous->next=current->next;
                free(current);
            }
            previous = current;
            current =  current->next;
        }if(this->size == 1){
            free(current);
            this->head = NULL;
        }if(this->size > 1 && current->dato.referencias == 0) {
            previous->next=current->next;
            free(current);
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
        }else{
            return false;
        }
    }
    return false;
}


void LinkedList::insertFirstCache(rmRef_h dato)
{
    Node* newNode = new Node(dato);
    if(this->head == NULL)
    {
        this->head = newNode;
        this->size++;
    }
    if(this->size == 5){
        newNode->next = this->head;
        this->head = newNode;
        deleteLast();
    }else{
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

}
