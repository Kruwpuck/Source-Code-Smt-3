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

address findMin_103032330054(List L){
    address p = L.first;
    address q = L.first;
    while (p!=NULL){
        if (q->info > p->info){
            q = p;
        }
        p=p->next;
    }
    return q;
}

void insertMiddle_103032330054(List &L, int data){
    address p,q;
    q=CreateNewElm_103032330054(data);
    int x = 0;
    int y = 1;
    p = L.first;
    while(p!=NULL){
        x++;
        p=p->next;
    }
    if (x%2==0){
        x = x/2;
    }else{
        x = (x/2) +1;
    }

    p = L.first;
    while(y!=x){
        p=p->next;
        y++;
    }
    q->next = p->next;
    p->next = q;
}

int selectMenu_103032330054(){
    cout << endl << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan data min" << endl;
    cout << "4. Menambahkan data tengah" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu: ";

    int input = 0;
    cin >> input;

    return input;
}

