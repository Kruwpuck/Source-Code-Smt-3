#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
using namespace std;
typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List{
    address first;
};

void CreateList(List &L);
address allocate(infotype x);
void InsertFirst(List &L, address P);
void InsertLast(List &L, address P);
void InsertAfter(List &L, address prec, address P);
void DeleteFirst(List &L, address &P);
void DeleteLast(List &L, address &P);
void DeleteAfter(List &L, address prec, address &P);
address Search(List L, infotype x);
void Show(List L);


#endif // LIST_H_INCLUDED
