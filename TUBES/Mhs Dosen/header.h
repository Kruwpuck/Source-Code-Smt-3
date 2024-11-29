#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct elm_mhs;
struct elm_dosen;
struct elm_relasi;

typedef elm_mhs* adr_mhs;
typedef elm_dosen* adr_dosen;
typedef elm_relasi* adr_relasi;

struct infotype_mhs {
    int NIM;
    string nama;
    float IPK;
};

struct infotype_dosen {
    string kode;
    int NIDN;
    string nama;
};

struct elm_mhs {
    infotype_mhs info;
    adr_mhs next_mhs;
    adr_mhs prev_mhs;
};

struct elm_dosen {
    infotype_dosen info;
    adr_dosen next_dosen;
};

struct elm_relasi {
    adr_mhs next_mhs;
    adr_dosen next_dosen;
    adr_relasi next_relasi;
    string info;
};

struct List_mhs {
    adr_mhs first;
    adr_mhs last;
};

struct List_relasi {
    adr_relasi first;
};

struct List_dosen {
    adr_dosen first;
};

void insert_dosen(List_dosen &L, adr_dosen P);
void insert_mhs(List_mhs &L, adr_mhs P);
void insert_relasi(List_relasi &L, adr_relasi P);
void delete_dosen(List_dosen &L, adr_dosen &P);
void delete_Firstdosen(List_dosen &L, adr_dosen &P);
void delete_Lastdosen(List_dosen &L, adr_dosen &P);
void delete_Afterdosen(List_dosen &L, adr_dosen &P);
void delete_mhs(List_mhs &L, adr_mhs &P);
void delete_Firstmhs(List_mhs &L, adr_mhs &P);
void delete_Lastmhs(List_mhs &L, adr_mhs &P);
void delete_Aftermhs(List_mhs &L, adr_mhs &P);
void delete_relasi(List_relasi &L, adr_relasi &P);
void find_dosen(List_dosen L, adr_dosen &P);
void find_mhs(List_mhs L, adr_mhs &P);
void checkrelasi(List_relasi L, adr_mhs P, adr_dosen Q, adr_relasi &R);
void show_dosen(List_dosen L);
void show_mhs(List_mhs L);
void show_mhs_daridosen(List_relasi L, adr_dosen P);
void show_dosen_darimhs(List_relasi L, adr_mhs P);
void show_All_relasidosen(List_dosen Ld, List_relasi Lr);
void show_All_relasimhs(List_mhs Lm, List_relasi Lr);
void count_mhs(List_relasi L, adr_dosen P);
void count_dosen(List_relasi L, adr_mhs P);
void count_dosenTanpamhs(List_relasi Lr, List_dosen Ld);
void count_mhsTanpadosen(List_relasi Lr, List_mhs Lm);
void edit_dosen(List_relasi &L, adr_dosen P, adr_mhs Q, adr_mhs R);
void edit_mhs(List_relasi &L, adr_mhs P, adr_dosen Q, adr_dosen R);
void menu(List_relasi &Lr, List_dosen &Ld, List_mhs &Lm);
void delete_relasimhs(List_relasi &L, adr_mhs &P);
void delete_relasidosen(List_relasi &L, adr_dosen &P);
bool checkNIM(List_mhs L, int NIM);
bool checkNIDN(List_dosen L, int NIDN);

#endif // HEADER_H_INCLUDED