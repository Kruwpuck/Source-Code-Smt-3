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
    address prev;
};
struct List{
    address first;
    address last;
};
void insertLast_103032330054(List &L, address P);
void createList_103032330054(List &L);
address createElm_103032330054(infotype data);
void deleteLast_103032330054(List &L, address &P);
void showInfo_103032330054(List L);
void reset_103032330054(List &L);
void split_103032330054(List &L, List &L1, List &L2, float N);
#endif // COBA_H_INCLUDED
