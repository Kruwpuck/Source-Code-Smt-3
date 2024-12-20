#include "header.h"
void Menu(List_eCommerce &Lt, List_Pengirim &Lc){
    adr_Relasi R;
    adr_eCommerce P,Q;
    adr_Pengirim C,D;
    infotype_eCommerce dataP;
    infotype_Pengirim dataC;
    int pilihan;
    cout << "================================================================" << endl;
    cout << "[]                        Lion Parcel                         []" << endl;
    cout << "================================================================" << endl;
    cout << "[]           Muh. Ikhsan Fahmi     //   103032300109          []" << endl;
    cout << "[]      Muhammad Riandafa Yusaufa  //   103032300145          []" << endl;
    cout << "================================================================" << endl;
    cout << "[]   1. Data eCommerce                                        []" << endl;
    cout << "[]   2. Data Pengirim                                         []" << endl;
    cout << "[]   3. Data Relasi                                           []" << endl;
    cout << "[]   4. Exit                                                  []" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    if (pilihan == 4){
        return ;
    }
    while (pilihan < 1 || pilihan > 4){
        cout << "================================================================" << endl;
        cout << "[]                        Lion Parcel                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]           Muh. Ikhsan Fahmi     //   103032300109          []" << endl;
        cout << "[]      Muhammad Riandafa Yusaufa  //   103032300145          []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Data eCommerce                                        []" << endl;
        cout << "[]   2. Data Pengirim                                         []" << endl;
        cout << "[]   3. Data Relasi                                           []" << endl;
        cout << "[]   4. Keluar                                                []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
    }
    if (pilihan == 1){
        cout << "================================================================" << endl;
        cout << "[]                        Lion Parcel                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]           Muh. Ikhsan Fahmi     //   103032300109          []" << endl;
        cout << "[]      Muhammad Riandafa Yusaufa  //   103032300145          []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan eCommerce                                 []" << endl;
        cout << "[]   2. Menghapus eCommerce                                   []" << endl;
        cout << "[]   3. Mencari eCommerce                                     []" << endl;
        cout << "[]   4. Menampilkan eCommerce                                 []" << endl;
        cout << "[]   5. Menampilkan Pengirim dari eCommerce Tertentu          []" << endl;
        cout << "[]   6. Menampilkan Semua Relasi eCommerce                    []" << endl;
        cout << "[]   7. Menghitung Semua Relasi eCommerce                     []" << endl;
        cout << "[]   8. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            inserteCommerce(Lt); // a
        }else if(pilihan == 2){
            deleteeCommerce(Lt, P); // d
        }else if(pilihan == 3){
            findeCommerce(Lt, P); // g
        }else if(pilihan == 4){
            showeCommerce(Lt); // j
        }else if(pilihan == 5){
            showPengirimDarieCommerce(Lt); // l
        }else if(pilihan == 6){
            showAllRelasieCommerce(Lt); // m
        }else if(pilihan == 7){
            countAllRelasieCommerce(Lt); // p
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "================================================================" << endl;
        cout << "[]                        Lion Parcel                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]           Muh. Ikhsan Fahmi     //   103032300109          []" << endl;
        cout << "[]      Muhammad Riandafa Yusaufa  //   103032300145          []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan Pengirim                                  []" << endl;
        cout << "[]   2. Menghapus Pengirim                                    []" << endl;
        cout << "[]   3. Mencari Pengirim                                      []" << endl;
        cout << "[]   4. Menampilkan Pengirim                                  []" << endl;
        cout << "[]   5. Menampilkan eCommerce dari Pengirim Tertentu          []" << endl;
        cout << "[]   6. Menampilkan Semua Relasi Pengirim                     []" << endl;
        cout << "[]   7. Menghitung Relasi Pengirim Tertentu                   []" << endl;
        cout << "[]   8. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertPengirim(Lc); // b
        }else if(pilihan == 2){
            deletePengirim(Lt, Lc, D); // e
        }else if(pilihan == 3){
            findPengirim(Lc, C); // h
        }else if(pilihan == 4){
            showPengirim(Lc); // k
        }else if(pilihan == 5){
            showeCommerceDariPengirim(Lc, Lt); // o
        }else if(pilihan == 6){
            showAllRelasiPengirim(Lc, Lt); // n
        }else if(pilihan == 7){
            countRelasiDariPengirim(Lc, Lt); // q
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "================================================================" << endl;
        cout << "[]                        Lion Parcel                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]           Muh. Ikhsan Fahmi     //   103032300109          []" << endl;
        cout << "[]      Muhammad Riandafa Yusaufa  //   103032300145          []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan Relasi                                    []" << endl;
        cout << "[]   2. Menghapus Relasi                                      []" << endl;
        cout << "[]   3. Check Relasi                                          []" << endl;
        cout << "[]   4. Jumlah Pengirim Tanpa eCommerce                       []" << endl;
        cout << "[]   5. Edit Pengirim dari eCommerce                          []" << endl;
        cout << "[]   6. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertRelasi(Lt, Lc); // c
        }else if (pilihan == 2){
            findeCommerce(Lt, P);
            if (P != NULL){
                findPengirim(Lc, C);
                if (C != NULL){
                    findRelasi(P, C, R);
                }
            }
            deleteRelasi(P, R); // f
        }else if (pilihan == 3){
            findeCommerce(Lt, P);
            if (P != NULL){
                findPengirim(Lc, C);
                if (C != NULL){
                    findRelasi(P, C, R); // i
                }
            }

        }else if (pilihan == 4){
            countPengirimTanpaeCommerce(Lc, Lt); // r
        }else if (pilihan == 5){
            editPengirimDarieCommerce(Lc, Lt); // s
        }else if (pilihan == 6){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    Menu(Lt, Lc);
}
void inserteCommerce(List_eCommerce &L){
    infotype_eCommerce dataP;
    cout << "Masukkan Nama eCommerce : ";
    cin >> dataP.Nama;
    cout << "Masukkan Jenis eCommerce: ";
    cin >> dataP.Jenis;
    cout << "Masukkan Kode eCommerce  : ";
    cin >> dataP.Kode;
    
    while (!checkKode(L, dataP.Kode)){
        cout << "Kode sudah ada, masukkan Kode lain : ";
        cin >> dataP.Kode;
    }
    adr_eCommerce P = new eLc_eCommerce;
    P->info = dataP;
    P->next_eCommerce = NULL;
    P->relasi.first = NULL;
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_eCommerce = L.first;
        L.first = P;
    }
}
void insertPengirim(List_Pengirim &L){
    infotype_Pengirim dataC;
    cout << "Masukkan Nama Pengirim: ";
    cin >> dataC.Nama;
    cout << "Masukkan Barang      : ";
    cin >> dataC.Barang;
    cout << "Masukkan Alamat      : ";
    cin >> dataC.Alamat;
    cout << "Masukkan HP Pengirim : ";
    cin >> dataC.HP;
    while (!checkHP(L, dataC.HP)){
        cout << "HP sudah ada, masukkan HP lain : ";
        cin >> dataC.HP;
    }
    adr_Pengirim P = new eLc_Pengirim;
    P->info = dataC;
    P->next_Pengirim = NULL;
    P->prev_Pengirim = NULL;
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Pengirim = P;
        P->prev_Pengirim = L.last;
        L.last = P;
    }
}
void insertRelasi(List_eCommerce &Lt, List_Pengirim &Lc){
    if(Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }else if(Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
        return;
    }
    adr_eCommerce P;
    findeCommerce(Lt, P);
    if(P == NULL){
        return;
    }
    adr_Pengirim Q;
    findPengirim(Lc, Q);
    if(Q == NULL){
        return;
    }
    if (!checkRelasi(Q, P)){
        cout << "Relasi sudah ada" << endl;
        return;
    }
    adr_Relasi R = new eLc_Relasi;
    R->next_Pengirim = Q;
    insertRelasiFirst(P, R);
}
void insertRelasiFirst(adr_eCommerce &P, adr_Relasi &R){
    if (P->relasi.first == NULL){
        R->next_Relasi = NULL;
        P->relasi.first = R;
    }else{
        R->next_Relasi = P->relasi.first;
        P->relasi.first = R;
    }
}
void deleteeCommerce(List_eCommerce &Lt, adr_eCommerce &P){
    if(Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
        return;
    }
    findeCommerce(Lt, P);
    if (P == NULL){
        return;
    }
    if (P->relasi.first != NULL){
        adr_Relasi R;
        R = P->relasi.first;
        while (R != NULL){
            deleteRelasi(P, R);
            R = P->relasi.first;
        }
    }
    if (Lt.first->next_eCommerce == NULL){
        Lt.first = NULL;
    }else if(P == Lt.first){
        deleteFirsteCommerce(Lt, P);
    }else {
        deleteAfterLasteCommerce(Lt, P);
    }
}
void deleteFirsteCommerce(List_eCommerce &L, adr_eCommerce &P){
    L.first = P->next_eCommerce;
    P->next_eCommerce = NULL;
}
void deleteAfterLasteCommerce(List_eCommerce &L, adr_eCommerce &P){
    adr_eCommerce Q = L.first;
    while (Q->next_eCommerce != P){
        Q = Q->next_eCommerce;
    }
    if (P->next_eCommerce == NULL){
        Q->next_eCommerce = P->next_eCommerce;
    }
    Q->next_eCommerce = NULL;
}
void deletePengirim(List_eCommerce &Lt, List_Pengirim &Lc, adr_Pengirim &P){
    if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
        return;
    }
    findPengirim(Lc, P);
    if (P == NULL){
        return;
    }
    if (Lt.first != NULL){
        adr_eCommerce Q = Lt.first;
        while (Q != NULL){
            if (Q->relasi.first != NULL){
                adr_Relasi R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Pengirim == P){
                        deleteRelasi(Q, R);
                        R = Q->relasi.first;
                    }else{
                        R = R->next_Relasi;
                    }
                }
            }
            Q = Q->next_eCommerce;
        }
    }
    if (Lc.first->next_Pengirim == NULL){
        Lc.first = NULL;
    }else if(P == Lc.first){
        deleteFirstPengirim(Lc, P);
    }else if (P == Lc.last){
        deleteLastPengirim(Lc, P);
    }else{
        deleteAfterPengirim(Lc, P);
    }
}
void deleteFirstPengirim(List_Pengirim &L, adr_Pengirim &P){
    L.first = P->next_Pengirim;
    P->next_Pengirim = NULL;
    P->prev_Pengirim = NULL;
}
void deleteLastPengirim(List_Pengirim &L, adr_Pengirim &P){
    L.last = P->prev_Pengirim;
    P->prev_Pengirim = NULL;
    L.last->next_Pengirim = NULL;
}
void deleteAfterPengirim(List_Pengirim &L, adr_Pengirim &P){
    P->next_Pengirim->prev_Pengirim = P->prev_Pengirim;
    P->prev_Pengirim->next_Pengirim = P->next_Pengirim;
    P->next_Pengirim = NULL;
    P->prev_Pengirim = NULL;
}
void deleteRelasi(adr_eCommerce &Q ,adr_Relasi &P){
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
    cout << "================================================================" << endl;
}
void findeCommerce(List_eCommerce L, adr_eCommerce &P){
    int Kode;
    cout << "Masukkan Kode eCommerce yang dicari : ";
    cin >> Kode;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.Kode == Kode){
            cout << "Data eCommerce ditemukan" << endl;
            cout << "Nama eCommerce    : " << P->info.Nama << endl;
            cout << "Kode eCommerce      : " << P->info.Kode << endl;
            cout << "Jenis eCommerce: " << P->info.Jenis << endl;
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_eCommerce;
    }
    cout << "Data eCommerce tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findPengirim(List_Pengirim L, adr_Pengirim &P){
    int HP;
    cout << "Masukkan HP Pengirim yang dicari : ";
    cin >> HP;
    P = L.first;
    while(P != NULL){
        if(P->info.HP == HP){
            cout << "Data Pengirim ditemukan" << endl;
            cout << "Nama Pengirim: " << P->info.Nama << endl;
            cout << "HP Pengirim : " << P->info.HP << endl;
            cout << "Barang        : " << P->info.Barang << endl;
            cout << "Alamat        : " << P->info.Alamat << endl;
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_Pengirim;
    }
    cout << "Data Pengirim tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findRelasi(adr_eCommerce P, adr_Pengirim Q, adr_Relasi &R){
    if (P->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        R = P->relasi.first;
        while(R != NULL){
            if(R->next_Pengirim == Q){
                cout << "Data Relasi ditemukan" << endl;
                cout << "Nama eCommerce     : " << P->info.Nama << endl;
                cout << "Kode eCommerce       : " << P->info.Kode << endl;
                cout << "Jenis eCommerce : " << P->info.Jenis << endl;
                cout << "================================================================" << endl;
                cout << "Nama Pengirim: " << Q->info.Nama << endl;
                cout << "HP Pengirim : " << Q->info.HP << endl;
                cout << "Barang        : " << Q->info.Barang << endl;
                cout << "Alamat        : " << Q->info.Alamat << endl;
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
void showeCommerce(List_eCommerce L){
    adr_eCommerce P = L.first;
    if(P == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        cout << "Data eCommerce : " << endl;
        while(P != NULL){
            cout << "Nama eCommerce    : " << P->info.Nama << endl;
            cout << "Kode eCommerce      : " << P->info.Kode << endl;
            cout << "Jenis eCommerce: " << P->info.Jenis << endl;
            cout << "================================================================" << endl;
            P = P->next_eCommerce;
        }
    }
}
void showPengirim(List_Pengirim L){
    adr_Pengirim P = L.first;
    if(P == NULL){
        cout << "Data Pengirim kosong" << endl;
        cout << "================================================================" << endl;
    }else{
        cout << "Data Pengirim : " << endl;
        while(P != NULL){
            cout << "Nama Pengirim: " << P->info.Nama << endl;
            cout << "HP Pengirim : " << P->info.HP << endl;
            cout << "Barang        : " << P->info.Barang << endl;
            cout << "Alamat        : " << P->info.Alamat << endl;
            cout << "================================================================" << endl;
            P = P->next_Pengirim;
        }
    }
}
void showPengirimDarieCommerce(List_eCommerce Lt){
    if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_eCommerce P;
        findeCommerce(Lt, P);
        if (P == NULL){
            return;
        }
        if (P->relasi.first == NULL){
            cout << "eCommerce Ini Tidak Memiliki Relasi" << endl;
        }else{
            adr_Relasi R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Pengirim: " << R->next_Pengirim->info.Nama << endl;
                cout << "HP Pengirim : " << R->next_Pengirim->info.HP << endl;
                cout << "Barang        : " << R->next_Pengirim->info.Barang << endl;
                cout << "Alamat        : " << R->next_Pengirim->info.Alamat << endl;
                cout << "================================================================" << endl;
                R = R->next_Relasi;
            }
        }
    }
}
void showAllRelasieCommerce(List_eCommerce Lt){
    if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_eCommerce P = Lt.first;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama eCommerce    : " << P->info.Nama << endl;
            cout << "Kode eCommerce      : " << P->info.Kode << endl;
            cout << "Jenis eCommerce: " << P->info.Jenis << endl;
            cout << "================================================================" << endl;
            R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Pengirim: " << R->next_Pengirim->info.Nama << endl;
                cout << "HP Pengirim : " << R->next_Pengirim->info.HP << endl;
                cout << "Barang        : " << R->next_Pengirim->info.Barang << endl;
                cout << "Alamat        : " << R->next_Pengirim->info.Alamat << endl;
                cout << "================================================================" << endl;
                R = R->next_Relasi;
                ada = true;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_eCommerce;
        }
    }
}
void showAllRelasiPengirim(List_Pengirim Lc, List_eCommerce Lt){
    if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
    }else if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_Pengirim P = Lc.first;
        adr_Relasi R;
        adr_eCommerce Q;
        bool ada;
        while (P != NULL){
            ada = false;
            cout << "Nama Pengirim: " << P->info.Nama << endl;
            cout << "HP Pengirim : " << P->info.HP << endl;
            cout << "Barang        : " << P->info.Barang << endl;
            cout << "Alamat        : " << P->info.Alamat << endl;
            cout << "================================================================" << endl;
            Q = Lt.first;
            while (Q != NULL){
                R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Pengirim == P){
                        cout << "Nama eCommerce    : " << Q->info.Nama << endl;
                        cout << "Kode eCommerce      : " << Q->info.Kode << endl;
                        cout << "Jenis eCommerce: " << Q->info.Jenis << endl;
                        cout << "================================================================" << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_eCommerce;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Pengirim;
        }
    }
}
void showeCommerceDariPengirim(List_Pengirim Lc, List_eCommerce Lt){
    if (Lc.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
    }else{
        adr_Pengirim P;
        adr_Relasi R;
        findPengirim(Lc, P);
        if (P == NULL){
            return;
        }
        adr_eCommerce Q = Lt.first;
        bool ada = false;
        while (Q != NULL){
            R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Pengirim == P){
                    cout << "Nama eCommerce    : " << Q->info.Nama << endl;
                    cout << "Kode eCommerce      : " << Q->info.Kode << endl;
                    cout << "Jenis eCommerce: " << Q->info.Jenis << endl;
                    cout << "================================================================" << endl;
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_eCommerce;
        }
        if (!ada){
            cout << "Data Relasi tidak ditemukan" << endl;
        }
    }
}
void countAllRelasieCommerce(List_eCommerce Lt){
    if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else{
        adr_eCommerce P = Lt.first;
        int count;
        while (P != NULL){
            adr_Relasi R = P->relasi.first;
            count = 0;
            while (R != NULL){
                count++;
                R = R->next_Relasi;
            }
            P = P->next_eCommerce;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countRelasiDariPengirim(List_Pengirim Lc, List_eCommerce Lt){
    if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
    }else if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else {
        adr_Pengirim P;
        findPengirim(Lc, P);
        if (P == NULL){
            return;
        }
        adr_eCommerce Q = Lt.first;
        int count = 0;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Pengirim == P){
                    count++;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_eCommerce;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countPengirimTanpaeCommerce(List_Pengirim Lc, List_eCommerce Lt){
    if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
        return;
    }
    adr_Pengirim P = Lc.first;
    int count = 0;
    bool ada;
    while (P != NULL){
        adr_eCommerce Q = Lt.first;
        ada = false;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Pengirim == P){
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_eCommerce;
        }
        if (!ada){
            count++;
        }
        P = P->next_Pengirim;
    }
    cout << "Jumlah Pengirim tanpa eCommerce : " << count << endl;
    cout << "================================================================" << endl;
}
void editPengirimDarieCommerce(List_Pengirim &Lc, List_eCommerce &Lt){
    if (Lt.first == NULL){
        cout << "Data eCommerce kosong" << endl;
    }else if (Lc.first == NULL){
        cout << "Data Pengirim kosong" << endl;
    }else{
        adr_eCommerce P;
        findeCommerce(Lt, P);
        if (P == NULL){
            return;
        }
        adr_Pengirim Q,S;
        findPengirim(Lc, Q);
        if (Q == NULL){
            return;
        }
        adr_Relasi R,T;
        findRelasi(P, Q, R);
        if (R == NULL){
            return;
        }
        cout << "Masukkan HP Pengirim yang baru : "<< endl;
        findPengirim(Lc, S);
        findRelasi(P, S, T);
        if (T != NULL){
            cout << "Relasi sudah ada" << endl;
            return;
        }
        R->next_Pengirim = S;
        cout << "Data Pengirim berhasil diubah" << endl;
    }
}

bool checkHP(List_Pengirim L, int HP){
    adr_Pengirim P = L.first;
    while (P != NULL){
        if (P->info.HP == HP){
            return false;
        }
        P = P->next_Pengirim;
    }
    return true;
}
bool checkKode(List_eCommerce L, int Kode){
    adr_eCommerce P = L.first;
    while (P != NULL){
        if (P->info.Kode == Kode){
            return false;
        }
        P = P->next_eCommerce;
    }
    return true;
}
bool checkRelasi(adr_Pengirim P, adr_eCommerce Q){
    adr_Relasi R = Q->relasi.first;
    while (R != NULL){
        if (R->next_Pengirim == P){
            return false;
        }
        R = R->next_Relasi;
    }
    return true;
}
