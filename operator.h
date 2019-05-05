#ifndef STACK
#define STACK
#include "stack.h"
#endif // STACK


//inherits from Stack, which in turn inherits from LinkedList
class Operator : public Stack {
    public:
       //default constructor implicitly created

        //instance methods perform operation on top two nodes
        void add();
        void subtract();
        void multiply();
        void divide();
        //power
        void exp();

        //clear entire stack
        void allClear();
};

