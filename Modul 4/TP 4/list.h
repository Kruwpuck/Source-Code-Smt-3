#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

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

void createList_103032300018(List &L);
address allocate_103032300018(infotype x);
void insertFirst_103032300018(List &L, address P);
void printInfo_103032300018(List L);




#endif // LIST_H_INCLUDED
