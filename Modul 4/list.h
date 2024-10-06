

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

void createList_103032330054(List &L);
address allocate_103032330054(infotype x);
void insertFirst_103032330054(List &L, address P);
void printInfo_103032330054(List L);

