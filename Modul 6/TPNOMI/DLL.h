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
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

bool isEmpty_103032300090(List L);
void createList_103032300090(List &L);
address creatNewElm_103032300090(infotype X);
void insertfirst_103032300090(List &L,address P);
void insertafter_103032300090(List &L, address &Prec,address P);
void insertlast_103032300090(List &L,address P);
void deletefirst_103032300090(List &L,address &P);
void deleteafter_103032300090(List &L,address prec,address &P);
void deletelast_103032300090(List &L,address &P);
void concat_103032300090(List L1 , List L2, List &L3);
address findsong_103032300090(string judul,List L);
void removesong_103032300090(string judul,List &L);
void show_103032300090(List L);







#endif // DLL_H_INCLUDED
