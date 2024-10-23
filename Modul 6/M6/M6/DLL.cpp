#include <iostream>
#include "DLL.h"

using namespace std;

void createNewlist_103032300129(List &L){
    L.first = NULL;
    L.last = NULL;

}

bool isEmpty_103032300129(List L){
    return L.first == NULL;
}

adr createNewEml_103032300129(infotype X){
    adr p = new elmlist;
    p->info = X;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void insertFirst_103032300129(List &L, adr p){
    if(isEmpty_103032300129(L)){
        L.first = p;
        L.last = p;
    }else{
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertAfter_103032300129(List &L, adr &prec, adr p){
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
}


void insertLast_103032300129(List &L, adr p){
    if(isEmpty_103032300129(L)){
        L.first = p;
        L.last = p;
    }else{
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void deleteFirst_103032300129(List &L, adr &p){
    p = L.first;
    if(L.first != L.last){
        L.first = p->next;
        p->next = NULL;
        L.first->prev = NULL;
    }else{
        L.first = NULL;
        L.last = NULL;
    }
}

void deleteAfter_103032300129(List &L, adr prec, adr &p){
    if(prec == NULL || prec->prev == NULL || prec->next == NULL){
        p = NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next->prev = prec;
        p->prev = NULL;
        p->next = NULL;
    }
}

void deleteLast_103032300129(List &L, adr &p){
     if(L.first != L.last){
        p = L.last;
        L.last = L.last->prev;
        p->prev = NULL;
        L.last->next = NULL;
    }else{
        p = L.last;
        L.first =NULL;
        L.last = NULL;
    }
}

void concat_103032300129(List L1, List L2, List &L3){
    adr P = L1.first;
    adr Q = L2.first;
    adr temp;
    while(P != NULL){
        temp = createNewEml_103032300129(P->info);
        insertLast_103032300129(L3, temp);
        P = P->next;
    }

    while(Q != NULL){
        temp = createNewEml_103032300129(Q->info);
        insertLast_103032300129(L3, temp);
        Q = Q->next;
    }

}

adr findLagu_103032300129(List L, string judul){
    adr p = L.first;
    while(p != NULL){
        if(p->info.judulLagu == judul){
            return p;
        }
        p = p->next;
    }
        return NULL;
}


void removeLagu_103032300129(List &L, string judul){
    if(isEmpty_103032300129(L)){
        cout << "List kosong";
    }else{
        adr prec;
        adr p = findLagu_103032300129(L, judul);
        if (p != NULL){
            if(p == L.first){
                deleteFirst_103032300129(L, p);
            }else if(p == L.last){
                deleteLast_103032300129(L, p);
            }else{
                prec = p->prev;
                deleteAfter_103032300129(L, prec, p);
            }
            delete p;
        }
    }
}

void show_103032300129(List L){
    adr p = L.first;
    while(p != NULL){
        cout << "Lagu    : " << p->info.penyanyi << endl;
        cout << "Penyanyi: " << p->info.judulLagu << endl;
        cout << endl;

        p = p->next;
    }
}
