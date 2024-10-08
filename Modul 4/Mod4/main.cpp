#include <iostream>
#include "list.h"
#include "lish.cpp"

using namespace std;

int main(){
    List l;
    infotype x, n,i;
    address p;
    address z;

    createList(l);

    cout << "Masukkan berapa digit angka: ";
    cin >> n;
    for( i = 0; i < n; i++){
        cout<< "Masukkan angka ke" << i+1 << ": ";
        cin >> x;
        p = allocate(x);
        insertLast(l,p);
    }
    cout << "Isi list: ";
    printInfo(l);


    cout << "Cari angka berapa? ";
    cin >> x;

    z = searchInfo(l, x);
    if (z != NULL) {
        cout << "Angka " << x << " ditemukan dalam list." << endl;
    } else {
        cout << "Angka " << x << " tidak ditemukan dalam list." << endl;
    }

//    cout << "Masukkan angka pertama: ";
//    cin>> x;
//    p = allocate(x);
//    insertFisrt(l,p);
//    printInfo(l);
//
//    cout << "Masukkan angka kedua: ";
//    cin >> x;
//    p = allocate(x);
//    insertFisrt(l,p);
//    printInfo(l);
//
//    cout << "Masukkan angka ketiga: ";
//    cin >> x;
//    p = allocate(x);
//    insertFisrt(l,p);
//    printInfo(l);


    return 0;
}
