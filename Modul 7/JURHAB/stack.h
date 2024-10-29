#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;
const int MAXSTACK = 10;
typedef char infotype;
struct stack{
    infotype info[MAXSTACK];
    int top;
};
void createStack_103032330054(stack &S);
bool isEmpty_103032330054(stack S);
bool isFull_103032330054(stack S);
void push_103032330054(stack &S, infotype xpush);
void pop_103032330054(stack &S, infotype &xpop);
void printInfo_103032330054(stack S);
void ascending_103032330054(stack &S);
void descending_103032330054(stack &S);
void stringToStack_103032330054(stack &S, const string &str);
void reverseStack_103032330054(stack &S);
#endif // STACK_H_INCLUDED
