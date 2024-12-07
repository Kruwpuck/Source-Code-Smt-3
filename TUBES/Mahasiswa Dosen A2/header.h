#include <iostream>
using namespace std;
struct infotype_Mahasiswa{
    long long NIM;
    string nama;
    string semester;
};
struct infotype_Dosen{
    string kode;
    long long NIP;
    string nama;
};
typedef struct elm_Mahasiswa *adr_Mahasiswa;
typedef struct elm_Dosen *adr_Dosen;
typedef struct elm_Relasi *adr_Relasi;
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
struct elm_Mahasiswa{
    infotype_Mahasiswa info;
    adr_Mahasiswa next_Mahasiswa;
};
struct elm_Dosen{
    infotype_Dosen info;
    List_Relasi relasi;
    adr_Dosen next_Dosen;
    adr_Dosen prev_Dosen;
};
struct elm_Relasi{
    adr_Mahasiswa next_Mahasiswa;
    adr_Relasi next_Relasi;
};
void insertDosen(List_Dosen &L); 
void insertMahasiswa(List_Mahasiswa &L); 
void insertRelasi(List_Dosen &Ld, List_Mahasiswa &Lm); 
void deleteDosen(List_Dosen &Ld, adr_Dosen &P); 
void deleteFirstDosen(List_Dosen &L, adr_Dosen &P);
void deleteLastDosen(List_Dosen &L, adr_Dosen &P);
void deleteAfterDosen(List_Dosen &L, adr_Dosen &P);
void deleteMahasiswa(List_Dosen &Ld, List_Mahasiswa &Lm, adr_Mahasiswa &P); 
void deleteFirstMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P); 
void deleteLastAfterMahasiswa(List_Mahasiswa &L, adr_Mahasiswa &P);
void insertRelasiFirst(adr_Dosen &P, adr_Relasi &R);
void deleteRelasi(adr_Dosen &Q,adr_Relasi &P); 
void findDosen(List_Dosen L, adr_Dosen &P); 
void findMahasiswa(List_Mahasiswa L, adr_Mahasiswa &P); 
void findRelasi(adr_Dosen P, adr_Mahasiswa Q, adr_Relasi &R);
void showDosen(List_Dosen L); 
void showMahasiswa(List_Mahasiswa L); 
void showMahasiswaDariDosen(List_Dosen Ld); 
void showAllRelasiDosen(List_Dosen Ld); 
void showAllRelasiMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void showDosenDariMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void countAllRelasiDosen(List_Dosen Ld); 
void countRelasiDariMahasiswa(List_Mahasiswa Lm, List_Dosen Ld); 
void countMahasiswaTanpaDosen(List_Mahasiswa Lm, List_Dosen Ld); 
void editMahasiswaDariDosen(List_Mahasiswa &Lm, List_Dosen &Ld); 
void mainMenu(List_Dosen &Ld, List_Mahasiswa &Lm); 
bool checkNIM(List_Mahasiswa L, long long NIM);
bool checkNIP(List_Dosen L, long long NIP);
bool checkRelasi(adr_Mahasiswa P, adr_Dosen Q);