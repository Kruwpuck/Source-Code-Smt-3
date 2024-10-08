#include <iostream>
#include "list.h"

using namespace std;

void createList_103032300018(List &L){
    first(L) = NULL;
}

address allocate_103032300018(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst_103032300018(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void printInfo_103032300018(List L){
    address p = first(L);
    while (p != NULL){
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}
