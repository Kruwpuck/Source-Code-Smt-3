#include "flight.h"
void createListJadwal_103032330054(listJadwal &L){
    L.first = NULL;
}
adr_jadwalP createElemenJadwal_103032330054(infotypeJadwal X){
    adr_jadwalP P = new elemenJadwal;
    P->info = X;
    P->next = NULL;
    return P;
}
void InsertLastJ_103032330054(listJadwal &L, adr_jadwalP P){
    if (L.first == NULL){
        L.first = P;
    }else{
        adr_jadwalP Q = L.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
void ShowJadwal_103032330054(listJadwal L){
    if (L.first == NULL){
        cout << "List Kosong" << endl;
    }else{
        adr_jadwalP P = L.first;
        while(P != NULL){
            cout << "Kode: " << P->info.kode << endl;
            cout << "Jenis: " << P->info.jenis << endl;
            cout << "Tanggal: " << P->info.tanggal << endl;
            cout << "Waktu: " << P->info.waktu << endl;
            cout << "Asal: " << P->info.asal << endl;
            cout << "Tujuan: " << P->info.tujuan << endl;
            cout << "Kapasitas: " << P->info.kapasitas << endl << endl;
            P = P->next;
        }
    }
}
void DeleteFirstJ_103032330054(listJadwal &L, adr_jadwalP &P){
    if (L.first == NULL){
        cout << endl << "List Kosong" << endl;
    }else if (L.first->next == NULL){
        P = L.first;
        L.first = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}
adr_jadwalP SearchJ_103032330054(listJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP P = L.first;
    while(P != NULL){
        if (P->info.asal == dari && P->info.tujuan == ke && P->info.tanggal == tanggal){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void createListPenumpang_103032330054(listPenumpang &LP){
    LP.first = NULL;
}
adr_penumpangP createElemenPenumpang_103032330054(infotypePenumpang X){
    adr_penumpangP P = new elemenPenumpang;
    P->info = X;
    P->next = NULL;
    P->jadwalP = NULL;
    return P;
}
void insertLastP_103032330054(listPenumpang &LP, adr_penumpangP P){
    if (LP.first == NULL){
        LP.first = P;
    }else{
        adr_penumpangP Q = LP.first;
        while (Q->next != NULL){
            Q=Q->next;
        }
        Q->next = P;
    }
}
void booking_103032330054(listPenumpang &LP, infotypePenumpang X, listJadwal LJ, string dari, string ke, string tanggal){
    adr_penumpangP P = createElemenPenumpang_103032330054(X);
    insertLastP_103032330054(LP, P);
    adr_jadwalP Q = SearchJ_103032330054(LJ,dari,ke,tanggal);
    if (Q == NULL){
        cout << "JADWAL TIDAK DITEMUKAN" << endl;
        return;
    }
    P->jadwalP = Q;
}
void showPenumpang_103032330054(listPenumpang LP){
    if (LP.first == NULL){
        cout << "List kosong"<< endl << endl;
    }else{
        adr_penumpangP P = LP.first;
        while (P!=NULL){
            cout << "Nama          : " << P->info.nama << endl;
            cout << "NIK           : " << P->info.nik << endl;
            cout << "Jenis Kelamin : " << P->info.jk << endl;
            cout << "Usia          : " << P->info.usia << endl;
            cout << "Kode          : " << P->jadwalP->info.kode << endl << endl;
            P = P->next;
        }
    }
}
void reschedule_103032330054(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal){
    if (LP.first == NULL){
        cout << "List kosong"<< endl << endl;
    }else{
        adr_penumpangP P = LP.first;
        while (P != NULL && P->info.nik != NIK){
            P=P->next;
        }
        if (P == NULL){
            cout << "PENUMPANG TIDAK DITEMUKAN" << endl;
        }
        adr_jadwalP Q = SearchJ_103032330054(LJ,newDari,newKe,newTanggal);
        if (Q == NULL){
            cout << "JADWAL TIDAK DITEMUKAN" << endl;
        }else{
            cout << "ketemu";
            P->jadwalP = Q;
        }

    }
}
void showAllListPenumpang_103032330054(listJadwal LJ, listPenumpang LP, string kode){
    if (LP.first == NULL || LJ.first == NULL){
        cout << "List kosong"<< endl << endl;
        return;
    }else{
        int i = 0;
        adr_jadwalP Q = LJ.first;
        adr_penumpangP P = LP.first;
        while (Q!=NULL && Q->info.kode != kode){
            Q=Q->next;
        }
        if (Q == NULL){
            cout << "JADWAL TIDAK DITEMUKAN" << endl;
            return;
        }
        while (P!=NULL){
            if (P->jadwalP == Q){
                i++;
                cout << "Nama          : " << P->info.nama << endl;
                cout << "NIK           : " << P->info.nik << endl << endl;
            }
            P = P->next;
        }
        cout << "Total Penumpang : "<< i;
    }
}
