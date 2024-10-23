#include <iostream>
#include "dll.h"

using namespace std;

int main()
{
    List L1, L2, L3;
    address p, q;
    infotype data;
    int i, j;
    string judul;

    createList_103032300090(L1);
    createList_103032300090(L2);
    createList_103032300090(L3);

    cout << "=============== ALBUM PERTAMA ===============" << endl;
    for (i = 0; i < 3; i++) {
        cout << endl << "Judul ke-" << i + 1 << ": ";
        cin >> data.judul;
        cout << endl << "Nama penyanyi ke-" << i + 1 << ": ";
        cin >> data.penyanyi;
        p = creatNewElm_103032300090(data);
        insertlast_103032300090(L1, p);
    }

    cout << endl << "=============== ALBUM KEDUA ===============" << endl;
    for (j = 0; j < 3; j++) {
        cout << endl << "Judul ke-" << j + 1 << ": ";
        cin >> data.judul;
        cout << endl << "Nama penyanyi ke-" << j + 1 << ": ";
        cin >> data.penyanyi;
        p = creatNewElm_103032300090(data);
        insertlast_103032300090(L2, p);

    }

    cout << "=============== ALBUM PERTAMA ===============" << endl;
    show_103032300090(L1);


    cout << endl <<  "=============== ALBUM KEDUA ===============" << endl;
    show_103032300090(L2);



    concat_103032300090(L1, L2, L3);

    cout << endl <<  "=============== ALBUM KETIGA ===============" << endl;
    show_103032300090(L3);



    cout << "=============== DELETE FIRST ===============" << endl;
    deletefirst_103032300090(L3, p);
    show_103032300090(L3);



    cout << "=============== DELETE LAST ===============" << endl;
    deletelast_103032300090(L3, p);
    show_103032300090(L3);



    cout << "=============== DELETE AFTER ===============" << endl;
    cout << endl <<  "Judul lagu setelahnya yang akan dihapus: ";
    cin >> judul;
    q = findsong_103032300090(judul, L3);
    if (q != NULL) {
        deleteafter_103032300090(L3, q, p);
        show_103032300090(L3);
    }
    cout << endl <<  "Judul lagu yang akan dihapus: ";
    cin >> judul;
    removesong_103032300090(judul, L3);
    show_103032300090(L3);


    cout << "=============== INSERT AFTER ===============" << endl;
    cout << endl <<  "Judul lagu setelahnya yang akan dimasukkan: ";
    cin >> judul;
    q = findsong_103032300090(judul, L3);
    if (q != NULL) {
        cout << endl <<  "Judul lagu yang akan dimasukkan: ";
        cin >> data.judul;
        cout << endl <<  "Nama penyanyi yang akan dimasukkan: ";
        cin >> data.penyanyi;
        p = creatNewElm_103032300090(data);
        insertafter_103032300090(L3, q, p);
        show_103032300090(L3);
    }


    return 0;
}
