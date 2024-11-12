#ifndef COBA_H_INCLUDED
#define COBA_H_INCLUDED
#include <iostream>
using namespace std;
struct driver{
    string nama;
    float rating;
};
typedef driver infotype;
typedef struct elmlist *address;
struct elmlist{
    infotype info;
    address next;
};
struct List{
    address first;
};
void insertFirst_103032330054(List &L, address P);
address createElm_103032330054(infotype data);
void deleteFirst_103032330054(List &L, address &P);
void showInfo_103032330054(List L);
void reset_103032330054(List &L);
void split_103032330054(List &L, List &L1, List &L2, float N);
#endif // COBA_H_INCLUDED
