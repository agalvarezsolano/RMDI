
#include <cstdio>
#include <malloc.h>
#include "LinkedList.h"


LinkedList::LinkedList()
{
    this->head =  NULL;
    this->size = 0;
}
///@brief inserta un dato al inicio
///@tparam dato
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
///@brief borra el ultimo dato
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
///@brief borra un dato con la clave
///@tparam key clave a eliminar
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
///@brief libera el espacio de las claves no instanciadas
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
///@brief devuelve la instancia que corresponde a la clave solicitada
///@tparam key clave solicitada
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
///@brief informa si la clave esta o no en la memoria
///@tparam key dato que se busca
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
///@brief inserta al inicio de la cache
///@tparam dato
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
