#include "DLL.h"

bool isEmpty_103032330054(List L){
    return L.first == NULL;
}
address createNewElmt_103032330054(infotype X){
    address p = new elmlist;
    p->info=X;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void inserFirst_103032330054(List &L, address P){
    if (isEmpty_103032330054){
        L.first = P;
        L.last = P;
    }else{
        L.first->prev = P;
        P->next = L.first;
        L.first = P;
    }
}
void insertAfter_103032330054(List &L, address &prec, address P){
    P->next = prec->next;
    P->prev = prec;
    prec->next->prev = P;
    prec->next = P;
}
void insertLast_103032330054(List &L, address P){
    L.last->next = P;
    P->prev = L.last;
    L.last = P;
}
void deleteFirst_103032330054(List &L, address &P){
    if (L.last==L.first) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}
void deleteAfter_103032330054(List &L, address prec, address &P){
    P = prec->next;
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}
void deleteLast_103032330054(List &L, address &P){
    if (L.last==L.first) {
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
void concat_103032330054(List L1, List L2, List &L3){
    L3 = L1;
    L3.last->next = L2.first;
    L2.first->prev = L3.last;
}
address findLagu_103032330054(List L, string Judul){
    if (isEmpty_103032330054){
        return NULL;
    }else{
        address p = L.first;
        while (p!=NULL){
            if (p->info.judul == Judul){
                return p;
            }
            p=p->next;
        }
        return NULL;
    }
}
void removeLagu_103032330054(List &L, string Judul){
    if (isEmpty_103032330054){
        cout << "List Kosong" << endl;
    }else{
        address p = findLagu_103032330054(L, Judul);
        if (p == NULL){
            cout << "Lagu tidak ditemukan" << endl;
        }else if (p == L.first){
            deleteFirst_103032330054(L,p);
        }else if (p == L.last){
            deleteLast_103032330054(L,p);
        }else{
            deleteAfter_103032330054(L, p->prev, p);
        }
    }
}
