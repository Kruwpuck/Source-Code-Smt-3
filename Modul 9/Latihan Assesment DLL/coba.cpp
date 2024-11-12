#include "coba.h"
address createElm_103032330054(infotype data){
    address P = new elmlist;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    return P;
}
void createList_103032330054(List &L){
    L.first = NULL;
    L.last = NULL;
}
void insertLast_103032330054(List &L, address P){
    if (L.last == NULL){
        L.first = P;
        L.last = P;
    }else{
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void deleteLast_103032330054(List &L, address &P){
    if (L.first == NULL){
        cout << endl << "LIST KOSONG" << endl;
    }else if (L.last->prev == NULL){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
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
    while (L.last != NULL){
        deleteLast_103032330054(L,Q);
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
    address Q;
    while (L.last != NULL){
        deleteLast_103032330054(L,Q);
        if (Q->info.rating < N){
            insertLast_103032330054(L1,Q);
        }else{
            insertLast_103032330054(L2,Q);
        }
    }
}
