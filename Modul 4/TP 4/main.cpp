#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    int masukkan=0;
    address P;

    createList_103032330054(L);
    cout << "Masukkan angka pertama: ";
    cin >> masukkan;
    P = allocate_103032330054(masukkan);
    insertFirst_103032330054(L,P);
    printInfo_103032330054(L);


    cout << "Masukkan angka kedua: ";
    cin >> masukkan;
    P = allocate_103032330054(masukkan);
    insertFirst_103032330054(L,P);
    printInfo_103032330054(L);


    cout << "Masukkan angka ketiga: ";
    cin >> masukkan;
    P = allocate_103032330054(masukkan);
    insertFirst_103032330054(L,P);
    printInfo_103032330054(L);
}
