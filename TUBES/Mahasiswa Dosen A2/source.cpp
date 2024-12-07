#include "header.h"
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm){
    adr_Relasi R;
    adr_Dosen P,Q;
    adr_Mahasiswa C,D;
    infotype_Dosen dataP;
    infotype_Mahasiswa dataC;
    int pilihan;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|      (JUDUL APLIKASI)       |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|       Adinata Kurnianto Paliling    //   103032330088        |" << endl;
    cout << "|          Hanif Wafi Abdillah        //   103032330108        |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|   1. Data Dosen                                              |" << endl;
    cout << "|   2. Data Mahasiswa                                          |" << endl;
    cout << "|   3. Data Relasi                                             |" << endl;
    cout << "|   4. Exit                                                    |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "----------------------------------------------------------------" << endl;
        cout << "|                        INPUT INVALID                         |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|       Adinata Kurnianto Paliling    //   103032330088        |" << endl;
        cout << "|          Hanif Wafi Abdillah        //   103032330108        |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|   1. Data Dosen                                              |" << endl;
        cout << "|   2. Data Mahasiswa                                          |" << endl;
        cout << "|   3. Data Relasi                                             |" << endl;
        cout << "|   4. Keluar                                                  |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
    }
    if (pilihan == 1){
        cout << "----------------------------------------------------------------" << endl;
        cout << "|                        MENU DOSEN                            |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|       Adinata Kurnianto Paliling    //   103032330088        |" << endl;
        cout << "|          Hanif Wafi Abdillah        //   103032330108        |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Dosen                                       |" << endl;
        cout << "|   2. Menghapus Dosen                                         |" << endl;
        cout << "|   3. Mencari Dosen                                           |" << endl;
        cout << "|   4. Menampilkan Dosen                                       |" << endl;
        cout << "|   5. Menampilkan Mahasiswa dari Dosen Tertentu               |" << endl;
        cout << "|   6. Menampilkan Semua Relasi Dosen                          |" << endl;
        cout << "|   7. Menghitung Semua Relasi Dosen                           |" << endl;
        cout << "|   8. Kembali                                                 |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            insertDosen(Ld); // a
        }else if(pilihan == 2){
            deleteDosen(Ld, P); // d
        }else if(pilihan == 3){
            findDosen(Ld, P); // g
        }else if(pilihan == 4){
            showDosen(Ld); // j
        }else if(pilihan == 5){
            showMahasiswaDariDosen(Ld); // l
        }else if(pilihan == 6){
            showAllRelasiDosen(Ld); // m
        }else if(pilihan == 7){
            countAllRelasiDosen(Ld); // p
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "----------------------------------------------------------------" << endl;
        cout << "|                      MENU MAHASISWA                          |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|       Adinata Kurnianto Paliling    //   103032330088        |" << endl;
        cout << "|          Hanif Wafi Abdillah        //   103032330108        |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Mahasiswa                                   |" << endl;
        cout << "|   2. Menghapus Mahasiswa                                     |" << endl;
        cout << "|   3. Mencari Mahasiswa                                       |" << endl;
        cout << "|   4. Menampilkan Mahasiswa                                   |" << endl;
        cout << "|   5. Menampilkan Dosen dari Mahasiswa Tertentu               |" << endl;
        cout << "|   6. Menampilkan Semua Relasi Mahasiswa                      |" << endl;
        cout << "|   7. Menghitung Relasi Mahasiswa Tertentu                    |" << endl;
        cout << "|   8. Kembali                                                 |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertMahasiswa(Lm); // b
        }else if(pilihan == 2){
            deleteMahasiswa(Ld, Lm, D); // e
        }else if(pilihan == 3){
            findMahasiswa(Lm, C); // h
        }else if(pilihan == 4){
            showMahasiswa(Lm); // k
        }else if(pilihan == 5){
            showDosenDariMahasiswa(Lm, Ld); // o
        }else if(pilihan == 6){
            showAllRelasiMahasiswa(Lm, Ld); // n
        }else if(pilihan == 7){
            countRelasiDariMahasiswa(Lm, Ld); // q
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "----------------------------------------------------------------" << endl;
        cout << "|                        MENU RELASI                           |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|       Adinata Kurnianto Paliling    //   103032330088        |" << endl;
        cout << "|          Hanif Wafi Abdillah        //   103032330108        |" << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Relasi                                      |" << endl;
        cout << "|   2. Menghapus Relasi                                        |" << endl;
        cout << "|   3. Check Relasi                                            |" << endl;
        cout << "|   4. Jumlah Mahasiswa Tanpa Dosen                            |" << endl;
        cout << "|   5. Edit Mahasiswa dari Dosen                               |" << endl;
        cout << "|   6. Kembali                                                 |" << endl;
        cout << "----------------------------------------------------------------" << endl;
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
            deleteRelasi(P, R); // f
        }else if (pilihan == 3){
            findDosen(Ld, P);
            if (P != NULL){
                findMahasiswa(Lm, C);
                if (C != NULL){
                    findRelasi(P, C, R); // i
                }
            }

        }else if (pilihan == 4){
            countMahasiswaTanpaDosen(Lm, Ld); // r
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
void insertDosen(List_Dosen &L){
    infotype_Dosen dataP;
    cout << "Masukkan Nama Dosen : ";
    cin >> dataP.nama;
    cout << "Masukkan Kode Dosen: ";
    cin >> dataP.kode;
    cout << "Masukkan NIP Dosen  : ";
    cin >> dataP.NIP;
    while (!checkNIP(L, dataP.NIP)){
        cout << "NIP sudah ada, masukkan NIP lain : ";
        cin >> dataP.NIP;
    }
    adr_Dosen P = new elm_Dosen;
    P->info = dataP;
    P->next_Dosen = NULL;
    P->prev_Dosen = NULL;
    P->relasi.first = NULL;
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Dosen = P;
        P->prev_Dosen = L.last;
        L.last = P;
    }
}
void insertMahasiswa(List_Mahasiswa &L){
    infotype_Mahasiswa dataC;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> dataC.nama;
    cout << "Masukkan Semester      : ";
    cin >> dataC.semester;
    cout << "Masukkan NIM Mahasiswa : ";
    cin >> dataC.NIM;
    while (!checkNIM(L, dataC.NIM)){
        cout << "NIM sudah ada, masukkan NIM lain : ";
        cin >> dataC.NIM;
    }
    adr_Mahasiswa P = new elm_Mahasiswa;
    P->info = dataC;
    P->next_Mahasiswa = NULL;
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Mahasiswa = L.first;
        L.first = P;
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
    R->next_Mahasiswa = Q;
    insertRelasiFirst(P, R);
}
void insertRelasiFirst(adr_Dosen &P, adr_Relasi &R){
    if (P->relasi.first == NULL){
        R->next_Relasi = NULL;
        P->relasi.first = R;
    }else{
        R->next_Relasi = P->relasi.first;
        P->relasi.first = R;
    }
}
void deleteDosen(List_Dosen &Ld, adr_Dosen &P){
    if(Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
        return;
    }
    findDosen(Ld, P);
    if (P == NULL){
        return;
    }
    if (P->relasi.first != NULL){
        adr_Relasi R;
        R = P->relasi.first;
        while (R != NULL){
            deleteRelasi(P, R);
            // delete R;
            R = P->relasi.first;
        }
    }
    if (Ld.first->next_Dosen == NULL){
        Ld.first = NULL;
    }else if(P == Ld.first){
        deleteFirstDosen(Ld, P);
    }else if (P == Ld.last){
        deleteLastDosen(Ld, P);
    }else{
        deleteAfterDosen(Ld, P);
    }
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
void deleteMahasiswa(List_Dosen &Ld, List_Mahasiswa &Lm, adr_Mahasiswa &P){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    findMahasiswa(Lm, P);
    if (P == NULL){
        return;
    }
    if (Ld.first != NULL){
        adr_Dosen Q = Ld.first;
        while (Q != NULL){
            if (Q->relasi.first != NULL){
                adr_Relasi R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Mahasiswa == P){
                        deleteRelasi(Q, R);
                        R = Q->relasi.first;
                    }else{
                        R = R->next_Relasi;
                    }
                }
            }
            Q = Q->next_Dosen;
        }
    }
    if (Lm.first->next_Mahasiswa == NULL){
        Lm.first = NULL;
    }else if(P == Lm.first){
        deleteFirstMahasiswa(Lm, P);
    }else {
        deleteLastAfterMahasiswa(Lm, P);
    }
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
void deleteRelasi(adr_Dosen &Q ,adr_Relasi &P){
    if(Q->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(Q->relasi.first->next_Relasi == NULL){
            P = Q->relasi.first;
            Q->relasi.first = NULL;
        }else{
            if (P == Q->relasi.first){
                Q->relasi.first = P->next_Relasi;
                P->next_Relasi = NULL;
            }else{
                adr_Relasi R = Q->relasi.first;
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
    cout << "----------------------------------------------------------------" << endl;
}
void findDosen(List_Dosen L, adr_Dosen &P){
    long long NIP;
    cout << "Masukkan NIP Dosen yang dicari : ";
    cin >> NIP;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.NIP == NIP){
            cout << "Data Dosen ditemukan" << endl;
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl;
            cout << "----------------------------------------------------------------" << endl;
            return;
        }
        P = P->next_Dosen;
    }
    cout << "Data Dosen tidak ditemukan" << endl;
    cout << "----------------------------------------------------------------" << endl;
    P = NULL;
}
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P){
    long long NIM;
    cout << "Masukkan NIM Mahasiswa yang dicari : ";
    cin >> NIM;
    P = L.first;
    while(P != NULL){
        if(P->info.NIM == NIM){
            cout << "Data Mahasiswa ditemukan" << endl;
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Semester       : " << P->info.semester << endl;
            cout << "----------------------------------------------------------------" << endl;
            return;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Data Mahasiswa tidak ditemukan" << endl;
    cout << "----------------------------------------------------------------" << endl;
    P = NULL;
}
void findRelasi(adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R){
    if (P->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        R = P->relasi.first;
        while(R != NULL){
            if(R->next_Mahasiswa == Q){
                cout << "Data Relasi ditemukan" << endl;
                cout << "Nama Dosen     : " << P->info.nama << endl;
                cout << "NIP Dosen      : " << P->info.NIP << endl;
                cout << "Kode Dosen     : " << P->info.kode << endl;
                cout << "----------------------------------------------------------------" << endl;
                cout << "Nama Mahasiswa : " << Q->info.nama << endl;
                cout << "NIM Mahasiswa  : " << Q->info.NIM << endl;
                cout << "Semester       : " << Q->info.semester << endl;
                cout << "----------------------------------------------------------------" << endl;
                return;
            }
            R = R->next_Relasi;
        }
        cout << "Data Relasi tidak ditemukan" << endl;
        cout << "----------------------------------------------------------------" << endl;
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
            cout << "Kode Dosen    : " << P->info.kode << endl;
            cout << "----------------------------------------------------------------" << endl;
            P = P->next_Dosen;
        }
    }
}
void showMahasiswa(List_Mahasiswa L){
    adr_Mahasiswa P = L.first;
    if(P == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }else{
        cout << "Data Mahasiswa : " << endl;
        while(P != NULL){
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Semester       : " << P->info.semester << endl;
            cout << "----------------------------------------------------------------" << endl;
            P = P->next_Mahasiswa;
        }
    }
}
void showMahasiswaDariDosen(List_Dosen Ld){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        adr_Dosen P;
        findDosen(Ld, P);
        if (P == NULL){
            return;
        }
        if (P->relasi.first == NULL){
            cout << "Dosen Ini Tidak Memiliki Relasi" << endl;
        }else{
            adr_Relasi R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Mahasiswa : " << R->next_Mahasiswa->info.nama << endl;
                cout << "NIM Mahasiswa  : " << R->next_Mahasiswa->info.NIM << endl;
                cout << "Semester       : " << R->next_Mahasiswa->info.semester << endl;
                cout << "----------------------------------------------------------------" << endl;
                R = R->next_Relasi;
            }
        }
    }
}
void showAllRelasiDosen(List_Dosen Ld){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        adr_Dosen P = Ld.first;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Dosen    : " << P->info.nama << endl;
            cout << "NIP Dosen     : " << P->info.NIP << endl;
            cout << "Kode Dosen    : " << P->info.kode << endl;
            cout << "----------------------------------------------------------------" << endl;
            R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Mahasiswa : " << R->next_Mahasiswa->info.nama << endl;
                cout << "NIM Mahasiswa  : " << R->next_Mahasiswa->info.NIM << endl;
                cout << "Semester       : " << R->next_Mahasiswa->info.semester << endl;
                cout << "----------------------------------------------------------------" << endl;
                R = R->next_Relasi;
                ada = true;
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
        adr_Dosen Q;
        bool ada;
        while (P != NULL){
            ada = false;
            cout << "Nama Mahasiswa : " << P->info.nama << endl;
            cout << "NIM Mahasiswa  : " << P->info.NIM << endl;
            cout << "Semester       : " << P->info.semester << endl;
            cout << "----------------------------------------------------------------" << endl;
            Q = Ld.first;
            while (Q != NULL){
                R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Mahasiswa == P){
                        cout << "Nama Dosen    : " << Q->info.nama << endl;
                        cout << "NIP Dosen     : " << Q->info.NIP << endl;
                        cout << "Kode Dosen    : " << Q->info.kode << endl;
                        cout << "----------------------------------------------------------------" << endl;
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
void showDosenDariMahasiswa(List_Mahasiswa Lm, List_Dosen Ld){
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
        adr_Dosen Q = Ld.first;
        bool ada = false;
        while (Q != NULL){
            R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Mahasiswa == P){
                    cout << "Nama Dosen    : " << Q->info.nama << endl;
                    cout << "NIP Dosen     : " << Q->info.NIP << endl;
                    cout << "Kode Dosen    : " << Q->info.kode << endl;
                    cout << "----------------------------------------------------------------" << endl;
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Dosen;
        }
        if (!ada){
            cout << "Data Relasi tidak ditemukan" << endl;
        }
    }
}
void countAllRelasiDosen(List_Dosen Ld){
    if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else{
        adr_Dosen P = Ld.first;
        int count;
        while (P != NULL){
            adr_Relasi R = P->relasi.first;
            count = 0;
            while (R != NULL){
                count++;
                R = R->next_Relasi;
            }
            P = P->next_Dosen;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countRelasiDariMahasiswa(List_Mahasiswa Lm, List_Dosen Ld){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
    }else if (Ld.first == NULL){
        cout << "Data Dosen kosong" << endl;
    }else {
        adr_Mahasiswa P;
        findMahasiswa(Lm, P);
        if (P == NULL){
            return;
        }
        adr_Dosen Q = Ld.first;
        int count = 0;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Mahasiswa == P){
                    count++;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Dosen;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countMahasiswaTanpaDosen(List_Mahasiswa Lm, List_Dosen Ld){
    if (Lm.first == NULL){
        cout << "Data Mahasiswa kosong" << endl;
        return;
    }
    adr_Mahasiswa P = Lm.first;
    int count = 0;
    bool ada;
    while (P != NULL){
        adr_Dosen Q = Ld.first;
        ada = false;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Mahasiswa == P){
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Dosen;
        }
        if (!ada){
            count++;
        }
        P = P->next_Mahasiswa;
    }
    cout << "Jumlah Mahasiswa tanpa Dosen : " << count << endl;
    cout << "----------------------------------------------------------------" << endl;
}
void editMahasiswaDariDosen(List_Mahasiswa &Lm, List_Dosen &Ld){
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
        adr_Mahasiswa Q,S;
        findMahasiswa(Lm, Q);
        if (Q == NULL){
            return;
        }
        adr_Relasi R,T;
        findRelasi(P, Q, R);
        if (R == NULL){
            return;
        }
        cout << "Masukkan NIM Mahasiswa yang baru : "<< endl;
        findMahasiswa(Lm, S);
        findRelasi(P, S, T);
        if (T != NULL){
            cout << "Relasi sudah ada" << endl;
            return;
        }
        R->next_Mahasiswa = S;
        cout << "Data Mahasiswa berhasil diubah" << endl;
    }
}

bool checkNIM(List_Mahasiswa L, long long NIM){
    adr_Mahasiswa P = L.first;
    while (P != NULL){
        if (P->info.NIM == NIM){
            return false;
        }
        P = P->next_Mahasiswa;
    }
    return true;
}
bool checkNIP(List_Dosen L, long long NIP){
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
    adr_Relasi R = Q->relasi.first;
    while (R != NULL){
        if (R->next_Mahasiswa == P){
            return false;
        }
        R = R->next_Relasi;
    }
    return true;
}
