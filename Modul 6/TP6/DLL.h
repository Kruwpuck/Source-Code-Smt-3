#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype{
    string judul;
    string penyanyi;
};
typedef struct elmlist *address;
struct elmlist{
    infotype info;
    address prev;
    address next;
};
struct List{
    address first;
    address last;
};
void createNewList(List &L);
bool isEmpty_103032330054(List L);
address createNewElmt_103032330054(infotype X);
void inserFirst_103032330054(List &L, address P);
void insertAfter_103032330054(List &L, address &prec, address P);
void insertLast_103032330054(List &L, address P);
void deleteFirst_103032330054(List &L, address &P);
void deleteAfter_103032330054(List &L, address prec, address &P);
void deleteLast_103032330054(List &L, address &P);
void concat_103032330054(List L1, List L2, List &L3);
address findLagu_103032330054(List L, string Judul);
void removeLagu_103032330054(List &L, string Judul);
#endif // DLL_H_INCLUDED
