#include "header.h"
void insertDosen(List_Dosen &L){
    infotype_Dosen dataP;
    cout << "Masukkan Nama Dosen : ";
    cin >> dataP.nama;
    cout << "Masukkan Jabatan Dosen: ";
    cin >> dataP.jabatan;
    cout << "Masukkan NIP Dosen  : ";
    cin >> dataP.NIP;
    while (!checkNIP(L, dataP.NIP)){
        cout << "NIP sudah ada, masukkan NIP lain : ";
        cin >> dataP.NIP;
    }
    adr_Dosen P = new elm_Dosen;
    P->info = dataP;
    P->next_Dosen = NULL;
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Dosen = L.first;
        L.first = P;
    }
}
void insertMahasiswa(List_Mahasiswa &L){
    infotype_Mahasiswa dataC;
    cout << "================================================================" << endl;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> dataC.nama;
    cout << "Masukkan Angkatan      : ";
    cin >> dataC.angkatan;
    cout << "Masukkan NIM Mahasiswa : ";
    cin >> dataC.NIM;
    while (!checkNIM(L, dataC.NIM)){
        cout << "NIM sudah ada, masukkan NIM lain : ";
        cin >> dataC.NIM;
    }
    cout << "================================================================" << endl;
    adr_Mahasiswa P = new elm_Mahasiswa;
    P->info = dataC;
    P->next_Mahasiswa = NULL;
    P->prev_Mahasiswa = NULL;
    P->hubungan.first = NULL;
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Mahasiswa = P;
        P->prev_Mahasiswa = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Dosen &Ld, List_Mahasiswa &Lm){
    if(Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }else if(Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    adr_Dosen P;
    findDosen(Ld, P);
    if(P == NULL){
        return;
    }
    adr_Mahasiswa Q;
    findMahasiswa(Lm, Q);
    if(Q == NULL){
        return;
    }
    if (!checkRelasi(Q, P)){
        cout << "Relasi sudah ada" << endl;
        return;
    }
    adr_Relasi R = new elm_Relasi;
    R->next_Dosen = P;
    insertRelasiFirst(Q, R);
}
void insertRelasiFirst(adr_Mahasiswa &P, adr_Relasi &R){
    if (P->hubungan.first == NULL){
        R->next_Relasi = NULL;
        P->hubungan.first = R;
    }else{
        R->next_Relasi = P->hubungan.first;
        P->hubungan.first = R;
    }
}
void deleteDosen(List_Dosen &Ld, List_Mahasiswa &Lm, adr_Dosen &P){
    if(Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    findDosen(Ld, P);
    if (P == NULL){
        return;
    }
    if (Lm.first != NULL){
        adr_Mahasiswa Q = Lm.first;
        while (Q != NULL){
            if (Q->hubungan.first != NULL){
                adr_Relasi R = Q->hubungan.first;
                while (R != NULL){
                    if (R->next_Dosen == P){
                        deleteRelasi(Q, R);
                        // delete R;
                        R = Q->hubungan.first;
                    }else{
                        R = R->next_Relasi;
                    }
                }
            }
            Q = Q->next_Mahasiswa;
        }
    }
    if (Ld.first->next_Dosen == NULL){
        Ld.first = NULL;
    }else if(P == Ld.first){
        deleteFirstDosen(Ld, P);
    }else{
        deleteLastAfterDosen(Ld, P);
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
    if (P == NULL){
        return;
    }
    if (P->hubungan.first != NULL){
        adr_Relasi R;
        R = P->hubungan.first;
        while (R != NULL){
            deleteRelasi(P, R);
            // delete R;
            R = P->hubungan.first;
        }
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
            if (P == Q->hubungan.first){
                Q->hubungan.first = P->next_Relasi;
                P->next_Relasi = NULL;
            }else{
                adr_Relasi R = Q->hubungan.first;
                while(R->next_Relasi != P){
                    R = R->next_Relasi;
                }
                if (P->next_Relasi != NULL){
                    R->next_Relasi = P->next_Relasi;
                    P->next_Relasi = NULL;
                }else{
                    R->next_Relasi = NULL;
                }

            }
        }
    }
    cout << "================================================================" << endl;
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
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_Dosen;
    }
    cout << "Data Dosen tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
    int NIM;
    cout << "Masukkan NIM Mahasiswa yang dicari : ";
    cin >> NIM;
    P = L.first;
    while(P != NULL){
        if(P->info.NIM == NIM){
            cout << "Data Mahasiswa ditemukan" << endl;
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Angkatan       : " << P->info.angkatan << endl;
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Data Mahasiswa tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findRelasi(adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){
    if (Q->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        R = Q->hubungan.first;
        while(R != NULL){
            if(R->next_Dosen == P){
                cout << "Data Relasi ditemukan" << endl;
                cout << "Nama Dosen     : " << P->info.nama << endl;
                cout << "NIP Dosen      : " << P->info.NIP << endl;
                cout << "Jabatan Dosen  : " << P->info.jabatan << endl;
                cout << "================================================================" << endl;
                cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                cout << "Angkatan       : " << Q->info.angkatan << endl;
                cout << "================================================================" << endl;
                return;
            }
            R = R->next_Relasi;
        }
        cout << "Data Relasi tidak ditemukan" << endl;
        cout << "================================================================" << endl;
        R = NULL;
    }
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
            cout << "================================================================" << endl;
            P = P->next_Dosen;
        }
    }
}
void showMahasiswa(List_Mahasiswa L){
    adr_Mahasiswa P = L.first;
    if(P == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        cout << "================================================================" << endl;
    }else{
        cout << "Data Mahasiswa : " << endl;
        while(P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Angkatan       : " << P->info.angkatan << endl;
            cout << "================================================================" << endl;
            P = P->next_Mahasiswa;
        }
    }
}
void showMahasiswaDariDosen(List_Mahasiswa Lm, List_Dosen Ld){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Dosen P;
        findDosen(Ld, P);
        if (P == NULL){
            return;
        }
        adr_Mahasiswa Q = Lm.first;
        adr_Relasi R;
        while (Q != NULL){
            R = Q->hubungan.first;
            while (R != NULL){
                if (R->next_Dosen == P){
                    cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                    cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                    cout << "Angkatan       : " << Q->info.angkatan << endl;
                    cout << "================================================================" << endl;
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
            cout << "================================================================" << endl;
            Q = Lm.first;
            ada = false;
            while (Q != NULL){
                R = Q->hubungan.first;
                while (R != NULL){
                    if (R->next_Dosen == P){
                        cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                        cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                        cout << "Angkatan       : " << Q->info.angkatan << endl;
                        cout << "================================================================" << endl;
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
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Angkatan       : " << P->info.angkatan << endl;
            cout << "================================================================" << endl;
            R = P->hubungan.first;
            while (R != NULL){
                cout << "Nama Dosen    : " << R->next_Dosen->info.nama << endl;
                cout << "NIP Dosen     : " << R->next_Dosen->info.NIP << endl;
                cout << "Jabatan Dosen : " << R->next_Dosen->info.jabatan << endl;
                cout << "================================================================" << endl;
                R = R->next_Relasi;
                ada = true;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Mahasiswa;
        }
    }
}
void showDosenDariMahasiswa(List_Mahasiswa Lm){
    if (Lm.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Mahasiswa P;
        adr_Relasi R;
        findMahasiswa(Lm, P);
        if (P == NULL){
            return;
        }
        if (P->hubungan.first == NULL){
            cout << "Mahasiswa Ini Tidak Memiliki Relasi" << endl;
        }else{
            R = P->hubungan.first;
            while (R != NULL){
                cout << "Nama Dosen    : " << R->next_Dosen->info.nama << endl;
                cout << "NIP Dosen     : " << R->next_Dosen->info.NIP << endl;
                cout << "Jabatan Dosen : " << R->next_Dosen->info.jabatan << endl;
                cout << "================================================================" << endl;
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
        adr_Dosen P = Ld.first;
        while (P != NULL){
            adr_Mahasiswa Q = Lm.first;
            int count = 0;
            while (Q != NULL){
                adr_Relasi R = Q->hubungan.first;
                while (R != NULL){
                    if (R->next_Dosen == P){
                        count++;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Mahasiswa;
            }
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Jabatan Dosen : " << P->info.jabatan << endl;
            cout << "Jumlah Relasi : " << count << endl;
            cout << "================================================================" << endl;
            P = P->next_Dosen;
        }
    }
}
void countRelasiDariMahasiswa(List_Mahasiswa Lm){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else{
        adr_Mahasiswa P = NULL;
        findMahasiswa(Lm, P);
        if (P == NULL){
            return;
        }
        adr_Relasi R = P->hubungan.first;
        int count = 0;
        while(R != NULL){
            count++;
            R = R->next_Relasi;
        }
        cout << "Jumlah Relasi  : " << count << endl;
        cout << "================================================================" << endl;
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
    cout << "================================================================" << endl;
}
void editMahasiswaDariDosen(List_Mahasiswa &Lm, List_Dosen &Ld){
    adr_Mahasiswa P,T;
    adr_Dosen Q;
    findMahasiswa(Lm, P);
    if (P == NULL){
        return;
    }
    findDosen(Ld,Q);
    if (Q == NULL){
        return;
    }
    adr_Relasi R;
    findRelasi(Q, P, R);
    if (R == NULL){
        return;
    }
    cout << "================= NAMA MAHASISWA BARU ==================" << endl;
    findMahasiswa(Lm, T);
    deleteRelasi(P, R);
    insertRelasiFirst(T, R);
    cout << "Data Mahasiswa berhasil diubah" << endl;
}
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm){
    adr_Relasi R;
    adr_Dosen P,Q;
    adr_Mahasiswa C,D;
    infotype_Dosen dataP;
    infotype_Mahasiswa dataC;
    int pilihan;
    cout << "================================================================" << endl;
    cout << "|#|      Sistem Informasi Manajemen Mahasiswa dan Dosen      |#|" << endl;
    cout << "================================================================" << endl;
    cout << "|#|       Aldo Darma Pangestu           //   103032330069    |#|" << endl;
    cout << "|#|  Kenzo Paramarafsya Radith Prasetyo //   103032300187    |#|" << endl;
    cout << "================================================================" << endl;
    cout << "|#|   1. Data Dosen                                          |#|" << endl;
    cout << "|#|   2. Data Mahasiswa                                      |#|" << endl;
    cout << "|#|   3. Data Relasi                                         |#|" << endl;
    cout << "|#|   4. Exit                                                |#|" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "================================================================" << endl;
        cout << "|#|                        INPUT INVALID                     |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|       Aldo Darma Pangestu           //   103032330069    |#|" << endl;
        cout << "|#|  Kenzo Paramarafsya Radith Prasetyo //   103032300187    |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|   1. Data Dosen                                          |#|" << endl;
        cout << "|#|   2. Data Mahasiswa                                      |#|" << endl;
        cout << "|#|   3. Data Relasi                                         |#|" << endl;
        cout << "|#|   4. Keluar                                              |#|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
    }
    if (pilihan == 1){
        cout << "================================================================" << endl;
        cout << "|#|                        MENU DOSEN                        |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|       Aldo Darma Pangestu           //   103032330069    |#|" << endl;
        cout << "|#|  Kenzo Paramarafsya Radith Prasetyo //   103032300187    |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|   1. Menambahkan Dosen                                   |#|" << endl;
        cout << "|#|   2. Menghapus Dosen                                     |#|" << endl;
        cout << "|#|   3. Mencari Dosen                                       |#|" << endl;
        cout << "|#|   4. Menampilkan Dosen                                   |#|" << endl;
        cout << "|#|   5. Menampilkan Mahasiswa dari Dosen Tertentu           |#|" << endl;
        cout << "|#|   6. Menampilkan Semua Relasi Dosen                      |#|" << endl;
        cout << "|#|   7. Menghitung Semua Relasi Dosen                       |#|" << endl;
        cout << "|#|   8. Kembali                                             |#|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            insertDosen(Ld); // a
        }else if(pilihan == 2){
            deleteDosen(Ld,Lm, P); // d
        }else if(pilihan == 3){
            findDosen(Ld, P); // g
        }else if(pilihan == 4){
            showDosen(Ld); // j
        }else if(pilihan == 5){
            showMahasiswaDariDosen(Lm, Ld); // l
        }else if(pilihan == 6){
            showAllRelasiDosen(Ld, Lm); // m
        }else if(pilihan == 7){
            countAllRelasiDosen(Ld, Lm); // p
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "================================================================" << endl;
        cout << "|#|                      MENU MAHASISWA                      |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|       Aldo Darma Pangestu           //   103032330069    |#|" << endl;
        cout << "|#|  Kenzo Paramarafsya Radith Prasetyo //   103032300187    |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|   1. Menambahkan Mahasiswa                               |#|" << endl;
        cout << "|#|   2. Menghapus Mahasiswa                                 |#|" << endl;
        cout << "|#|   3. Mencari Mahasiswa                                   |#|" << endl;
        cout << "|#|   4. Menampilkan Mahasiswa                               |#|" << endl;
        cout << "|#|   5. Menampilkan Dosen dari Mahasiswa Tertentu           |#|" << endl;
        cout << "|#|   6. Menampilkan Semua Relasi Mahasiswa                  |#|" << endl;
        cout << "|#|   7. Menghitung Relasi Mahasiswa Tertentu                |#|" << endl;
        cout << "|#|   8. Kembali                                             |#|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertMahasiswa(Lm); // b
        }else if(pilihan == 2){
            deleteMahasiswa(Lm, D); // e
        }else if(pilihan == 3){
            findMahasiswa(Lm, C); // h
        }else if(pilihan == 4){
            showMahasiswa(Lm); // k
        }else if(pilihan == 5){
            showDosenDariMahasiswa(Lm); // o
        }else if(pilihan == 6){
            showAllRelasiMahasiswa(Lm, Ld); // n
        }else if(pilihan == 7){
            countRelasiDariMahasiswa(Lm); // q
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "================================================================" << endl;
        cout << "|#|                        MENU RELASI                       |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|       Aldo Darma Pangestu           //   103032330069    |#|" << endl;
        cout << "|#|  Kenzo Paramarafsya Radith Prasetyo //   103032300187    |#|" << endl;
        cout << "================================================================" << endl;
        cout << "|#|   1. Menambahkan Relasi                                  |#|" << endl;
        cout << "|#|   2. Menghapus Relasi                                    |#|" << endl;
        cout << "|#|   3. Check Relasi                                        |#|" << endl;
        cout << "|#|   4. Jumlah Mahasiswa Tanpa Dosen                        |#|" << endl;
        cout << "|#|   5. Edit Mahasiswa dari Dosen                           |#|" << endl;
        cout << "|#|   6. Kembali                                             |#|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertRelasi(Ld, Lm); // c
        }else if (pilihan == 2){
            findDosen(Ld, P);
            if (P != NULL){
                findMahasiswa(Lm, C);
                if (C != NULL){
                    findRelasi(P, C, R);
                }
            }
            deleteRelasi(C, R); // f
        }else if (pilihan == 3){
            findDosen(Ld, P);
            if (P != NULL){
                findMahasiswa(Lm, C);
                if (C != NULL){
                    findRelasi(P, C, R); // i
                }
            }

        }else if (pilihan == 4){
            countMahasiswaTanpaDosen(Lm); // r
        }else if (pilihan == 5){
            editMahasiswaDariDosen(Lm, Ld); // s
        }else if (pilihan == 6){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    mainMenu(Ld, Lm);
}
bool checkNIM(List_Mahasiswa L, int NIM){
    adr_Mahasiswa P = L.first;
    while (P != NULL){
        if (P->info.NIM == NIM){
            return false;
        }
        P = P->next_Mahasiswa;
    }
    return true;
}
bool checkNIP(List_Dosen L, int NIP){
    adr_Dosen P = L.first;
    while (P != NULL){
        if (P->info.NIP == NIP){
            return false;
        }
        P = P->next_Dosen;
    }
    return true;
}
bool checkRelasi(adr_Mahasiswa P, adr_Dosen Q){
    adr_Relasi R = P->hubungan.first;
    while (R != NULL){
        if (R->next_Dosen == Q){
            return false;
        }
        R = R->next_Relasi;
    }
    return true;
}
