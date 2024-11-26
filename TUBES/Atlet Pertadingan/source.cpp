#include "header.h"
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
        L.first->prev_Relasi = P;
        L.first = P;
    }
}
void deletePertandingan(List_Pertandingan &L, adr_Pertandingan &P){
    if(L.first == NULL){
        cout << "Data Atlet kosong" << endl;
        return;
    }
    findAtlet(L, P);
    if (P == NULL){
        cout << "Data Atlet tidak ditemukan" << endl;
        return;
    }
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else if (L.last == P){
        L.last = P->prev_Atlet;
        P->prev_Atlet = NULL;
        L.last->next_Atlet = NULL;
    }else if (L.first == P){
        L.first = P->next_Atlet;
        P->next_Atlet = NULL;
        L.first->prev_Atlet = NULL;
    }else{
        P->prev_Atlet->next_Atlet = P->next_Atlet;
        P->next_Atlet->prev_Atlet = P->prev_Atlet;
        P->next_Atlet = NULL;
        P->prev_Atlet = NULL;
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
    if(L.first == L.last){
        L.first = NULL;
        L.last = NULL;
    }else if (L.last == P){
        L.last = P->prev_Atlet;
        P->prev_Atlet = NULL;
        L.last->next_Atlet = NULL;
    }else if (L.first == P){
        L.first = P->next_Atlet;
        P->next_Atlet = NULL;
        L.first->prev_Atlet = NULL;
    }else{
        P->prev_Atlet->next_Atlet = P->next_Atlet;
        P->next_Atlet->prev_Atlet = P->prev_Atlet;
        P->next_Atlet = NULL;
        P->prev_Atlet = NULL;
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
void checkRelasi(List_Relasi L, adr_Atlet P, adr_Pertandingan Q, adr_Relasi &R){
    R = L.first;
    while(R != NULL){
        if(R->next_Atlet == P && R->next_Pertandingan == Q){
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

void showAtlet_dariPertandingan(List_Relasi L, adr_Pertandingan P){
    if(L.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = L.first;
        cout << endl << "===============================" << endl;
        while(R != NULL){
            if(R->next_Pertandingan == P){
                cout << "Nama Atlet: " << R->next_Atlet->info.nama << endl;
                cout << "Kelas Atlet: " << R->next_Atlet->info.kelas << endl;
                cout << "NISN Atlet: " << R->next_Atlet->info.NISN << endl;
                cout << "Info Relasi: " << R->info << endl;
                cout << endl;
            }
            R = R->next_Relasi;
        }
        cout << "===============================" << endl;
    }
}

void countAtlet(List_Relasi L, adr_Pertandingan P){
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
        cout << "Jumlah Atlet di Pertandingan " << P->info.nama << ": " << hitung << endl;
    }
}
void countPertandingan(List_Relasi L, adr_Atlet P){
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
        cout << "Jumlah Pertandingan dari Atlet " << P->info.nama << ": " << hitung << endl;
    }
}
void countAtlet_Less(List_Relasi Lr, List_Pertandingan Ld){
    if(Lr.first == NULL){
        showPertandingan(Ld);
    }else{
        adr_Pertandingan P = Ld.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Pertandingan == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
            }
            if (!found){
                hitung++;
            }
            P = P->next_Pertandingan;
        }
        cout << "Jumlah Pertandingan yang tidak memiliki Atlet: " << hitung << endl;
    }
}
void countPertandingan_Less(List_Relasi Lr, List_Atlet Lm){
    if(Lr.first == NULL){
        showAtlet(Lm);
    }else{
        adr_Atlet P = Lm.first;
        bool found;
        int hitung = 0;
        while (P != NULL){
            adr_Relasi R = Lr.first;
            found = false;
            while(R != NULL && !found){
                if (R->next_Atlet == P){
                    found = true;
                }else{
                    R = R->next_Relasi;
                }
            }
            if (!found){
                hitung++;
            }
            P = P->next_Atlet;
        }
        cout << "Jumlah Atlet yang tidak memiliki Pertandingan: " << hitung << endl;
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