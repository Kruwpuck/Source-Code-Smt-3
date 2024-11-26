#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Atlet{
    string ID;
    string nama;
    string umur;
};
struct infotype_Pertandingan{
    string babak;
    string ID;
    string waktu;
};
typedef struct adr_Atlet *elm_Atlet;
typedef struct adr_Pertandingan *elm_Pertandingan;
typedef struct adr_Relasi *elm_Relasi;
struct elm_Atlet{
    infotype_Atlet info;
    adr_Atlet next_Atlet;
};
struct elm_Pertandingan{
    infotype_Pertandingan info;
    adr_Pertandingan next_Pertandingan;
    adr_Pertandingan prev_Pertandingan;
};
struct elm_Relasi{
    adr_Atlet next_Atlet;
    adr_Pertandingan next_Pertandingan;
    adr_Relasi next_Relasi;
    string info;
};
struct List_Atlet{
    adr_Atlet first;
    adr_Atlet last;
};
struct List_Relasi{
    adr_Relasi first;
};
struct List_Pertandingan{
    adr_Pertandingan first;
};
void insertPertandingan(List_Pertandingan &L, adr_Pertandingan P);
void insertAtlet(List_Atlet &L, adr_Atlet P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deletePertandingan(List_Pertandingan &L, adr_Pertandingan &P);
void deleteAtlet(List_Atlet &L, adr_Atlet &P);
void deleteRelasi(List_Relasi &L, adr_Relasi P);
void checkRelasi(List_Relasi L, adr_Atlet P, adr_Pertandingan Q, adr_Relasi &R);
void showPertandingan(List_Pertandingan L);
void showAtlet(List_Atlet L);
void showAtlet_dariPertandingan(List_Relasi L, adr_Pertandingan P);
void showPertandingan_dariAtlet(List_Relasi L, adr_Atlet P);
void showAll_RelasiPertandingan(List_Pertandingan Lg, List_Relasi Lr);
void showAll_RelasiAtlet(List_Pertandingan Lm, List_Relasi Lr);
void countAtlet(List_Relasi L, adr_Pertandingan P);
void countPertandingan(List_Relasi L, adr_Atlet P);
void countAtlet_Less(List_Relasi Lr, List_Pertandingan Lg);
void countPertandingan_Less(List_Relasi Lr, List_Atlet Lm);
void editPertandingan(List_Relasi L, adr_Pertandingan P, adr_Atlet Q);
void editAtlet(List_Relasi L, adr_Pertandingan P, adr_Atlet Q);
#endif // HEADER_H_INCLUDED
