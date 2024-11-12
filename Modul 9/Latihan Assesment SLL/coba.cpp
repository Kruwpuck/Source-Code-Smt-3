#include "coba.h"
address createElm_103032330054(infotype data){
    address P = new elmlist;
    P->info = data;
    return P;
}
void insertFirst_103032330054(List &L, address P){
    if (L.first == NULL){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}
void deleteFirst_103032330054(List &L, address &P){
    if (L.first == NULL){
        cout << endl << "LIST KOSONG" << endl;
    }else if (L.first->next == NULL){
        P = L.first;
        L.first = NULL;
    }else{
        P = L.first;
        L.first = L.first->next;
        P->next = NULL;
    }
}
void showInfo_103032330054(List L){
    if (L.first != NULL){
        address P = L.first;
        while (P != NULL){
            cout << "---------------------------" << endl;
            cout << P->info.nama << endl;
            cout << P->info.rating << endl;
            cout << "---------------------------" << endl;
            P = P->next;
        }
    }else{
        cout << endl << "LIST KOSONG" << endl;
    }
}
void reset_103032330054(List &L){
    address Q;
    float total=0;
    float driver=0;
    while (L.first != NULL){
        deleteFirst_103032330054(L,Q);
        cout << "---------------------------" << endl;
        cout << Q->info.nama << endl;
        cout << Q->info.rating << endl;
        cout << "---------------------------" << endl;
        total += Q->info.rating;
        driver++;
    }
    cout << endl << "Rata rata: " << total/driver << endl;
}
void split_103032330054(List &L, List &L1, List &L2, float N){
    address P,Q;
    while (L.first != NULL){
        deleteFirst_103032330054(L,Q);
        if (Q->info.rating < N){
            insertFirst_103032330054(L1,Q);
        }else{
            insertFirst_103032330054(L2,Q);
        }
    }
}
