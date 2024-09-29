#include <iostream>

using namespace std;

struct karyawan {
    string nama, npwp, jabatan;
    int gaji;
};

typedef karyawan infotype;

typedef struct elmList *adr;

struct elmList {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void Create_List(List &L);

adr New_Elemen(infotype data);

void Insert_First(List &L, adr P);

void Insert_Last(List &L, adr P);

void Insert_After(List &L, adr P, adr prec);

void Delete_First(List &L, adr &P);

void Delete_Last(List &L, adr &P);

void Delete_After(List &L, adr prec, adr &P);

void Show(List L);
