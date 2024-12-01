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
    int NIDN;
    cout << "Masukkan NIDN Dosen yang dicari : ";
    cin >> NIDN;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.NIDN == NIDN){
            cout << "Data Dosen ditemukan" << endl;
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIDN Dosen    : " << P->info.NIDN << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl;
            return;
        }
        P = P->next_Dosen;
    }
    cout << "Data Dosen tidak ditemukan" << endl;
    P = NULL;
}
void cariMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
    int NIM;
    cout << "Masukkan NIM Mahasiswa yang dicari : ";
    cin >> NIM;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.NIM == NIM){
            cout << "Data Mahasiswa ditemukan" << endl;
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "IPK Mahasiswa  : " << P->info.IPK << endl;
            return;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Data Mahasiswa tidak ditemukan" << endl;
    P = NULL;
}
void cariRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){
    if (P->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
        R = NULL;
        return;
    }
    R = P->relasi.first;
    while(R != NULL){
        if(R->next_Dosen == P){
            cout << "Data Relasi ditemukan" << endl;
            cout << "Jenis Relasi : " << R->info << endl;
            return;
        }
        R = R->next_Relasi;
    }
    cout << "Data Relasi tidak ditemukan" << endl;
}
void TampilkanDosen(List_Dosen L){
    adr_Dosen P = L.first;
    if(P == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        cout << "Data Dosen : " << endl;
        while(P != NULL){
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIDN Dosen    : " << P->info.NIDN << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl;
            cout << endl;
            P = P->next_Dosen;
        }
    }
}
void TampilkanMahasiswa(List_Mahasiswa L){
    adr_Mahasiswa P = L.first;
    if(P == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        cout << "Data Mahasiswa : " << endl;
        while(P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "IPK Mahasiswa  : " << P->info.IPK << endl;
            cout << endl;
            P = P->next_Mahasiswa;
        }
    }
}
void TampilkanMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P){
    adr_Mahasiswa Q = L.first;
    if (L.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Relasi R;
        while(Q != NULL){
            R = Q->relasi.first;
            while(R != NULL){
                if(R->next_Dosen == P){
                    cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                    cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                    cout << "IPK Mahasiswa  : " << Q->info.IPK << endl;
                    cout << "Jenis Relasi   : " << R->info << endl;
                    cout << endl;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Mahasiswa;
        }
    }
}
void TampilkanAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Dosen P = Ld.first;
        adr_Mahasiswa Q;
        adr_Relasi R;
        while(P != NULL){
            Q = Lm.first;
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIDN Dosen    : " << P->info.NIDN << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl << endl;
            while(Q != NULL){
                R = Q->relasi.first;
                while(R != NULL){
                    if(R->next_Dosen == P){
                        cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                        cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                        cout << "IPK Mahasiswa  : " << Q->info.IPK << endl;
                        cout << "Jenis Relasi   : " << R->info << endl;
                        cout << endl;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Mahasiswa;
            }
            P = P->next_Dosen;
        }
    }
}
void TampilkanAllRelasiMahasiswa(List_Mahasiswa Lm){
    adr_Mahasiswa P = Lm.first;
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Relasi R;
        while(P != NULL){
            R = P->relasi.first;
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "IPK Mahasiswa  : " << P->info.IPK << endl << endl;
            while(R != NULL){
                cout << "Nama Dosen    : " << R->next_Dosen->info.nama << endl;
                cout << "NIDN Dosen    : " << R->next_Dosen->info.NIDN << endl;
                cout << "Kode Dosen    : " << R->next_Dosen->info.kode << endl;
                cout << "Jenis Relasi  : " << R->info << endl;
                cout << endl;
                R = R->next_Relasi;
            }
            P = P->next_Mahasiswa;
        }
    }
}
void TampilkanDosenDariMahasiswa(adr_Mahasiswa P){
    if (P->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = P->relasi.first;
        while (R != NULL){
            cout << "Nama Dosen    : " << R->next_Dosen->info.nama << endl;
            cout << "NIDN Dosen    : " << R->next_Dosen->info.NIDN << endl;
            cout << "Kode Dosen    : " << R->next_Dosen->info.kode << endl;
            cout << "Jenis Relasi  : " << R->info << endl;
            cout << endl;
            R = R->next_Relasi;
        }
    }
}
void hitungAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Dosen P = Ld.first;
        adr_Mahasiswa Q;
        adr_Relasi R;
        int count;
        while(P != NULL){
            count = 0;
            Q = Lm.first;
            while(Q != NULL){
                R = Q->relasi.first;
                while(R != NULL){
                    if(R->next_Dosen == P){
                        count++;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Mahasiswa;
            }
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIDN Dosen    : " << P->info.NIDN << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl;
            cout << "Jumlah Relasi : " << count << endl;
            cout << endl;
            P = P->next_Dosen;
        }
    }
}
void hitungRelasiDariMahasiswa(adr_Mahasiswa P){
    int count = 0;
    adr_Relasi R = P->relasi.first;
    while (R != NULL){
        count++;
        R = R->next_Relasi;
    }
    cout << "Jumlah Relasi : " << count << endl;
}
void hitungMahasiswaTanpaDosen(List_Mahasiswa Lm){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Mahasiswa P = Lm.first;
        int count = 0;
        while (P != NULL){
            if (P->relasi.first == NULL){
                count++;
            }
            P = P->next_Mahasiswa;
        }
        cout << "Jumlah Mahasiswa tanpa Dosen : " << count << endl;
    }
}
void editMahasiswaDariDosen(adr_Mahasiswa &S, adr_Mahasiswa &T, adr_Dosen P, adr_Relasi &R){
    deleteRelasi(S, R);
    insertRelasi(T, R);
    cout << "Data Mahasiswa berhasil diedit" << endl;
}
void menuUtama(List_Dosen &Ld, List_Mahasiswa &Lm){
    
}