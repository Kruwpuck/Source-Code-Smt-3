#include <iostream>
using namespace std;
struct infotype_Mahasiswa{
    int NIM;
    string nama;
    string angkatan;
};
struct infotype_Dosen{
    string jabatan;
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
    adr_Mahasiswa prev_Mahasiswa;
    List_Relasi hubungan;
};
struct elm_Dosen{
    infotype_Dosen info;
    adr_Dosen next_Dosen;
    List_Relasi hubungan;
};
struct elm_Relasi{
    adr_Dosen next_Dosen;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
struct List_Mahasiswa{
    adr_Mahasiswa first;
    adr_Mahasiswa last;
};
struct List_Dosen{
    adr_Dosen first;
};
struct List_Relasi{
    adr_Relasi first;
};
void insertDosen(List_Dosen &L, adr_Dosen P); 
void insertMahasiswa(List_Mahasiswa &L, adr_Mahasiswa P); 
void insertRelasi(adr_Mahasiswa Q, adr_Relasi &P); 
void deleteDosen(List_Dosen &L, adr_Dosen &P); 
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P);
void deleteLastAfterDosen(List_Dosen &L, adr_Dosen &P);
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteLastMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P); 
void findDosen(List_Dosen L, adr_Dosen &P); 
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P); 
void findRelasi(List_Relasi L, adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R);
void showDosen(List_Dosen L); 
void showMahasiswa(List_Mahasiswa L); 
void showMahasiswaDariDosen(List_Mahasiswa L,adr_Dosen P); 
void showAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void showAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void showDosenDariMahasiswa(List_Dosen L, adr_Mahasiswa P); 
void countAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void countRelasiDariMahasiswa(adr_Mahasiswa P); 
void countMahasiswaTanpaDosen(List_Mahasiswa Lm); 
void editMahasiswaDariDosen(adr_Mahasiswa &S, adr_Mahasiswa &T, adr_Dosen P, adr_Relasi &R); 
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm); 