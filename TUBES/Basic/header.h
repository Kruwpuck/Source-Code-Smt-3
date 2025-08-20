#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct elm_char *adr_char;
struct elm_char {
    char info;
    adr_char next;
};
struct List_char {
    adr_char first;
};
void insertLastchar(List_char &L, adr_char P);
void insertFirstchar(List_char &L, adr_char P);
#endif // HEADER_H_INCLUDED
