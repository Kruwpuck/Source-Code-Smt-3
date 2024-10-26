#include <iostream>
using namespace std;
typedef char infotype;

struct stack{
    infotype info[15];
    int Top;
};

void createStack_103032330054(stack &S);
bool isEmpty_103032330054(stack S);
bool isFull_103032330054(stack S);
void push_103032330054(stack &S, infotype x);
infotype pop_103032330054(stack &S);
void printInfo_103032330054(stack S);
