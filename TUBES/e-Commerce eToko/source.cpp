#include "header.h"
void menu(List_Relasi &Lr, List_eCommerce &Lp, List_Toko &Lc){
    adr_Relasi R;
    adr_eCommerce P,Q;
    adr_Toko C,D;
    infotype_Relasi dataR;
    infotype_eCommerce dataP;
    infotype_Toko dataC;
    int pilihan;
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Sistem Informasi Manajemen Toko dan eCommerce     |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Tasya Amanda Bahri  //   103032330053             |" << endl;
    cout << "|          Annisah Akram     //   103032300066             |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|   1. Data eCommerce                                      |" << endl;
    cout << "|   2. Data Toko                                           |" << endl;
    cout << "|   3. Data Relasi                                         |" << endl;
    cout << "|   4. Exit                                                |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        INPUT INVALID                     |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Tasya Amanda Bahri  //   103032330053             |" << endl;
        cout << "|          Annisah Akram     //   103032300066             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Data eCommerce                                      |" << endl;
        cout << "|   2. Data Toko                                           |" << endl;
        cout << "|   3. Data Relasi                                         |" << endl;
        cout << "|   4. Keluar                                              |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    if (pilihan == 1){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU eCommerce                    |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Tasya Amanda Bahri  //   103032330053             |" << endl;
        cout << "|          Annisah Akram     //   103032300066             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Last eCommerce                          |" << endl;
        cout << "|   2. Menghapus First eCommerce                           |" << endl;
        cout << "|   3. Mencari eCommerce                                   |" << endl;
        cout << "|   4. Menampilkan eCommerce                               |" << endl;
        cout << "|   5. Total eCommerce Tanpa Toko                          |" << endl;
        cout << "|   6. Total Toko Dari eCommerce Tertentu                  |" << endl;
        cout << "|   7. Menampilkan Toko dari eCommerce Tertentu            |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama eCommerce: ";
            cin >> dataP.nama;
            cout << "Masukkan Platform eCommerce: ";
            cin >> dataP.platform;
            cout << "Masukkan ID eCommerce: ";
            cin >> dataP.ID;
            while (!checkID(Lp, dataP.ID)){
                cout << "ID sudah ada" << endl;
                cin >> dataP.ID;
            }
            P = new elm_eCommerce;
            P->info = dataP;
            P->next_eCommerce = NULL;
            inserteCommerce(Lp, P);
            cout << "Data eCommerce berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            P = NULL;
            deleteeCommerce(Lp, P);
            if (P != NULL){
                deleteRelasieCommerce(Lr, P);
                cout << "Elemen List eCommerce "<< P->info.nama << " telah berhasil dihapus" << endl;
                delete P;
            }
        }else if(pilihan == 3){
            findeCommerce(Lp, P);
        }else if(pilihan == 4){
            showeCommerce(Lp);
        }else if(pilihan == 5){
            hitungTokoTanpaeCommerce(Lr, Lc);
        }else if(pilihan == 6){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            hitungToko(Lr, P);
        }else if(pilihan == 7){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            showToko_darieCommerce(Lr, P);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                         MENU Toko                        |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Tasya Amanda Bahri  //   103032330053             |" << endl;
        cout << "|          Annisah Akram     //   103032300066             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan First Toko                              |" << endl;
        cout << "|   2. Menghapus Last Toko                                 |" << endl;
        cout << "|   3. Mencari Toko                                        |" << endl;
        cout << "|   4. Menampilkan Toko                                    |" << endl;
        cout << "|   5. Total Toko Tanpa eCommerce                          |" << endl;
        cout << "|   6. Total eCommerce Dari Toko Tertentu                  |" << endl;
        cout << "|   7. Menampilkan eCommerce dari Toko Tertentu            |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Toko: ";
            cin >> dataC.nama;
            cout << "Masukkan Lokasi Toko: ";
            cin >> dataC.lokasi;
            cout << "Masukkan ID Toko: ";
            cin >> dataC.ID;
            while (!checkID(Lc, dataC.ID)){
                cout << "ID sudah ada" << endl;
                cin >> dataC.ID;
            }
            C = new elm_Toko;
            C->info = dataC;
            C->next_Toko = NULL;
            C->prev_Toko = NULL;
            insertToko(Lc, C);
            cout << "Data Toko berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteToko(Lc, C);
            if (C != NULL){
                deleteRelasiToko(Lr, C);
                cout << "Toko dengan nama: " << C->info.nama  << " telah berhasil dihapus" << endl;
                delete C;
            }
        }else if(pilihan == 3){
            findToko(Lc, C);
        }else if(pilihan == 4){
            showToko(Lc);
        }else if(pilihan == 5){
            hitungTokoTanpaeCommerce(Lr, Lc);
        }else if(pilihan == 6){
            findToko(Lc, C);
            while (C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            hitungeCommerce(Lr, C);
        }else if(pilihan == 7){
            findToko(Lc, C);
            showeCommerce_dariToko(Lr, C);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU RELASI                       |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Tasya Amanda Bahri  //   103032330053             |" << endl;
        cout << "|          Annisah Akram     //   103032300066             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan Relasi                                  |" << endl;
        cout << "|   2. Menghapus Relasi                                    |" << endl;
        cout << "|   3. Check Relasi                                        |" << endl;
        cout << "|   4. Menampilkan Toko & Relasinya                        |" << endl;
        cout << "|   5. Menampilkan eCommerce & Relasinya                   |" << endl;
        cout << "|   6. Edit Relasi Dari eCommerce                          |" << endl;
        cout << "|   7. Edit Relasi Dari Toko                               |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            findToko(Lc, C);
            while ( C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            cout << "Masukkan Info Relasi: ";
            cin >> dataR;
            R = new elm_Relasi;
            R->info = dataR;
            R->next_eCommerce = P;
            R->next_Toko = C;
            R->next_Relasi = NULL;
            insertRelasi(Lr, R);
            cout << "Relasi berhasil ditambahkan" << endl;
        }else if (pilihan == 2){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            findToko(Lc, C);
            while ( C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R == NULL){
                cout << "Relasi tidak ditemukan" << endl;
            }else{}
            deleteRelasi(Lr, R);
            delete R;
            cout << "Relasi berhasil dihapus" << endl;
        }else if (pilihan == 3){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            findToko(Lc, C);
            while ( C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            checkRelasi(Lr, C, P, R);
        }else if (pilihan == 4){
            showAll_RelasieCommerce(Lp, Lr);
        }else if (pilihan == 5){
            showAll_RelasiToko(Lc, Lr);
        }else if (pilihan == 6){
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            findToko(Lc, C);
            while ( C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findToko(Lc, D);
                editeCommerce(Lr, P, C, D);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 7){
            findToko(Lc, C);
            while ( C == NULL){
                cout << "Data Toko tidak ditemukan" << endl;
                findToko(Lc, C);
            }
            findeCommerce(Lp, P);
            while (P == NULL){
                cout << "Data eCommerce tidak ditemukan" << endl;
                findeCommerce(Lp, P);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findeCommerce(Lp, Q);
                editToko(Lr, C, P, Q);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    menu(Lr, Lp, Lc);
}
void inserteCommerce(List_eCommerce &L, adr_eCommerce P){
    if(L.first == NULL){
        L.first = P;
    }else{
        adr_eCommerce Q = L.first;
        while(Q->next_eCommerce != NULL){
            Q = Q->next_eCommerce;
        }
        Q->next_eCommerce = P;
    }
}
void insertToko(List_Toko &L, adr_Toko P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.first->prev_Toko = P;
        P->next_Toko = L.first;
        L.first = P;
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
void deleteeCommerce(List_eCommerce &L, adr_eCommerce &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    findeCommerce(L, P);
    while (P == NULL){
        cout << "Data eCommerce tidak ditemukan" << endl;
        findeCommerce(L, P);
    }
    if(P == L.first){
        deleteFirsteCommerce(L, P);
    }else if (P->next_eCommerce == NULL){
        deleteLasteCommerce(L, P);
    }else{
        deleteAftereCommerce(L, P);
    }
}
void deleteToko(List_Toko &L, adr_Toko &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    findToko(L, P);
    if (P == NULL){
        cout << "Data Toko tidak ditemukan" << endl;
        return;
    }
    if (P == L.first){
        deleteFirstToko(L, P);
    }else if (P == L.last){
        deleteLastToko(L, P);
    }else{
        deleteAfterToko(L, P);
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
void findeCommerce(List_eCommerce L, adr_eCommerce &P){
    if (L.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }else{
        int ID;
        cout << "Masukkan ID eCommerce: ";
        cin >> ID;
        P = L.first;
        while(P != NULL){
            if(P->info.ID == ID){
                cout << "Data eCommerce ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama eCommerce: " << P->info.nama << endl;
                cout << "|   Platform eCommerce: " << P->info.platform << endl;
                cout << "|   ID eCommerce: " << P->info.ID << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_eCommerce;
            }
        }
    }
}
void findToko(List_Toko L, adr_Toko &P){
    if (L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }else{
        int ID;
        cout << "Masukkan ID Toko: ";
        cin >> ID;
        P = L.first;
        while(P != NULL){
            if(P->info.ID == ID){
                cout << "Data Toko ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama Toko: " << P->info.nama << endl;
                cout << "|   Lokasi Toko: " << P->info.lokasi << endl;
                cout << "|   ID Toko: " << P->info.ID << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_Toko;
            }
        }
    }
}
void checkRelasi(List_Relasi L, adr_Toko P, adr_eCommerce Q, adr_Relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_Toko == P && R->next_eCommerce == Q){
            cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   Relasi ditemukan" << endl;
            cout << "|   Info Relasi: " << R->info << endl;
            cout << endl << "------------------------------------------------------------" << endl;
            return;
        }else{
            R = R->next_Relasi;
        }
    }
    cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   Relasi Tidak Ditemukan" << endl;
    cout << endl << "------------------------------------------------------------" << endl;
}
void showeCommerce(List_eCommerce L){
    if(L.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_eCommerce P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama eCommerce: " << P->info.nama << endl;
            cout << "|   Platform eCommerce: " << P->info.platform << endl;
            cout << "|   ID eCommerce: " << P->info.ID << endl;
            cout << endl;
            P = P->next_eCommerce;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void showToko(List_Toko L){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Toko P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama Toko: " << P->info.nama << endl;
            cout << "|   Lokasi Toko: " << P->info.lokasi << endl;
            cout << "|   ID Toko: " << P->info.ID << endl;
            cout << endl;
            P = P->next_Toko;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void showToko_darieCommerce(List_Relasi L, adr_eCommerce P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        bool ada = false;
        int count = 0;
        cout << endl << "------------------------------------------------------------" << endl;
        while(R != NULL){
            if(R->next_eCommerce == P){
                ada = true;
                if (count == 0 && ada){
                    cout << "|     Toko Yang Memiliki Relasi Dengan eCommerce Diatas     |" << endl;
                    cout << "------------------------------------------------------------" << endl;
                }
                cout << "|   Nama Toko: " << R->next_Toko->info.nama << endl;
                cout << "|   Lokasi Toko: " << R->next_Toko->info.lokasi << endl;
                cout << "|   ID Toko: " << R->next_Toko->info.ID << endl;
                cout << "|   Info Relasi: " << R->info << endl;
                cout << endl;
                count++;
            }
            R = R->next_Relasi;
        }
        if (!ada){
            cout << "|   eCommerce tidak memiliki relasi dengan Toko manapun" << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void showeCommerce_dariToko(List_Relasi L, adr_Toko P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        bool ada = false;
        int count = 0;
        cout << endl << "------------------------------------------------------------" << endl;
        while(R != NULL){
            if(R->next_Toko == P){
                ada = true;
                if (count == 0 && ada){
                    cout << "|     eCommerce Yang Memiliki Relasi Dengan Toko Diatas     |" << endl;
                    cout << "------------------------------------------------------------" << endl;
                }
                cout << "|   Nama eCommerce: " << R->next_eCommerce->info.nama << endl;
                cout << "|   Platform eCommerce: " << R->next_eCommerce->info.platform << endl;
                cout << "|   ID eCommerce: " << R->next_eCommerce->info.ID << endl;
                cout << "|   Info Relasi: " << R->info << endl;
                cout << endl;
                count++;
            }
            R = R->next_Relasi;
        }
        if (!ada){
            cout << "|   Toko tidak memiliki relasi dengan eCommerce manapun" << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void showAll_RelasieCommerce(List_eCommerce Lp, List_Relasi Lr){
    if(Lp.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_eCommerce P = Lp.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama eCommerce: " << P->info.nama << endl;
            cout << "|   Platform eCommerce: " << P->info.platform << endl;
            cout << "|   ID eCommerce: " << P->info.ID << endl;
            showToko_darieCommerce(Lr, P);
            P = P->next_eCommerce;
        }
    }
}
void showAll_RelasiToko(List_Toko Lc, List_Relasi Lr){
    if(Lc.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Toko P = Lc.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama Toko: " << P->info.nama << endl;
            cout << "|   Lokasi Toko: " << P->info.lokasi << endl;
            cout << "|   ID Toko: " << P->info.ID << endl;
            showeCommerce_dariToko(Lr, P);
            P = P->next_Toko;
        }
    }
}
void hitungToko(List_Relasi L, adr_eCommerce P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_eCommerce == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|   Total Toko di eCommerce " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungeCommerce(List_Relasi L, adr_Toko P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Toko == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "|   Total eCommerce dari Toko " << P->info.nama << ": " << hitung << endl;
    }
}
void hitungeCommerceTanpaToko(List_Relasi Lr, List_eCommerce Lp){
    if(Lr.first == NULL){
        showeCommerce(Lp);
    }else{
        adr_eCommerce P = Lp.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_eCommerce == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_eCommerce;
        }
        cout << "|   Total eCommerce yang tidak memiliki Toko: " << hitung << endl;
    }
}
void hitungTokoTanpaeCommerce(List_Relasi Lr, List_Toko Lc){
    if(Lr.first == NULL){
        showToko(Lc);
    }else{
        adr_Toko P = Lc.first;
        bool found;
        int hitung = 0;
        adr_Relasi R;
        while (P != NULL){
            R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Toko == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Toko;
        }
        cout << "|   Total Toko yang tidak memiliki eCommerce: " << hitung << endl;
    }
}
void editeCommerce(List_Relasi &L, adr_eCommerce P, adr_Toko Q, adr_Toko R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    T->next_Toko = R;
}
void editToko(List_Relasi &L, adr_Toko P, adr_eCommerce Q, adr_eCommerce R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    T->next_eCommerce = R;
}
void deleteRelasiToko(List_Relasi &L, adr_Toko &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Toko == P){
            deleteRelasi(L,R);
            R = L.first;
        }
        R = R->next_Relasi;
    }
}
void deleteRelasieCommerce(List_Relasi &L, adr_eCommerce &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_eCommerce == P){
            deleteRelasi(L, R);
            R = L.first;
        }else{
            R = R->next_Relasi;
        }
    }
}
void deleteFirstToko(List_Toko &L, adr_Toko &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.first = P->next_Toko;
        P->next_Toko = NULL;
        L.first->prev_Toko = NULL;
    }
}
void deleteLastToko(List_Toko &L, adr_Toko &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.last = P->prev_Toko;
        P->prev_Toko = NULL;
        L.last->next_Toko = NULL;
    }
}
void deleteAfterToko(List_Toko &L, adr_Toko &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    P->next_Toko->prev_Toko = P->prev_Toko;
    P->prev_Toko->next_Toko = P->next_Toko;
    P->next_Toko = NULL;
    P->prev_Toko = NULL;
}
void deleteFirsteCommerce(List_eCommerce &L, adr_eCommerce &P){
    if(L.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }
    if(L.first->next_eCommerce == NULL){
        L.first = NULL;
    }else{
        L.first = P->next_eCommerce;
        P->next_eCommerce = NULL;
    }
}
void deleteLasteCommerce(List_eCommerce &L, adr_eCommerce &P){
    if(L.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }
    if(L.first->next_eCommerce == NULL){
        L.first = P;
        L.first = NULL;
    }else{
        adr_eCommerce Q;
        P = L.first;
        while (P->next_eCommerce != NULL){
            Q = P;
            P = P->next_eCommerce;
        }
        Q->next_eCommerce = NULL;
        Q->next_eCommerce = P;
    }
}
void deleteAftereCommerce(List_eCommerce &L, adr_eCommerce &P){
    if(L.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }
    adr_eCommerce Q = L.first;
    while (Q->next_eCommerce != P){
        Q = Q->next_eCommerce;
    }
    Q->next_eCommerce = P->next_eCommerce;
    P->next_eCommerce = NULL;
}
bool checkID(List_Toko L, int ID){
    adr_Toko P = L.first;
    while (P != NULL){
        if (P->info.ID == ID){
            return false;
        }
        P = P->next_Toko;
    }
    return true;
}
bool checkID(List_eCommerce L, int ID){
    adr_eCommerce P = L.first;
    while (P != NULL){
        if (P->info.ID == ID){
            return false;
        }
        P = P->next_eCommerce;
    }
    return true;
}
