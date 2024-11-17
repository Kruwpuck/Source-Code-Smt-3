#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_siswa{
    string NISN;
    string nama;
    int kelas;
};
struct infotype_sekolah{
    string kode;
    string NIDN;
    string nama;
};
typedef struct adr_siswa *elm_siswa;
typedef struct adr_sekolah *elm_sekolah;
typedef struct adr_relasi *elm_relasi;
struct elm_siswa{
    infotype_siswa info;
    adr_siswa next_siswa;
    adr_siswa prev_siswa;
};
struct elm_sekolah{
    infotype_sekolah info;
    adr_sekolah next_sekolah;
};
struct elm_relasi{
    adr_siswa next_siswa;
    adr_sekolah next_sekolah;
    adr_relasi next_relasi;
};
struct List_siswa{
    adr_siswa first;
    adr_siswa last;
};
struct List_relasi{
    adr_relasi first;
};
struct List_sekolah{
    adr_sekolah first;
};
void insertsekolah(List_sekolah &L, adr_sekolah P);
void insertsiswa(List_siswa &L, adr_siswa P);
void insertRelasi(List_relasi &L, adr_relasi P);
void deletesekolah(List_sekolah &L, adr_sekolah &P);
void deletesiswa(List_siswa &L, adr_siswa &P);
void deleteRelasi(List_relasi &L, adr_relasi P);
void checkRelasi(List_relasi L, adr_siswa P, adr_sekolah Q);
void showsekolah(List_sekolah L);
void showsiswa(List_siswa L);
void showsiswa_darisekolah(List_relasi L, adr_sekolah P);
void showsekolah_darisiswa(List_relasi L, adr_siswa P);
void showAll_relasisekolah(List_sekolah Ld, List_relasi Lr);
void showAll_relasisiswa(List_sekolah Lm, List_relasi Lr);
void countsiswa(List_relasi L, adr_sekolah P);
void countsekolah(List_relasi L, adr_siswa P);
void countsiswa_Less(List_relasi Lr, List_sekolah Ld);
void countsekolah_Less(List_relasi Lr, List_siswa Lm);
void editsekolah(List_relasi L, adr_sekolah P, adr_siswa Q);
void editsiswa(List_relasi L, adr_sekolah P, adr_siswa Q);
#endif // HEADER_H_INCLUDED
