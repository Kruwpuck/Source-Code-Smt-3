#include "header.h"
void insertToko(List_Toko &L, adr_Toko P){
    if(L.first == NULL){
        L.first = P;
    }else{
        P->next_Toko = L.first;
        L.first = P;
    }
}
void insertCustomer(List_Customer &L, adr_Customer P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next_Customer = P;
        P->prev_Customer = L.last;
        L.last = P;
    }
}
void insertRelasi(adr_Customer Q, adr_Relasi &P){
    if (Q->hubungan.first == NULL){
        Q->hubungan.first = P;
    }else{
        P->next_Relasi = Q->hubungan.first;
        Q->hubungan.first = P;
    }
}
void deleteToko(List_Toko &L, adr_Toko &P){
    if(L.first == NULL){
        cout << "Data Toko kosong" << endl;
        return;
    }
    findToko(L, P);
    while (P == NULL){
        cout << "Data Toko tidak ditemukan" << endl;
        findToko(L, P);
    }
    if (L.first->next_Toko == NULL){
        L.first = NULL;
    }else if(P == L.first){
        deleteFirstToko(L, P); 
    }else{
        deleteLastAfterToko(L, P);
    }
}
void deleteFirstToko(List_Toko &L, adr_Toko &P){
    L.first = P->next_Toko;
    P->next_Toko = NULL;
}
void deleteLastAfterToko(List_Toko &L, adr_Toko &P){
    adr_Toko Q = L.first;
    while (Q->next_Toko != P){
        Q = Q->next_Toko;    
    }
    if (P->next_Toko == NULL){
        Q->next_Toko = P->next_Toko;
    }
    Q->next_Toko = NULL;
}
void deleteCustomer(List_Customer &L, adr_Customer &P){
    if (L.first == NULL){
        cout << "Data Customer kosong" << endl;
        return;
    }
    findCustomer(L, P);
    while (P == NULL){
        cout << "Data Customer tidak ditemukan" << endl;
        findCustomer(L, P);
    }
    if (L.first->next_Customer == NULL){
        L.first = NULL;
    }else if(P == L.first){
        deleteFirstCustomer(L, P);
    }else if (P == L.last){
        deleteLastCustomer(L, P);
    }else{
        deleteAfterCustomer(L, P);
    }
} 
void deleteFirstCustomer(List_Customer &L, adr_Customer &P){
    L.first = P->next_Customer;
    P->next_Customer = NULL;
    P->prev_Customer = NULL;
} 
void deleteLastCustomer(List_Customer &L, adr_Customer &P){
    L.last = P->prev_Customer;
    P->prev_Customer = NULL;
    L.last->next_Customer = NULL;
}
void deleteAfterCustomer(List_Customer &L, adr_Customer &P){
    P->next_Customer->prev_Customer = P->prev_Customer;
    P->prev_Customer->next_Customer = P->next_Customer;
    P->next_Customer = NULL;
    P->prev_Customer = NULL;
}
void deleteRelasi(adr_Customer &Q ,adr_Relasi &P){
    if(Q->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if(Q->hubungan.first->next_Relasi == NULL){
            P = Q->hubungan.first;
            Q->hubungan.first = NULL;
        }else{
            adr_Relasi R = Q->hubungan.first;
            while(P->next_Relasi != NULL){
                Q = P;
                P = P->next_Relasi;
            }
            P = R->next_Relasi;
            R->next_Relasi = P->next_Relasi;
            P->next_Relasi = NULL;
        }
    }
} 
void findToko(List_Toko L, adr_Toko &P){
    int ID;
    cout << "Masukkan ID Toko yang dicari : ";
    cin >> ID;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.ID == ID){
            cout << "Data Toko ditemukan" << endl;
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko     : " << P->info.ID << endl;
            cout << "Kategori Toko : " << P->info.kategori << endl;
            return;
        }
        P = P->next_Toko;
    }
    cout << "Data Toko tidak ditemukan" << endl;
    P = NULL;
} 
void findCustomer(List_Customer L, adr_Customer &P){
    int NIK;
    cout << "Masukkan NIK Customer yang dicari : ";
    cin >> NIK;
    cout << endl;
    P = L.first;
    while(P != NULL){
        if(P->info.NIK == NIK){
            cout << "Data Customer ditemukan" << endl;
            cout << "Nama Customer : " << P->info.nama << endl;
            cout << "NIK Customer  : " << P->info.NIK << endl;
            cout << "Kelas       : " << P->info.kelas << endl;
            return;
        }
        P = P->next_Customer;
    }
    cout << "Data Customer tidak ditemukan" << endl;
    P = NULL;
} 
void findRelasi(List_Relasi L, adr_Toko P, adr_Customer Q, adr_Relasi &R){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
        R = NULL;
        return;
    }
    R = P->hubungan.first;
    while(R != NULL){
        if(R->next_Toko == P){
            cout << "Data Relasi ditemukan" << endl;
            cout << "Jenis Relasi : " << R->info << endl;
            return;
        }
        R = R->next_Relasi;
    }
    cout << "Data Relasi tidak ditemukan" << endl;
    R = NULL;

}
void showToko(List_Toko L){
    adr_Toko P = L.first;
    if(P == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        cout << "Data Toko : " << endl;
        while(P != NULL){
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko     : " << P->info.ID << endl;
            cout << "Kategori Toko : " << P->info.kategori << endl;
            cout << endl;
            P = P->next_Toko;
        }
    }
} 
void showCustomer(List_Customer L){
    adr_Customer P = L.first;
    if(P == NULL){
        cout << "Data Customer kosong" << endl;
    }else{
        cout << "Data Customer : " << endl;
        while(P != NULL){
            cout << "Nama Customer : " << P->info.nama << endl;
            cout << "NIK Customer  : " << P->info.NIK << endl;
            cout << "Kelas       : " << P->info.kelas << endl;
            cout << endl;
            P = P->next_Customer;
        }
    }
} 
void showCustomerDariToko(List_Customer L,adr_Toko P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R;
        adr_Customer Q = L.first;
        while(Q != NULL){
            R = P->hubungan.first;
            while(R != NULL){
                if(R->next_Toko == P){
                    cout << "Nama Customer : " << Q->info.nama << endl;
                    cout << "NIK Customer  : " << Q->info.NIK << endl;
                    cout << "Kelas       : " << Q->info.kelas << endl;
                    cout << "Jenis Relasi   : " << R->info << endl;
                    cout << endl;
                }
                R = R->next_Relasi;
            }
            Q = Q->next_Customer;
        }
    }

} 
void showAllRelasiToko(List_Toko Ld, List_Customer Lm){
    if (Ld.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else{
        adr_Toko P = Ld.first;
        adr_Customer Q;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko     : " << P->info.ID << endl;
            cout << "Kategori Toko : " << P->info.kategori << endl;
            Q = Lm.first;
            ada = false;
            while (Q != NULL){
                R = P->hubungan.first;
                while (R != NULL){
                    if (R->next_Toko == P){
                        cout << "Nama Customer : " << Q->info.nama << endl;
                        cout << "NIK Customer  : " << Q->info.NIK << endl;
                        cout << "Kelas       : " << Q->info.kelas << endl;
                        cout << "Jenis Relasi   : " << R->info << endl;
                        cout << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Customer;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Toko;
        }
    }
} 
void showAllRelasiCustomer(List_Customer Lm, List_Toko Ld){
    if (Lm.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else if (Ld.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else{
        adr_Customer P = Lm.first;
        adr_Toko Q;
        adr_Relasi R;
        bool ada;
        while (P != NULL){
            cout << "Nama Customer : " << P->info.nama << endl;
            cout << "NIK Customer  : " << P->info.NIK << endl;
            cout << "Kelas       : " << P->info.kelas << endl;
            Q = Ld.first;
            ada = false;
            while (Q != NULL){
                R = Q->hubungan.first;
                while (R != NULL){
                    if (R->next_Toko == Q){
                        cout << "Nama Toko    : " << Q->info.nama << endl;
                        cout << "ID Toko     : " << Q->info.ID << endl;
                        cout << "Kategori Toko : " << Q->info.kategori << endl;
                        cout << "Jenis Relasi   : " << R->info << endl;
                        cout << endl;
                        ada = true;
                    }
                    R = R->next_Relasi;
                }
                Q = Q->next_Toko;
            }
            if (!ada){
                cout << "Data Relasi tidak ditemukan" << endl;
            }
            P = P->next_Customer;
        }
    }
} 
void showTokoDariCustomer(List_Toko L, adr_Customer P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        if (P->hubungan.first == NULL){
            cout << "Data Relasi kosong" << endl;
        }else{
            adr_Relasi R = P->hubungan.first;
            while(R != NULL){
                cout << "Nama Toko    : " << R->next_Toko->info.nama << endl;
                cout << "ID Toko     : " << R->next_Toko->info.ID << endl;
                cout << "Kategori Toko : " << R->next_Toko->info.kategori << endl;
                cout << "Jenis Relasi  : " << R->info << endl;
                cout << endl;
                R = R->next_Relasi;
            }
        }
    }
} 
void countAllRelasiToko(List_Toko Ld, List_Customer Lm){
    if (Ld.first == NULL){
        cout << "Data Toko kosong" << endl;
    }else if (Lm.first == NULL){
        cout << "Data Customer kosong" << endl;
    }else{
        adr_Relasi R;
        adr_Toko P = Ld.first;
        adr_Customer Q;
        int count;
        while (P != NULL){
            count = 0;
            Q = Lm.first;
            while (Q != NULL){
                if (P->hubungan.first != NULL){
                    R = P->hubungan.first;
                    while (R != NULL){
                        if (R->next_Toko == P){
                            count++;
                        }
                        R = R->next_Relasi;
                    }
                }else{
                    cout << "Data Relasi kosong" << endl;
                }
                Q = Q->next_Customer;
            }
            cout << "Nama Toko    : " << P->info.nama << endl;
            cout << "ID Toko     : " << P->info.ID << endl;
            cout << "Kategori Toko : " << P->info.kategori << endl;
            cout << "Jumlah Relasi : " << count << endl;
            cout << endl;
            P = P->next_Toko;
        }
    }
} 
void countRelasiDariCustomer(adr_Customer P){
    if (P->hubungan.first == NULL){
        cout << "Data Relasi kosong" << endl;
    }else{
        adr_Relasi R = P->hubungan.first;
        int count = 0;
        while(R != NULL){
            count++;
            R = R->next_Relasi;
        }
        cout << "Nama Customer : " << P->info.nama << endl;
        cout << "NIK Customer  : " << P->info.NIK << endl;
        cout << "Kelas       : " << P->info.kelas << endl;
        cout << "Jumlah Relasi  : " << count << endl;
        cout << endl;
    }
} 
void countCustomerTanpaToko(List_Customer Lm){
    adr_Customer P = Lm.first;
    int count = 0;
    while(P != NULL){
        if (P->hubungan.first == NULL){
            count++;
        }
        P = P->next_Customer;
    }
    cout << "Jumlah Customer tanpa Toko : " << count << endl;
} 
void editCustomerDariToko(adr_Customer &S, adr_Customer &T, adr_Toko P, adr_Relasi &R){
    deleteRelasi(S, R);
    insertRelasi(T, R);
    cout << "Data Customer berhasil diubah" << endl;
} 
void mainMenu(List_Toko &Ld, List_Customer &Lm){

} 