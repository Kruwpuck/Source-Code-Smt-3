#include "header.h"
void menu(List_Relasi &Lr, List_Sekolah &Lp, List_Siswa &Lc){
    adr_Relasi R;
    adr_Sekolah P,Q;
    adr_Siswa C,D;
    infotype_Relasi dataR;
    infotype_Sekolah dataP;
    infotype_Siswa dataC;
    int pilihan;
    cout << endl << "===============MENU UTAMA================" << endl;
    cout << "1. Data Sekolah" << endl;
    cout << "2. Data Siswa" << endl;
    cout << "3. Data Relasi" << endl;
    cout << "4. Exit" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == 4){
        return ;
    }
    if (pilihan < 1 || pilihan > 4){
        cout << "Pilihan tidak valid" << endl;
        cin >> pilihan;
    }
    if (pilihan == 1){
        cout << endl << "===============MENU SEKOLAH================" << endl;
        cout << "1. Tambah Sekolah" << endl;
        cout << "2. Hapus Sekolah" << endl;
        cout << "3. Cari Sekolah" << endl;
        cout << "4. Tampilkan Sekolah" << endl;
        cout << "5. Jumlah Sekolah Tanpa Siswa" << endl;
        cout << "6. Jumlah Siswa Dari Sekolah Tertentu" << endl;
        cout << "7. Data Siswa dari Sekolah Tertentu" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Sekolah: ";
            cin >> dataP.nama;
            cout << "Masukkan Alamat Sekolah: ";
            cin >> dataP.alamat;
            cout << "Masukkan NPSN Sekolah: ";
            cin >> dataP.NPSN;
            P = new elm_Sekolah;
            P->info = dataP;
            insertSekolah(Lp, P);
            cout << "Data Sekolah berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteSekolah(Lp, P);
            delete P;
            cout << "Elemen Pertama List Sekolah berhasil dihapus" << endl;
        }else if(pilihan == 3){
            findSekolah(Lp, P);
        }else if(pilihan == 4){
            showSekolah(Lp);
        }else if(pilihan == 5){
            countSekolah_Less(Lr, Lc);
        }else if(pilihan == 6){
            findSekolah(Lp, P);
            countSiswa(Lr, P);
        }else if(pilihan == 7){
            findSekolah(Lp, P);
            showSiswa_dariSekolah(Lr, P);
        }else if(pilihan == 8){
            cout << "Kembali ke menu utama" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }
    }else if(pilihan == 2){
        cout << endl << "===============MENU SISWA================" << endl;
        cout << "1. Tambah Siswa" << endl;
        cout << "2. Hapus Siswa" << endl;
        cout << "3. Cari Siswa" << endl;
        cout << "4. Tampilkan Siswa" << endl;
        cout << "5. Jumlah Siswa Tanpa Sekolah" << endl;
        cout << "6. Jumlah Sekolah dari Siswa Tertentu" << endl;
        cout << "7. Data Sekolah dari Siswa Tertentu" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            cout << "Masukkan Nama Siswa: ";
            cin >> dataC.nama;
            cout << "Masukkan Kelas Siswa: ";
            cin >> dataC.kelas;
            cout << "Masukkan NISN Siswa: ";
            cin >> dataC.NISN;
            C = new elm_Siswa;
            C->info = dataC;
            insertSiswa(Lc, C);
            cout << "Data Siswa berhasil ditambahkan" << endl;
        }else if(pilihan == 2){
            deleteSiswa(Lc, C);
            delete C;
            cout << "Elemen Pertama List Siswa berhasil dihapus" << endl;
        }else if(pilihan == 3){
            findSiswa(Lc, C);
        }else if(pilihan == 4){
            showSiswa(Lc);
        }else if(pilihan == 5){
            countSekolah_Less(Lr, Lc);
        }else if(pilihan == 6){
            findSiswa(Lc, C);
            countSekolah(Lr, C);
        }else if(pilihan == 7){
            findSiswa(Lc, C);
            showSekolah_dariSiswa(Lr, C);
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
        cout << "4. Tampilkan Siswa & Relasinya" << endl;
        cout << "5. Tampilkan Sekolah & Relasinya" << endl;
        cout << "6. Edit Relasi Dari Sekolah" << endl;
        cout << "7. Edit Relasi Dari Siswa" << endl;
        cout << "8. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){
            findSekolah(Lp, P);
            findSiswa(Lc, C);
            cout << "Masukkan Info Relasi: ";
            cin >> dataR;
            R = new elm_Relasi;
            R->info = dataR;
            R->next_Sekolah = P;
            R->next_Siswa = C;
            insertRelasi(Lr, R);
            cout << "Relasi berhasil ditambahkan" << endl;
        }else if (pilihan == 2){
            findSekolah(Lp, P);
            findSiswa(Lc, C);
            deleteRelasi(Lr, P, C, R);
            delete R;
            cout << "Relasi berhasil dihapus" << endl;
        }else if (pilihan == 3){
            findSekolah(Lp, P);
            findSiswa(Lc, C);
            checkRelasi(Lr, C, P, R);
        }else if (pilihan == 4){
            showAll_RelasiSekolah(Lp, Lr);
        }else if (pilihan == 5){
            showAll_RelasiSiswa(Lc, Lr);
        }else if (pilihan == 6){
            findSekolah(Lp, P);
            findSiswa(Lc, C);
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findSiswa(Lc, D);
                editSekolah(Lr, P, C, D);
                cout << "Relasi berhasil diubah" << endl;
            }
        }else if (pilihan == 7){
            findSiswa(Lc, C);
            findSekolah(Lp, P);
            checkRelasi(Lr, C, P, R);
            if (R != NULL){
                findSekolah(Lp, Q);
                editSiswa(Lr, C, P, Q);
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
void insertSekolah(List_Sekolah &L, adr_Sekolah P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Sekolah = L.first;
        L.first = P;
    }
}
void insertSiswa(List_Siswa &L, adr_Siswa P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.first->next_Siswa = P;
        P->prev_Siswa = L.first;
        L.first = P;
    }
}
void insertRelasi(List_Relasi &L, adr_Relasi P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->next_Relasi = L.first;
        L.first->prev_Relasi = P;
        L.first = P;
    }
}
void deleteSekolah(List_Sekolah &L, adr_Sekolah &P){
    if(L.first == NULL){
        cout << "Data Sekolah kosong" << endl;
    }else if(L.first == P){
        P = L.first;
        L.first = NULL;
    }else{
        P = L.first;
        L.first = P->next_Sekolah;
        P->next_Sekolah = NULL;
    }
}
void deleteSiswa(List_Siswa &L, adr_Siswa &P){
    if(L.first == NULL){
        cout << "Data Siswa kosong" << endl;
    }else if(L.first == L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.last;
        L.last = P->prev_Siswa;
        P->prev_Siswa = NULL;
        L.last->next_Siswa = NULL;
    }
}
void deleteRelasi(List_Relasi &L, adr_Sekolah &S, adr_Siswa &R ,adr_Relasi &P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        checkRelasi(L, R, S, P);
        if(P == L.first){
            L.first = P->next_Relasi;
            P->next_Relasi = NULL;
        }else if(P == L.last){
            L.last = P->prev_Relasi;
            P->prev_Relasi = NULL;
            L.last->next_Relasi = NULL;
        }else{
            P->prev_Relasi->next_Relasi = P->next_Relasi;
            P->next_Relasi->prev_Relasi = P->prev_Relasi;
            P->next_Relasi = NULL;
            P->prev_Relasi = NULL;
        }
    }
}
void findSekolah(List_Sekolah L, adr_Sekolah &P){
    if (L.first == NULL){
        cout << "Data Sekolah kosong" << endl;
        return;
    }else{
        string NPSN;
        cout << "Masukkan NPSN Sekolah: ";
        cin >> NPSN;
        P = L.first;
        while(P != NULL){
            if(P->info.NPSN == NPSN){
                cout << "Data Sekolah ditemukan" << endl;
                cout << endl << "===============================" << endl;
                cout << "Nama Sekolah: " << P->info.nama << endl;
                cout << "Alamat Sekolah: " << P->info.alamat << endl;
                cout << "NPSN Sekolah: " << P->info.NPSN << endl;
                cout << endl << "===============================" << endl;
                return;
            }else{
                P = P->next_Sekolah;
            }
        }
    }
}
void findSiswa(List_Siswa L, adr_Siswa &P){
    if (L.first == NULL){
        cout << "Data Siswa kosong" << endl;
        return;
    }else{
        string NISN;
        cout << "Masukkan NISN Siswa: ";
        cin >> NISN;
        P = L.first;
        while(P != NULL){
            if(P->info.NISN == NISN){
                cout << "Data Siswa ditemukan" << endl;
                cout << endl << "===============================" << endl;
                cout << "Nama Siswa: " << P->info.nama << endl;
                cout << "Kelas Siswa: " << P->info.kelas << endl;
                cout << "NISN Siswa: " << P->info.NISN << endl;
                cout << endl << "===============================" << endl;
                return;
            }else{
                P = P->next_Siswa;
            }
        }
    }
}
void checkRelasi(List_Relasi L, adr_Siswa P, adr_Sekolah Q, adr_Relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_Siswa == P && R->next_Sekolah == Q){
            cout << endl << "===============================" << endl;
            cout << "Relasi ditemukan" << endl;
            cout << "Info Relasi: " << R->info << endl;
            cout << endl << "===============================" << endl;
            return;
        }else{
            R = R->next_Relasi;
        }
    }
    cout << endl << "===============================" << endl;
            cout << "Relasi Tidak Ditemukan" << endl;
    cout << endl << "===============================" << endl;
}
void showSekolah(List_Sekolah L){
    if(L.first == NULL){
        cout << "Data Sekolah kosong" << endl;
    }else{
        adr_Sekolah P = L.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Sekolah: " << P->info.nama << endl;
            cout << "Alamat Sekolah: " << P->info.alamat << endl;
            cout << "NPSN Sekolah: " << P->info.NPSN << endl;
            cout << endl;
            P = P->next_Sekolah;
        }
        cout << "===============================" << endl;
    }
}
void showSiswa(List_Siswa L){
    if(L.first == NULL){
        cout << "Data Siswa kosong" << endl;
    }else{
        adr_Siswa P = L.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Siswa: " << P->info.nama << endl;
            cout << "Kelas Siswa: " << P->info.kelas << endl;
            cout << "NISN Siswa: " << P->info.NISN << endl;
            cout << endl;
            P = P->next_Siswa;
        }
        cout << "===============================" << endl;
    }
}
void showSiswa_dariSekolah(List_Relasi L, adr_Sekolah P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "===============================" << endl;
        while(R != NULL){
            if(R->next_Sekolah == P){
                cout << "Nama Siswa: " << R->next_Siswa->info.nama << endl;
                cout << "Kelas Siswa: " << R->next_Siswa->info.kelas << endl;
                cout << "NISN Siswa: " << R->next_Siswa->info.NISN << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "===============================" << endl;
    }
}
void showSekolah_dariSiswa(List_Relasi L, adr_Siswa P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "===============================" << endl;
        while(R != NULL){
            if(R->next_Siswa == P){
                cout << "Nama Sekolah: " << R->next_Sekolah->info.nama << endl;
                cout << "Alamat Sekolah: " << R->next_Sekolah->info.alamat << endl;
                cout << "NPSN Sekolah: " << R->next_Sekolah->info.NPSN << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "===============================" << endl;
    }
}
void showAll_RelasiSekolah(List_Sekolah Ld, List_Relasi Lr){
    if(Ld.first == NULL){
        cout << "Data Sekolah kosong" << endl;
    }else{
        adr_Sekolah P = Ld.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Sekolah: " << P->info.nama << endl;
            cout << "Alamat Sekolah: " << P->info.alamat << endl;
            cout << "NPSN Sekolah: " << P->info.NPSN << endl;
            cout << "===============================" << endl;
            showSiswa_dariSekolah(Lr, P);
            P = P->next_Sekolah;
        }
    }
}
void showAll_RelasiSiswa(List_Siswa Lm, List_Relasi Lr){
    if(Lm.first == NULL){
        cout << "Data Siswa kosong" << endl;
    }else{
        adr_Siswa P = Lm.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Siswa: " << P->info.nama << endl;
            cout << "Kelas Siswa: " << P->info.kelas << endl;
            cout << "NISN Siswa: " << P->info.NISN << endl;
            cout << "===============================" << endl;
            showSekolah_dariSiswa(Lr, P);
            P = P->next_Siswa;
        }
    }
}
void countSiswa(List_Relasi L, adr_Sekolah P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Sekolah == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Siswa di Sekolah " << P->info.nama << ": " << hitung << endl;
    }
}
void countSekolah(List_Relasi L, adr_Siswa P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int hitung = 0;
        while(R != NULL){
            if(R->next_Siswa == P){
                hitung++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Sekolah dari Siswa " << P->info.nama << ": " << hitung << endl;
    }
}
void countSiswa_Less(List_Relasi Lr, List_Sekolah Ld){
    if(Lr.first == NULL){
        showSekolah(Ld);
    }else{
        adr_Sekolah P = Ld.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Sekolah == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
            }
            if (!found){
                hitung++;
            }
            P = P->next_Sekolah;
        }
        cout << "Jumlah Sekolah yang tidak memiliki Siswa: " << hitung << endl;
    }
}
void countSekolah_Less(List_Relasi Lr, List_Siswa Lm){
    if(Lr.first == NULL){
        showSiswa(Lm);
    }else{
        adr_Siswa P = Lm.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Siswa == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
            }
            if (!found){
                hitung++;
            }
            P = P->next_Siswa;
        }
        cout << "Jumlah Siswa yang tidak memiliki Sekolah: " << hitung << endl;
    }
}
void editSekolah(List_Relasi &L, adr_Sekolah P, adr_Siswa Q, adr_Siswa R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, Q, P, T);
    T->next_Siswa = R;
}
void editSiswa(List_Relasi &L, adr_Siswa P, adr_Sekolah Q, adr_Sekolah R){
    adr_Relasi S = L.first;
    adr_Relasi T = NULL;
    checkRelasi(L, P, Q, T);
    T->next_Sekolah = R;
}
