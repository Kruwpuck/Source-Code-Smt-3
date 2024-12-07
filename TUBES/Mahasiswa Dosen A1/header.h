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
typedef struct elm_Mahasiswa *adr_Mahasiswa;
typedef struct elm_Dosen *adr_Dosen;
typedef struct elm_Relasi *adr_Relasi;
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
struct elm_Mahasiswa{
    infotype_Mahasiswa info;
    adr_Mahasiswa next_Mahasiswa;
    adr_Mahasiswa prev_Mahasiswa;
    List_Relasi hubungan;
};
struct elm_Dosen{
    infotype_Dosen info;
    adr_Dosen next_Dosen;
};
struct elm_Relasi{
    adr_Dosen next_Dosen;
    adr_Relasi next_Relasi;
};
void insertDosen(List_Dosen &L); 
void insertMahasiswa(List_Mahasiswa &L); 
void insertRelasi(List_Dosen &Ld, List_Mahasiswa &Lm); 
void deleteDosen(List_Dosen &Ld, List_Mahasiswa &Lm, adr_Dosen &P); 
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P);
void deleteLastAfterDosen(List_Dosen &L, adr_Dosen &P);
void deleteMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteLastMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void deleteAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void insertRelasiFirst(adr_Mahasiswa &P, adr_Relasi &R);
void deleteRelasi(adr_Mahasiswa &Q,adr_Relasi &P); 
void findDosen(List_Dosen L, adr_Dosen &P); 
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P); 
void findRelasi(adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R);
void showDosen(List_Dosen L); 
void showMahasiswa(List_Mahasiswa L); 
void showMahasiswaDariDosen(List_Mahasiswa Lm, List_Dosen Ld); 
void showAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void showAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void showDosenDariMahasiswa(List_Mahasiswa Lm); 
void countAllRelasiDosen(List_Dosen Ld, List_Mahasiswa Lm); 
void countRelasiDariMahasiswa(List_Mahasiswa Lm); 
void countMahasiswaTanpaDosen(List_Mahasiswa Lm); 
void editMahasiswaDariDosen(List_Mahasiswa &Lm, List_Dosen &Ld); 
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm); 
bool checkNIM(List_Mahasiswa L, int NIM);
bool checkNIP(List_Dosen L, int NIP);
bool checkRelasi(adr_Mahasiswa P, adr_Dosen Q);