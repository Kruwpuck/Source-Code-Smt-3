#include "dll.h"

void createList_103032300090(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}


bool isEmpty_103032300090(List L){
    return L.first == NULL;
}


address creatNewElm_103032300090(infotype X){
    address P = new elmlist;
        P->info = X;
        P->next = NULL;
        P->prev = NULL;
        return P;
}

void insertfirst_103032300090(List &L,address P){
    if(isEmpty_103032300090(L)){
        L.first = P;
        L.last = P;
    }else{
        P->next = L.first;
       L.first->prev = P;
        L.first = P;
    }
}


void insertafter_103032300090(List &L, address &Prec,address P){
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
}

void insertlast_103032300090(List &L,address P){
     if (isEmpty_103032300090(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deletefirst_103032300090(List &L,address &P){
    if(L.last == L.first){
        P= L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        L.first->prev =NULL;
        P->next = NULL;
    }

}
void deleteafter_103032300090(List &L,address prec,address &P){
    P = prec->next;
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}


void deletelast_103032300090(List &L,address &P){
    if(L.last == L.first){
        P = L.first;
        L.first = NULL;
        L.last =NULL;
    }else{
        P = L.last;
        L.last->next = NULL;
        P->prev =NULL;
    }
}

void concat_103032300090(List L1, List L2, List &L3){
    L3 = L1;
    L3.last ->next = L2.first;
    L2.first->prev = L3.last;
    L3.last = L2.last;
}

address findsong_103032300090(string judul, List L) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info.judul == judul) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void removesong_103032300090(string judul,List &L){
    if (isEmpty_103032300090(L)){
        cout << "List Kosong" << endl;
    }else {
        address P = findsong_103032300090(judul,L);
        if (P!=NULL){
            deletefirst_103032300090(L,P);
        }else if(P == L.last){
            deletelast_103032300090(L,P);
        }else {
            deleteafter_103032300090(L,P->prev,P);
        }
        delete P;
    }
}

void show_103032300090(List L){
    address P = L.first;
    while(P!=NULL){
        cout<< "Judul Lagu  :" << P->info.judul << endl;
        cout<< "Nama penyanyi  :" << P->info.penyanyi << endl;
        P = P->next;
    }
}
