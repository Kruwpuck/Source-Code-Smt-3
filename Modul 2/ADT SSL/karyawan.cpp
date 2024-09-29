#include "karyawan.h"

void Create_List(List &L){
    L.first = NULL;
}

adr New_Elemen(infotype data){
    adr P = new elmList;
    P -> info = data;
    P -> next = NULL;
    return P;
}

void Insert_First(List &L, adr P){
    if (L.first == NULL){
        L.first = P;
    }else{
        P ->next = L.first;
        L.first = P;
    }
}

void Insert_Last(List &L, adr P){
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

void Insert_After(List &L, adr prec, adr P){
    if (prec != NULL){
        P ->next = prec ->next;
        prec ->next = P;
    }
}

void Delete_First(List &L, adr &P){
    if (L.first == NULL){
        P = NULL;
    }else{
        P = L.first;
        L.first = P ->next;
        P ->next = NULL;
    }

}

void Delete_Last(List &L, adr &P){
    adr Q;
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next ==NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        adr q = L.first;
        while (q->next->next != NULL) {
            q = q->next;
        }
        P = q->next;
        q->next = NULL;
    }
}

void Delete_After(List &L, adr prec, adr &P){
    if (prec != NULL && prec->next != NULL){
        P = prec -> next;
        prec -> next = P -> next;
        P ->next = NULL;
    }

}

void Show(List L){

    if (L.first == NULL){
       cout << "List kosong" << endl;
    }else{
        adr P = L.first;  // Start from the first node
        while (P != NULL) {
        // Display the employee's details
            cout << P->info.nama << " " << P->info.npwp << " " << P->info.  jabatan << " " << P->info.gaji << endl;

        // Move to the next node
        P = P->next;
        }
    }
    // Traverse the list

}

