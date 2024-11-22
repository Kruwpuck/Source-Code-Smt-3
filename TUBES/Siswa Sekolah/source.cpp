#include "header.h"
int menu(){
    cout << endl << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan data min" << endl;
    cout << "4. Menambahkan data tengah" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu: ";

    int input = 0;
    cin >> input;

    return input;
}
void insertSekolah(List_Sekolah &L, adr_Sekolah P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->next_Sekolah = L.first;
        L.first = P;
    }
}
void insertSiswa(List_Siswa &L, adr_Siswa P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Siswa = P;
        P->prev_Siswa = L.last;
        L.last = P;
    }
}
void insertRelasi(List_relasi &L, adr_relasi P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_relasi = L.first;
        L.first = P;
    }
}
void deleteSekolah(List_Sekolah &L, adr_Sekolah &P){
    if(L.first == NULL){
        cout << "Data Sekolah kosong" << endl;
    }else if(L.first == L.last){
        P = L.first;
        L.first = NULL;
    }else{
        P = L.first;
        L.first = P->next_Sekolah;
        P->next_Sekolah = NULL;
    }
}
void deleteSiswa(List_Siswa &L, adr_Siswa &P){
    if(L.first == NULL){
        cout << "Data Siswa kosong" << endl;
    }else if(L.first == L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.last;
        L.last = P->prev_Siswa;
        P->prev_Siswa = NULL;
        L.last->next_Siswa = NULL;
    }
}
void deleteRelasi(List_relasi &L, adr_relasi P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else if (L.first->next_relasi == NULL){
        P = L.first;
        L.first = NULL;
    }else{
        P = L.first;
        L.first = P->next_relasi;
        P->next_relasi = NULL;
    }
}
void checkRelasi(List_relasi L, adr_Siswa P, adr_Sekolah Q){
    adr_relasi R = L.first;
    while(R != NULL){
        if(R->next_Siswa == P && R->next_Sekolah == Q){
            cout << "Relasi ditemukan" << endl;
            break;
        }else{
            R = R->next_relasi;
        }
    }
}