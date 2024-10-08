#include "list.h"

void CreateList(List &L){
    L.first = NULL;
}

address allocate(infotype x){
    address p = new elmlist;
    p->info = x;
    p->next = NULL;
    return p;
}

void InsertFirst(List &L, address P){
    if (L.first == NULL){
        L.first = P;
    }else {
        P->next = L.first;
        L.first = P;
    }
    P = NULL;
}

void InsertLast(List &L, address P){
    if (L.first==NULL){
        L.first = P;
    }else{
        address Q = L.first;
        while (Q->next != NULL){
            Q =  Q->next;
        }
        Q->next = P;
    }
    P =NULL;
}

void InsertAfter(List &L, address prec, address P){
    P->next = prec->next;
    prec->next = P;
    P = NULL;
}

void DeleteFirst(List &L, address &P){
    if (L.first == NULL){
        P = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void DeleteLast(List &L, address &P){
    if (L.first == NULL){
        P = NULL;
    }else{
        address Q = L.first;
        address R;

        while (Q->next != NULL){
            R = Q;
            Q = Q->next;
        }
        P = R->next;
        R->next = NULL;
    }
}

void DeleteAfter(List &L, address prec, address &P){
    if (prec->next != NULL){
        P = prec->next;
        prec->next = P->next;
        P->next = NULL;
    }
}

address Search(List L, infotype x){
    address P = L.first;
    while (P->next != NULL){
        if (P->info == x){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void Show(List L){
    if (L.first != NULL){
        address P = L.first;
        while (P->next != NULL){
        cout << P->info << ", ";
    }
    }

    cout << endl;
}
