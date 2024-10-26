#include "stack.h"

int main()
{
    stack S;
    infotype data;
    int n=0;
    createStack_103032330054(S);
    cout << "Masukkan berapa karakter yang akan dimasukkan: ";
    cin >> n;
    for (int i = 0; i < n ; i++ ){
        cin >> data;
        push_103032330054(S,data);
    }
    printInfo_103032330054(S);
    for (int j = 4; j < n ; j++ ){
        data = pop_103032330054(S);
    }
    printInfo_103032330054(S);

}
