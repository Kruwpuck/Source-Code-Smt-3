#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
using namespace std;
typedef int infotype;
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
address findMin_103032330054(List L);
void insertMiddle_103032330054(List &L, int data);
int selectMenu_103032330054();
#endif // SLL_H_INCLUDED
