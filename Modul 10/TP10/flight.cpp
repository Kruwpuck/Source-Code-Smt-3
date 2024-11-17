#include "flight.h"
void createListJadwal_103032330054(ListJadwal &L){
    L.First = NULL;
}
adr_jadwalP createElemenJadwal_103032330054(infotype X){
    adr_jadwalP P = new elemenJadwal;
    P->info = X;
    P->next = NULL;
    return P;
}
void InsertLastJ_103032330054(ListJadwal &L, adr_jadwalP P){
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
void ShowJadwal_103032330054(ListJadwal L){
    if (L.First == NULL){
        cout << "List Kosong" << endl;
    }else{
        adr_jadwalP P = L.First;
        while(P != NULL){
            cout << P->info.Kode << ", " << P->info.Jenis << ", " << P->info.Tanggal << ", " << P->info.Waktu << ", " << P->info.Asal << ", " << P->info.Tujuan << ", " << P->info.Kapasitas << endl;
            P = P->next;
        }
    }
}
void DeleteFirstJ_103032330054(ListJadwal &L, adr_jadwalP &P){
    if (L.First == NULL){
        cout << endl << "List Kosong" << endl;
    }else if (L.First->next == NULL){
        P = L.First;
        L.First = NULL;
    }else{
        P = L.First;
        L.First = P->next;
        P->next = NULL;
    }
}
adr_jadwalP SearchJ_103032330054(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP P = L.First;
    while(P != NULL){
        if (P->info.Asal == dari && P->info.Tujuan == ke && P->info.Tanggal == tanggal){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
