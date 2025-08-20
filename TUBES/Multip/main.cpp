#include "header.h"
int main(){
    List_int L1,L2,L3;
    L1.first = NULL;
    L2.first = NULL;
    L3.first = NULL;
    int n, carry;
    carry = 0;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    cout << "Masukkan angka List 1: " << endl;
    for (int i = 0; i < n; i++) {
        adr_int P = new elm_int;
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        int s;
        cin >> s;
        P->info = s;
        P->next = NULL;
        insertLastint(L1, P);
    }
    cout << "Masukkan angka List 2: " << endl;
    for (int i = 0; i < n; i++) {
        adr_int P = new elm_int;
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        int s;
        cin >> s;
        P->info = s;
        P->next = NULL;
        insertLastint(L2, P);
    }

    while (L1.first != NULL && L2.first != NULL) {
        adr_int P1 = deleteListint(L1);
        adr_int P2 = deleteListint(L2);
        adr_int P = new elm_int;
        cout << "P1: " << P1->info << ", P2: " << P2->info << endl;
        if (P1->info + P2->info > 9) {
            P->info = (P1->info + P2->info) % 10;
            carry = (P1->info + P2->info) / 10;
        } else {
            P->info = P1->info + P2->info + carry;
            carry = 0;
        }
        P->next = NULL;
        insertLastint(L3, P);
    }

    adr_int P = L3.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    return 0;
}
