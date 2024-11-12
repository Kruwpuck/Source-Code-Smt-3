#include "coba.h"

int main()
{
    List L,L1,L2;
    createList_103032330054(L);
    createList_103032330054(L1);
    createList_103032330054(L2);
    infotype data;
    float N;
    address P,Q;
    for (int i=0;i<4;i++){
        cout << "---------------------------" << endl;
        cout << "Masukkan data ke " << i+1 << ": "<< endl;
        cout << "Nama   : ";
        cin >> data.nama;
        cout << endl << "Rating : ";
        cin >> data.rating;
        cout << endl <<"---------------------------" << endl;
        P = createElm_103032330054(data);
        insertLast_103032330054(L,P);
    }
    cout << endl << "------------- PRINT INFO ----------------" << endl;
    showInfo_103032330054(L);
    cout << endl << "------------- SETELAH DELETE LAST ----------------" << endl;
    deleteLast_103032330054(L,Q);
    showInfo_103032330054(L);
    cout << endl << "------------- SETELAH RESET ----------------" << endl;
    reset_103032330054(L);

    for (int j=0;j<4;j++){
        cout << "---------------------------" << endl;
        cout << "Masukkan data ke " << j+1 << ": "<< endl;
        cout << "Nama   : ";
        cin >> data.nama;
        cout << endl << "Rating : ";
        cin >> data.rating;
        cout << endl <<"---------------------------" << endl;
        P = createElm_103032330054(data);
        insertLast_103032330054(L,P);
    }
    cout << endl << "------------- PRINT INFO ----------------" << endl;
    showInfo_103032330054(L);
    cout << "Masukkan N (0.00 s/d 5.00): ";
    cin >> N;
    cout << endl << "------------- SETELAH SPLIT ----------------" << endl;
    split_103032330054(L,L1,L2,N);
    showInfo_103032330054(L);
    cout << endl << "------------- LIST 1 ----------------" << endl;
    showInfo_103032330054(L1);
    cout << endl << "------------- LIST 2 ----------------" << endl;
    showInfo_103032330054(L2);
    return 0;
}
