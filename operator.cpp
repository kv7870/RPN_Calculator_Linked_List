#include <iostream>
#include <cmath>

#ifndef OP
#define OP
#include "operator.h"
#endif // OP
using namespace std;


//add top two nodes in stack
void Operator::add() {
    //store operands
    float temp[2];

    for(int i=0; i<2; i++) {
        temp[i] = getHead()->data;
        //remove node from stack once it is copied
        pop();
    }
    float sum = temp[0] + temp[1];
    push(sum);
}

//subtract topmost node from second node
void Operator::subtract() {
    //store operands
    float temp[2];

    for(int i=0; i<2; i++) {
        temp[i] = getHead()->data;
        //remove node from stack once it is copied
        pop();
    }
    float difference = temp[1] - temp[0];
    push(difference);
}

//multiply top two nodes in stack
void Operator::multiply() {
    //store operands
    float temp[2];

    for(int i=0; i<2; i++) {
        temp[i] = getHead()->data;
        //remove node from stack once it is copied
        pop();
    }
    float product = temp[0] * temp[1];
    push(product);
}

//divide the second node by the topmost node
void Operator::divide() {
    //store operands
    float temp[2];

    for(int i=0; i<2; i++) {
        temp[i] = getHead()->data;
        //remove node from stack once it is copied
        pop();
    }
    float quotient = temp[1] / temp[0];
    push(quotient);
}

//raise the second node to the power of the topmost node
void Operator::exp() {
    //store operands
     float temp[2];

    for(int i=0; i<2; i++) {
        temp[i] = getHead()->data;
        //remove node from stack once it is copied
        pop();
    }
    float ans = pow(temp[1], temp[0]);
    push(ans);
}

//delete all elements in the stack
void Operator::allClear() {
    //get the # of nodes in the stack
    int nodeCnt = getSize();
    for(int i=0; i<nodeCnt; i++)
        pop();
}
