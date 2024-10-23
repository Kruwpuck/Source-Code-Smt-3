#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
using namespace std;
struct history{
    string title, url, timestamp;
    int visitcount;
};
typedef history infotype;
typedef struct elmList *address;
struct elmList{
    infotype info;
    address next;
    address prev;
};
struct List{
    address First;
    address Last;
};

void createList_103032330054(List &L);
address createElemen_103032330054(infotype dataBaru);
void insertLast_103032330054(List &L, address P);
void insertAfter_103032330054(address &Prec, address &P);
void deleteFirst_103032330054(List &L, address &P);
void deleteLast_103032330054(List &L, address &P);
void deleteAfter_103032330054(address &Prec, address &P);
void insertFirst_103032330054(List &L, address P);
void insertAscending_103032330054(List &L, infotype dataBaru);
bool findElemen_103032330054(List L, string X);
int moreThanOnce_103032330054(List L);
void printList_103032330054(List L);


#endif // DLL_H_INCLUDED
