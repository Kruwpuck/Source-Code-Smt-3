#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;
struct jadwalPenerbangan{
    string Kode, Jenis, Tanggal, Waktu, Asal, Tujuan;
    int Kapasitas;
};
typedef struct jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_jadwalP;
struct elemenJadwal{
    infotype info;
    adr_jadwalP next;
};
struct ListJadwal{
    adr_jadwalP First;
};
void createListJadwal_103032330054(ListJadwal &L);
adr_jadwalP createElemenJadwal_103032330054(infotype X);
void InsertLastJ_103032330054(ListJadwal &L, adr_jadwalP P);
void ShowJadwal_103032330054(ListJadwal L);
void DeleteFirstJ_103032330054(ListJadwal &L, adr_jadwalP &P);
adr_jadwalP SearchJ_103032330054(ListJadwal L, string dari, string ke, string tanggal);


#endif // MLL_H_INCLUDED
