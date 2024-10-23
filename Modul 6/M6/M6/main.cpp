#include <iostream>
#include "DLL.h"

using namespace std;

int main()
{
   List l, l1, l2, l3;
   adr p, prec;
   infotype data;
   int i, n;
   string judul;

   createNewlist_103032300129(l);

    cout << "Ingin input berapa data: ";
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Nama penyanyi ke " << i+1 << ": " ;
        cin >> data.penyanyi;
        cout << "Judul lagu        : ";
        cin >> data.judulLagu;
        p = createNewEml_103032300129(data);
        insertLast_103032300129(l,p);
    }
    cout << endl;
    cout << "Berikut data penyanyi dan lagu" << endl;
    show_103032300129(l);

    cout << "Ingin tambah berapa data: ";
    cin >> n;
    string tambah;
    for(i = 0; i < n; i++){
        cout << "Tambah awal/after? ";
        cin >> tambah;
        if (tambah == "awal"){
            cout << "Nama penyanyi ke " << i+1 << ": " ;
            cin >> data.penyanyi;
            cout << "Judul lagu        : ";
            cin >> data.judulLagu;
            p = createNewEml_103032300129(data);
            insertFirst_103032300129(l,p);
        }else if(tambah == "after"){
            cout << "Masukkan judul lagu yang ingin ditambahkan setelahnya: ";
            cin >> judul;
            prec = findLagu_103032300129(l, judul);
            if(prec != NULL){
                cout << "Nama penyanyi yang ingin ditambahkan: ";
                cin >> data.penyanyi;
                cout << "Judul lagu yang ingin ditambahkan   : ";
                cin >> data.judulLagu;
                p = createNewEml_103032300129(data);
                insertAfter_103032300129(l, prec, p);

            }else{
                cout << "Judul lagu tersebut tidak ditemukan";
            }
        }
    }
    cout << endl;
    cout << "Berikut data penyanyi dan lagu setelah ditambah" << endl;
    show_103032300129(l);

    cout << "Masukkan judul lagu yang ingin dihapus: ";
    cin >> judul;
    removeLagu_103032300129(l, judul);
    cout << endl;
    cout << "Berikut data penyanyi dan lagu setelah dihapus" << endl;
    show_103032300129(l);

    // isi list 1
    createNewlist_103032300129(l1);
    cout << "ingin memasukkan berapa element untuk list 1? ";
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Nama penyanyi ke " << i + 1 << " : ";;
        cin >> data.penyanyi;
        cout << "Judul lagu        : ";
        cin >> data.judulLagu;
        p = createNewEml_103032300129(data);
        insertLast_103032300129(l1,p);
    }
    //isi list 2
    createNewlist_103032300129(l2);
    cout << "ingin memasukkan berapa element untuk list 2? ";
    cin >> n;

    for(i = 0; i < n; i++){
         cout << "Nama penyanyi ke " << i + 1 << " : ";;
        cin >> data.penyanyi;
        cout << "Judul lagu        : ";
        cin >> data.judulLagu;
        p = createNewEml_103032300129(data);
        insertLast_103032300129(l2,p);
    }
    cout << "isi list 1: ";
    show_103032300129(l1);
    cout << "isi list 2: ";
    show_103032300129(l2);

    //gabung list
    createNewlist_103032300129(l3);
    concat_103032300129(l1,l2,l3);

    cout << "List yang sudah digabung"<< endl;
    show_103032300129(l3);


    return 0;
}
