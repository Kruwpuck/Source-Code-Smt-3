#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;
struct infotype_Mahasiswa{
    int NIM;
    string nama;
    float IPK;
};
struct infotype_Dosen{
    string kode;
    int NIDN;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Mahasiswa *adr_Mahasiswa;
typedef struct elm_Dosen *adr_Dosen;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Mahasiswa{
    infotype_Mahasiswa info;
    adr_Mahasiswa next_Mahasiswa;
    adr_Mahasiswa prev_Mahasiswa;
};
struct elm_Dosen{
    infotype_Dosen info;
    adr_Dosen next_Dosen;
};
struct elm_Relasi{
    adr_Mahasiswa next_Mahasiswa;
    adr_Dosen next_Dosen;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
struct List_Mahasiswa{
    adr_Mahasiswa first;
    adr_Mahasiswa last;
};
struct List_Relasi{
    adr_Relasi first;
    adr_Relasi last;
};
struct List_Dosen{
    adr_Dosen first;
};
void insertDosen(List_Dosen &L, adr_Dosen P);
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deleteDosen(List_Dosen &L, adr_Dosen &P);
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P);
void deleteLastDosen(List_Dosen &L, adr_Dosen &P);
void deleteAfterDosen(List_Dosen &L, adr_Dosen &P);
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteLastMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P);
void findDosen(List_Dosen L, adr_Dosen &P);
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P);
void checkRelasi(List_Relasi L, adr_Mahasiswa P, adr_Dosen Q, adr_Relasi &R);
void showDosen(List_Dosen L);
void showMahasiswa(List_Mahasiswa L);
void showMahasiswa_dariDosen(List_Relasi L, adr_Dosen P);
void showDosen_dariMahasiswa(List_Relasi L, adr_Mahasiswa P);
void showAll_RelasiDosen(List_Dosen Ld, List_Relasi Lr);
void showAll_RelasiMahasiswa(List_Mahasiswa Lm, List_Relasi Lr);
void hitungMahasiswa(List_Relasi L, adr_Dosen P);
void hitungDosen(List_Relasi L, adr_Mahasiswa P);
void hitungDosenTanpaMahasiswa(List_Relasi Lr, List_Dosen Ld);
void hitungMahasiswaTanpaDosen(List_Relasi Lr, List_Mahasiswa Lm);
void editDosen(List_Relasi &L, adr_Dosen P, adr_Mahasiswa Q, adr_Mahasiswa R);
void editMahasiswa(List_Relasi &L, adr_Mahasiswa P, adr_Dosen Q, adr_Dosen R);
void menu(List_Relasi &Lr, List_Dosen &Ld, List_Mahasiswa &Lm);
void deleteRelasiMahasiswa(List_Relasi &L, adr_Mahasiswa &P);
void deleteRelasiDosen(List_Relasi &L, adr_Dosen &P);
bool checkNIM(List_Mahasiswa L, int NIM);
bool checkNIDN(List_Dosen L, int NIDN);
#endif // HEADER_H_INCLUDED
