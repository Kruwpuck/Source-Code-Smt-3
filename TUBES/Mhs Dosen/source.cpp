#include "header.h"
void menu(List_relasi &Lr, List_dosen &Lp, List_mhs &Lc){
    adr_relasi R;
    adr_dosen P,Q;
    adr_mhs C,D;
    string dataR;
    infotype_dosen dataP;
    infotype_mhs dataC;
    int pilihan;
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Sistem Informasi Manajemen mahasiswa dan dosen      |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Salsabila Alya Saputri  //   103032300004         |" << endl;
    cout << "|       Marthin Saborang Nababan //   103032300125         |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|   1. Data dosen                                        |" << endl;
    cout << "|   2. Data mahasiswa                                          |" << endl;
    cout << "|   3. Data relasi                                         |" << endl;
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
        cout << "|        Salsabila Alya Saputri  //   103032300004         |" << endl;
        cout << "|       Marthin Saborang Nababan //   103032300125         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Data dosen                                        |" << endl;
        cout << "|   2. Data mahasiswa                                          |" << endl;
        cout << "|   3. Data relasi                                         |" << endl;
        cout << "|   4. Keluar                                              |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    if (pilihan == 1){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU SEKOLAH                      |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Salsabila Alya Saputri  //   103032300004         |" << endl;
        cout << "|       Marthin Saborang Nababan //   103032300125         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan dosen                                 |" << endl;
        cout << "|   2. Menghapus dosen                                   |" << endl;
        cout << "|   3. Mencari dosen                                     |" << endl;
        cout << "|   4. Menampilkan dosen                                 |" << endl;
        cout << "|   5. Total dosen Tanpa mahasiswa                           |" << endl;
        cout << "|   6. Total mahasiswa Dari dosen Tertentu                   |" << endl;
        cout << "|   7. Menampilkan mahasiswa dari dosen Tertentu             |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama dosen: ";
            cin >> dataP.nama;
            cout << "Masukkan Kode dosen: ";
            cin >> dataP.kode;
            cout << "Masukkan NIDN dosen: ";
            cin >> dataP.NIDN;
            while (!checkNIDN(Lp, dataP.NIDN)){
                cout << "NIDN sudah ada" << endl;
                cin >> dataP.NIDN;
            }
            P = new elm_dosen;
            P->info = dataP;
            P->next_dosen = NULL;
            insert_dosen(Lp, P);
            cout << "Data dosen berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            P = NULL;
            delete_dosen(Lp, P);
            if (P != NULL){
                delete_relasidosen(Lr, P);
                cout << "Elemen List dosen "<< P->info.nama << " telah berhasil dihapus" << endl;
                delete P;
            }
        }else if(pilihan == 3){
            find_dosen(Lp, P);
        }else if(pilihan == 4){
            show_dosen(Lp);
        }else if(pilihan == 5){
            count_mhsTanpadosen(Lr, Lc);
        }else if(pilihan == 6){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            count_mhs(Lr, P);
        }else if(pilihan == 7){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            show_mhs_daridosen(Lr, P);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                         MENU SISWA                       |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Salsabila Alya Saputri  //   103032300004         |" << endl;
        cout << "|       Marthin Saborang Nababan //   103032300125         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan mahasiswa                                   |" << endl;
        cout << "|   2. Menghapus mahasiswa                                     |" << endl;
        cout << "|   3. Mencari mahasiswa                                       |" << endl;
        cout << "|   4. Menampilkan mahasiswa                                   |" << endl;
        cout << "|   5. Total mahasiswa Tanpa dosen                           |" << endl;
        cout << "|   6. Total dosen Dari mahasiswa Tertentu                   |" << endl;
        cout << "|   7. Menampilkan dosen dari mahasiswa Tertentu             |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama mahasiswa: ";
            cin >> dataC.nama;
            cout << "Masukkan IPK mahasiswa: ";
            cin >> dataC.IPK;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> dataC.NIM;
            while (!checkNIM(Lc, dataC.NIM)){
                cout << "NIM sudah ada" << endl;
                cin >> dataC.NIM;
            }
            C = new elm_mhs;
            C->info = dataC;
            C->next_mhs = NULL;
            C->prev_mhs = NULL;
            insert_mhs(Lc, C);
            cout << "Data mahasiswa berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            delete_mhs(Lc, C);
            if (C != NULL){
                delete_relasimhs(Lr, C);
                cout << "mahasiswa dengan nama: " << C->info.nama  << " telah berhasil dihapus" << endl;
                delete C;
            }
        }else if(pilihan == 3){
            find_mhs(Lc, C);
        }else if(pilihan == 4){
            show_mhs(Lc);
        }else if(pilihan == 5){
            count_mhsTanpadosen(Lr, Lc);
        }else if(pilihan == 6){
            find_mhs(Lc, C);
            while (C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            count_dosen(Lr, C);
        }else if(pilihan == 7){
            find_mhs(Lc, C);
            show_dosen_darimhs(Lr, C);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if (pilihan == 3){
        cout << "------------------------------------------------------------" << endl;
        cout << "|                        MENU RELASI                       |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|        Salsabila Alya Saputri  //   103032300004         |" << endl;
        cout << "|       Marthin Saborang Nababan //   103032300125         |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Menambahkan relasi                                  |" << endl;
        cout << "|   2. Menghapus relasi                                    |" << endl;
        cout << "|   3. Check relasi                                        |" << endl;
        cout << "|   4. Menampilkan mahasiswa & relasinya                       |" << endl;
        cout << "|   5. Menampilkan dosen & relasinya                     |" << endl;
        cout << "|   6. edit relasi Dari dosen                            |" << endl;
        cout << "|   7. edit relasi Dari mahasiswa                              |" << endl;
        cout << "|   8. Kembali                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            find_mhs(Lc, C);
            while ( C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            cout << "Masukkan Info relasi: ";
            cin >> dataR;
            R = new elm_relasi;
            R->info = dataR;
            R->next_dosen = P;
            R->next_mhs = C;
            R->next_relasi = NULL;
            insert_relasi(Lr, R);
            cout << "relasi berhasil ditambahkan" << endl;
        }else if (pilihan == 2){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            find_mhs(Lc, C);
            while ( C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            checkrelasi(Lr, C, P, R);
            if (R == NULL){
                cout << "relasi tidak ditemukan" << endl;
            }else{}
            delete_relasi(Lr, R);
            delete R;
            cout << "relasi berhasil dihapus" << endl;
        }else if (pilihan == 3){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            find_mhs(Lc, C);
            while ( C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            checkrelasi(Lr, C, P, R);
        }else if (pilihan == 4){
            show_All_relasidosen(Lp, Lr);
        }else if (pilihan == 5){
            show_All_relasimhs(Lc, Lr);
        }else if (pilihan == 6){
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            find_mhs(Lc, C);
            while ( C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            checkrelasi(Lr, C, P, R);
            if (R != NULL){
                find_mhs(Lc, D);
                edit_dosen(Lr, P, C, D);
                cout << "relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 7){
            find_mhs(Lc, C);
            while ( C == NULL){
                cout << "Data mahasiswa tidak ditemukan" << endl;
                find_mhs(Lc, C);
            }
            find_dosen(Lp, P);
            while (P == NULL){
                cout << "Data dosen tidak ditemukan" << endl;
                find_dosen(Lp, P);
            }
            checkrelasi(Lr, C, P, R);
            if (R != NULL){
                find_dosen(Lp, Q);
                edit_mhs(Lr, C, P, Q);
                cout << "relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }
    menu(Lr, Lp, Lc);
}
void insert_dosen(List_dosen &L, adr_dosen P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_dosen = L.first;
        L.first = P;
    }
}
void insert_mhs(List_mhs &L, adr_mhs P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_mhs = P;
        P->prev_mhs = L.last;
        L.last = P;
    }
}
void insert_relasi(List_relasi &L, adr_relasi P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_relasi = L.first;
        L.first = P;
    }
}
void delete_dosen(List_dosen &L, adr_dosen &P){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    find_dosen(L, P);
    while (P == NULL){
        cout << "Data dosen tidak ditemukan" << endl;
        find_dosen(L, P);
    }
    if(P == L.first){
        delete_Firstdosen(L, P);
    }else if (P->next_dosen == NULL){
        delete_Lastdosen(L, P);
    }else{
        delete_Afterdosen(L, P);
    }
}
void delete_mhs(List_mhs &L, adr_mhs &P){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    find_mhs(L, P);
    if (P == NULL){
        cout << "Data mahasiswa tidak ditemukan" << endl;
        return;
    }
    if (P == L.first){
        delete_Firstmhs(L, P);
    }else if (P == L.last){
        delete_Lastmhs(L, P);
    }else{
        delete_Aftermhs(L, P);
    }
}
void delete_relasi(List_relasi &L ,adr_relasi &P){
    if(L.first == NULL){
        cout << "Data relasi kosong" << endl;
    }else{
        if(P == L.first){
            L.first = P->next_relasi;
            P->next_relasi = NULL;
        }else{
            adr_relasi Q = L.first;
            while(Q->next_relasi != P){
                Q = Q->next_relasi;
            }
            if (P->next_relasi != NULL){
                Q->next_relasi = P->next_relasi;
            }
            Q->next_relasi = NULL;
        }
    }
}
void find_dosen(List_dosen L, adr_dosen &P){
    if (L.first == NULL){
        cout << "Data dosen kosong" << endl;
        return;
    }else{
        int NIDN;
        cout << "Masukkan NIDN dosen: ";
        cin >> NIDN;
        P = L.first;
        while(P != NULL){
            if(P->info.NIDN == NIDN){
                cout << "Data dosen ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama dosen: " << P->info.nama << endl;
                cout << "|   Kode dosen: " << P->info.kode << endl;
                cout << "|   NIDN dosen: " << P->info.NIDN << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_dosen;
            }
        }
    }
}
void find_mhs(List_mhs L, adr_mhs &P){
    if (L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }else{
        int NIM;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> NIM;
        P = L.first;
        while(P != NULL){
            if(P->info.NIM == NIM){
                cout << "Data mahasiswa ditemukan" << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                cout << "|   Nama mahasiswa: " << P->info.nama << endl;
                cout << "|   IPK mahasiswa: " << P->info.IPK << endl;
                cout << "|   NIM mahasiswa: " << P->info.NIM << endl;
                cout << endl << "------------------------------------------------------------" << endl;
                return;
            }else{
                P = P->next_mhs;
            }
        }
    }
}
void checkrelasi(List_relasi L, adr_mhs P, adr_dosen Q, adr_relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_mhs == P && R->next_dosen == Q){
            cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   relasi ditemukan" << endl;
            cout << "|   Info relasi: " << R->info << endl;
            cout << endl << "------------------------------------------------------------" << endl;
            return;
        }else{
            R = R->next_relasi;
        }
    }
    cout << endl << "------------------------------------------------------------" << endl;
            cout << "|   relasi Tidak Ditemukan" << endl;
    cout << endl << "------------------------------------------------------------" << endl;
}
void show_dosen(List_dosen L){
    if(L.first == NULL){
        cout << "Data dosen kosong" << endl;
    }else{
        adr_dosen P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama dosen: " << P->info.nama << endl;
            cout << "|   Kode dosen: " << P->info.kode << endl;
            cout << "|   NIDN dosen: " << P->info.NIDN << endl;
            cout << endl;
            P = P->next_dosen;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void show_mhs(List_mhs L){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
    }else{
        adr_mhs P = L.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama mahasiswa: " << P->info.nama << endl;
            cout << "|   IPK mahasiswa: " << P->info.IPK << endl;
            cout << "|   NIM mahasiswa: " << P->info.NIM << endl;
            cout << endl;
            P = P->next_mhs;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void show_mhs_daridosen(List_relasi L, adr_dosen P){
    if(L.first == NULL){
        cout << "Data relasi kosong" << endl;
    }else{
        adr_relasi R = L.first;
        bool ada = false;
        cout << endl << "------------------------------------------------------------" << endl;
        while(R != NULL){
            if(R->next_dosen == P){
                cout << "|   Nama mahasiswa: " << R->next_mhs->info.nama << endl;
                cout << "|   IPK mahasiswa: " << R->next_mhs->info.IPK << endl;
                cout << "|   NIM mahasiswa: " << R->next_mhs->info.NIM << endl;
                cout << "|   Info relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_relasi;
        }
        if (!ada){
            cout << "|   dosen tidak memiliki relasi dengan mahasiswa manapun" << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void show_dosen_darimhs(List_relasi L, adr_mhs P){
    if(L.first == NULL){
        cout << "Data relasi kosong" << endl;
    }else{
        adr_relasi R = L.first;
        bool ada = false;
        cout << endl << "------------------------------------------------------------" << endl;
        while(R != NULL){
            if(R->next_mhs == P){
                cout << "|   Nama dosen: " << R->next_dosen->info.nama << endl;
                cout << "|   Kode dosen: " << R->next_dosen->info.kode << endl;
                cout << "|   NIDN dosen: " << R->next_dosen->info.NIDN << endl;
                cout << "|   Info relasi: " << R->info << endl;
                cout << endl;
                ada = true;
            }
            R = R->next_relasi;
        }
        if (!ada){
            cout << "|   mahasiswa tidak memiliki relasi dengan sekolah manapun" << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}
void show_All_relasidosen(List_dosen Lp, List_relasi Lr){
    if(Lp.first == NULL){
        cout << "Data dosen kosong" << endl;
    }else{
        adr_dosen P = Lp.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama dosen: " << P->info.nama << endl;
            cout << "|   Kode dosen: " << P->info.kode << endl;
            cout << "|   NIDN dosen: " << P->info.NIDN << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "|     mahasiswa Yang Memiliki relasi Dengan dosen Diatas     |" << endl;
            cout << "------------------------------------------------------------" << endl;
            show_mhs_daridosen(Lr, P);
            P = P->next_dosen;
        }
    }
}
void show_All_relasimhs(List_mhs Lc, List_relasi Lr){
    if(Lc.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
    }else{
        adr_mhs P = Lc.first;
        cout << endl << "------------------------------------------------------------" << endl;
        while(P != NULL){
            cout << "|   Nama mahasiswa: " << P->info.nama << endl;
            cout << "|   IPK mahasiswa: " << P->info.IPK << endl;
            cout << "|   NIM mahasiswa: " << P->info.NIM << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "|     dosen Yang Memiliki relasi Dengan mahasiswa Diatas     |" << endl;
            cout << "------------------------------------------------------------" << endl;
            show_dosen_darimhs(Lr, P);
            P = P->next_mhs;
        }
    }
}
void count_mhs(List_relasi L, adr_dosen P){
    if(L.first == NULL){
        cout << "Data relasi kosong" << endl;
    }else{
        adr_relasi R = L.first;
        int count_ = 0;
        while(R != NULL){
            if(R->next_dosen == P){
                count_++;
            }
            R = R->next_relasi;
        }
        cout << "|   Total mahasiswa di dosen " << P->info.nama << ": " << count_ << endl;
    }
}
void count_dosen(List_relasi L, adr_mhs P){
    if(L.first == NULL){
        cout << "Data relasi kosong" << endl;
    }else{
        adr_relasi R = L.first;
        int count_ = 0;
        while(R != NULL){
            if(R->next_mhs == P){
                count_++;
            }
            R = R->next_relasi;
        }
        cout << "|   Total dosen dari mahasiswa " << P->info.nama << ": " << count_ << endl;
    }
}
void count_dosenTanpamahasiswa(List_relasi Lr, List_dosen Lp){
    if(Lr.first == NULL){
        show_dosen(Lp);
    }else{
        adr_dosen P = Lp.first;
        bool found;
        int count_ = 0;
        while (P != NULL){
            adr_relasi R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_dosen == P){
                    found = true;
                }
                R = R->next_relasi;
            }
            if (!found){
                count_++;
            }
            P = P->next_dosen;
        }
        cout << "|   Total dosen yang tidak memiliki mahasiswa: " << count_ << endl;
    }
}
void count_mhsTanpadosen(List_relasi Lr, List_mhs Lc){
    if(Lr.first == NULL){
        show_mhs(Lc);
    }else{
        adr_mhs P = Lc.first;
        bool found;
        int count_ = 0;
        adr_relasi R;
        while (P != NULL){
            R = Lr.first;
            found = false;
            while(R != NULL){
                if (R->next_mhs == P){
                    found = true;
                }
                R = R->next_relasi;
            }
            if (!found){
                count_++;
            }
            P = P->next_mhs;
        }
        cout << "|   Total mahasiswa yang tidak memiliki dosen: " << count_ << endl;
    }
}
void edit_dosen(List_relasi &L, adr_dosen P, adr_mhs Q, adr_mhs R){
    adr_relasi S = L.first;
    adr_relasi T = NULL;
    checkrelasi(L, Q, P, T);
    T->next_mhs = R;
}
void edit_mhs(List_relasi &L, adr_mhs P, adr_dosen Q, adr_dosen R){
    adr_relasi S = L.first;
    adr_relasi T = NULL;
    checkrelasi(L, P, Q, T);
    T->next_dosen = R;
}
void delete_relasimhs(List_relasi &L, adr_mhs &P){
    adr_relasi R = L.first;
    while (R != NULL){
        if (R->next_mhs == P){
            delete_relasi(L,R);
            R = L.first;
        }
        R = R->next_relasi;
    }
}
void delete_relasidosen(List_relasi &L, adr_dosen &P){
    adr_relasi R = L.first;
    while (R != NULL){
        if (R->next_dosen == P){
            delete_relasi(L, R);
            R = L.first;
        }else{
            R = R->next_relasi;
        }
    }
}
void delete_Firstmhs(List_mhs &L, adr_mhs &P){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.first = P->next_mhs;
        P->next_mhs = NULL;
        L.first->prev_mhs = NULL;
    }
}
void delete_Lastmhs(List_mhs &L, adr_mhs &P){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else{
        L.last = P->prev_mhs;
        P->prev_mhs = NULL;
        L.last->next_mhs = NULL;
    }
}
void delete_Aftermhs(List_mhs &L, adr_mhs &P){
    if(L.first == NULL){
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    P->next_mhs->prev_mhs = P->prev_mhs;
    P->prev_mhs->next_mhs = P->next_mhs;
    P->next_mhs = NULL;
    P->prev_mhs = NULL;
}
void delete_Firstdosen(List_dosen &L, adr_dosen &P){
    if(L.first == NULL){
        cout << "Data dosen kosong" << endl;
        return;
    }
    if(L.first->next_dosen == NULL){
        L.first = NULL;
    }else{
        L.first = P->next_dosen;
        P->next_dosen = NULL;
    }
}
void delete_Lastdosen(List_dosen &L, adr_dosen &P){
    if(L.first == NULL){
        cout << "Data dosen kosong" << endl;
        return;
    }
    if(L.first->next_dosen == NULL){
        L.first = NULL;
    }else{
        adr_dosen Q = L.first;
        while (Q->next_dosen != P){
            Q = Q->next_dosen;
        }
        Q->next_dosen = NULL;
    }
}
void delete_Afterdosen(List_dosen &L, adr_dosen &P){
    if(L.first == NULL){
        cout << "Data dosen kosong" << endl;
        return;
    }
    adr_dosen Q = L.first;
    while (Q->next_dosen != P){
        Q = Q->next_dosen;
    }
    Q->next_dosen = P->next_dosen;
    P->next_dosen = NULL;
}
bool checkNIM(List_mhs L, int NIM){
    adr_mhs P = L.first;
    while (P != NULL){
        if (P->info.NIM == NIM){
            return false;
        }
        P = P->next_mhs;
    }
    return true;
}
bool checkNIDN(List_dosen L, int NIDN){
    adr_dosen P = L.first;
    while (P != NULL){
        if (P->info.NIDN == NIDN){
            return false;
        }
        P = P->next_dosen;
    }
    return true;
}
