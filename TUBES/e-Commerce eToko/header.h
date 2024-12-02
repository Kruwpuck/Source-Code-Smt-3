#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype_Toko{
    int ID;
    string nama;
    string lokasi;
};
struct infotype_eCommerce{
    string platform;
    int ID;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Toko *adr_Toko;
typedef struct elm_eCommerce *adr_eCommerce;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Toko{
    infotype_Toko info;
    adr_Toko next_Toko;
    adr_Toko prev_Toko;
};
struct elm_eCommerce{
    infotype_eCommerce info;
    adr_eCommerce next_eCommerce;
};
struct elm_Relasi{
    adr_Toko next_Toko;
    adr_eCommerce next_eCommerce;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
struct List_Toko{
    adr_Toko first;
    adr_Toko last;
};
struct List_Relasi{
    adr_Relasi first;
    adr_Relasi last;
};
struct List_eCommerce{
    adr_eCommerce first;
};
void inserteCommerce(List_eCommerce &L, adr_eCommerce P);
void insertToko(List_Toko &L, adr_Toko P);
void insertRelasi(List_Relasi &L, adr_Relasi P);
void deleteeCommerce(List_eCommerce &L, adr_eCommerce &P);
void deleteFirsteCommerce(List_eCommerce &L, adr_eCommerce &P);
void deleteLasteCommerce(List_eCommerce &L, adr_eCommerce &P);
void deleteAftereCommerce(List_eCommerce &L, adr_eCommerce &P);
void deleteToko(List_Toko &L, adr_Toko &P);
void deleteFirstToko(List_Toko &L, adr_Toko &P);
void deleteLastToko(List_Toko &L, adr_Toko &P);
void deleteAfterToko(List_Toko &L, adr_Toko &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P);
void findeCommerce(List_eCommerce L, adr_eCommerce &P);
void findToko(List_Toko L, adr_Toko &P);
void checkRelasi(List_Relasi L, adr_Toko P, adr_eCommerce Q, adr_Relasi &R);
void showeCommerce(List_eCommerce L);
void showToko(List_Toko L);
void showToko_darieCommerce(List_Relasi L, adr_eCommerce P);
void showeCommerce_dariToko(List_Relasi L, adr_Toko P);
void showAll_RelasieCommerce(List_eCommerce Lp, List_Relasi Lr);
void showAll_RelasiToko(List_Toko Lc, List_Relasi Lr);
void hitungToko(List_Relasi L, adr_eCommerce P);
void hitungeCommerce(List_Relasi L, adr_Toko P);
void hitungeCommerceTanpaToko(List_Relasi Lr, List_eCommerce Lp);
void hitungTokoTanpaeCommerce(List_Relasi Lr, List_Toko Lc);
void editeCommerce(List_Relasi &L, adr_eCommerce P, adr_Toko Q, adr_Toko R);
void editToko(List_Relasi &L, adr_Toko P, adr_eCommerce Q, adr_eCommerce R);
void menu(List_Relasi &Lr, List_eCommerce &Lp, List_Toko &Lc);
void deleteRelasiToko(List_Relasi &L, adr_Toko &P);
void deleteRelasieCommerce(List_Relasi &L, adr_eCommerce &P);
bool checkID(List_Toko L, int ID);
bool checkID(List_eCommerce L, int ID);
#endif // HEADER_H_INCLUDED
