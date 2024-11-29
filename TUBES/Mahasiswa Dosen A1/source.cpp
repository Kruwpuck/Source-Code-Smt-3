#include "header.h"
void insertDosen(List_Dosen &L, adr_Dosen P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Dosen = L.first;
        L.first = P;
    }
}
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Mahasiswa = P;
        P->prev_Mahasiswa = L.last;
        L.last = P;
    }
}
void insertRelasi(adr_Mahasiswa Q, adr_Relasi &P){
    if (Q->hubungan.first == NULL){
        Q->hubungan.first = P;
    }else{
        P->next_Relasi = Q->hubungan.first;
        Q->hubungan.first = P;
    }
}
void deleteDosen(List_Dosen &L, adr_Dosen &P){
    if(L.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    findDosen(L, P);
    while (P == NULL){
        cout << "Data Dosen tidak ditemukan" << endl;
        findDosen(L, P);
    }
    if (L.first->next_Dosen == NULL){
        L.first = NULL;
    }else if(P == L.first){
        deleteFirstDosen(L, P); 
    }else{
        deleteLastAfterDosen(L, P);
    }
}
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P){
    L.first = P->next_Dosen;
    P->next_Dosen = NULL;
}
void deleteLastAfterDosen(List_Dosen &L, adr_Dosen &P){
    adr_Dosen Q = L.first;
    while (Q->next_Dosen != P){
        Q = Q->next_Dosen;    
    }
    if (P->next_Dosen == NULL){
        Q->next_Dosen = P->next_Dosen;
    }
    Q->next_Dosen = NULL;
}
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    if (L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    findMahasiswa(L, P);
    while (P == NULL){
        cout << "Data Mahasiswa tidak ditemukan" << endl;
        findMahasiswa(L, P);
    }
    if (L.first->next_Mahasiswa == NULL){
        L.first = NULL;
    }else if(P == L.first){
        deleteFirstMahasiswa(L, P);
    }else if (P == L.last){
        deleteLastMahasiswa(L, P);
    }else{
        deleteAfterMahasiswa(L, P);
    }
} 
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    L.first = P->next_Mahasiswa;
    P->next_Mahasiswa = NULL;
    P->prev_Mahasiswa = NULL;
} 
void deleteLastMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    L.last = P->prev_Mahasiswa;
    P->prev_Mahasiswa = NULL;
    L.last->next_Mahasiswa = NULL;
}
void deleteAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    P->next_Mahasiswa->prev_Mahasiswa = P->prev_Mahasiswa;
    P->prev_Mahasiswa->next_Mahasiswa = P->next_Mahasiswa;
    P->next_Mahasiswa = NULL;
    P->prev_Mahasiswa = NULL;
}
void deleteRelasi(adr_Mahasiswa &Q ,adr_Relasi &P){
    if(Q->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(Q->hubungan.first->next_Relasi == NULL){
            P = Q->hubungan.first;
            Q->hubungan.first = NULL;
        }else{
            adr_Relasi R = Q->hubungan.first;
            while(P->next_Relasi != NULL){
                Q = P;
                P = P->next_Relasi;
            }
            P = R->next_Relasi;
            R->next_Relasi = P->next_Relasi;
            P->next_Relasi = NULL;
        }
    }
} 
void findDosen(List_Dosen L, adr_Dosen &P){

} 
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){

} 
void findRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){

}
void showDosen(List_Dosen L){

} 
void showMahasiswa(List_Mahasiswa L){

} 
void showMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P){

} 
void showAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){

} 
void showAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld){

} 
void showDosenDariMahasiswa(List_Dosen L, adr_Mahasiswa P){

} 
void countAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){

} 
void countRelasiDariMahasiswa(adr_Mahasiswa P){

} 
void countMahasiswaTanpaDosen(List_Mahasiswa Lm){

} 
void editMahasiswaDariDosen(List_Dosen Ld, List_Mahasiswa Lm, adr_Dosen P){

} 
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm){

} 