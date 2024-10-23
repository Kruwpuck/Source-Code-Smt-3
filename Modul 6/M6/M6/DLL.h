#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

using namespace std;

struct X{
    string penyanyi;
    string judulLagu;
};

typedef X infotype;
typedef struct elmlist *adr;

struct elmlist{
    infotype info;
    adr next;
    adr prev;
};

struct List{
    adr first;
    adr last;
};

void createNewlist_103032300129(List &L);
bool isEmpty_103032300129(List L);
adr createNewEml_103032300129(infotype X);
void insertFirst_103032300129(List &L, adr p);
void insertAfter_103032300129(List &L, adr &prec, adr p);
void insertLast_103032300129(List &L, adr p);
void deleteFirst_103032300129 (List &L, adr &p);
void deleteAfter_103032300129(List &L, adr prec, adr &p);
void deleteLast_103032300129(List &L, adr &p);
void concat_103032300129(List L1, List L2, List &L3);
adr findLagu_103032300129(List L, string judul);
void removeLagu_103032300129(List &L, string judul);
void show_103032300129(List L);






#endif // DLL_H_INCLUDED
