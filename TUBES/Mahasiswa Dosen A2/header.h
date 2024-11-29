#include <iostream>
using namespace std;
struct infotype_Mahasiswa{
    int NIM;
    string nama;
    float IPK;
};
struct infotype_Dosen{
    string kode;
    int NIP;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Mahasiswa *adr_Mahasiswa;
typedef struct elm_Dosen *adr_Dosen;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Mahasiswa{
    infotype_Mahasiswa info;
    adr_Mahasiswa next_Mahasiswa;
    List_Relasi relasi;
};
struct elm_Dosen{
    infotype_Dosen info;
    adr_Dosen next_Dosen;
    adr_Dosen prev_Dosen;
    List_Relasi hubungan;
};
struct elm_Relasi{
    adr_Dosen next_Dosen;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
struct List_Mahasiswa{
    adr_Mahasiswa first;
};
struct List_Dosen{
    adr_Dosen first;
    adr_Dosen last;
};
struct List_Relasi{
    adr_Relasi first;
};
void insertDosen(List_Dosen &L, adr_Dosen P); 
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P); 
void insertRelasi(adr_Mahasiswa Q, adr_Relasi &P); 
void deleteDosen(List_Dosen &L, adr_Dosen &P); 
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P);
void deleteLastDosen(List_Dosen &L, adr_Dosen &P);
void deleteAfterDosen(List_Dosen &L, adr_Dosen &P);
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteLastAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P); 
void cariDosen(List_Dosen L, adr_Dosen &P); 
void cariMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P); 
void cariRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R);
void TampilkanDosen(List_Dosen L); 
void TampilkanMahasiswa(List_Mahasiswa L); 
void TampilkanMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P); 
void TampilkanAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void TampilkanAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void TampilkanDosenDariMahasiswa(List_Dosen L, adr_Mahasiswa P); 
void hitungAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void hitungRelasiDariMahasiswa(adr_Mahasiswa P); 
void hitungMahasiswaTanpaDosen(List_Mahasiswa Lm); 
void editMahasiswaDariDosen(List_Dosen Ld, List_Mahasiswa Lm, adr_Dosen P); 
void menuUtama(List_Dosen &Ld, List_Mahasiswa &Lm); 