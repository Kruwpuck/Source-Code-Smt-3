#include "header.h"
void insertDosen(List_Dosen &L, adr_Dosen P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->prev_Dosen = L.last;
        L.last->next_Dosen = P;
        L.last = P;
    }
}
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P){
    if (L.first == NULL){
        L.first = P;
    }else{
        P->next_Mahasiswa = L.first;
        L.first = P;
    }
}
void insertRelasi(adr_Mahasiswa Q, adr_Relasi &P){
    if (Q->relasi.first == NULL){
        Q->relasi.first = P;
    }else{
        P->next_Relasi = Q->relasi.first;
        Q->relasi.first = P;
    }
}
void deleteDosen(List_Dosen &L, adr_Dosen &P){
    if (L.first == NULL){
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
        L.last = NULL;
    }else if(P == L.first){
        deleteFirstDosen(L, P);
    }else if (P == L.last){
        deleteLastDosen(L, P);
    }else{
        deleteAfterDosen(L, P);
    }
    cout << "Data Dosen berhasil dihapus" << endl;
}
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P){
    L.first = P->next_Dosen;
    P->next_Dosen = NULL;
    P->prev_Dosen = NULL;  
}
void deleteLastDosen(List_Dosen &L, adr_Dosen &P){
    L.last = P->prev_Dosen;
    P->prev_Dosen = NULL;
    L.last->next_Dosen = NULL;
}
void deleteAfterDosen(List_Dosen &L, adr_Dosen &P){
    P->next_Dosen->prev_Dosen = P->prev_Dosen;
    P->prev_Dosen->next_Dosen = P->next_Dosen;
    P->next_Dosen = NULL;
    P->prev_Dosen = NULL;
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
    }else{
        deleteLastAfterMahasiswa(L, P);
    }
    cout << "Data Mahasiswa berhasil dihapus" << endl;
}
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    L.first = P->next_Mahasiswa;
    P->next_Mahasiswa = NULL;
}
void deleteLastAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P){
    adr_Mahasiswa Q = L.first;
    while (Q->next_Mahasiswa != P){
        Q = Q->next_Mahasiswa;
    }
    if (P->next_Mahasiswa == NULL){
        Q->next_Mahasiswa = P->next_Mahasiswa;
    }
    Q->next_Mahasiswa = NULL;
}
void deleteRelasi(adr_Mahasiswa &Q,adr_Relasi &P){
    if (Q->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(Q->relasi.first->next_Relasi == NULL){
            P = Q->relasi.first;
            Q->relasi.first = NULL;
        }else{
            adr_Relasi R = Q->relasi.first;
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
void cariDosen(List_Dosen L, adr_Dosen &P){
    
}
void cariMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
    
}
void cariRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){

}
void TampilkanDosen(List_Dosen L){
    
}
void TampilkanMahasiswa(List_Mahasiswa L){
    
}
void TampilkanMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P){
    
}
void TampilkanAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    
}
void TampilkanAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld){
    
}
void TampilkanDosenDariMahasiswa(List_Dosen L, adr_Mahasiswa P){
    
}
void hitungAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    
}
void hitungRelasiDariMahasiswa(adr_Mahasiswa P){
    
}
void hitungMahasiswaTanpaDosen(List_Mahasiswa Lm){
    
}
void editMahasiswaDariDosen(List_Dosen Ld, List_Mahasiswa Lm, adr_Dosen P){
    
}
void menuUtama(List_Dosen &Ld, List_Mahasiswa &Lm){
    
}