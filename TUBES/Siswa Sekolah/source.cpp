#include "header.h"
int menu(List_Relasi &Lr, List_Sekolah &Lp, List_Siswa &Lc){
    adr_Relasi R;
    adr_Sekolah P;
    adr_Siswa C;
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
    if (pilihan == 0){
        return;
    }
    while ( pilihan < 1 || pilihan > 4){
        cout << "Pilihan tidak valid" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    if (pilihan == 1){
        cout << endl << "===============MENU SEKOLAH================" << endl;
        cout << "1. Tambah Sekolah" << endl;
        cout << "2. Hapus Sekolah" << endl;
        cout << "3. Cari Sekolah" << endl;
        cout << "4. Tampilkan Sekolah" << endl;
        cout << "5. Jumlah Sekolah Tanpa Siswa" << endl;
        cout << "6. Data Siswa dari Sekolah Tertentu" << endl;
        cout << "5. Kembali" << endl;
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
            cout << "Elemen Pertama List Sekolah berhasil dihapus" << endl;
        }else if(pilihan == 3){
            findSekolah(Lp, P);
        }else if(pilihan == 4){
            showSekolah(Lp);
        }
    }else if(pilihan == 2){
        cout << endl << "===============MENU SISWA================" << endl;
        cout << "1. Tambah Siswa" << endl;
        cout << "2. Hapus Siswa" << endl;
        cout << "3. Cari Siswa" << endl;
        cout << "4. Tampilkan Siswa" << endl;
        cout << "5. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }else if (pilihan == 3){
        cout << endl << "===============MENU RELASI================" << endl;
        cout << "1. Tambah Relasi" << endl;
        cout << "2. Hapus Relasi" << endl;
        cout << "3. Tampilkan Relasi" << endl;
        cout << "4. Edit Relasi" << endl;
        cout << "5. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
    }
    menu(Lr, Lp, Lc);
}
void insertSekolah(List_Sekolah &L, adr_Sekolah P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
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
        L.last->next_Siswa = P;
        P->prev_Siswa = L.last;
        L.last = P;
    }
}
void insertRelasi(List_Relasi &L, adr_Relasi P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Relasi = L.first;
        L.first = P;
    }
}
void deleteSekolah(List_Sekolah &L, adr_Sekolah &P){
    if(L.first == NULL){
        cout << "Data Sekolah kosong" << endl;
    }else if(L.first == L.last){
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
void checkRelasi(List_Relasi L, adr_Siswa P, adr_Sekolah Q){
    adr_Relasi R = L.first;
    while(R != NULL){
        if(R->next_Siswa == P && R->next_Sekolah == Q){
            cout << "Relasi ditemukan" << endl;
            break;
        }else{
            R = R->next_Relasi;
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
    adr_Relasi R = L.first;
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
void showAll_RelasiSiswa(List_Sekolah Lm, List_Relasi Lr){
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
        int count = 0;
        while(R != NULL){
            if(R->next_Sekolah == P){
                count++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Siswa di Sekolah " << P->info.nama << ": " << count << endl;
    }
}
void countSekolah(List_Relasi L, adr_Siswa P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        int count = 0;
        while(R != NULL){
            if(R->next_Siswa == P){
                count++;
            }
            R = R->next_Relasi;
        }
        cout << "Jumlah Sekolah dari Siswa " << P->info.nama << ": " << count << endl;
    }
}
void countSiswa_Less(List_Relasi Lr, List_Sekolah Ld){
    if(Lr.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Sekolah P = Ld.first;
        bool found;
        while (P != NULL){
            int count = 0;
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
                count++;
            }
            P = P->next_Sekolah;
        }
        cout << "Jumlah Sekolah yang tidak memiliki Siswa: " << count << endl;
    }
}
void countSekolah_Less(List_Relasi Lr, List_Siswa Lm){
    if(Lr.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Siswa P = Lm.first;
        bool found;
        while (P != NULL){
            int count = 0;
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
                count++;
            }
            P = P->next_Siswa;
        }
        cout << "Jumlah Siswa yang tidak memiliki Sekolah: " << count << endl;
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
