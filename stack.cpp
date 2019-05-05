#include <iostream>
#include "windows.h"

#ifndef STACK
#define STACK
#include "stack.h"
#endif // STACK
using namespace std;


//set cursor position in console
void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

//clear user input history for convenience
void clearInput(int y, int firstRow) {
    int i = firstRow;
    while(i<=y) {
        gotoxy(0, i);
        cout<<"                              ";
        i++;
    }
}


//Add new node to beginning using inherited method.
//Return 1 if memory allocation successful.
int Stack::push(float n)
{
    return insertStart(n);
}

//pop first node using inherited method
void Stack::pop() {
    removeStart();
}


//print all elements in the stack
void Stack::printStack(int y) {
    //clear stack display
    clearScreen(y);

    Node * curr;
    Node * head = getHead();
    for(Node * curr = head; curr; curr = curr->next, y++) {
        //set cursor x-position to middle of screen
        gotoxy(50, y);
        cout<<curr->data;
    }
}

//clear stack display to display a newly pushed value,
//or show that a value has been popped
void Stack::clearScreen(int y) {
    Node * curr;
    Node * head = getHead();

    //replace all console lines that display stack with blank space
    for(curr = head; curr; curr = curr->next, y++) {
        gotoxy(50, y);
        cout<<"                         ";
    }
}


//returns the # of elements in the stack
int Stack::getSize() {
    int nodeCnt = 0;

    for(Node * curr = getHead(); curr; curr = curr->next)
        nodeCnt++;

    return nodeCnt;
}




