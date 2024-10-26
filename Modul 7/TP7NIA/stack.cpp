#include "stack.h"
void createStack_103032300018(stack &S){
    S.Top = 0;
}
bool isEmpty_103032300018(stack S){
    if (S.Top == 0){
        return 1;
    }else{
        return 0;
    }
}
bool isFull_103032300018(stack S){
    if (S.Top == 15){
        return 1;
    }else{
        return 0;
    }
}
void push_103032300018(stack &S, infotype x){
    if (isFull_103032300018(S) == false){
        S.Top++;
        S.info[S.Top] = x;
    }
}
infotype pop_103032300018(stack &S){
    infotype x = S.info[S.Top];
    S.Top--;
    return x;
}
void printInfo_103032300018(stack S){
    for (int i = S.Top; i>=1;i--){
        cout << S.info[i] << " ";
    }
    cout << endl;
}
