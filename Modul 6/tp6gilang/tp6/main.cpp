#include <iostream>
#include "DLL.h"

using namespace std;

int main()
{
    list l1, l2, l3;
    address p;
    int i = 1;
    string judul;
    infotype info;

    //create
    createlist_103032300130(l1);
    createlist_103032300130(l2);

    // memasukkan dengan insert last
    cout << "masukkan list l1: " << endl;
    while (i <= 5){
        cin >> info.judul >> info.nama;
        createNewElm_10302300130(info, p);
        insertLast_10302300130(l1, p);
        i ++;
    }

    cout << "info : " << endl;
    show_103032300130(l1);

    cout << "------------" << endl;

    // memasukkan dengan insert first
    cout << "masukkan list l2: " << endl;
    i = 1;
    while (i <= 5){
        cin >> info.judul >> info.nama;
        createNewElm_10302300130(info, p);
        insertFirst_10302300130(l2, p);
        i ++;
    }

    cout << "info : " << endl;
    show_103032300130(l2);

    cout << "------------" << endl;

    concat_10302300130(l1, l2, l3);

    cout << "info : " << endl;
    show_103032300130(l3);

    cout << "------------" << endl;

    //find song
    cout << "Find song: ";
    cin >> judul;
    address q = findSong_10302300130(l3, judul);
    cout << q -> info.judul << " " << q -> info.nama;

    cout << endl;

    //insert after
    cout << "Insert setelah: ";
    cin >> judul;
    q = findSong_10302300130(l3, judul);
    cout << "Masukkan lagu setelah " << q -> info.judul << ": ";
    cin >> info.judul >> info.nama;
    createNewElm_10302300130(info, p);
    insertAfter_10302300130(l3, p, q);

    cout << endl;
    cout << "info : " << endl;
    show_103032300130(l3);

    cout << "------------" << endl;

    //delete first
    cout << "delete first 5 awal: " << endl;
    i = 1;
    while(i <= 5){
        deleteFirst_10302300130(l3, p);
        show_103032300130(l3);
        cout << "----------" << endl;
        i ++;
    }


    //pilih lagu yang akan diremove
    cout << "lagu yang akan di remove: ";
    cin >> judul;

    removeSong_10302300130(judul, l3);
    cout << "info : " << endl;
    show_103032300130(l3);

    //delete after
    cout << "delete after: ";
    cin >> judul;
    q = findSong_10302300130(l3, judul);
    deleteAfter_10302300130(l3, q, p);


    cout << "info : " << endl;
    show_103032300130(l3);

    // delete last
    cout << "delete last: " << endl;
    i = 1;
     while(i <= 5){
        deleteLast_10302300130(l3, p);
        show_103032300130(l3);
         cout << "----------" << endl;
         i ++;
    }

}
