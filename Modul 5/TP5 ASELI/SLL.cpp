#include "SLL.h"

void CreateList_103032330054(List &L){
    L.first = NULL;
}
address CreateNewElm_103032330054(infotype data){
    address p = new elmlist;
    p->next = NULL;
    p->info=data;
    return p;
}

void InsertLast_103032330054(List &L, address p){
    if (L.first==NULL){
        L.first = p;
    }else{
        address q = L.first;
        while (q->next!=NULL){
            q = q->next;
        }
        q->next = p;
    }
}

void Show_103032330054(List L){
    address p = L.first;
    while (p!=NULL){
        cout << p->info << ", ";
        p=p->next;
    }
}

address shortestName_103032330054(List L){
    address p = L.first;
    address min = L.first;
    while (p!=NULL){
        if (min->info.size() > p->info.size()){
            min = p;
        }
        p=p->next;
    }
    return min;
}

void showFirstKNameC_103032330054(List L, int k, char c){
    address p = L.first;
    int l = 0;
    while (p!=NULL && k > l){
        if (p->info[0] == toupper(c) || p->info[0] == tolower(c)){
            cout << p->info << ", ";
            l++;
        }
        p = p->next;
    }
}

int selectMenu_103032330054(){
    cout << endl << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan nama terpendek" << endl;
    cout << "4. Menampilkan k pengunjung yang berawalan c" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu: ";

    int input = 0;
    cin >> input;

    return input;
}

