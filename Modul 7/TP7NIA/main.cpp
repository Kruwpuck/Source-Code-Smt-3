#include "stack.h"

int main()
{
    stack S;
    infotype data;
    int n=0;
    createStack_103032300018(S);
    cin >> n;
    for (int i = 0; i < n ; i++ ){
        cin >> data;
        push_103032300018(S,data);
    }
    printInfo_103032300018(S);
    for (int j = 4; j < n ; j++ ){
        data = pop_103032300018(S);
    }
    printInfo_103032300018(S);

}
