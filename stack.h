#include "windows.h"

#ifndef STACK
#define STACK
#include "stack.h"
#endif // STACK

#ifndef LIST
#define LIST
#include "linkedlist.h"
#endif // LIST


//prototypes
//function sets cursor position in console
void gotoxy(int x, int y);

//function clears the user's input history
//after a certain # of lines for convenience
void clearInput(int y, int lenText);


//Stack inherits from LinkedList
class Stack : public LinkedList {
    public:
        //default constructor implicitly created

        //add node to LinkedList
        int push(float);

        //remove head node
        void pop();

        //print all nodes in LinkedList
        void printStack(int);

        //return the # of nodes contained in LinkedList
        int getSize();

        //clear the stack display
        void clearScreen(int);

};



