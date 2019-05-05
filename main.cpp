/*Kevin Yang    ICS4U   Ms. Cullum  4/11/2019
RPN Calculator Part 4
*/

#include <iostream>
#include <fstream>
#include <string>

#ifndef STACK
#define STACK
#include "stack.h"
#endif // STACK

#ifndef OP
#define OP
#include "operator.h"
#endif // OP

#ifndef LIST
#define LIST
#include "linkedlist.h"
#endif // LIST
using namespace std;

//# of rows taken up by instructions
const int firstRow = 14;

int main ()
{
    //object inherits from both Stack and LinkedList
    Operator op;

    ifstream fin("instructions.txt");
    string text;

    //display instructions
    while(getline(fin, text))
        cout<<text<<endl;
    fin.close();

    //formatting
    gotoxy(0, firstRow);
    cout<<"INPUT: ";

    gotoxy(50, firstRow);
    cout<<"STACK: ";

    //keep track of what row the cursor is on
    int y = firstRow;

    while(1)
    {
        //stores number and/or operator entered by user
        string input;

        //stores only the digits and decimal point from input
        string operand;

        //keeps track of whether an operator has been encountered
        bool isOp = false;

        //temporarily store the operator entered by the user
        char tempOp;

        //refresh stack display every time a new value is pushed onto stack
        op.printStack(firstRow+1);

        //set cursor position to left of screen and move one line down
        gotoxy(0, ++y);

        cin>>input;

        //traverse user's input
        for(unsigned int i=0; i<input.length(); i++)
        {
            //concatenate element to operand if it is a digit or decimal point
            if(isdigit(input[i]) || input[i] == '.')
            {
                operand+=input[i];
            }
            else
            {
                //store the operator
                tempOp = input[i];
                isOp = true;
                break;
            }
        }

        //if input contains at least one digit, push that number into stack;
        //for ex. if 567+ is entered, push 567
        //otherwise, the user must have entered an operator by itself
        if(operand.length() > 0 && isdigit(operand[0]))
        {
            //convert operand into a float and push it onto the stack
            //print error message if push() returns failed (not enough memory)
            if(!(op.push(stof(operand))))
            {
                gotoxy(0, ++y);
                cout<<"Failed to push new value into stack."<<endl;
            }
        }

        if(isOp)
        {
            //ensures no operation is performed when only 1 element in stack
            if(op.getSize() > 1)
            {
                //clear stack display before size of list changes
                op.clearScreen(firstRow+1);

                switch(tempOp)
                {

                case '+':
                    op.add();
                    break;

                case '-':
                    op.subtract();
                    break;

                case '*':
                    op.multiply();
                    break;

                case '/':
                    op.divide();
                    break;

                case '^':
                    op.exp();
                    break;

                //pop top element
                case 'd':
                    op.pop();
                    break;

                //clear stack
                case 'c':
                    op.allClear();
                    break;

                //no need for default since invalid operators will be ignored
                }
            }
        }

        //clear user input history for convenience in windowed mode
        if(y > firstRow+15 && op.getSize() < 15) {
            clearInput(y, firstRow+1);
            y = firstRow;
        }
    }
}
