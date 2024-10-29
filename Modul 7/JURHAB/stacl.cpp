#include "stack.h"
void createStack_103032330054(stack &S){
    S.top = 0;
}
bool isEmpty_103032330054(stack S){
    return S.top == 0;
}
bool isFull_103032330054(stack S){
    return S.top == MAXSTACK;
}
void push_103032330054(stack &S, infotype xpush){
    if (!isFull_103032330054(S)){
        S.top++;
        S.info[S.top] = xpush;
    }else{
        cout << endl << "Stack penuh" << endl;
    }
}
void pop_103032330054(stack &S, infotype &xpop){
    if (!isEmpty_103032330054(S)){
        xpop = S.info[S.top];
        S.top--;
    }else{
        cout << endl << "Stack kosong" << endl;
    }
}
void ascending_103032330054(stack &S){
    stack R;
    createStack_103032330054(R);
    infotype data1,data2;
    while (!isEmpty_103032330054(S)){
        pop_103032330054(S, data1);
        while (!isEmpty_103032330054(R) && R.info[R.top] > data1){
            push_103032330054(S,R.info[R.top]);
            pop_103032330054(R,data2);
        }
        push_103032330054(R,data1);
    }
    while (!isEmpty_103032330054(R)){
        pop_103032330054(R, data1);
        push_103032330054(S, data1);
    }
}
void descending_103032330054(stack &S){
    stack R;
    createStack_103032330054(R);
    infotype data1,data2;
    while (!isEmpty_103032330054(S)){
        pop_103032330054(S, data1);
        while (!isEmpty_103032330054(R) && R.info[R.top] < data1){
            push_103032330054(S,R.info[R.top]);
            pop_103032330054(R,data2);
        }
        push_103032330054(R,data1);
    }
    while (!isEmpty_103032330054(R)){
        pop_103032330054(R, data1);
        push_103032330054(S, data1);
    }
}
void stringToStack_103032330054(stack &S, const string &str){
    int panjang = 0;
    while (str[panjang] != '\0'){
        panjang++;
    }
    for (int i=0;i < panjang;i++){
            push_103032330054(S,str[i]);
    }
}
void reverseStack_103032330054(stack &S){
    stack R;
    infotype data;
    createStack_103032330054(R);
    while (!isEmpty_103032330054(S)){
        pop_103032330054(S,data);
        push_103032330054(R,data);
    }
    S = R;
}
void printInfo_103032330054(stack S){
    infotype data;
    while (!isEmpty_103032330054(S)){
        pop_103032330054(S,data);
        cout << data << " ";
    }
    cout << endl << endl;
}
