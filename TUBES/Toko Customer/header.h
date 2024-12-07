#include <iostream>
using namespace std;
struct infotype_Customer{
    long long NIK;
    string nama;
    string kelas;
};
struct infotype_Toko{
    string kategori;
    long long ID;
    string nama;
};
typedef struct eLc_Customer *adr_Customer;
typedef struct eLc_Toko *adr_Toko;
typedef struct eLc_Relasi *adr_Relasi;
struct List_Customer{
    adr_Customer first;
    adr_Customer last;
};
struct List_Toko{
    adr_Toko first;
};
struct List_Relasi{
    adr_Relasi first;
};
struct eLc_Customer{
    infotype_Customer info;
    adr_Customer next_Customer;
    adr_Customer prev_Customer;
};
struct eLc_Toko{
    infotype_Toko info;
    List_Relasi relasi;
    adr_Toko next_Toko;
};
struct eLc_Relasi{
    adr_Customer next_Customer;
    adr_Relasi next_Relasi;
};
void Menu(List_Toko &Lt, List_Customer &Lc);
void insertToko(List_Toko &L);
void insertCustomer(List_Customer &L);
void insertRelasi(List_Toko &Lt, List_Customer &Lc);
void deleteToko(List_Toko &Lt, adr_Toko &P);
void deleteFirstToko(List_Toko &L, adr_Toko &P);
void deleteAfterLastToko(List_Toko &L, adr_Toko &P);
void deleteCustomer(List_Toko &Lt, List_Customer &Lc, adr_Customer &P);
void deleteFirstCustomer(List_Customer &L, adr_Customer &P);
void deleteLastCustomer(List_Customer &L, adr_Customer &P);
void deleteAfterCustomer(List_Customer &L, adr_Customer &P);
void insertRelasiFirst(adr_Toko &P, adr_Relasi &R);
void deleteRelasi(adr_Toko &Q,adr_Relasi &P);
void findToko(List_Toko L, adr_Toko &P);
void findCustomer(List_Customer L, adr_Customer &P);
void findRelasi(adr_Toko P, adr_Customer Q, adr_Relasi &R);
void showToko(List_Toko L);
void showCustomer(List_Customer L);
void showCustomerDariToko(List_Toko Lt);
void showAllRelasiToko(List_Toko Lt);
void showAllRelasiCustomer(List_Customer Lc, List_Toko Lt);
void showTokoDariCustomer(List_Customer Lc, List_Toko Lt);
void countAllRelasiToko(List_Toko Lt);
void countRelasiDariCustomer(List_Customer Lc, List_Toko Lt);
void countCustomerTanpaToko(List_Customer Lc, List_Toko Lt);
void editCustomerDariToko(List_Customer &Lc, List_Toko &Lt);
void Menu(List_Toko &Lt, List_Customer &Lc);
bool checkNIK(List_Customer L, long long NIK);
bool checkID(List_Toko L, long long ID);
bool checkRelasi(adr_Customer P, adr_Toko Q);
