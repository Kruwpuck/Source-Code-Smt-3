#include "header.h"
void insertLastint(List_int &L, adr_int P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_int Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertFirstint(List_int &L, adr_int P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
adr_int deleteListint(List_int &L) {
    if (L.first->next == NULL) {
        adr_int P = L.first;
        L.first = NULL;
        return P;
    }else{
        adr_int Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        adr_int P = Q->next;
        Q->next = NULL;
        return P;
    }
}
