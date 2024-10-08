#include <iostream>

using namespace std;

typedef int infotype;

typedef struct Elm *address;

struct Elm {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L){
    L.first = NULL;
};

address createNewElement(infotype x){
    address P;
    P = new Elm;
    P ->info =x;
    P->next = NULL;
    return P;
}

address searchX(List L, int x){
    address P;
    P = L.first;
    while (P != NULL && P->info != x) {
        P = P->next;
    }
    return P;
}

address deleteX(List &L, int x){
    address P,Q,R, prec;
    P = searchX(L, x);
    if (P == L.first){
        L.first = P -> next;
        P -> next = NULL;
    } else if (P -> next == NULL){
            Q = L.first;
            while (Q -> next != NULL){
                R = Q;
                Q = Q -> next;
            }
            P = R -> next;
            R -> next = NULL;
    }   else {
        prec = P;
        P = prec -> next;
        prec -> next = P ->next;
        P ->next = NULL;
    }
    return P;
}

address maxElm(List L, address P){
    address prec, temp;
    prec = NULL;
    temp = L.first;
    while (temp != NULL && P -> info >  temp-> info) {
        prec = temp;
        temp = temp->next;
    }

    return prec;
}

void insertAscending(List &L ,address P){
    address prec;
    prec = maxElm(L, P);
    if (prec != NULL) {
            P->next = prec ->next;
            prec ->next = P;
    } else {
        P->next = L.first;
        L.first = P;
    }


}
void Show(List L){
    address P;
    if (L.first != NULL){
        P = L.first;
        while (P != NULL){
            cout << P ->info << " ";
            P = P ->next;
        }
    }
}

int main()
{
    List L;
    address P, ketemu;
    int x;
    createList(L);
    for (int i = 1; i <= 4; i++){
        cin >> x;
        P = createNewElement(x);
        insertAscending(L, P);
    }
     Show(L);
    cin >> x;
    ketemu = deleteX(L, x);
    if (ketemu == NULL) {
        cout << "Tidak ditemukan";
    } else {

        Show(L);
    }
}