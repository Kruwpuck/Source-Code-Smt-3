#include "header.h"
void menu(List_Relasi &Lr, List_Guru &Lg, List_Murid &Lm){
    adr_Relasi R;
    adr_Guru P,Q;
    adr_Murid C,D;
    infotype_Relasi dataR;
    infotype_Guru data_Guru;
    infotype_Murid data_Murid;
    int pilihan;
    cout << endl << "========= PENDATAAN MURID & GURU ==========" << endl;
    cout << endl << "||                                       ||" << endl;
    cout << endl << "||   Chantika Syafana Z || 103032300058  ||" << endl;
    cout << endl << "||      Wirdatul Ahya   || 103032300071  ||" << endl;
    cout << endl << "||                                       ||" << endl;
    cout << endl << "=============== MENU UTAMA ================" << endl;
    cout << "1. Data Guru" << endl;
    cout << "2. Data Murid" << endl;
    cout << "3. Data Relasi" << endl;
    cout << "4. Exit" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cout << endl;
    if (pilihan < 1 || pilihan > 4){
        cout << "Pilihan tidak valid" << endl;
        cout << endl << "=============== MENU UTAMA ================" << endl;
        cout << "1. Data Guru" << endl;
        cout << "2. Data Murid" << endl;
        cout << "3. Data Relasi" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
    }
    if (pilihan == 4){
        return ;
    }
    if (pilihan == 1){
        cout << endl << "=============== MENU Guru ================" << endl;
        cout << "1. Tambah Guru" << endl;
        cout << "2. Hapus Guru" << endl;
        cout << "3. Cari Guru" << endl;
        cout << "4. Tampilkan Guru" << endl;
        cout << "5. Jumlah Guru Tanpa Murid" << endl;
        cout << "6. Jumlah Murid Dari Guru Tertentu" << endl;
        cout << "7. Data Murid dari Guru Tertentu" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Guru: ";
            cin >> data_Guru.nama;
            cout << "Masukkan Jabatan Guru: ";
            cin >> data_Guru.jabatan;
            cout << "Masukkan NUPTK Guru: ";
            cin >> data_Guru.NUPTK;
            while (!checkNUPTK(Lg, data_Guru.NUPTK)){
                cout << "NUPTK sudah ada" << endl;
                cin >> data_Guru.NUPTK;
            }
            P = new elm_Guru;
            P->info = data_Guru;
            P->next_Guru = NULL;
            P->prev_Guru = NULL;
            insertGuru(Lg, P);
            cout << "Data Guru berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            P = NULL;
            deleteGuru(Lg, P);
            if (P != NULL){
                deleteRelasiGuru(Lr, P);
                cout << "Elemen List Guru "<< P->info.nama << " telah berhasil dihapus" << endl;
                delete P;
            }
        }else if(pilihan == 3){
            findGuru(Lg, P);
        }else if(pilihan == 4){
            showGuru(Lg);
        }else if(pilihan == 5){
            countGuru_Less(Lr, Lm);
        }else if(pilihan == 6){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            countMurid(Lr, P);
        }else if(pilihan == 7){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            showMurid_dariGuru(Lr, P);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << endl << "=============== MENU Murid ================" << endl;
        cout << "1. Tambah Murid" << endl;
        cout << "2. Hapus Murid" << endl;
        cout << "3. Cari Murid" << endl;
        cout << "4. Tampilkan Murid" << endl;
        cout << "5. Jumlah Murid Tanpa Guru" << endl;
        cout << "6. Jumlah Guru dari Murid Tertentu" << endl;
        cout << "7. Data Guru dari Murid Tertentu" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Murid: ";
            cin >> data_Murid.nama;
            cout << "Masukkan Kelas Murid: ";
            cin >> data_Murid.kelas;
            cout << "Masukkan NISN Murid: ";
            cin >> data_Murid.NISN;
            while (!checkNISN(Lm, data_Murid.NISN)){
                cout << "NISN sudah ada" << endl;
                cin >> data_Murid.NISN;
            }
            C = new elm_Murid;
            C->info = data_Murid;
            C->next_Murid = NULL;
            insertMurid(Lm, C);
            cout << "Data Murid berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteMurid(Lm, C);
            if (C != NULL){
                deleteRelasiMurid(Lr, C);
                cout << "Murid dengan nama: " << C->info.nama  << " telah berhasil dihapus" << endl;
                delete C;
            }
        }else if(pilihan == 3){
            findMurid(Lm, C);
        }else if(pilihan == 4){
            showMurid(Lm);
        }else if(pilihan == 5){
            countGuru_Less(Lr, Lm);
        }else if(pilihan == 6){
            findMurid(Lm, C);
            while (C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            countGuru(Lr, C);
        }else if(pilihan == 7){
            findMurid(Lm, C);
            showGuru_dariMurid(Lr, C);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << endl << "===============MENU RELASI================" << endl;
        cout << "1. Tambah Relasi" << endl;
        cout << "2. Hapus Relasi" << endl;
        cout << "3. Check Relasi" << endl;
        cout << "4. Tampilkan Murid & Relasinya" << endl;
        cout << "5. Tampilkan Guru & Relasinya" << endl;
        cout << "6. Edit Relasi Dari Guru" << endl;
        cout << "7. Edit Relasi Dari Murid" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            findMurid(Lm, C);
            while ( C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            cout << "Masukkan Info Relasi: ";
            cin >> dataR;
            R = new elm_Relasi;
            R->info = dataR;
            R->next_Guru = P;
            R->next_Murid = C;
            R->next_Relasi = NULL;
            insertRelasi(Lr, R);
            cout << "Relasi berhasil ditambahkan" << endl;
        }else if (pilihan == 2){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            findMurid(Lm, C);
            while ( C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R == NULL){
                cout << "Relasi tidak ditemukan" << endl;
            }else{}
            deleteRelasi(Lr, R);
            delete R;
            cout << "Relasi berhasil dihapus" << endl;
        }else if (pilihan == 3){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            findMurid(Lm, C);
            while ( C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            checkRelasi(Lr, C, P, R);
        }else if (pilihan == 4){
            showAll_RelasiGuru(Lg, Lr);
        }else if (pilihan == 5){
            showAll_RelasiMurid(Lm, Lr);
        }else if (pilihan == 6){
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            findMurid(Lm, C);
            while ( C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findMurid(Lm, D);
                editGuru(Lr, P, C, D);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 7){
            findMurid(Lm, C);
            while ( C == NULL){
                cout << "Data Murid tidak ditemukan" << endl;
                findMurid(Lm, C);
            }
            findGuru(Lg, P);
            while (P == NULL){
                cout << "Data Guru tidak ditemukan" << endl;
                findGuru(Lg, P);
            }
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findGuru(Lg, Q);
                editMurid(Lr, C, P, Q);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    menu(Lr, Lg, Lm);
}
void insertGuru(List_Guru &L, adr_Guru P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Guru = L.first;
        L.first = P;
    }
}
void insertMurid(List_Murid &L, adr_Murid P){
    if(L.first == NULL){
        L.first = P;
    }else{
        adr_Murid Q = L.first;
        while(Q->next_Murid != NULL){
            Q = Q->next_Murid;
        }
        Q->next_Murid = P;
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
void deleteGuru(List_Guru &L, adr_Guru &P){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }
    findGuru(L, P);
    while (P == NULL){
        cout << "Data Guru tidak ditemukan" << endl;
        findGuru(L, P);
    }
    if(P == L.first){
        deleteFirstGuru(L, P);
    }else if (P->next_Guru == NULL){
        deleteLastGuru(L, P);
    }else{
        deleteAfterGuru(L, P);
    }
}
void deleteMurid(List_Murid &L, adr_Murid &P){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }
    findMurid(L, P);
    if (P == NULL){
        cout << "Data Murid tidak ditemukan" << endl;
        return;
    }
    if (P == L.first){
        deleteFirstMurid(L, P);
    }else if (P->next_Murid == NULL){
        deleteLastMurid(L, P);
    }else{
        deleteAfterMurid(L, P);
    }
}
void deleteRelasi(List_Relasi &L ,adr_Relasi &P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi Q = L.first;
        if(P == L.first){
            L.first = P->next_Relasi;
            P->next_Relasi = NULL;
        }else if(P->next_Relasi == NULL){
            while (Q->next_Relasi != P){
                Q = Q->next_Relasi;
            }
            Q->next_Relasi = NULL;
        }else{
            while (Q->next_Relasi != P){
                Q = Q->next_Relasi;
            }
            Q->next_Relasi = P->next_Relasi;
            P->next_Relasi = NULL;
        }
    }
}
void findGuru(List_Guru L, adr_Guru &P){
    if (L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }else{
        int NUPTK;
        cout << "Masukkan NUPTK Guru: ";
        cin >> NUPTK;
        P = L.first;
        while(P != NULL){
            if(P->info.NUPTK == NUPTK){
                cout << "Data Guru ditemukan" << endl;
                cout << endl << "=========================================" << endl;
                cout << "Nama Guru: " << P->info.nama << endl;
                cout << "Jabatan Guru: " << P->info.jabatan << endl;
                cout << "NUPTK Guru: " << P->info.NUPTK << endl;
                cout << endl << "=========================================" << endl;
                return;
            }else{
                P = P->next_Guru;
            }
        }
    }
}
void findMurid(List_Murid L, adr_Murid &P){
    if (L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }else{
        int NISN;
        cout << "Masukkan NISN Murid: ";
        cin >> NISN;
        P = L.first;
        while(P != NULL){
            if(P->info.NISN == NISN){
                cout << "Data Murid ditemukan" << endl;
                cout << endl << "=========================================" << endl;
                cout << "Nama Murid: " << P->info.nama << endl;
                cout << "Kelas Murid: " << P->info.kelas << endl;
                cout << "NISN Murid: " << P->info.NISN << endl;
                cout << endl << "=========================================" << endl;
                return;
            }else{
                P = P->next_Murid;
            }
        }
    }
}
void checkRelasi(List_Relasi L, adr_Murid P, adr_Guru Q, adr_Relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_Murid == P && R->next_Guru == Q){
            cout << endl << "=========================================" << endl;
            cout << "Relasi ditemukan" << endl;
            cout << "Info Relasi: " << R->info << endl;
            cout << endl << "=========================================" << endl;
            return;
        }else{
            R = R->next_Relasi;
        }
    }
    cout << endl << "=========================================" << endl;
            cout << "Relasi Tidak Ditemukan" << endl;
    cout << endl << "=========================================" << endl;
}
void showGuru(List_Guru L){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
    }else{
        adr_Guru P = L.first;
        cout << endl << "=========================================" << endl;
        while(P != NULL){
            cout << "Nama Guru: " << P->info.nama << endl;
            cout << "Jabatan Guru: " << P->info.jabatan << endl;
            cout << "NUPTK Guru: " << P->info.NUPTK << endl;
            cout << endl;
            P = P->next_Guru;
        }
        cout << "=========================================" << endl;
    }
}
void showMurid(List_Murid L){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
    }else{
        adr_Murid P = L.first;
        cout << endl << "=========================================" << endl;
        while(P != NULL){
            cout << "Nama Murid: " << P->info.nama << endl;
            cout << "Kelas Murid: " << P->info.kelas << endl;
            cout << "NISN Murid: " << P->info.NISN << endl;
            cout << endl;
            P = P->next_Murid;
        }
        cout << "=========================================" << endl;
    }
}
void showMurid_dariGuru(List_Relasi L, adr_Guru P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "=========================================" << endl;
        while(R != NULL){
            if(R->next_Guru == P){
                cout << "Nama Murid : " << R->next_Murid->info.nama << endl;
                cout << "Kelas Murid: " << R->next_Murid->info.kelas << endl;
                cout << "NISN Murid : " << R->next_Murid->info.NISN << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "=========================================" << endl;
    }
}
void showGuru_dariMurid(List_Relasi L, adr_Murid P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "=========================================" << endl;
        while(R != NULL){
            if(R->next_Murid == P){
                cout << "Nama Guru   : " << R->next_Guru->info.nama << endl;
                cout << "Jabatan Guru: " << R->next_Guru->info.jabatan << endl;
                cout << "NUPTK Guru  : " << R->next_Guru->info.NUPTK << endl;
                cout << "Info Relasi : " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "=========================================" << endl;
    }
}
void showAll_RelasiGuru(List_Guru Lg, List_Relasi Lr){
    if(Lg.first == NULL){
        cout << "Data Guru kosong" << endl;
    }else{
        adr_Guru P = Lg.first;
        cout << endl << "=========================================" << endl;
        while(P != NULL){
            cout << "Nama Guru: " << P->info.nama << endl;
            cout << "Jabatan Guru: " << P->info.jabatan << endl;
            cout << "NUPTK Guru: " << P->info.NUPTK << endl;
            cout << "=========================================" << endl;
            cout << "Berikut Data Murid dari Guru diatas" << endl;
            cout << "=========================================" << endl;
            showMurid_dariGuru(Lr, P);
            P = P->next_Guru;
        }
    }
}
void showAll_RelasiMurid(List_Murid Lm, List_Relasi Lr){
    if(Lm.first == NULL){
        cout << "Data Murid kosong" << endl;
    }else{
        adr_Murid P = Lm.first;
        cout << endl << "=========================================" << endl;
        while(P != NULL){
            cout << "Nama Murid: " << P->info.nama << endl;
            cout << "Kelas Murid: " << P->info.kelas << endl;
            cout << "NISN Murid: " << P->info.NISN << endl;
            cout << "=========================================" << endl;
            cout << "Berikut Data Guru dari Murid diatas" << endl;
            cout << "=========================================" << endl;
            showGuru_dariMurid(Lr, P);
            P = P->next_Murid;
        }
    }
}
void countMurid(List_Relasi L, adr_Guru P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Guru == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Murid di Guru " << P->info.nama << ": " << hitung << endl;
    }
}
void countGuru(List_Relasi L, adr_Murid P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Murid == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Guru dari Murid " << P->info.nama << ": " << hitung << endl;
    }
}
void countMurid_Less(List_Relasi Lr, List_Guru Lg){
    if(Lr.first == NULL){
        showGuru(Lg);
    }else{
        adr_Guru P = Lg.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Guru == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Guru;
        }
        cout << "Jumlah Guru yang tidak memiliki Murid: " << hitung << endl;
    }
}
void countGuru_Less(List_Relasi Lr, List_Murid Lm){
    if(Lr.first == NULL){
        showMurid(Lm);
    }else{
        adr_Murid P = Lm.first;
        bool found;
        int hitung = 0;
        adr_Relasi R;
        while (P != NULL){
            R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_Murid == P){
                    found = true;
                }
                R = R->next_Relasi;
            }
            if (!found){
                hitung++;
            }
            P = P->next_Murid;
        }
        cout << "Jumlah Murid yang tidak memiliki Guru: " << hitung << endl;
    }
}
void editGuru(List_Relasi &L, adr_Guru P, adr_Murid Q, adr_Murid R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    T->next_Murid = R;
}
void editMurid(List_Relasi &L, adr_Murid P, adr_Guru Q, adr_Guru R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    T->next_Guru = R;
}
void deleteRelasiMurid(List_Relasi &L, adr_Murid &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Murid == P){
            deleteRelasi(L,R);
            R = L.first;
        }
        R = R->next_Relasi;
    }
}
void deleteRelasiGuru(List_Relasi &L, adr_Guru &P){
    adr_Relasi R = L.first;
    while (R != NULL){
        if (R->next_Guru == P){
            deleteRelasi(L, R);
            R = L.first;
        }else{
            R = R->next_Relasi;
        }
    }
}
void deleteFirstMurid(List_Murid &L, adr_Murid &P){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }
    if(L.first->next_Murid == NULL){
        L.first = NULL;
    }else{
        L.first = P->next_Murid;
        P->next_Murid = NULL;
    }
}
void deleteLastMurid(List_Murid &L, adr_Murid &P){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }
    if(L.first->next_Murid == NULL){
        L.first = NULL;
    }else{
        adr_Murid Q = L.first;
        while (Q->next_Murid != P){
            Q = Q->next_Murid;
        }
        Q->next_Murid = NULL;
    }
}
void deleteAfterMurid(List_Murid &L, adr_Murid &P){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }
    adr_Murid Q = L.first;
    while (Q->next_Murid != P){
        Q = Q->next_Murid;
    }
    Q->next_Murid = P->next_Murid;
    P->next_Murid = NULL;
}
void deleteFirstGuru(List_Guru &L, adr_Guru &P){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.first = P->next_Guru;
        P->next_Guru = NULL;
        L.first->prev_Guru = NULL;
    }
}
void deleteLastGuru(List_Guru &L, adr_Guru &P){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.last = P->prev_Guru;
        P->prev_Guru = NULL;
        L.last->next_Guru = NULL;
    }
}
void deleteAfterGuru(List_Guru &L, adr_Guru &P){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }
    P->next_Guru->prev_Guru = P->prev_Guru;
    P->prev_Guru->next_Guru = P->next_Guru;
    P->next_Guru = NULL;
    P->prev_Guru = NULL;
}
bool checkNISN(List_Murid L, int NISN){
    adr_Murid P = L.first;
    while (P != NULL){
        if (P->info.NISN == NISN){
            return false;
        }
        P = P->next_Murid;
    }
    return true;
}
bool checkNUPTK(List_Guru L, int NUPTK){
    adr_Guru P = L.first;
    while (P != NULL){
        if (P->info.NUPTK == NUPTK){
            return false;
        }
        P = P->next_Guru;
    }
    return true;
}
