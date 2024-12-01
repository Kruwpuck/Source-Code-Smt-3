#include <iostream>
using namespace std;
struct infotype_Customer{
    int NIK;
    string nama;
    string kelas;
};
struct infotype_Toko{
    string kategori;
    int ID;
    string nama;
};
typedef string infotype_Relasi;
typedef struct elm_Customer *adr_Customer;
typedef struct elm_Toko *adr_Toko;
typedef struct elm_Relasi *adr_Relasi;
struct elm_Customer{
    infotype_Customer info;
    adr_Customer next_Customer;
    adr_Customer prev_Customer;
    List_Relasi relasi;
};
struct elm_Toko{
    infotype_Toko info;
    adr_Toko next_Toko;
    List_Relasi hubungan;
};
struct elm_Relasi{
    adr_Toko next_Toko;
    adr_Relasi next_Relasi;
    infotype_Relasi info;
};
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
void insertToko(List_Toko &L, adr_Toko P); 
void insertCustomer(List_Customer &L, adr_Customer P); 
void insertRelasi(adr_Customer Q, adr_Relasi &P); 
void deleteToko(List_Toko &L, adr_Toko &P); 
void deleteFirstToko(List_Toko &L, adr_Toko &P);
void deleteLastAfterToko(List_Toko &L, adr_Toko &P);
void deleteCustomer(List_Customer &L, adr_Customer &P); 
void deleteFirstCustomer(List_Customer &L, adr_Customer &P); 
void deleteLastCustomer(List_Customer &L, adr_Customer &P);
void deleteAfterCustomer(List_Customer &L, adr_Customer &P);
void deleteRelasi(List_Relasi &L,adr_Relasi &P); 
void findToko(List_Toko L, adr_Toko &P); 
void findCustomer(List_Customer L, adr_Customer &P); 
void findRelasi(List_Relasi L, adr_Toko P, adr_Customer Q, adr_Relasi &R);
void showToko(List_Toko L); 
void showCustomer(List_Customer L); 
void showCustomerDariToko(List_Customer L,adr_Toko P); 
void showAllRelasiToko(List_Toko Ld, List_Customer Lm); 
void showAllRelasiCustomer(List_Customer Lm, List_Toko Ld); 
void showTokoDariCustomer(List_Toko L, adr_Customer P); 
void countAllRelasiToko(List_Toko Ld, List_Customer Lm); 
void countRelasiDariCustomer(adr_Customer P); 
void countCustomerTanpaToko(List_Customer Lm); 
void editCustomerDariToko(adr_Customer &S, adr_Customer &T, adr_Toko P, adr_Relasi &R); 
void mainMenu(List_Toko &Ld, List_Customer &Lm); 