#include "header.h"
int main()
{
    List_char L1,L2;
    L1.first = NULL;
    L2.first = NULL;
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        adr_char P = new elm_char;
        adr_char Q = new elm_char;
        cout << "Masukkan elemen ke-" << (i + 1) << ": ";
        char s;
        cin >> s;
        P->info = s;
        Q->info = s;
        Q->next = NULL;
        P->next = NULL;
        insertLastchar(L1, P);
        insertFirstchar(L2, Q);
    }
    adr_char P1 = L1.first;
    adr_char P2 = L2.first;
    while( P1 != NULL && P2 != NULL) {
        if (P1->info != P2->info) {
            cout << "False" << endl;
            return 0;
        }
        P1 = P1->next;
        P2 = P2->next;
    }
    cout << "True" << endl;
    return 0;
}
