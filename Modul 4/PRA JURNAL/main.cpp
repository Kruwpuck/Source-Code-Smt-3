#include "list.h"



int main()
{
    List L;
    address P,Q;
    CreateList(L);
    infotype n,x;
    cout << "Masukkan berapa digit angka: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout<< "Masukkan angka ke" << i+1 << ": ";
        cin >> x;
        P = allocate(x);
        InsertLast(L,P);
    }
    cout << "Isi List: " << endl;
    Show(L);

    cout << "Cari angka berapa? " << endl;
    cin >> x;
    Q = Search(L,x);
    if (Q != NULL) {
        cout << "Angka " << x << " ditemukan dalam list." << endl;
    } else {
        cout << "Angka " << x << " tidak ditemukan dalam list." << endl;
    }
    return 0;
}
