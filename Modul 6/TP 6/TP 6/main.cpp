#include <iostream>
#include <string>
using namespace std;

// Definisi type
typedef int infotype;  // Type infotype adalah integer

// Forward declaration dari elmtList
struct elmtList;

// Definisi type address sebagai pointer ke elmtList
typedef elmtList* address;

// Definisi elemen list (elmtList)
struct elmtList {
    infotype info;
    string judul;
    address prev;
    address next;
};

// Definisi list yang memiliki pointer ke first dan last
struct List {
    address first;
    address last;
};

// Fungsi untuk mengecek apakah list kosong
bool isEmpty(List L) {
    return (L.first == nullptr && L.last == nullptr);
}

// Prosedur untuk membuat list kosong
void createList(List& L) {
    // I.S: -
    // F.S: List L terdefinisi dan kosong
    L.first = nullptr;
    L.last = nullptr;
}

// Fungsi untuk membuat elemen baru dengan info dan judul
address createNewElmt(infotype X, string judul) {
    // I.S: X adalah info dan judul adalah nama lagu
    // F.S: Elemen baru terdefinisi dengan info X dan judul, atau NULL jika alokasi gagal
    address P = new elmtList;
    if (P != nullptr) {
        P->info = X;
        P->judul = judul;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;  // Mengembalikan address dari elemen baru
}

// Prosedur untuk menyisipkan elemen di awal list
void insertFirst(List& L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

// Prosedur untuk menyisipkan elemen di akhir list
void insertLast(List& L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// Prosedur untuk menghapus elemen setelah Prec
void deleteAfter(List& L, address Prec, address& P) {
    // I.S: Prec tidak NULL dan next(Prec) tidak NULL
    // F.S: Elemen setelah Prec dihapus dan dicatat pada P
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        } else {
            // Jika elemen yang dihapus adalah elemen terakhir
            L.last = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

// Prosedur untuk menghapus elemen terakhir
void deleteLast(List& L, address& P) {
    // I.S: List L memiliki satu atau lebih elemen
    // F.S: Elemen terakhir dihapus dan dicatat pada P
    if (!isEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            // Jika hanya ada satu elemen
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
            P->prev = nullptr;
        }
    }
}

// Prosedur untuk menggabungkan dua list
void concat(List L1, List L2, List& L3) {
    // I.S: L1 dan L2 terdefinisi, L3 kosong
    // F.S: L3 berisi gabungan elemen dari L1 dan L2
    createList(L3);
    address P = L1.first;
    while (P != nullptr) {
        address newElmt = createNewElmt(P->info, P->judul);
        insertLast(L3, newElmt);
        P = P->next;
    }
    P = L2.first;
    while (P != nullptr) {
        address newElmt = createNewElmt(P->info, P->judul);
        insertLast(L3, newElmt);
        P = P->next;
    }
}

// Fungsi untuk mencari elemen berdasarkan judul lagu
address findLagu(string Judul, List L) {
    address P = L.first;
    while (P != nullptr) {
        if (P->judul == Judul) {
            return P;
        }
        P = P->next;
    }
    return nullptr;  // Mengembalikan nullptr jika lagu tidak ditemukan
}

// Prosedur untuk menghapus elemen pertama
void deleteFirst(List& L, address& P) {
    // I.S: List L memiliki satu atau lebih elemen
    // F.S: Elemen pertama dihapus dan dicatat pada P. List mungkin menjadi kosong
    if (!isEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
            P->next = nullptr;
        }
    }
}

// Prosedur untuk menghapus lagu berdasarkan judul
void removeLagu(string Judul, List& L) {
    // I.S: List mungkin kosong. Jika tidak kosong, minimal ada 1 elemen
    // F.S: Elemen dengan judul yang dicari dihapus dari list
    address P = findLagu(Judul, L);
    if (P != nullptr) {
        if (P == L.first) {
            // Jika elemen pertama yang dihapus
            address temp;
            deleteFirst(L, temp);
            delete temp;  // Dealokasi
        } else if (P == L.last) {
            // Jika elemen terakhir yang dihapus
            address temp;
            deleteLast(L, temp);
            delete temp;  // Dealokasi
        } else {
            // Jika elemen berada di tengah
            address temp;
            deleteAfter(L, P->prev, temp);
            delete temp;  // Dealokasi
        }
    }
}

// Fungsi untuk mencetak list dari depan
void printList(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->judul << " ";
        P = P->next;
    }
    cout << endl;
}

int main() {
    // Membuat list kosong
    List L1, L2, L3;
    createList(L1);
    createList(L2);

    // Menambah elemen baru
    insertLast(L1, createNewElmt(1, "Song A"));
    insertLast(L1, createNewElmt(2, "Song B"));
    insertLast(L2, createNewElmt(3, "Song C"));
    insertLast(L2, createNewElmt(4, "Song D"));

    // Menggabungkan dua list
    concat(L1, L2, L3);
    printList(L3);  // Output: Song A Song B Song C Song D

    // Mencari dan menghapus lagu berdasarkan judul
    removeLagu("Song C", L3);
    printList(L3);  // Output: Song A Song B Song D

    return 0;
}
