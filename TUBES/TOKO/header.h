#include <iostream>
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
using namespace std;
struct bioskop{
    string id;
    string nama;
    int kapasitas;
};
struct film{
    string id;
    string judul;
    int durasi;
};
typedef struct elm_bioskop *adr_bioskop;
typedef struct elm_film *adr_film;
struct elm_bioskop{
    bioskop info;
    adr_bioskop next_bioskop;
    adr_bioskop prev_bioskop;
    adr_film film;
};
struct elm_film{
    film info;
    adr_film next_film;
    adr_film prev_film;
};
struct List_Bioskop{
    adr_bioskop first;
    adr_bioskop last;
};
struct List_film{
    adr_film first;
    adr_film last;
};
void insertLastBioskop(List_Bioskop &L, adr_bioskop P);
void updateBioskop(List_Bioskop &L, adr_bioskop P);
void searchBioskop(List_Bioskop L, string id, adr_bioskop &P);
void deleteBioskop(List_Bioskop &L, adr_bioskop &P);

void insertLastfilm(List_film &L, adr_film P);
void updatefilm(List_film &L, adr_film P);
void searchfilm(List_film L, string id, adr_film &P);
void deletefilm(List_film &L, adr_film &P);
void sortfilm(List_film &L);
adr_film findMax(List_film L);
void swapFilms(adr_film &a, adr_film &b);
void showBioskop(List_Bioskop L);
#endif // HEADER_H_INCLUDED
