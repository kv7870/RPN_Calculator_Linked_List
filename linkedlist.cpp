#include <iostream>

#ifndef LIST
#define LIST
#include "linkedlist.h"
#endif // LIST

//constructor
LinkedList::LinkedList() {
    head = NULL;
};

//add new node at beginning of list
int LinkedList::insertStart(float value) {
    Node * newnode = new Node;
     //check if memory allocation successful
    if(!newnode)
        return 0;

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    return 1;
}

//remove first node
void LinkedList::removeStart() {
    Node * temp = head;
    head = head->next;
    delete temp;
}


//return head
Node * LinkedList::getHead() {
    return head;
}


