#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Murid{
    int NISN;
    string nama;
    string kelas;
};
struct infotype_Guru{
    string jabatan;
    int NUPTK;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Murid *adr_Murid;
typedef struct elm_Guru *adr_Guru;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Murid{
    infotype_Murid info;
    adr_Murid next_Murid;
};
struct elm_Guru{
    infotype_Guru info;
    adr_Guru next_Guru;
    adr_Guru prev_Guru;
};
struct elm_Relasi{
    adr_Murid next_Murid;
    adr_Guru next_Guru;
    adr_Relasi next_Relasi;
    adr_Relasi prev_Relasi;
    infotype_Relasi info;
};
struct List_Murid{
    adr_Murid first;
};
struct List_Relasi{
    adr_Relasi first;
    adr_Relasi last;
};
struct List_Guru{
    adr_Guru first;
    adr_Guru last;
};
void insertGuru(List_Guru &L, adr_Guru P);
void insertMurid(List_Murid &L, adr_Murid P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deleteGuru(List_Guru &L, adr_Guru &P);
void deleteFirstGuru(List_Guru &L, adr_Guru &P);
void deleteLastGuru(List_Guru &L, adr_Guru &P);
void deleteAfterGuru(List_Guru &L, adr_Guru &P);
void deleteMurid(List_Murid &L, adr_Murid &P);
void deleteFirstMurid(List_Murid &L, adr_Murid &P);
void deleteLastMurid(List_Murid &L, adr_Murid &P);
void deleteAfterMurid(List_Murid &L, adr_Murid &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P);
void findGuru(List_Guru L, adr_Guru &P);
void findMurid(List_Murid L, adr_Murid &P);
void checkRelasi(List_Relasi L, adr_Murid P, adr_Guru Q, adr_Relasi &R);
void showGuru(List_Guru L);
void showMurid(List_Murid L);
void showMurid_dariGuru(List_Relasi L, adr_Guru P);
void showGuru_dariMurid(List_Relasi L, adr_Murid P);
void showAll_RelasiGuru(List_Guru Lg, List_Relasi Lr);
void showAll_RelasiMurid(List_Murid Lm, List_Relasi Lr);
void countMurid(List_Relasi L, adr_Guru P);
void countGuru(List_Relasi L, adr_Murid P);
void countMurid_Less(List_Relasi Lr, List_Guru Lg);
void countGuru_Less(List_Relasi Lr, List_Murid Lm);
void editGuru(List_Relasi &L, adr_Guru P, adr_Murid Q, adr_Murid R);
void editMurid(List_Relasi &L, adr_Murid P, adr_Guru Q, adr_Guru R);
void menu(List_Relasi &Lr, List_Guru &Lg, List_Murid &Lm);
void deleteRelasiMurid(List_Relasi &L, adr_Murid &P);
void deleteRelasiGuru(List_Relasi &L, adr_Guru &P);
bool checkNISN(List_Murid L, int NISN);
bool checkNUPTK(List_Guru L, int NUPTK);
#endif // HEADER_H_INCLUDED
