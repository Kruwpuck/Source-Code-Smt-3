#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Siswa{
    int NISN;
    string nama;
    string kelas;
};
struct infotype_Sekolah{
    string alamat;
    int NPSN;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Siswa *adr_Siswa;
typedef struct elm_Sekolah *adr_Sekolah;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Siswa{
    infotype_Siswa info;
    adr_Siswa next_Siswa;
    adr_Siswa prev_Siswa;
};
struct elm_Sekolah{
    infotype_Sekolah info;
    adr_Sekolah next_Sekolah;
};
struct elm_Relasi{
    adr_Siswa next_Siswa;
    adr_Sekolah next_Sekolah;
    adr_Relasi next_Relasi;
    adr_Relasi prev_Relasi;
    infotype_Relasi info;
};
struct List_Siswa{
    adr_Siswa first;
    adr_Siswa last;
};
struct List_Relasi{
    adr_Relasi first;
    adr_Relasi last;
};
struct List_Sekolah{
    adr_Sekolah first;
};
void insertSekolah(List_Sekolah &L, adr_Sekolah P);
void insertSiswa(List_Siswa &L, adr_Siswa P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deleteSekolah(List_Sekolah &L, adr_Sekolah &P);
void deleteFirstSekolah(List_Sekolah &L, adr_Sekolah &P);
void deleteLastSekolah(List_Sekolah &L, adr_Sekolah &P);
void deleteAfterSekolah(List_Sekolah &L, adr_Sekolah &P);
void deleteSiswa(List_Siswa &L, adr_Siswa &P);
void deleteFirstSiswa(List_Siswa &L, adr_Siswa &P);
void deleteLastSiswa(List_Siswa &L, adr_Siswa &P);
void deleteAfterSiswa(List_Siswa &L, adr_Siswa &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P);
void findSekolah(List_Sekolah L, adr_Sekolah &P);
void findSiswa(List_Siswa L, adr_Siswa &P);
void checkRelasi(List_Relasi L, adr_Siswa P, adr_Sekolah Q, adr_Relasi &R);
void showSekolah(List_Sekolah L);
void showSiswa(List_Siswa L);
void showSiswa_dariSekolah(List_Relasi L, adr_Sekolah P);
void showSekolah_dariSiswa(List_Relasi L, adr_Siswa P);
void showAll_RelasiSekolah(List_Sekolah Ld, List_Relasi Lr);
void showAll_RelasiSiswa(List_Siswa Lm, List_Relasi Lr);
void countSiswa(List_Relasi L, adr_Sekolah P);
void countSekolah(List_Relasi L, adr_Siswa P);
void countSiswa_Less(List_Relasi Lr, List_Sekolah Ld);
void countSekolah_Less(List_Relasi Lr, List_Siswa Lm);
void editSekolah(List_Relasi &L, adr_Sekolah P, adr_Siswa Q, adr_Siswa R);
void editSiswa(List_Relasi &L, adr_Siswa P, adr_Sekolah Q, adr_Sekolah R);
void menu(List_Relasi &Lr, List_Sekolah &Lp, List_Siswa &Lc);
void deleteRelasiSiswa(List_Relasi &L, adr_Siswa &P);
void deleteRelasiSekolah(List_Relasi &L, adr_Sekolah &P);
bool checkNISN(List_Siswa L, int NISN);
bool checkNPSN(List_Sekolah L, int NPSN);
#endif // HEADER_H_INCLUDED
