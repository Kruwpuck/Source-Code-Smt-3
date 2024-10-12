#include "SLL.h"

using namespace std;

int main()
{
    List L;
    address p,q;
    CreateList_103032330054(L);
    int NUM = 0, pilihan = 0, x;
    infotype data;

    pilihan = selectMenu_103032330054();
    while (pilihan!=0){
        switch(pilihan){
        case 1:
            cout << "Jumlah data yang akan ditambahkan: ";
            cin >> x;
            for (int i = 0;i<x;i++){
                cout << endl << "Masukkan data baru: ";
                cin >> data;
                p = CreateNewElm_103032330054(data);
                InsertLast_103032330054(L,p);
            }
            break;
        case 2:
            Show_103032330054(L);
            break;
        case 3:
            p = findMin_103032330054(L);
            cout << endl << "Data dengan nilai minimal: "<< p->info << endl;
            break;
        case 4:
            cout << "Masukkan data yang akan ditambahkan pada tengah list: ";
            cin >> data;
            insertMiddle_103032330054(L, data);
            break;
        }

        pilihan = selectMenu_103032330054();
    }
    cout << "BYE BYE" << endl;
    return 0;
}
