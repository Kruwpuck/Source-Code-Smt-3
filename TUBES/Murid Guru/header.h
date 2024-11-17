#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_murid{
    string NISN;
    string nama;
    int kelas;
};
struct infotype_guru{
    string kode;
    string NIDN;
    string nama;
};
typedef struct adr_murid *elm_murid;
typedef struct adr_guru *elm_guru;
typedef struct adr_relasi *elm_relasi;
struct elm_murid{
    infotype_murid info;
    adr_murid next_murid;
};
struct elm_guru{
    infotype_guru info;
    adr_guru next_guru;
    adr_guru prev_guru;
};
struct elm_relasi{
    adr_murid next_murid;
    adr_guru next_guru;
    adr_relasi next_relasi;
};
struct List_murid{
    adr_murid first;
    adr_murid last;
};
struct List_relasi{
    adr_relasi first;
};
struct List_guru{
    adr_guru first;
};
void insertguru(List_guru &L, adr_guru P);
void insertmurid(List_murid &L, adr_murid P);
void insertRelasi(List_relasi &L, adr_relasi P);
void deleteguru(List_guru &L, adr_guru &P);
void deletemurid(List_murid &L, adr_murid &P);
void deleteRelasi(List_relasi &L, adr_relasi P);
void checkRelasi(List_relasi L, adr_murid P, adr_guru Q);
void showguru(List_guru L);
void showmurid(List_murid L);
void showmurid_dariguru(List_relasi L, adr_guru P);
void showguru_darimurid(List_relasi L, adr_murid P);
void showAll_relasiguru(List_guru Ld, List_relasi Lr);
void showAll_relasimurid(List_guru Lm, List_relasi Lr);
void countmurid(List_relasi L, adr_guru P);
void countguru(List_relasi L, adr_murid P);
void countmurid_Less(List_relasi Lr, List_guru Ld);
void countguru_Less(List_relasi Lr, List_murid Lm);
void editguru(List_relasi L, adr_guru P, adr_murid Q);
void editmurid(List_relasi L, adr_guru P, adr_murid Q);
#endif // HEADER_H_INCLUDED
