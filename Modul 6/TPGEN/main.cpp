#include "DLL.h"

int main() {
    List L1, L2, L3;
    address P, Prec;
    infotype X;
    string Judul;
    int pilihan = 1;

    createList_103032330095(L1);
    createList_103032330095(L2);
    createList_103032330095(L3);

    while (pilihan != 0) {
        pilihan = tampilkanMenu_103032330095();
        switch (pilihan) {
            case 1:
                cout << "Tambahkan lagu ke Album 1" << endl;
                cout << "Masukkan Nama Band: ";
                cin >> X.namaBand;
                cout << "Masukkan Judul Lagu: ";
                cin >> X.Judul;
                P = createNewElmt_103032330095(X);
                insertFirst_103032330095(L1, P);
                cout << "Lagu berhasil ditambahkan ke Album 1." << endl;
                break;
            case 2:
                cout << "Tambahkan lagu ke Album 2" << endl;
                cout << "Masukkan Nama Band: ";
                cin >> X.namaBand;
                cout << "Masukkan Judul Lagu: ";
                cin >> X.Judul;
                P = createNewElmt_103032330095(X);
                insertLast_103032330095(L2, P);
                cout << "Lagu berhasil ditambahkan ke Album 2." << endl;
                break;
            case 3:
                cout << "===== DAFTAR LAGU ALBUM 1 =====" << endl;
                showAll_103032330095(L1);
                cout << "===============================" << endl;
                break;
            case 4:
                cout << "===== DAFTAR LAGU ALBUM 2 =====" << endl;
                showAll_103032330095(L2);
                cout << "===============================" << endl;
                break;
            case 5:
                concat_103032330095(L1, L2, L3);
                cout << "Album 1 dan Album 2 berhasil digabungkan." << endl;
                showAll_103032330095(L3);
                break;
            case 6:
                cout << "===== DAFTAR LAGU ALBUM 3 (GABUNGAN) =====" << endl;
                showAll_103032330095(L3);
                break;
            case 7:
                cout << "Masukkan Judul lagu setelahnya akan ditambahkan lagu baru: ";
                cin >> Judul;
                Prec = findLagu_103032330095(L3, Judul);
                if (Prec != NULL) {
                    cout << "Masukkan Nama Band untuk lagu baru: ";
                    cin >> X.namaBand;
                    cout << "Masukkan Judul Lagu baru: ";
                    cin >> X.Judul;
                    P = createNewElmt_103032330095(X);
                    insertAfter_103032330095(L3, Prec, P);
                    cout << "Lagu baru berhasil ditambahkan." << endl;
                } else {
                    cout << "Lagu dengan Judul '" << Judul << "' tidak ditemukan." << endl;
                }
                break;
            case 8:
                deleteFirst_103032330095(L3, P);
                cout << "Lagu pertama berhasil dihapus." << endl;
                showAll_103032330095(L3);
                break;
            case 9:
                deleteLast_103032330095(L3, P);
                cout << "Lagu terakhir berhasil dihapus." << endl;
                showAll_103032330095(L3);
                break;
            case 10:
                cout << "Masukkan Judul lagu sebelum lagu yang akan dihapus: ";
                cin >> Judul;
                Prec = findLagu_103032330095(L3, Judul);
                if (Prec != NULL) {
                    deleteAfter_103032330095(L3, Prec, P);
                    cout << "Lagu setelah '" << Judul << "' berhasil dihapus." << endl;
                } else {
                    cout << "Lagu dengan Judul '" << Judul << "' tidak ditemukan." << endl;
                }
                break;
            case 11:
                cout << "Masukkan Judul lagu yang akan dihapus: ";
                cin >> Judul;
                removeLagu_103032330095(L3, Judul);
                break;
            case 12:
                cout << "Masukkan Judul lagu yang dicari: ";
                cin >> Judul;
                P = findLagu_103032330095(L3, Judul);
                if (P != NULL) {
                    cout << "Lagu ditemukan: " << P->info.Judul << " oleh " << P->info.namaBand << endl;
                } else {
                    cout << "Lagu dengan Judul '" << Judul << "' tidak ditemukan." << endl;
                }
                break;
        }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    return 0;
}
