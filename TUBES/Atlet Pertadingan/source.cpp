#include "header.h"
void menu(List_Relasi &Lr, List_Pertandingan &Lp, List_Atlet &La){
    adr_Relasi R;
    adr_Pertandingan P,Q;
    adr_Atlet C,D;
    infotype_Relasi dataR;
    infotype_Pertandingan dataP;
    infotype_Atlet dataC;
    int pilihan;
    cout << "================================================================" << endl;
    cout << "|*|                  Jadwal Atlet Pertandingan               |*|" << endl;
    cout << "================================================================" << endl;
    cout << "|*|        Raja Wali Putra Ertha  //   103032300003          |*|" << endl;
    cout << "|*|       Saladin Setyo Harfianto //   103032330194          |*|" << endl;
    cout << "================================================================" << endl;
    cout << "|*|   1. Data Pertandingan                                   |*|" << endl;
    cout << "|*|   2. Data Atlet                                          |*|" << endl;
    cout << "|*|   3. Data Relasi                                         |*|" << endl;
    cout << "|*|   4. Exit                                                |*|" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "================================================================" << endl;
        cout << "|*|                        INPUT INVALID                     |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|        Raja Wali Putra Ertha  //   103032300003          |*|" << endl;
        cout << "|*|       Saladin Setyo Harfianto //   103032330194          |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|   1. Data Pertandingan                                   |*|" << endl;
        cout << "|*|   2. Data Atlet                                          |*|" << endl;
        cout << "|*|   3. Data Relasi                                         |*|" << endl;
        cout << "|*|   4. Keluar                                              |*|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    if (pilihan == 1){
        cout << "================================================================" << endl;
        cout << "|*|                     MENU Pertandingan                    |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|        Raja Wali Putra Ertha  //   103032300003          |*|" << endl;
        cout << "|*|       Saladin Setyo Harfianto //   103032330194          |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|   1. Menambahkan Pertandingan                            |*|" << endl;
        cout << "|*|   2. Menghapus Pertandingan                              |*|" << endl;
        cout << "|*|   3. Mencari Pertandingan                                |*|" << endl;
        cout << "|*|   4. Menampilkan Pertandingan                            |*|" << endl;
        cout << "|*|   5. Total Pertandingan Tanpa Atlet                      |*|" << endl;
        cout << "|*|   6. Total Atlet Dari Pertandingan Tertentu              |*|" << endl;
        cout << "|*|   7. Menampilkan Atlet dari Pertandingan Tertentu        |*|" << endl;
        cout << "|*|   8. Kembali                                             |*|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Pertandingan: ";
            cin >> dataP.nama;
            cout << "Masukkan Waktu Pertandingan: ";
            cin >> dataP.waktu;
            cout << "Masukkan ID Pertandingan: ";
            cin >> dataP.ID;
            while (!checkID(Lp, dataP.ID)){
                cout << "ID sudah ada" << endl;
                cin >> dataP.ID;
            }
            P = new elm_Pertandingan;
            P->info = dataP;
            P->next_Pertandingan = NULL;
            insertPertandingan(Lp, P);
            cout << "Data Pertandingan berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            P = NULL;
            deletePertandingan(Lp, P);
            if (P != NULL){
                deleteRelasiPertandingan(Lr, P);
                cout << "Elemen List Pertandingan "<< P->info.nama << " telah berhasil dihapus" << endl;
                delete P;
            }
        }else if(pilihan == 3){
            findPertandingan(Lp, P);
        }else if(pilihan == 4){
            showPertandingan(Lp);
        }else if(pilihan == 5){
            hitungAtletTanpaPertandingan(Lr, La);
        }else if(pilihan == 6){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            hitungAtlet(Lr, P);
        }else if(pilihan == 7){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            showAtlet_dariPertandingan(Lr, P);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "================================================================" << endl;
        cout << "|*|                         MENU Atlet                       |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|        Raja Wali Putra Ertha  //   103032300003          |*|" << endl;
        cout << "|*|       Saladin Setyo Harfianto //   103032330194          |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|   1. Menambahkan Atlet                                   |*|" << endl;
        cout << "|*|   2. Menghapus Atlet                                     |*|" << endl;
        cout << "|*|   3. Mencari Atlet                                       |*|" << endl;
        cout << "|*|   4. Menampilkan Atlet                                   |*|" << endl;
        cout << "|*|   5. Total Atlet Tanpa Pertandingan                      |*|" << endl;
        cout << "|*|   6. Total Pertandingan Dari Atlet Tertentu              |*|" << endl;
        cout << "|*|   7. Menampilkan Pertandingan dari Atlet Tertentu        |*|" << endl;
        cout << "|*|   8. Kembali                                             |*|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Atlet: ";
            cin >> dataC.nama;
            cout << "Masukkan Umur Atlet: ";
            cin >> dataC.umur;
            cout << "Masukkan ID Atlet: ";
            cin >> dataC.ID;
            while (!checkID(La, dataC.ID)){
                cout << "ID sudah ada" << endl;
                cin >> dataC.ID;
            }
            C = new elm_Atlet;
            C->info = dataC;
            C->next_Atlet = NULL;
            C->prev_Atlet = NULL;
            insertAtlet(La, C);
            cout << "Data Atlet berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteAtlet(La, C);
            if (C != NULL){
                deleteRelasiAtlet(Lr, C);
                cout << "Atlet dengan nama: " << C->info.nama  << " telah berhasil dihapus" << endl;
                delete C;
            }
        }else if(pilihan == 3){
            findAtlet(La, C);
        }else if(pilihan == 4){
            showAtlet(La);
        }else if(pilihan == 5){
            hitungAtletTanpaPertandingan(Lr, La);
        }else if(pilihan == 6){
            findAtlet(La, C);
            while (C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            hitungPertandingan(Lr, C);
        }else if(pilihan == 7){
            findAtlet(La, C);
            showPertandingan_dariAtlet(Lr, C);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "================================================================" << endl;
        cout << "|*|                        MENU RELASI                       |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|        Raja Wali Putra Ertha  //   103032300003          |*|" << endl;
        cout << "|*|       Saladin Setyo Harfianto //   103032330194          |*|" << endl;
        cout << "================================================================" << endl;
        cout << "|*|   1. Menambahkan Relasi                                  |*|" << endl;
        cout << "|*|   2. Menghapus Relasi                                    |*|" << endl;
        cout << "|*|   3. Check Relasi                                        |*|" << endl;
        cout << "|*|   4. Menampilkan Atlet & Relasinya                       |*|" << endl;
        cout << "|*|   5. Menampilkan Pertandingan & Relasinya                |*|" << endl;
        cout << "|*|   6. Edit Relasi Dari Pertandingan                       |*|" << endl;
        cout << "|*|   7. Edit Relasi Dari Atlet                              |*|" << endl;
        cout << "|*|   8. Kembali                                             |*|" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            findAtlet(La, C);
            while ( C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            cout << "Masukkan Info Relasi: ";
            cin >> dataR;
            R = new elm_Relasi;
            R->info = dataR;
            R->next_Pertandingan = P;
            R->next_Atlet = C;
            R->next_Relasi = NULL;
            insertRelasi(Lr, R);
            cout << "Relasi berhasil ditambahkan" << endl;
        }else if (pilihan == 2){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            findAtlet(La, C);
            while ( C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R == NULL){
                cout << "Relasi tidak ditemukan" << endl;
            }else{}
            deleteRelasi(Lr, R);
            delete R;
            cout << "Relasi berhasil dihapus" << endl;
        }else if (pilihan == 3){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            findAtlet(La, C);
            while ( C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            checkRelasi(Lr, C, P, R);
        }else if (pilihan == 4){
            showAll_RelasiPertandingan(Lp, Lr);
        }else if (pilihan == 5){
            showAll_RelasiAtlet(La, Lr);
        }else if (pilihan == 6){
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            findAtlet(La, C);
            while ( C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findAtlet(La, D);
                editPertandingan(Lr, P, C, D);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 7){
            findAtlet(La, C);
            while ( C == NULL){
                cout << "Data Atlet tidak ditemukan" << endl;
                findAtlet(La, C);
            }
            findPertandingan(Lp, P);
            while (P == NULL){
                cout << "Data Pertandingan tidak ditemukan" << endl;
                findPertandingan(Lp, P);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findPertandingan(Lp, Q);
                editAtlet(Lr, C, P, Q);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    menu(Lr, Lp, La);
}
void insertPertandingan(List_Pertandingan &L, adr_Pertandingan P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Pertandingan = L.first;
        L.first = P;
    }
}
void insertAtlet(List_Atlet &L, adr_Atlet P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Atlet = P;
        P->prev_Atlet = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Relasi &L, adr_Relasi P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->next_Relasi = L.first;
        L.first = P;
    }
}
void deletePertandingan(List_Pertandingan &L, adr_Pertandingan &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    findPertandingan(L, P);
    while (P == NULL){
        cout << "Data Pertandingan tidak ditemukan" << endl;
        findPertandingan(L, P);
    }
    if(P == L.first){
        deleteFirstPertandingan(L, P);
    }else if (P->next_Pertandingan == NULL){
        deleteLastPertandingan(L, P);
    }else{
        deleteAfterPertandingan(L, P);
    }
}
void deleteAtlet(List_Atlet &L, adr_Atlet &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    findAtlet(L, P);
    if (P == NULL){
        cout << "Data Atlet tidak ditemukan" << endl;
        return;
    }
    if (P == L.first){
        deleteFirstAtlet(L, P);
    }else if (P == L.last){
        deleteLastAtlet(L, P);
    }else{
        deleteAfterAtlet(L, P);
    }
}
void deleteRelasi(List_Relasi &L ,adr_Relasi &P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(P == L.first){
            L.first = P->next_Relasi;
            P->next_Relasi = NULL;
        }else{
            adr_Relasi Q = L.first;
            while(Q->next_Relasi != P){
                Q = Q->next_Relasi;
            }
            if (P->next_Relasi != NULL){
                Q->next_Relasi = P->next_Relasi;
            }
            Q->next_Relasi = NULL;
        }
    }
}
void findPertandingan(List_Pertandingan L, adr_Pertandingan &P){
    if (L.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
        return;
    }else{
        int ID;
        cout << "Masukkan ID Pertandingan: ";
        cin >> ID;
        P = L.first;
        while(P != NULL){
            if(P->info.ID == ID){
                cout << "Data Pertandingan ditemukan" << endl;
                cout << endl << "==============================================================" << endl;
                cout << "|*|   Nama Pertandingan: " << P->info.nama << endl;
                cout << "|*|   Waktu Pertandingan: " << P->info.waktu << endl;
                cout << "|*|   ID Pertandingan: " << P->info.ID << endl;
                cout << endl << "==============================================================" << endl;
                return;
            }else{
                P = P->next_Pertandingan;
            }
        }
    }
}
void findAtlet(List_Atlet L, adr_Atlet &P){
    if (L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }else{
        int ID;
        cout << "Masukkan ID Atlet: ";
        cin >> ID;
        P = L.first;
        while(P != NULL){
            if(P->info.ID == ID){
                cout << "Data Atlet ditemukan" << endl;
                cout << endl << "==============================================================" << endl;
                cout << "|*|   Nama Atlet: " << P->info.nama << endl;
                cout << "|*|   Umur Atlet: " << P->info.umur << endl;
                cout << "|*|   ID Atlet: " << P->info.ID << endl;
                cout << endl << "==============================================================" << endl;
                return;
            }else{
                P = P->next_Atlet;
            }
        }
    }
}
void checkRelasi(List_Relasi L, adr_Atlet P, adr_Pertandingan Q, adr_Relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_Atlet == P && R->next_Pertandingan == Q){
            cout << endl << "==============================================================" << endl;
            cout << "|*|   Relasi ditemukan" << endl;
            cout << "|*|   Info Relasi: " << R->info << endl;
            cout << endl << "==============================================================" << endl;
            return;
        }else{
            R = R->next_Relasi;
        }
    }
    cout << endl << "==============================================================" << endl;
            cout << "|*|   Relasi Tidak Ditemukan" << endl;
    cout << endl << "==============================================================" << endl;
}
void showPertandingan(List_Pertandingan L){
    if(L.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
    }else{
        adr_Pertandingan P = L.first;
        cout << endl << "==============================================================" << endl;
        while(P != NULL){
            cout << "|*|   Nama Pertandingan: " << P->info.nama << endl;
            cout << "|*|   Waktu Pertandingan: " << P->info.waktu << endl;
            cout << "|*|   ID Pertandingan: " << P->info.ID << endl;
            cout << endl;
            P = P->next_Pertandingan;
        }
        cout << "==============================================================" << endl;
    }
}
void showAtlet(List_Atlet L){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
    }else{
        adr_Atlet P = L.first;
        cout << endl << "==============================================================" << endl;
        while(P != NULL){
            cout << "|*|   Nama Atlet: " << P->info.nama << endl;
            cout << "|*|   Umur Atlet: " << P->info.umur << endl;
            cout << "|*|   ID Atlet: " << P->info.ID << endl;
            cout << endl;
            P = P->next_Atlet;
        }
        cout << "==============================================================" << endl;
    }
}
void showAtlet_dariPertandingan(List_Relasi L, adr_Pertandingan P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        bool ada = false;
        int count = 0;
        cout << endl << "==============================================================" << endl;
        while(R != NULL){
            if(R->next_Pertandingan == P){
                ada = true;
                if (count == 0 && ada){
                    cout << "|*|  Atlet Yang Memiliki Relasi Dengan Pertandingan Diatas |*|" << endl;
                    cout << "==============================================================" << endl;
                }
                cout << "|*|   Nama Atlet: " << R->next_Atlet->info.nama << endl;
                cout << "|*|   Umur Atlet: " << R->next_Atlet->info.umur << endl;
                cout << "|*|   ID Atlet: " << R->next_Atlet->info.ID << endl;
                cout << "|*|   Info Relasi: " << R->info << endl;
                cout << endl;
                count++;
            }
            R = R->next_Relasi;
        }
        if (!ada){
            cout << "|*|   Pertandingan tidak memiliki relasi dengan Atlet manapun" << endl;
        }
        cout << "==============================================================" << endl;
    }
}
void showPertandingan_dariAtlet(List_Relasi L, adr_Atlet P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        bool ada = false;
        int count = 0;
        cout << endl << "==============================================================" << endl;
        while(R != NULL){
            if(R->next_Atlet == P){
                ada = true;
                if (count == 0 && ada){
                    cout << "|*|     Pertandingan Yang Memiliki Relasi Dengan Atlet Diatas     |*|" << endl;
                    cout << "==============================================================" << endl;
                }
                cout << "|*|   Nama Pertandingan: " << R->next_Pertandingan->info.nama << endl;
                cout << "|*|   Waktu Pertandingan: " << R->next_Pertandingan->info.waktu << endl;
                cout << "|*|   ID Pertandingan: " << R->next_Pertandingan->info.ID << endl;
                cout << "|*|   Info Relasi: " << R->info << endl;
                cout << endl;
                count++;
            }
            R = R->next_Relasi;
        }
        if (!ada){
            cout << "|*|   Atlet tidak memiliki relasi dengan Pertandingan manapun" << endl;
        }
        cout << "==============================================================" << endl;
    }
}
void showAll_RelasiPertandingan(List_Pertandingan Lp, List_Relasi Lr){
    if(Lp.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
    }else{
        adr_Pertandingan P = Lp.first;
        cout << endl << "==============================================================" << endl;
        while(P != NULL){
            cout << "|*|   Nama Pertandingan: " << P->info.nama << endl;
            cout << "|*|   Waktu Pertandingan: " << P->info.waktu << endl;
            cout << "|*|   ID Pertandingan: " << P->info.ID << endl;
            showAtlet_dariPertandingan(Lr, P);
            P = P->next_Pertandingan;
        }
    }
}
void showAll_RelasiAtlet(List_Atlet La, List_Relasi Lr){
    if(La.first == NULL){
        cout << "Data Atlet kosong" << endl;
    }else{
        adr_Atlet P = La.first;
        cout << endl << "==============================================================" << endl;
        while(P != NULL){
            cout << "|*|   Nama Atlet: " << P->info.nama << endl;
            cout << "|*|   Umur Atlet: " << P->info.umur << endl;
            cout << "|*|   ID Atlet: " << P->info.ID << endl;
            showPertandingan_dariAtlet(Lr, P);
            P = P->next_Atlet;
        }
    }
}
void hitungAtlet(List_Relasi L, adr_Pertandingan P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Pertandingan == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|*|   Total Atlet di Pertandingan " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungPertandingan(List_Relasi L, adr_Atlet P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Atlet == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|*|   Total Pertandingan dari Atlet " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungPertandinganTanpaAtlet(List_Relasi Lr, List_Pertandingan Lp){
    if(Lr.first == NULL){
        showPertandingan(Lp);
    }else{
        adr_Pertandingan P = Lp.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Pertandingan == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Pertandingan;
        }
        cout << "|*|   Total Pertandingan yang tidak memiliki Atlet: " << hitung << endl;
    }
}
void hitungAtletTanpaPertandingan(List_Relasi Lr, List_Atlet La){
    if(Lr.first == NULL){
        showAtlet(La);
    }else{
        adr_Atlet P = La.first;
        bool found;
        int hitung = 0;
        adr_Relasi R;
        while (P != NULL){
            R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Atlet == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Atlet;
        }
        cout << "|*|   Total Atlet yang tidak memiliki Pertandingan: " << hitung << endl;
    }
}
void editPertandingan(List_Relasi &L, adr_Pertandingan P, adr_Atlet Q, adr_Atlet R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    T->next_Atlet = R;
}
void editAtlet(List_Relasi &L, adr_Atlet P, adr_Pertandingan Q, adr_Pertandingan R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    T->next_Pertandingan = R;
}
void deleteRelasiAtlet(List_Relasi &L, adr_Atlet &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Atlet == P){
            deleteRelasi(L,R);
            R = L.first;
        }
        R = R->next_Relasi;
    }
}
void deleteRelasiPertandingan(List_Relasi &L, adr_Pertandingan &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Pertandingan == P){
            deleteRelasi(L, R);
            R = L.first;
        }else{
            R = R->next_Relasi;
        }
    }
}
void deleteFirstAtlet(List_Atlet &L, adr_Atlet &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.first = P->next_Atlet;
        P->next_Atlet = NULL;
        L.first->prev_Atlet = NULL;
    }
}
void deleteLastAtlet(List_Atlet &L, adr_Atlet &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.last = P->prev_Atlet;
        P->prev_Atlet = NULL;
        L.last->next_Atlet = NULL;
    }
}
void deleteAfterAtlet(List_Atlet &L, adr_Atlet &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    P->next_Atlet->prev_Atlet = P->prev_Atlet;
    P->prev_Atlet->next_Atlet = P->next_Atlet;
    P->next_Atlet = NULL;
    P->prev_Atlet = NULL;
}
void deleteFirstPertandingan(List_Pertandingan &L, adr_Pertandingan &P){
    if(L.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
        return;
    }
    if(L.first->next_Pertandingan == NULL){
        L.first = NULL;
    }else{
        L.first = P->next_Pertandingan;
        P->next_Pertandingan = NULL;
    }
}
void deleteLastPertandingan(List_Pertandingan &L, adr_Pertandingan &P){
    if(L.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
        return;
    }
    if(L.first->next_Pertandingan == NULL){
        L.first = NULL;
    }else{
        adr_Pertandingan Q = L.first;
        while (Q->next_Pertandingan != P){
            Q = Q->next_Pertandingan;
        }
        Q->next_Pertandingan = NULL;
    }
}
void deleteAfterPertandingan(List_Pertandingan &L, adr_Pertandingan &P){
    if(L.first == NULL){
        cout << "Data Pertandingan kosong" << endl;
        return;
    }
    adr_Pertandingan Q = L.first;
    while (Q->next_Pertandingan != P){
        Q = Q->next_Pertandingan;
    }
    Q->next_Pertandingan = P->next_Pertandingan;
    P->next_Pertandingan = NULL;
}
bool checkID(List_Atlet L, int ID){
    adr_Atlet P = L.first;
    while (P != NULL){
        if (P->info.ID == ID){
            return false;
        }
        P = P->next_Atlet;
    }
    return true;
}
bool checkID(List_Pertandingan L, int ID){
    adr_Pertandingan P = L.first;
    while (P != NULL){
        if (P->info.ID == ID){
            return false;
        }
        P = P->next_Pertandingan;
    }
    return true;
}
