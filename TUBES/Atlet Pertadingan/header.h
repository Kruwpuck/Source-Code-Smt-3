#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Atlet{
    int ID;
    string nama;
    string umur;
};
struct infotype_Pertandingan{
    string waktu;
    int ID;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Atlet *adr_Atlet;
typedef struct elm_Pertandingan *adr_Pertandingan;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Atlet{
    infotype_Atlet info;
    adr_Atlet next_Atlet;
    adr_Atlet prev_Atlet;
};
struct elm_Pertandingan{
    infotype_Pertandingan info;
    adr_Pertandingan next_Pertandingan;
};
struct elm_Relasi{
    adr_Atlet next_Atlet;
    adr_Pertandingan next_Pertandingan;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
struct List_Atlet{
    adr_Atlet first;
    adr_Atlet last;
};
struct List_Relasi{
    adr_Relasi first;
    adr_Relasi last;
};
struct List_Pertandingan{
    adr_Pertandingan first;
};
void insertPertandingan(List_Pertandingan &L, adr_Pertandingan P);
void insertAtlet(List_Atlet &L, adr_Atlet P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deletePertandingan(List_Pertandingan &L, adr_Pertandingan &P);
void deleteFirstPertandingan(List_Pertandingan &L, adr_Pertandingan &P);
void deleteLastPertandingan(List_Pertandingan &L, adr_Pertandingan &P);
void deleteAfterPertandingan(List_Pertandingan &L, adr_Pertandingan &P);
void deleteAtlet(List_Atlet &L, adr_Atlet &P);
void deleteFirstAtlet(List_Atlet &L, adr_Atlet &P);
void deleteLastAtlet(List_Atlet &L, adr_Atlet &P);
void deleteAfterAtlet(List_Atlet &L, adr_Atlet &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P);
void findPertandingan(List_Pertandingan L, adr_Pertandingan &P);
void findAtlet(List_Atlet L, adr_Atlet &P);
void checkRelasi(List_Relasi L, adr_Atlet P, adr_Pertandingan Q, adr_Relasi &R);
void showPertandingan(List_Pertandingan L);
void showAtlet(List_Atlet L);
void showAtlet_dariPertandingan(List_Relasi L, adr_Pertandingan P);
void showPertandingan_dariAtlet(List_Relasi L, adr_Atlet P);
void showAll_RelasiPertandingan(List_Pertandingan Lp, List_Relasi Lr);
void showAll_RelasiAtlet(List_Atlet La, List_Relasi Lr);
void hitungAtlet(List_Relasi L, adr_Pertandingan P);
void hitungPertandingan(List_Relasi L, adr_Atlet P);
void hitungPertandinganTanpaAtlet(List_Relasi Lr, List_Pertandingan Lp);
void hitungAtletTanpaPertandingan(List_Relasi Lr, List_Atlet La);
void editPertandingan(List_Relasi &L, adr_Pertandingan P, adr_Atlet Q, adr_Atlet R);
void editAtlet(List_Relasi &L, adr_Atlet P, adr_Pertandingan Q, adr_Pertandingan R);
void menu(List_Relasi &Lr, List_Pertandingan &Lp, List_Atlet &La);
void deleteRelasiAtlet(List_Relasi &L, adr_Atlet &P);
void deleteRelasiPertandingan(List_Relasi &L, adr_Pertandingan &P);
bool checkID(List_Atlet L, int ID);
bool checkID(List_Pertandingan L, int ID);
#endif // HEADER_H_INCLUDED
