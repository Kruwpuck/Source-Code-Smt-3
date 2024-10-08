#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L){
    L.first = NULL;
}

address allocate(infotype x){
    address P = new elmlist;
    P-> info = x;
    P-> next = NULL;

    return P;
}

void insertFisrt(List &L, address P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P-> next = L.first;
        L.first = P;
    }

}

void insertLast(List &L, address P){
    address Q;

    if(L.first == NULL){
        L.first = P;
    }else{
        Q = L.first;
    while(Q->next!= NULL){
            Q = Q->next;
        }
        Q->next = P;
    };
}

void insertAfter(List &L, address P, address prec){
    if(prec != NULL){
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteFirst(List &L, address &P){
    if(L.first == NULL){
        P = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P){
    address Q;
    address r;
    if(L.first == NULL){
        P = NULL;
    }else{
        Q = L.first;
        while(Q->next != NULL){
            r = Q;
            Q = Q-> next;
        }
        P = r->next;
        r->next = NULL;
    }
}

void deleteAfter(List &L, address &P, address prec ){
    if(prec != NULL && prec->next != NULL){
        P = prec->next;
        prec->next = P->next;
        P->next = NULL;
    }
}

address searchInfo(List &L, infotype x){
    address P;
    while(P != NULL){
        if (P->info == x){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printInfo(List L){
    address P = L.first;
    while(P != NULL){
        cout << P-> info << ", ";
        P = P-> next;
    }
    cout << endl;
}
