#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
typedef string infotype;
typedef struct elmlist *address;
struct elmlist{
    address next;
    infotype info;
};
struct List{
    address first;
};

void CreateList_103032330054(List &L);
address CreateNewElm_103032330054(infotype data);
void InsertLast_103032330054(List &L, address p);
void Show_103032330054(List L);
address shortestName_103032330054(List L);
void showFirstKNameC_103032330054(List L, int k, char c);
int selectMenu_103032330054();
#endif // SLL_H_INCLUDED
