#include "karyawan.h"

void Create_List(List &L){
    L.first = NULL;
}

adr New_Elemen(infotype data){
    adr P = new elmList;
    P -> next = NULL;
    (P -> info) = data;
    return P;
}

void Insert_First(List &L, adr &P){
    if (L.first == NULL){
        L.first = P;
    }else{
        P ->next = L.first;
        L.first = P;
    }
}

void Insert_Last(List &L, adr &P){
    adr Q;
    if (L.first != NULL){
        Q = L.first;
        while(Q -> next != NULL){
            Q = Q ->next;
        }
        Q ->next = P;
    }else {
        L.first = P;
    }
}

void Insert_After(List &L, adr &prec, adr &P){
    P ->next = prec ->next;
    prec ->next = P;
}

void Delete_First(List &L, adr &P){
    P = L.first;
    L.first = P ->next;
    P ->next = NULL;
}

void Delete_Last(List &L, adr &P){
    adr Q;
    Q = L.first;
    while ((Q ->next)->next != NULL){
        Q = Q ->next;
    }
    P = Q ->next;
    Q ->next = NULL;
}

void Delete_After(List &L, adr prec, adr &P){
    P = prec -> next;
    prec -> next = P -> next;
    P ->next = NULL;
}

void Show(List L){
    adr P;
    P = L.first;
    while (P != NULL) {
        cout << P ->info.nama << P ->info.npwp << P ->info.jabatan << P ->info.gaji << endl;
        P = P ->next;
    }
}

