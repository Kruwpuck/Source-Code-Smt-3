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
    int NIP;
    cout << "Masukkan NIP Dosen yang dicari : ";
    cin >> NIP;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.NIP == NIP){
            cout << "Data Dosen ditemukan" << endl;
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Jabatan Dosen : " << P->info.jabatan << endl;
            return;
        }
        P = P->next_Dosen;
    }
    cout << "Data Dosen tidak ditemukan" << endl;
    P = NULL;
} 
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
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
            cout << "Angkatan       : " << P->info.angkatan << endl;
            return;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Data Mahasiswa tidak ditemukan" << endl;
    P = NULL;
} 
void findRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
        R = NULL;
        return;
    }
    R = P->hubungan.first;
    while(R != NULL){
        if(R->next_Dosen == P){
            cout << "Data Relasi ditemukan" << endl;
            cout << "Jenis Relasi : " << R->info << endl;
            return;
        }
        R = R->next_Relasi;
    }
    cout << "Data Relasi tidak ditemukan" << endl;
    R = NULL;

}
void showDosen(List_Dosen L){
    adr_Dosen P = L.first;
    if(P == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        cout << "Data Dosen : " << endl;
        while(P != NULL){
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Jabatan Dosen : " << P->info.jabatan << endl;
            cout << endl;
            P = P->next_Dosen;
        }
    }
} 
void showMahasiswa(List_Mahasiswa L){
    adr_Mahasiswa P = L.first;
    if(P == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        cout << "Data Mahasiswa : " << endl;
        while(P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Angkatan       : " << P->info.angkatan << endl;
            cout << endl;
            P = P->next_Mahasiswa;
        }
    }
} 
void showMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R;
        adr_Mahasiswa Q = L.first;
        while(Q != NULL){
            R = P->hubungan.first;
            while(R != NULL){
                if(R->next_Dosen == P){
                    cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                    cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                    cout << "Angkatan       : " << Q->info.angkatan << endl;
                    cout << "Jenis Relasi   : " << R->info << endl;
                    cout << endl;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Mahasiswa;
        }
    }

} 
void showAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Dosen P = Ld.first;
        adr_Mahasiswa Q;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Jabatan Dosen : " << P->info.jabatan << endl;
            Q = Lm.first;
            ada = false;
            while (Q != NULL){
                R = P->hubungan.first;
                while (R != NULL){
                    if (R->next_Dosen == P){
                        cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                        cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                        cout << "Angkatan       : " << Q->info.angkatan << endl;
                        cout << "Jenis Relasi   : " << R->info << endl;
                        cout << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Mahasiswa;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Dosen;
        }
    }
} 
void showAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        adr_Mahasiswa P = Lm.first;
        adr_Dosen Q;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Angkatan       : " << P->info.angkatan << endl;
            Q = Ld.first;
            ada = false;
            while (Q != NULL){
                R = Q->hubungan.first;
                while (R != NULL){
                    if (R->next_Dosen == Q){
                        cout << "Nama Dosen    : " << Q->info.nama << endl;
                        cout << "NIP Dosen     : " << Q->info.NIP << endl;
                        cout << "Jabatan Dosen : " << Q->info.jabatan << endl;
                        cout << "Jenis Relasi   : " << R->info << endl;
                        cout << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Dosen;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Mahasiswa;
        }
    }
} 
void showDosenDariMahasiswa(List_Dosen L, adr_Mahasiswa P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if (P->hubungan.first == NULL){
            cout << "Data Relasi kosong" << endl;
        }else{
            adr_Relasi R = P->hubungan.first;
            while(R != NULL){
                cout << "Nama Dosen    : " << R->next_Dosen->info.nama << endl;
                cout << "NIP Dosen     : " << R->next_Dosen->info.NIP << endl;
                cout << "Jabatan Dosen : " << R->next_Dosen->info.jabatan << endl;
                cout << "Jenis Relasi  : " << R->info << endl;
                cout << endl;
                R = R->next_Relasi;
            }
        }
    }
} 
void countAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Relasi R;
        adr_Dosen P = Ld.first;
        adr_Mahasiswa Q;
        int count;
        while (P != NULL){
            count = 0;
            Q = Lm.first;
            while (Q != NULL){
                if (P->hubungan.first != NULL){
                    R = P->hubungan.first;
                    while (R != NULL){
                        if (R->next_Dosen == P){
                            count++;
                        }
                        R = R->next_Relasi;
                    }
                }else{
                    cout << "Data Relasi kosong" << endl;
                }
                Q = Q->next_Mahasiswa;
            }
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Jabatan Dosen : " << P->info.jabatan << endl;
            cout << "Jumlah Relasi : " << count << endl;
            cout << endl;
            P = P->next_Dosen;
        }
    }
} 
void countRelasiDariMahasiswa(adr_Mahasiswa P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = P->hubungan.first;
        int count = 0;
        while(R != NULL){
            count++;
            R = R->next_Relasi;
        }
        cout << "Nama Mahasiswa : " << P->info.nama << endl;
        cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
        cout << "Angkatan       : " << P->info.angkatan << endl;
        cout << "Jumlah Relasi  : " << count << endl;
        cout << endl;
    }
} 
void countMahasiswaTanpaDosen(List_Mahasiswa Lm){
    adr_Mahasiswa P = Lm.first;
    int count = 0;
    while(P != NULL){
        if (P->hubungan.first == NULL){
            count++;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Jumlah Mahasiswa tanpa Dosen : " << count << endl;
} 
void editMahasiswaDariDosen(adr_Mahasiswa &S, adr_Mahasiswa &T, adr_Dosen P, adr_Relasi &R){
    deleteRelasi(S, R);
    insertRelasi(T, R);
    cout << "Data Mahasiswa berhasil diubah" << endl;
} 
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm){

} 