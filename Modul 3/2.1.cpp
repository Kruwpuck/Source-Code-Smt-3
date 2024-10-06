#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Elm *address;

struct Elm
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

void createList(List &L){
    L.first = NULL;
}

address newElm(infotype X){
    address P;
    P = new Elm;
    P->info = X;
    P->next = NULL;
    return P;
}

void insertAscending(List &L, address P){
    address Q, temp;
    Q = NULL;
    temp = L.first;
    while (temp != NULL && P->info > temp->info){
        Q = temp;
        temp = temp->next;
    }
    if (Q != NULL){
        P->next = Q->next;
        Q->next = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}
void Show(List L){
    address P;
    if (L.first != NULL){
        P = L.first;
        while (P!=NULL){
            cout << P->info << " ";
            P = P->next;
        }
    }
    cout << endl;
}

address search(List L, infotype X){
    address P = L.first;
    address prev = NULL;
    while (P != NULL ){
        if (P->info == X){ 
            return prev == NULL ? L.first : prev;
        }
        prev = P;
        P = P->next;
    }
    cout << "Angka Tidak Ditemukan" << endl;
    return NULL; 
}

address lastElm(List L){
    address P = L.first;
    while (P->next !=NULL){
        P = P->next;
    }
    return P;
}

address deleteFirst(List &L){
    address P;
    P = L.first;
    L.first = P->next;
    P->next = NULL;
    return P;
}

address deleteLast(List &L){
    address P,Q;
    Q = L.first;
    if (Q== NULL){
        return NULL;
    }
    while (Q->next != NULL){
        P = Q;
        Q = Q->next;    
    }
    P -> next = NULL;
    return Q ;
}

address deleteAfter(List &L, address P){
    address prec;
    prec = P;
    P = prec->next;
    prec->next = P->next;
    P->next = NULL;
    return P;

}

void hapusElm(List &L, infotype X){
    address P = search(L, X);
    address Q;
    if (P != NULL){
        if (P == L.first ){
            Q = deleteFirst(L);
        } else {
            Q = deleteAfter(L, P);
        }
    }
}


int main(){
    List L;
    address P ;
    int x;
    createList(L);
    for (int i = 1; i < 5; i++){
        cin >> x;
        P = newElm(x);
        insertAscending(L, P);
    }
    Show(L);
    cin >> x;
    hapusElm(L,x);
    Show(L);

}