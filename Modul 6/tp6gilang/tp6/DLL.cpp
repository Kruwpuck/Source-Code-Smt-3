#include<iostream>
#include"DLL.h"

using namespace std;

void createlist_103032300130(list &l){
    l.first = NULL;
    l.last = NULL;
}

bool isEmpty_10302300130(list l){
    return l.first == NULL && l.last == NULL;
}

void createNewElm_10302300130(infotype x, address &p){
    p = new elmlist;
    p -> info = x;
    p -> next = NULL;
    p -> prev = NULL;
}

void insertFirst_10302300130(list &l, address p){
    if (isEmpty_10302300130(l)){
        l.first = p;
        l.last = p;
    } else {
        p -> next = l.first;
        l.first -> prev = p;
        l.first = p;
    }
}


void insertAfter_10302300130(list &l, address &p, address &prec){
    p -> next = prec -> next;
    p -> prev = prec;
    prec -> next -> prev = p;
    prec -> next = p;
}


void insertLast_10302300130(list &l, address p){
    if (isEmpty_10302300130(l)){
        l.first = p;
        l.last = p;
    } else {
        p -> prev = l.last;
        p -> prev -> next = p;
        l.last = p;
    }
}

void deleteFirst_10302300130(list &l, address &p){
    if (l.first != l.last){
        address p = l.first;
        l.first = p -> next;
        p -> next -> prev = NULL;
        p -> next = NULL;
    } else {
        l.first = NULL;
        l.last = NULL;
    }
}


void deleteAfter_10302300130(list &l, address &prec, address &p){
    p = prec -> next;
    prec -> next = p -> next;
    p -> next -> prev = prec;
    p -> prev = NULL;
    p -> next = NULL;
}

void deleteLast_10302300130(list &l, address &p){
    if (l.first != l.last){
        address p = l.last;
        l.last = p -> prev;
        p -> prev -> next = NULL;
        p -> prev = NULL;
    } else {
        l.first = NULL;
        l.last = NULL;
    }
}

//bug

void concat_10302300130(list l1, list l2, list &l3){
    address q;
    createlist_103032300130(l3);
    address P = l1.first;
    while (P != NULL) {
        createNewElm_10302300130(P->info, q);
        insertLast_10302300130(l3, q);
        P = P->next;
    }
    P = l2.first;
    while (P != NULL) {
        createNewElm_10302300130(P->info, q);
        insertLast_10302300130(l3, q);
        P = P->next;
    }
}

address findSong_10302300130(list &l, string judul){
    if (! isEmpty_10302300130(l)){
    address p = l.first;
    while (p != NULL){
        if (p -> info.judul == judul){
            return p;
        }
        p = p -> next;
    }
    }
}

//bug
//bikin delete fisrt, after, last
void removeSong_10302300130(string judul, list &l){
    address p;
    if (l.first != l.last){
    p = l.first;
    while (p -> info.judul != judul){
        p = p -> next;
    }
    if (p -> next == NULL){
        l.last = p -> prev;

    } else if (p -> prev == NULL){
        l.first = p -> next;
    } else {
    p -> prev -> next = p-> next;
    p -> next -> prev = p -> prev;
    }
    } else {
        p = l.first;
        l.first = NULL;
        l.last = NULL;
    }
    delete p;
}

void show_103032300130(list l){
    address p = l.first;
    while ( p != NULL){
        cout << p -> info.judul << " " << p -> info.nama << endl;
        p = p -> next;
    }
}
