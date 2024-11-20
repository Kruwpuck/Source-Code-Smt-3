#include "flight.h"
void createListJadwal_103032300018(ListJadwal &L){
    L.First = NULL;
}
adr_jadwalP createElemenJadwal_103032300018(infotype X){
    adr_jadwalP P = new elemenJadwal;
    P->info = X;
    P->next = NULL;
    return P;
}
void InsertLastJ_103032300018(ListJadwal &L, adr_jadwalP P){
    if (L.First == NULL){
        L.First = P;
    }else{
        adr_jadwalP Q = L.First;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
void ShowJadwal_103032300018(ListJadwal L){
    if (L.First == NULL){
        cout << "KOSONG" << endl;
    }else{
        adr_jadwalP P = L.First;
        while(P != NULL){
            cout << P->info.Kode << ", ";
            cout << P->info.Jenis << ", ";
            cout << P->info.Tanggal << ", ";
            cout << P->info.Waktu << ", ";
            cout << P->info.Asal << ", ";
            cout << P->info.Tujuan << ", ";
            cout << P->info.Kapasitas << endl;
            P = P->next;
        }
    }
}
void DeleteFirstJ_103032300018(ListJadwal &L, adr_jadwalP &P){
    if (L.First == NULL){
        cout << endl << "KOSONG" << endl;
    }else if (L.First->next == NULL){
        P = L.First;
        L.First = NULL;
    }else{
        P = L.First;
        L.First = P->next;
        P->next = NULL;
    }
}
adr_jadwalP SearchJ_103032300018(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP P = L.First;
    while(P != NULL){
        if (P->info.Asal == dari && P->info.Tujuan == ke && P->info.Tanggal == tanggal){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
