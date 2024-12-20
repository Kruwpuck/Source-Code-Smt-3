#include "header.h"
void Menu(List_Toko &Lt, List_Customer &Lc){
    adr_Relasi R;
    adr_Toko P,Q;
    adr_Customer C,D;
    infotype_Toko dataP;
    infotype_Customer dataC;
    int pilihan;
    cout << "================================================================" << endl;
    cout << "[]                   Bakhir Zakaria Mart                      []" << endl;
    cout << "================================================================" << endl;
    cout << "[]         Aidil Muhammad Bakir       //   103032300183       []" << endl;
    cout << "[]          Yafi Zakaria RIfqi        //   103032300082       []" << endl;
    cout << "================================================================" << endl;
    cout << "[]   1. Data Toko                                             []" << endl;
    cout << "[]   2. Data Customer                                         []" << endl;
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
        cout << "[]                        INPUT INVALID                       []" << endl;
        cout << "================================================================" << endl;
        cout << "[]         Aidil Muhammad Bakir       //   103032300183       []" << endl;
        cout << "[]          Yafi Zakaria RIfqi        //   103032300082       []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Data Toko                                             []" << endl;
        cout << "[]   2. Data Customer                                         []" << endl;
        cout << "[]   3. Data Relasi                                           []" << endl;
        cout << "[]   4. Keluar                                                []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
    }
    if (pilihan == 1){
        cout << "================================================================" << endl;
        cout << "[]                          MENU Toko                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]         Aidil Muhammad Bakir       //   103032300183       []" << endl;
        cout << "[]          Yafi Zakaria RIfqi        //   103032300082       []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan Toko                                      []" << endl;
        cout << "[]   2. Menghapus Toko                                        []" << endl;
        cout << "[]   3. Mencari Toko                                          []" << endl;
        cout << "[]   4. Menampilkan Toko                                      []" << endl;
        cout << "[]   5. Menampilkan Customer dari Toko Tertentu               []" << endl;
        cout << "[]   6. Menampilkan Semua Relasi Toko                         []" << endl;
        cout << "[]   7. Menghitung Semua Relasi Toko                          []" << endl;
        cout << "[]   8. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            insertToko(Lt); // a
        }else if(pilihan == 2){
            deleteToko(Lt, P); // d
        }else if(pilihan == 3){
            findToko(Lt, P); // g
        }else if(pilihan == 4){
            showToko(Lt); // j
        }else if(pilihan == 5){
            showCustomerDariToko(Lt); // l
        }else if(pilihan == 6){
            showAllRelasiToko(Lt); // m
        }else if(pilihan == 7){
            countAllRelasiToko(Lt); // p
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "================================================================" << endl;
        cout << "[]                         MENU Customer                      []" << endl;
        cout << "================================================================" << endl;
        cout << "[]       Aidil Muhammad Bakir    //   103032300183            []" << endl;
        cout << "[]          Yafi Zakaria RIfqi        //   103032300082       []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan Customer                                  []" << endl;
        cout << "[]   2. Menghapus Customer                                    []" << endl;
        cout << "[]   3. Mencari Customer                                      []" << endl;
        cout << "[]   4. Menampilkan Customer                                  []" << endl;
        cout << "[]   5. Menampilkan Toko dari Customer Tertentu               []" << endl;
        cout << "[]   6. Menampilkan Semua Relasi Customer                     []" << endl;
        cout << "[]   7. Menghitung Relasi Customer Tertentu                   []" << endl;
        cout << "[]   8. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertCustomer(Lc); // b
        }else if(pilihan == 2){
            deleteCustomer(Lt, Lc, D); // e
        }else if(pilihan == 3){
            findCustomer(Lc, C); // h
        }else if(pilihan == 4){
            showCustomer(Lc); // k
        }else if(pilihan == 5){
            showTokoDariCustomer(Lc, Lt); // o
        }else if(pilihan == 6){
            showAllRelasiCustomer(Lc, Lt); // n
        }else if(pilihan == 7){
            countRelasiDariCustomer(Lc, Lt); // q
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "================================================================" << endl;
        cout << "[]                        MENU RELASI                         []" << endl;
        cout << "================================================================" << endl;
        cout << "[]       Aidil Muhammad Bakir    //   103032300183            []" << endl;
        cout << "[]          Yafi Zakaria RIfqi        //   103032300082       []" << endl;
        cout << "================================================================" << endl;
        cout << "[]   1. Menambahkan Relasi                                    []" << endl;
        cout << "[]   2. Menghapus Relasi                                      []" << endl;
        cout << "[]   3. Check Relasi                                          []" << endl;
        cout << "[]   4. Jumlah Customer Tanpa Toko                            []" << endl;
        cout << "[]   5. Edit Customer dari Toko                               []" << endl;
        cout << "[]   6. Kembali                                               []" << endl;
        cout << "================================================================" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            insertRelasi(Lt, Lc); // c
        }else if (pilihan == 2){
            findToko(Lt, P);
            if (P != NULL){
                findCustomer(Lc, C);
                if (C != NULL){
                    findRelasi(P, C, R);
                }
            }
            deleteRelasi(P, R); // f
        }else if (pilihan == 3){
            findToko(Lt, P);
            if (P != NULL){
                findCustomer(Lc, C);
                if (C != NULL){
                    findRelasi(P, C, R); // i
                }
            }

        }else if (pilihan == 4){
            countCustomerTanpaToko(Lc, Lt); // r
        }else if (pilihan == 5){
            editCustomerDariToko(Lc, Lt); // s
        }else if (pilihan == 6){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    Menu(Lt, Lc);
}
void insertToko(List_Toko &L){
    infotype_Toko dataP;
    cout << "Masukkan Nama Toko : ";
    cin >> dataP.nama;
    cout << "Masukkan Kategori Toko: ";
    cin >> dataP.kategori;
    cout << "Masukkan ID Toko  : ";
    cin >> dataP.ID;
    while (!checkID(L, dataP.ID)){
        cout << "ID sudah ada, masukkan ID lain : ";
        cin >> dataP.ID;
    }
    adr_Toko P = new eLc_Toko;
    P->info = dataP;
    P->next_Toko = NULL;
    P->relasi.first = NULL;
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Toko = L.first;
        L.first = P;
    }
}
void insertCustomer(List_Customer &L){
    infotype_Customer dataC;
    cout << "Masukkan Nama Customer: ";
    cin >> dataC.nama;
    cout << "Masukkan Kelas      : ";
    cin >> dataC.kelas;
    cout << "Masukkan NIK Customer : ";
    cin >> dataC.NIK;
    while (!checkNIK(L, dataC.NIK)){
        cout << "NIK sudah ada, masukkan NIK lain : ";
        cin >> dataC.NIK;
    }
    adr_Customer P = new eLc_Customer;
    P->info = dataC;
    P->next_Customer = NULL;
    P->prev_Customer = NULL;
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Customer = P;
        P->prev_Customer = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Toko &Lt, List_Customer &Lc){
    if(Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }else if(Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
        return;
    }
    adr_Toko P;
    findToko(Lt, P);
    if(P == NULL){
        return;
    }
    adr_Customer Q;
    findCustomer(Lc, Q);
    if(Q == NULL){
        return;
    }
    if (!checkRelasi(Q, P)){
        cout << "Relasi sudah ada" << endl;
        return;
    }
    adr_Relasi R = new eLc_Relasi;
    R->next_Customer = Q;
    insertRelasiFirst(P, R);
}
void insertRelasiFirst(adr_Toko &P, adr_Relasi &R){
    if (P->relasi.first == NULL){
        R->next_Relasi = NULL;
        P->relasi.first = R;
    }else{
        R->next_Relasi = P->relasi.first;
        P->relasi.first = R;
    }
}
void deleteToko(List_Toko &Lt, adr_Toko &P){
    if(Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    findToko(Lt, P);
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
    if (Lt.first->next_Toko == NULL){
        Lt.first = NULL;
    }else if(P == Lt.first){
        deleteFirstToko(Lt, P);
    }else {
        deleteAfterLastToko(Lt, P);
    }
}
void deleteFirstToko(List_Toko &L, adr_Toko &P){
    L.first = P->next_Toko;
    P->next_Toko = NULL;
}
void deleteAfterLastToko(List_Toko &L, adr_Toko &P){
    adr_Toko Q = L.first;
    while (Q->next_Toko != P){
        Q = Q->next_Toko;
    }
    if (P->next_Toko == NULL){
        Q->next_Toko = P->next_Toko;
    }
    Q->next_Toko = NULL;
}
void deleteCustomer(List_Toko &Lt, List_Customer &Lc, adr_Customer &P){
    if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
        return;
    }
    findCustomer(Lc, P);
    if (P == NULL){
        return;
    }
    if (Lt.first != NULL){
        adr_Toko Q = Lt.first;
        while (Q != NULL){
            if (Q->relasi.first != NULL){
                adr_Relasi R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Customer == P){
                        deleteRelasi(Q, R);
                        R = Q->relasi.first;
                    }else{
                        R = R->next_Relasi;
                    }
                }
            }
            Q = Q->next_Toko;
        }
    }
    if (Lc.first->next_Customer == NULL){
        Lc.first = NULL;
    }else if(P == Lc.first){
        deleteFirstCustomer(Lc, P);
    }else if (P == Lc.last){
        deleteLastCustomer(Lc, P);
    }else{
        deleteAfterCustomer(Lc, P);
    }
}
void deleteFirstCustomer(List_Customer &L, adr_Customer &P){
    L.first = P->next_Customer;
    P->next_Customer = NULL;
    P->prev_Customer = NULL;
}
void deleteLastCustomer(List_Customer &L, adr_Customer &P){
    L.last = P->prev_Customer;
    P->prev_Customer = NULL;
    L.last->next_Customer = NULL;
}
void deleteAfterCustomer(List_Customer &L, adr_Customer &P){
    P->next_Customer->prev_Customer = P->prev_Customer;
    P->prev_Customer->next_Customer = P->next_Customer;
    P->next_Customer = NULL;
    P->prev_Customer = NULL;
}
void deleteRelasi(adr_Toko &Q ,adr_Relasi &P){
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
void findToko(List_Toko L, adr_Toko &P){
    long long ID;
    cout << "Masukkan ID Toko yang dicari : ";
    cin >> ID;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.ID == ID){
            cout << "Data Toko ditemukan" << endl;
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko      : " << P->info.ID << endl;
            cout << "Kategori Toko: " << P->info.kategori << endl;
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_Toko;
    }
    cout << "Data Toko tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findCustomer(List_Customer L, adr_Customer &P){
    long long NIK;
    cout << "Masukkan NIK Customer yang dicari : ";
    cin >> NIK;
    P = L.first;
    while(P != NULL){
        if(P->info.NIK == NIK){
            cout << "Data Customer ditemukan" << endl;
            cout << "Nama Customer: " << P->info.nama << endl;
            cout << "NIK Customer : " << P->info.NIK << endl;
            cout << "Kelas        : " << P->info.kelas << endl;
            cout << "================================================================" << endl;
            return;
        }
        P = P->next_Customer;
    }
    cout << "Data Customer tidak ditemukan" << endl;
    cout << "================================================================" << endl;
    P = NULL;
}
void findRelasi(adr_Toko P, adr_Customer Q, adr_Relasi &R){
    if (P->relasi.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        R = P->relasi.first;
        while(R != NULL){
            if(R->next_Customer == Q){
                cout << "Data Relasi ditemukan" << endl;
                cout << "Nama Toko     : " << P->info.nama << endl;
                cout << "ID Toko       : " << P->info.ID << endl;
                cout << "Kategori Toko : " << P->info.kategori << endl;
                cout << "================================================================" << endl;
                cout << "Nama Customer: " << Q->info.nama << endl;
                cout << "NIK Customer : " << Q->info.NIK << endl;
                cout << "Kelas        : " << Q->info.kelas << endl;
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
void showToko(List_Toko L){
    adr_Toko P = L.first;
    if(P == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        cout << "Data Toko : " << endl;
        while(P != NULL){
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko      : " << P->info.ID << endl;
            cout << "Kategori Toko: " << P->info.kategori << endl;
            cout << "================================================================" << endl;
            P = P->next_Toko;
        }
    }
}
void showCustomer(List_Customer L){
    adr_Customer P = L.first;
    if(P == NULL){
        cout << "Data Customer kosong" << endl;
        cout << "================================================================" << endl;
    }else{
        cout << "Data Customer : " << endl;
        while(P != NULL){
            cout << "Nama Customer: " << P->info.nama << endl;
            cout << "NIK Customer : " << P->info.NIK << endl;
            cout << "Kelas        : " << P->info.kelas << endl;
            cout << "================================================================" << endl;
            P = P->next_Customer;
        }
    }
}
void showCustomerDariToko(List_Toko Lt){
    if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Toko P;
        findToko(Lt, P);
        if (P == NULL){
            return;
        }
        if (P->relasi.first == NULL){
            cout << "Toko Ini Tidak Memiliki Relasi" << endl;
        }else{
            adr_Relasi R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Customer: " << R->next_Customer->info.nama << endl;
                cout << "NIK Customer : " << R->next_Customer->info.NIK << endl;
                cout << "Kelas        : " << R->next_Customer->info.kelas << endl;
                cout << "================================================================" << endl;
                R = R->next_Relasi;
            }
        }
    }
}
void showAllRelasiToko(List_Toko Lt){
    if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Toko P = Lt.first;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko      : " << P->info.ID << endl;
            cout << "Kategori Toko: " << P->info.kategori << endl;
            cout << "================================================================" << endl;
            R = P->relasi.first;
            while (R != NULL){
                cout << "Nama Customer: " << R->next_Customer->info.nama << endl;
                cout << "NIK Customer : " << R->next_Customer->info.NIK << endl;
                cout << "Kelas        : " << R->next_Customer->info.kelas << endl;
                cout << "================================================================" << endl;
                R = R->next_Relasi;
                ada = true;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Toko;
        }
    }
}
void showAllRelasiCustomer(List_Customer Lc, List_Toko Lt){
    if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Customer P = Lc.first;
        adr_Relasi R;
        adr_Toko Q;
        bool ada;
        while (P != NULL){
            ada = false;
            cout << "Nama Customer: " << P->info.nama << endl;
            cout << "NIK Customer : " << P->info.NIK << endl;
            cout << "Kelas        : " << P->info.kelas << endl;
            cout << "================================================================" << endl;
            Q = Lt.first;
            while (Q != NULL){
                R = Q->relasi.first;
                while (R != NULL){
                    if (R->next_Customer == P){
                        cout << "Nama Toko    : " << Q->info.nama << endl;
                        cout << "ID Toko      : " << Q->info.ID << endl;
                        cout << "Kategori Toko: " << Q->info.kategori << endl;
                        cout << "================================================================" << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Toko;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Customer;
        }
    }
}
void showTokoDariCustomer(List_Customer Lc, List_Toko Lt){
    if (Lc.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else{
        adr_Customer P;
        adr_Relasi R;
        findCustomer(Lc, P);
        if (P == NULL){
            return;
        }
        adr_Toko Q = Lt.first;
        bool ada = false;
        while (Q != NULL){
            R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Customer == P){
                    cout << "Nama Toko    : " << Q->info.nama << endl;
                    cout << "ID Toko      : " << Q->info.ID << endl;
                    cout << "Kategori Toko: " << Q->info.kategori << endl;
                    cout << "================================================================" << endl;
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Toko;
        }
        if (!ada){
            cout << "Data Relasi tidak ditemukan" << endl;
        }
    }
}
void countAllRelasiToko(List_Toko Lt){
    if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Toko P = Lt.first;
        int count;
        while (P != NULL){
            adr_Relasi R = P->relasi.first;
            count = 0;
            while (R != NULL){
                count++;
                R = R->next_Relasi;
            }
            P = P->next_Toko;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countRelasiDariCustomer(List_Customer Lc, List_Toko Lt){
    if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else {
        adr_Customer P;
        findCustomer(Lc, P);
        if (P == NULL){
            return;
        }
        adr_Toko Q = Lt.first;
        int count = 0;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Customer == P){
                    count++;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Toko;
        }
        cout << "Jumlah Relasi : " << count << endl;
    }
}
void countCustomerTanpaToko(List_Customer Lc, List_Toko Lt){
    if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
        return;
    }
    adr_Customer P = Lc.first;
    int count = 0;
    bool ada;
    while (P != NULL){
        adr_Toko Q = Lt.first;
        ada = false;
        while (Q != NULL){
            adr_Relasi R = Q->relasi.first;
            while (R != NULL){
                if (R->next_Customer == P){
                    ada = true;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Toko;
        }
        if (!ada){
            count++;
        }
        P = P->next_Customer;
    }
    cout << "Jumlah Customer tanpa Toko : " << count << endl;
    cout << "================================================================" << endl;
}
void editCustomerDariToko(List_Customer &Lc, List_Toko &Lt){
    if (Lt.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else if (Lc.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else{
        adr_Toko P;
        findToko(Lt, P);
        if (P == NULL){
            return;
        }
        adr_Customer Q,S;
        findCustomer(Lc, Q);
        if (Q == NULL){
            return;
        }
        adr_Relasi R,T;
        findRelasi(P, Q, R);
        if (R == NULL){
            return;
        }
        cout << "Masukkan NIK Customer yang baru : "<< endl;
        findCustomer(Lc, S);
        findRelasi(P, S, T);
        if (T != NULL){
            cout << "Relasi sudah ada" << endl;
            return;
        }
        R->next_Customer = S;
        cout << "Data Customer berhasil diubah" << endl;
    }
}

bool checkNIK(List_Customer L, long long NIK){
    adr_Customer P = L.first;
    while (P != NULL){
        if (P->info.NIK == NIK){
            return false;
        }
        P = P->next_Customer;
    }
    return true;
}
bool checkID(List_Toko L, long long ID){
    adr_Toko P = L.first;
    while (P != NULL){
        if (P->info.ID == ID){
            return false;
        }
        P = P->next_Toko;
    }
    return true;
}
bool checkRelasi(adr_Customer P, adr_Toko Q){
    adr_Relasi R = Q->relasi.first;
    while (R != NULL){
        if (R->next_Customer == P){
            return false;
        }
        R = R->next_Relasi;
    }
    return true;
}
