#include "QUEUE.h"
void createQueue_103032300018(Queue &Q){
    Q.head = NULL;
    Q.tail = NULL;
}
bool isEmpty_103032300018(Queue Q){
    return Q.head == NULL;
}
ElemQ* createElemQueue_103032300018(string nama, int usia, string pekerjaan, int nomor_antrean){
    ElemQ *P = new ElemQ;
    P->info.nama = nama;
    P->info.usia = usia;
    P->info.pekerjaan = pekerjaan;
    P->info.prioritas = usia >= 60 || pekerjaan == "tenaga kesehatan";
    P->info.nomor_antrean = nomor_antrean;
    P->info.kondisi_darurat = false;
    P->next = NULL;
    return P;
}
void enqueue_103032300018(Queue &Q, ElemQ *P){
    if (isEmpty_103032300018(Q)){
        Q.head = P;
        Q.tail = P;
    }else if (P->info.prioritas){
        if (!Q.head->info.prioritas){
            P->next = Q.head;
            Q.head = P;
        }else{
            ElemQ *temp = Q.head;
            while (temp->next != NULL && temp->next->info.prioritas){
                temp = temp->next;
            }
            P->next = temp->next;
            temp->next = P;
            if (P->next == NULL){
                Q.tail = P;
            }
        }
    }else{
        Q.tail->next = P;
        Q.tail = P;
    }
}
void dequeue_103032300018(Queue &Q, ElemQ *&P){
    if (isEmpty_103032300018(Q)){
        P = NULL;
        cout << "Semua warga telah terlayani." << endl;
    }else{
        P = Q.head;
        Q.head = Q.head->next;
        if (Q.head == NULL){
            Q.tail = NULL;
        }
        P->next = NULL;
    }
}
ElemQ* front_103032300018(Queue Q){
    return Q.head;
}
ElemQ* back_103032300018(Queue Q){
    return Q.tail;
}
int size_103032300018(Queue Q){
    int count = 0;
     ElemQ *temp = Q.head;
     while (temp != NULL) {
        count++;
        temp = temp->next;
     }
     return count;
}
void printInfo_103032300018(Queue Q){
    ElemQ *P = Q.head;
    while (P!=NULL){
        cout << endl << "------------------------------" << endl;
        cout << "Nama: " << P->info.nama << endl;
        cout << "Usia: " << P->info.usia << endl;
        cout << "Pekerjaan: " << P->info.pekerjaan << endl;
        if (P->info.prioritas){
            cout << "Prioritas: Ya" << endl;
        }else{
            cout << "Prioritas: Tidak" << endl;
        }
        cout << "Nomor Antrean: " << P->info.nomor_antrean << endl;
        P=P->next;
    }
}
void serveQueue_103032300018(Queue &Q){
    if (isEmpty_103032300018(Q)){

    }else{
        int kouta = 100;
        ElemQ *P;
        while (!isEmpty_103032300018(Q) && kouta != 0){
            dequeue_103032300018(Q,P);
            cout << "Melayanin warga:" << endl;
            cout << "Nama: " << P->info.nama << endl;
            cout << "Usia: " << P->info.usia << endl;
            cout << "Pekerjaan: " << P->info.pekerjaan << endl;
            if (P->info.prioritas){
                cout << "Prioritas: Ya" << endl;
            }else{
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Vaksinasi berhasil." << endl;
            cout << "------------------------------" << endl;
            kouta--;
        }
        if (kouta == 0){
            cout << endl << "KAPASITAS TELAH PENUH" << endl;
        }
        if (!isEmpty_103032300018(Q)){
            cout << endl << "SILAKAN DATANG KEMBALI BESOK" << endl;
        }
    }
}
void reassignQueue_103032300018(Queue &Q){
        Queue S;
        createQueue_103032300018(S);
        int P = size_103032300018(Q);
        ElemQ *R;
        while (P != 0 || !isEmpty_103032300018(Q)){
            dequeue_103032300018(Q,R);
            enqueue_103032300018(S,R);
            P--;
        }
        Q = S;
}
void checkWaitingTime_103032300018(Queue &Q, int waktu_sekarang){
        ElemQ *P = Q.head;
        if (waktu_sekarang > 120){
            P = Q.head;
            while (P!=NULL){
                P->info.prioritas = true;
                P=P->next;
            }
        }
        reassignQueue_103032300018(Q);
}
void emergencyHandle_103032300018(Queue &Q, int nomor_antrean){
    ElemQ *P = Q.head;
    while (P!=NULL){
        if (P->info.nomor_antrean == nomor_antrean){
            P->info.kondisi_darurat = true;
            P->info.prioritas = true;
            reassignQueue_103032300018(Q);
            return;
        }
        P=P->next;
    }
    cout << endl << "NOMOR ANTREAN TIDAK DITEMUKAN" << endl;
}
void updatePriority_103032300018(Queue &Q){
    ElemQ *P = Q.head;
    ElemQ *R;
    checkWaitingTime_103032300018(Q, 130);
    while (P != NULL){
        if (P->info.kondisi_darurat){
            reassignQueue_103032300018(Q);
        }
        P = P->next;
    }
}
ElemQ* findAndRemove_103032300018(Queue &Q, int nomor_antrean){
    ElemQ *P, *S, *R;
    P = Q.head;
    S = Q.head;
    while (P->next != NULL){
        if (nomor_antrean == P->info.nomor_antrean){
            if (P == Q.head){
                dequeue_103032300018(Q,R);
                return R;
            }else if (P == Q.tail){
                Q.tail = S;
                Q.tail->next = NULL;
                return P;
            }else{
                S->next = P->next;
                P->next = NULL;
                return P;
            }
        }
        S = P;
        P = P->next;
    }
    return NULL;
}
