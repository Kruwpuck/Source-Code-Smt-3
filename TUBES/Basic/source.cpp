#include "header.h"
void insertLastchar(List_char &L, adr_char P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_char Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertFirstchar(List_char &L, adr_char P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}