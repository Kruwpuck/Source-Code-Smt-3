#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct elm_int *adr_int;
struct elm_int {
    int info;
    adr_int next;
};
struct List_int {
    adr_int first;
};
void insertLastint(List_int &L, adr_int P);
adr_int deleteListint(List_int &L);
#endif // HEADER_H_INCLUDED
