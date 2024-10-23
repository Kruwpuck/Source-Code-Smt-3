#include <iostream>
using namespace std;

struct infotype {
    string Judul;
    string namaBand;
};

typedef struct elmtList *address;

struct elmtList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

void createList_103032330095(List &L);
bool isEmpty_103032330095(List L);
address createNewElmt_103032330095(infotype X);
void insertFirst_103032330095(List &L, address P);
void insertAfter_103032330095(List &L, address Prec, address P);
void insertLast_103032330095(List &L, address P);
void deleteFirst_103032330095(List &L, address &P);
void deleteAfter_103032330095(List &L, address Prec, address &P);
void deleteLast_103032330095(List &L, address &P);
void concat_103032330095(List L1, List L2, List &L3);
address findLagu_103032330095(List L, string Judul);
void removeLagu_103032330095(List &L, string Judul);
void showAll_103032330095(List L);
int tampilkanMenu_103032330095();


