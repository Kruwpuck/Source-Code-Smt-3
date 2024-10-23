#include "DLL.h"

void createList_103032330095(List &L) {
    L.first = NULL;
    L.last = NULL;
}

bool isEmpty_103032330095(List L) {
    return L.first == NULL;
}

address createNewElmt_103032330095(infotype X) {
    address P = new elmtList;
    P->info = X;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst_103032330095(List &L, address P) {
    if (isEmpty_103032330095(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter_103032330095(List &L, address Prec, address P) {
    if (Prec->next != NULL) {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    } else {
        insertLast_103032330095(L, P);
    }
}

void insertLast_103032330095(List &L, address P) {
    if (isEmpty_103032330095(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirst_103032330095(List &L, address &P) {
    if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteAfter_103032330095(List &L, address Prec, address &P) {
    P = Prec->next;
    if (P->next != NULL) {
        Prec->next = P->next;
        P->next->prev = Prec;
    } else {
        Prec->next = NULL;
        L.last = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

void deleteLast_103032330095(List &L, address &P) {
    if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void concat_103032330095(List L1, List L2, List &L3) {
    if (isEmpty_103032330095(L1)) {
        L3 = L2;
    } else if (isEmpty_103032330095(L2)) {
        L3 = L1;
    } else {
        L3 = L1;
        L3.last->next = L2.first;
        L2.first->prev = L3.last;
        L3.last = L2.last;
    }
}

address findLagu_103032330095(List L, string Judul) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.Judul == Judul) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void removeLagu_103032330095(List &L, string Judul) {
    address P = findLagu_103032330095(L, Judul);
    if (P != NULL) {
        if (P == L.first) {
            deleteFirst_103032330095(L, P);
        } else if (P == L.last) {
            deleteLast_103032330095(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter_103032330095(L, Prec, P);
        }
        delete P;
        cout << "Lagu '" << Judul << "' berhasil dihapus." << endl;
    } else {
        cout << "Lagu dengan Judul '" << Judul << "' tidak ditemukan." << endl;
    }
}

void showAll_103032330095(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << "Judul: " << P->info.Judul << " | Band: " << P->info.namaBand << endl;
        P = P->next;
    }
}
int tampilkanMenu_103032330095() {
    int pilihan;
    cout << "\n===== MENU =====" << endl;
    cout << "1. Tambah lagu ke Album 1 (insertFirst)" << endl;
    cout << "2. Tambah lagu ke Album 2 (insertLast)" << endl;
    cout << "3. Tampilkan semua lagu di Album 1" << endl;
    cout << "4. Tampilkan semua lagu di Album 2" << endl;
    cout << "5. Gabungkan Album 1 dan Album 2" << endl;
    cout << "6. Tampilkan semua lagu di Album 3 (Gabungan)" << endl;
    cout << "7. Tambah lagu setelah lagu tertentu di Album gabungan" << endl;
    cout << "8. Hapus lagu pertama di Album gabungan" << endl;
    cout << "9. Hapus lagu terakhir di Album gabungan" << endl;
    cout << "10. Hapus lagu setelah lagu tertentu di Album gabungan" << endl;
    cout << "11. Hapus lagu berdasarkan judul di Album gabungan" << endl;
    cout << "12. Cari lagu berdasarkan judul di Album gabungan" << endl;
    cout << "0. Keluar" << endl;
    cout << "===================" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    return pilihan;
}

