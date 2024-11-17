#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_mahasiswa{
    string NIM;
    string nama;
    float IPK;
};
struct infotype_dosen{
    string kode;
    string NIDN;
    string nama;
};
typedef struct adr_mahasiswa *elm_mahasiswa;
typedef struct adr_dosen *elm_dosen;
typedef struct adr_relasi *elm_relasi;
struct elm_mahasiswa{
    infotype_mahasiswa info;
    adr_mahasiswa next_mhs;
    adr_mahasiswa prev_mhs;
};
struct elm_dosen{
    infotype_dosen info;
    adr_dosen next_dosen;
};
struct elm_relasi{
    adr_mahasiswa next_mhs;
    adr_dosen next_dosen;
    adr_relasi next_relasi;
};
struct List_mhs{
    adr_mahasiswa first;
    adr_mahasiswa last;
};
struct List_relasi{
    adr_relasi first;
};
struct List_dosen{
    adr_dosen first;
};
void selectMenu();
void createList_Mhs(List_mhs &L);
void createList_Dosen(List_dosen &L);
void createList_Relasi(List_relasi &L);
adr_mahasiswa createElm_Mhs(infotype_mahasiswa data);
adr_dosen createElm_Dosen(infotype_dosen data);
adr_relasi createElm_Relasi(infotype_relasi data);
void insertDosen(List_dosen &L, adr_dosen P);
void insertMhs(List_mhs &L, adr_mahasiswa P);
void insertRelasi(List_relasi &L, adr_relasi P);
void deleteDosen(List_dosen &L, adr_dosen &P);
void deleteMhs(List_mhs &L, adr_mahasiswa &P);
void deleteRelasi(List_relasi &L, adr_relasi P);
void checkRelasi(List_relasi L, adr_mahasiswa P, adr_dosen Q);
void showDosen(List_dosen L);
void showMhs(List_mhs L);
void showMhs_dariDosen(List_relasi L, adr_dosen P);
void showDosen_dariMhs(List_relasi L, adr_mahasiswa P);
void showAll_relasiDosen(List_dosen Ld, List_relasi Lr);
void showAll_relasiMhs(List_dosen Lm, List_relasi Lr);
void countMhs(List_relasi L, adr_dosen P);
void countDosen(List_relasi L, adr_mahasiswa P);
void countMhs_Less(List_relasi Lr, List_dosen Ld);
void countDosen_Less(List_relasi Lr, List_mhs Lm);
void editDosen(List_relasi L, adr_dosen P, adr_mahasiswa Q);
void editMhs(List_relasi L, adr_dosen P, adr_mahasiswa Q);
#endif // HEADER_H_INCLUDED
