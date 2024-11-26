#include "header.h"
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
        L.last = P;
    }else{
        L.last->next_Murid = P;
        P->prev_Murid = L.last;
        L.last = P;
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
void deleteGuru(List_Guru &L, adr_Guru &P){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
        return;
    }
    findMurid(L, P);
    if (P == NULL){
        cout << "Data Murid tidak ditemukan" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else if (L.last == P){
        L.last = P->prev_Murid;
        P->prev_Murid = NULL;
        L.last->next_Murid = NULL;
    }else if (L.first == P){
        L.first = P->next_Murid;
        P->next_Murid = NULL;
        L.first->prev_Murid = NULL;
    }else{
        P->prev_Murid->next_Murid = P->next_Murid;
        P->next_Murid->prev_Murid = P->prev_Murid;
        P->next_Murid = NULL;
        P->prev_Murid = NULL;
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
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else if (L.last == P){
        L.last = P->prev_Murid;
        P->prev_Murid = NULL;
        L.last->next_Murid = NULL;
    }else if (L.first == P){
        L.first = P->next_Murid;
        P->next_Murid = NULL;
        L.first->prev_Murid = NULL;
    }else{
        P->prev_Murid->next_Murid = P->next_Murid;
        P->next_Murid->prev_Murid = P->prev_Murid;
        P->next_Murid = NULL;
        P->prev_Murid = NULL;
    }
}
void deleteRelasi(List_Relasi &L ,adr_Relasi &P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
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
void findGuru(List_Guru L, adr_Guru &P){
    if (L.first == NULL){
        cout << "Data Guru kosong" << endl;
        return;
    }else{
        string NUPTK;
        cout << "Masukkan NUPTK Guru: ";
        cin >> NUPTK;
        P = L.first;
        while(P != NULL){
            if(P->info.NUPTK == NUPTK){
                cout << "Data Guru ditemukan" << endl;
                cout << endl << "===============================" << endl;
                cout << "Nama Guru: " << P->info.nama << endl;
                cout << "Jabatan Guru: " << P->info.Jabatan << endl;
                cout << "NUPTK Guru: " << P->info.NUPTK << endl;
                cout << endl << "===============================" << endl;
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
        string NISN;
        cout << "Masukkan NISN Murid: ";
        cin >> NISN;
        P = L.first;
        while(P != NULL){
            if(P->info.NISN == NISN){
                cout << "Data Murid ditemukan" << endl;
                cout << endl << "===============================" << endl;
                cout << "Nama Murid: " << P->info.nama << endl;
                cout << "Kelas Murid: " << P->info.kelas << endl;
                cout << "NISN Murid: " << P->info.NISN << endl;
                cout << endl << "===============================" << endl;
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
void showGuru(List_Guru L){
    if(L.first == NULL){
        cout << "Data Guru kosong" << endl;
    }else{
        adr_Guru P = L.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Guru: " << P->info.nama << endl;
            cout << "Jabatan Guru: " << P->info.Jabatan << endl;
            cout << "NUPTK Guru: " << P->info.NUPTK << endl;
            cout << endl;
            P = P->next_Guru;
        }
        cout << "===============================" << endl;
    }
}
void showMurid(List_Murid L){
    if(L.first == NULL){
        cout << "Data Murid kosong" << endl;
    }else{
        adr_Murid P = L.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Murid: " << P->info.nama << endl;
            cout << "Kelas Murid: " << P->info.kelas << endl;
            cout << "NISN Murid: " << P->info.NISN << endl;
            cout << endl;
            P = P->next_Murid;
        }
        cout << "===============================" << endl;
    }
}
void showMurid_dariGuru(List_Relasi L, adr_Guru P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "===============================" << endl;
        while(R != NULL){
            if(R->next_Guru == P){
                cout << "Nama Murid: " << R->next_Murid->info.nama << endl;
                cout << "Kelas Murid: " << R->next_Murid->info.kelas << endl;
                cout << "NISN Murid: " << R->next_Murid->info.NISN << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "===============================" << endl;
    }
}
void showGuru_dariMurid(List_Relasi L, adr_Murid P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "===============================" << endl;
        while(R != NULL){
            if(R->next_Murid == P){
                cout << "Nama Guru: " << R->next_Guru->info.nama << endl;
                cout << "Jabatan Guru: " << R->next_Guru->info.Jabatan << endl;
                cout << "NUPTK Guru: " << R->next_Guru->info.NUPTK << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "===============================" << endl;
    }
}
void showAll_RelasiGuru(List_Guru Ld, List_Relasi Lr){
    if(Ld.first == NULL){
        cout << "Data Guru kosong" << endl;
    }else{
        adr_Guru P = Ld.first;
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Guru: " << P->info.nama << endl;
            cout << "Jabatan Guru: " << P->info.Jabatan << endl;
            cout << "NUPTK Guru: " << P->info.NUPTK << endl;
            cout << "===============================" << endl;
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
        cout << endl << "===============================" << endl;
        while(P != NULL){
            cout << "Nama Murid: " << P->info.nama << endl;
            cout << "Kelas Murid: " << P->info.kelas << endl;
            cout << "NISN Murid: " << P->info.NISN << endl;
            cout << "===============================" << endl;
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
void countMurid_Less(List_Relasi Lr, List_Guru Ld){
    if(Lr.first == NULL){
        showGuru(Ld);
    }else{
        adr_Guru P = Ld.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Guru == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
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
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Murid == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
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