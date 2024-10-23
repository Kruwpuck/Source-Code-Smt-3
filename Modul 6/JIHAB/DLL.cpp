#include "DLL.h"

void createList_103032330054(List &L){
    L.First = NULL;
    L.Last = NULL;
}

address createElemen_103032330054(infotype dataBaru){
    address P = new elmList;
    P->info = dataBaru;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLast_103032330054(List &L, address P){
    if (L.First == NULL){
        L.First = P;
        L.Last = P;
    }else{
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void insertAfter_103032330054(address &Prec, address &P){
    P->next = Prec->next;
    P->next->prev = P;
    P->next = P;
    P->prev = Prec;
}

void printList_103032330054(List L){
    if (L.First == NULL){
        cout << endl << "========= LIST KOSONG =========" << endl;
    }else{
        address P = L.First;
        while (P != NULL){
            cout << endl << "Tittle      : " << P->info.title << endl;
            cout << "URL         : " << P->info.url << endl;
            cout << "Time Stamp  : " << P->info.timestamp << endl;
            cout << "Visit Count : " << P->info.visitcount << endl;
            P = P->next;
        }
    }

}

void deleteFirst_103032330054(List &L, address &P){
    P = L.First;
    if (L.First->next == NULL){
        L.First = NULL;
        L.Last = NULL;
    }else{
        L.First = L.First->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast_103032330054(List &L, address &P){
    if (L.First->next == NULL){
        L.First = NULL;
        L.Last = NULL;
    }else{
        P = L.Last;
        L.Last = P->prev;
        P->prev = NULL;
        L.Last->next = NULL;
    }
}

void deleteAfter_103032330054(address &Prec, address &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = NULL;
    P->prev = NULL;
}

void insertFirst_103032330054(List &L, address P){
    L.First->prev = P;
    P->next = L.First;
    L.First = P;
}

void insertAscending_103032330054(List &L, infotype dataBaru){
    address P;
    address Q = L.First;
    P = createElemen_103032330054(dataBaru);
    if (L.First == NULL){
        insertFirst_103032330054(L,P);
    }else{
        while (Q != NULL){
            if (Q->info.visitcount < P->info.visitcount){
                if (Q == L.Last){
                    insertLast_103032330054(L,P);
                }else{
                    insertAfter_103032330054(Q,P);
                }

            }
            Q=Q->next;
        }
    }
}

bool findElemen_103032330054(List L, string X){
    address P = L.First;
    while (P != NULL){
        if (P->info.title == X){
            return true;
        }
        P = P->next;
    }
    return false;
}

int moreThanOnce_103032330054(List L){
    if (L.First == NULL){
        return 0;
    }else{
        int nilai = 0;
        address P = L.First;
        while (P != NULL){
            if (P->info.visitcount > 1){
                nilai++;
            }
            P = P->next;
        }
        return nilai;
    }
}
