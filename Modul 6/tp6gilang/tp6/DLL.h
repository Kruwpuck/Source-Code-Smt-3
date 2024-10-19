#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>

using namespace std;

struct lagu {
    string nama;
    string judul;
};

typedef lagu infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address prev;
    address next;
} ;

struct list {
    address first;
    address last;
};

void createlist_103032300130(list &l);
bool isEmpty_10302300130(list l);
void createNewElm_10302300130(infotype x, address &p);
void insertFirst_10302300130(list &l, address p);
void insertAfter_10302300130(list &l, address &p, address &prec);
void insertLast_10302300130(list &l, address p);
void deleteFirst_10302300130(list &l, address &p);
void deleteAfter_10302300130(list &l, address &prec, address &p);
void deleteLast_10302300130(list &l, address &p);
void concat_10302300130(list l1, list l2, list &l3);
address findSong_10302300130(list &l, string judul);
void removeSong_10302300130(string judul, list &l);
void show_103032300130(list l);


#endif // DLL_H_INCLUDED
