#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    int x=0;
    address P;

    createList_103032300018(L);
    cout << "Masukkan angka 1: ";
    cin >> x;
    P = allocate_103032300018(x);
    insertFirst_103032300018(L,P);
    printInfo_103032300018(L);


    cout << "Masukkan angka 2: ";
    cin >> x;
    P = allocate_103032300018(x);
    insertFirst_103032300018(L,P);
    printInfo_103032300018(L);


    cout << "Masukkan angka 3: ";
    cin >> x;
    P = allocate_103032300018(x);
    insertFirst_103032300018(L,P);
    printInfo_103032300018(L);
}
