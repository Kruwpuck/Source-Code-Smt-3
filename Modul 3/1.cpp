#include <iostream>
using namespace std;

typedef float infotype;
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
            cout << P->info << endl;
            P = P->next;
        }
    }
}

int main(){
    List L;
    address P ;
    float x;
    createList(L);
    for (int i = 1; i < 5; i++){
        cin >> x;
        P = newElm(x);
        insertAscending(L, P);
    }
    Show(L);

}