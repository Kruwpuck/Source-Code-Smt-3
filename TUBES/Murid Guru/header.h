#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Murid{
    string NISN;
    string nama;
    string kelas;
};
struct infotype_Guru{
    string Jabatan;
    string NUPTK;
    string nama;
};
typedef struct adr_Murid *elm_Murid;
typedef struct adr_Guru *elm_Guru;
typedef struct adr_Relasi *elm_Relasi;
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
    string info;
};
struct List_Murid{
    adr_Murid first;
    adr_Murid last;
};
struct List_Relasi{
    adr_Relasi first;
};
struct List_Guru{
    adr_Guru first;
};
void insertGuru(List_Guru &L, adr_Guru P);
void insertMurid(List_Murid &L, adr_Murid P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deleteGuru(List_Guru &L, adr_Guru &P);
void deleteMurid(List_Murid &L, adr_Murid &P);
void deleteRelasi(List_Relasi &L, adr_Relasi P);
void checkRelasi(List_Relasi L, adr_Murid P, adr_Guru Q, adr_Relasi &R);
void showGuru(List_Guru L);
void showMurid(List_Murid L);
void showMurid_dariGuru(List_Relasi L, adr_Guru P);
void showGuru_dariMurid(List_Relasi L, adr_Murid P);
void showAll_RelasiGuru(List_Guru Lg, List_Relasi Lr);
void showAll_RelasiMurid(List_Guru Lm, List_Relasi Lr);
void countMurid(List_Relasi L, adr_Guru P);
void countGuru(List_Relasi L, adr_Murid P);
void countMurid_Less(List_Relasi Lr, List_Guru Lg);
void countGuru_Less(List_Relasi Lr, List_Murid Lm);
void editGuru(List_Relasi L, adr_Guru P, adr_Murid Q);
void editMurid(List_Relasi L, adr_Guru P, adr_Murid Q);
#endif // HEADER_H_INCLUDED
