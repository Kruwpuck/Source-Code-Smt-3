#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Pengirim{
    int HP;
    string Nama;
    string Barang;
    string Alamat;
};
struct infotype_eCommerce{
    string Jenis;
    int Kode;
    string Nama;
};
typedef struct eLc_Pengirim *adr_Pengirim;
typedef struct eLc_eCommerce *adr_eCommerce;
typedef struct eLc_Relasi *adr_Relasi;
struct List_Pengirim{
    adr_Pengirim first;
    adr_Pengirim last;
};
struct List_eCommerce{
    adr_eCommerce first;
};
struct List_Relasi{
    adr_Relasi first;
};
struct eLc_Pengirim{
    infotype_Pengirim info;
    adr_Pengirim next_Pengirim;
    adr_Pengirim prev_Pengirim;
};
struct eLc_eCommerce{
    infotype_eCommerce info;
    List_Relasi relasi;
    adr_eCommerce next_eCommerce;
};
struct eLc_Relasi{
    adr_Pengirim next_Pengirim;
    adr_Relasi next_Relasi;
};
void Menu(List_eCommerce &Lt, List_Pengirim &Lc);
void inserteCommerce(List_eCommerce &L);
void insertPengirim(List_Pengirim &L);
void insertRelasi(List_eCommerce &Lt, List_Pengirim &Lc);
void deleteeCommerce(List_eCommerce &Lt, adr_eCommerce &P);
void deleteFirsteCommerce(List_eCommerce &L, adr_eCommerce &P);
void deleteAfterLasteCommerce(List_eCommerce &L, adr_eCommerce &P);
void deletePengirim(List_eCommerce &Lt, List_Pengirim &Lc, adr_Pengirim &P);
void deleteFirstPengirim(List_Pengirim &L, adr_Pengirim &P);
void deleteLastPengirim(List_Pengirim &L, adr_Pengirim &P);
void deleteAfterPengirim(List_Pengirim &L, adr_Pengirim &P);
void insertRelasiFirst(adr_eCommerce &P, adr_Relasi &R);
void deleteRelasi(adr_eCommerce &Q,adr_Relasi &P);
void findeCommerce(List_eCommerce L, adr_eCommerce &P);
void findPengirim(List_Pengirim L, adr_Pengirim &P);
void findRelasi(adr_eCommerce P, adr_Pengirim Q, adr_Relasi &R);
void showeCommerce(List_eCommerce L);
void showPengirim(List_Pengirim L);
void showPengirimDarieCommerce(List_eCommerce Lt);
void showAllRelasieCommerce(List_eCommerce Lt);
void showAllRelasiPengirim(List_Pengirim Lc, List_eCommerce Lt);
void showeCommerceDariPengirim(List_Pengirim Lc, List_eCommerce Lt);
void countAllRelasieCommerce(List_eCommerce Lt);
void countRelasiDariPengirim(List_Pengirim Lc, List_eCommerce Lt);
void countPengirimTanpaeCommerce(List_Pengirim Lc, List_eCommerce Lt);
void editPengirimDarieCommerce(List_Pengirim &Lc, List_eCommerce &Lt);
void Menu(List_eCommerce &Lt, List_Pengirim &Lc);
bool checkHP(List_Pengirim L, int HP);
bool checkKode(List_eCommerce L, int Kode);
bool checkRelasi(adr_Pengirim P, adr_eCommerce Q);

#endif // HEADER_H_INCLUDED
