#include "header.h"
void insertLastBioskop(List_Bioskop &L, adr_bioskop P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        L.last->next_bioskop = P;
        P->prev_bioskop = L.last;
        L.last = P;
    }
}
void updateBioskop(List_Bioskop &L, adr_bioskop P){
    cout << "Masukkan ID Bioskop yang ingin diupdate: ";
    cin >> P->info.id;
    cout << "Masukkan Nama Bioskop: ";
    cin >> P->info.nama;
    cout << "Masukkan Kapasitas Bioskop: ";
    cin >> P->info.kapasitas;
}
void searchBioskop(List_Bioskop L, string id, adr_bioskop &P){
    if (L.first == NULL){
        cout << "Data Bioskop kosong" << endl;
        P = NULL;
        return;
    }else{
        P = L.first;
        while (P != NULL){
            if (P->info.id == id){
                cout << "Data Bioskop ditemukan" << endl;
                cout << "ID: " << P->info.id << ", Nama: " << P->info.nama << ", Kapasitas: " << P->info.kapasitas << endl;
                return;
            }
            P = P->next_bioskop;
        }
        cout << "Data Bioskop tidak ditemukan" << endl;
    }
}
void deleteBioskop(List_Bioskop &L, adr_bioskop &P){
    if (L.first == NULL){
        cout << "Data Bioskop kosong" << endl;
        P = NULL;
        return;
    }else{
        if (L.first == L.last){
                L.first = NULL;
                L.last = NULL;
        }else if (P == L.first){
            L.first = P->next_bioskop;
            L.first->prev_bioskop = NULL;
            P->next_bioskop = NULL;
        } else if (P == L.last){
            L.last = P->prev_bioskop;
            P->prev_bioskop->next_bioskop = NULL;
        } else {
            P->prev_bioskop->next_bioskop = P->next_bioskop;
            P->next_bioskop->prev_bioskop = P->prev_bioskop;
        }
    }
}
void insertLastfilm(List_film &L, adr_film P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        L.last->next_film = P;
        P->prev_film = L.last;
        L.last = P;
    }
}
void updatefilm(List_film &L, adr_film P){
    cout << "Masukkan ID film yang ingin diupdate: ";
    cin >> P->info.id;
    cout << "Masukkan Nama Film: ";
    cin >> P->info.judul;
    cout << "Masukkan Durasi Film: ";
    cin >> P->info.durasi;
}
void searchfilm(List_film L, string id, adr_film &P){
    if (L.first == NULL){
        cout << "Data film kosong" << endl;
        P = NULL;
        return;
    }else{
        P = L.first;
        while (P != NULL){
            if (P->info.id == id){
                cout << "Data film ditemukan" << endl;
                cout << "ID: " << P->info.id << ", Judul: " << P->info.judul << ", Durasi: " << P->info.durasi << endl;
                return;
            }
            P = P->next_film;
        }
        cout << "Data film tidak ditemukan" << endl;
    }
}
void deletefilm(List_film &L, adr_film &P){
    if (L.first == NULL){
        cout << "Data film kosong" << endl;
        P = NULL;
        return;
    }else{
        if (L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        }else if (P == L.first){
            L.first = P->next_film;
            L.first->prev_film = NULL;
            P->next_film = NULL;
        } else if (P == L.last){
            L.last = P->prev_film;
            P->prev_film->next_film = NULL;
        } else {
            P->prev_film->next_film = P->next_film;
            P->next_film->prev_film = P->prev_film;
        }
    }
}
void sortfilm(List_film &L){
    List_film sortedList;
    while (L.first != NULL) {
        adr_film P = findMax(L);
        deletefilm(L, P);
        insertLastfilm(sortedList, P);
    }
    L.first = sortedList.first;
}
adr_film findMax(List_film L){
    if (L.first == NULL) {
        return NULL;
    }else if (L.first->next_film == NULL) {
        return L.first;
    } else {
        adr_film maxFilm = L.first;
        adr_film current = L.first->next_film;
        while (current != NULL) {
            if (current->info.durasi > maxFilm->info.durasi) {
                maxFilm = current;
            }
            current = current->next_film;
        }
        return maxFilm;
    }
}
void showBioskop(List_Bioskop L){
    if (L.first == NULL){
        cout << "Data Bioskop kosong" << endl;
    }else{
        adr_bioskop P = L.first;
        cout << "------------------------------------------------------------" << endl;
        while (P != NULL){
            cout << "|   ID: " << P->info.id << ", Nama: " << P->info.nama << ", Kapasitas: " << P->info.kapasitas << "Film: " << P->film->info.judul << endl;
            P = P->next_bioskop;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
