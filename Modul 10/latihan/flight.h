//test
#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct elemenJadwal *adr_jadwalP;
typedef struct elemenPenumpang *adr_penumpangP;
struct penumpang{
    string nama, nik, jk;
    int usia;
};
struct JadwalPenerbangan{
    string kode, jenis, tanggal, waktu, asal, tujuan;
    int kapasitas;
};
typedef penumpang infotypePenumpang;
typedef JadwalPenerbangan infotypeJadwal;
struct elemenJadwal{
    infotypeJadwal info;
    adr_jadwalP next;
};
struct elemenPenumpang{
    infotypePenumpang info;
    adr_jadwalP jadwalP;
    adr_penumpangP next;
};
struct listPenumpang{
    adr_penumpangP first;
};
struct listJadwal{
     adr_jadwalP first;
};
void createListJadwal_103032330054(listJadwal &L);
adr_jadwalP createElemenJadwal_103032330054(infotypeJadwal X);
void InsertLastJ_103032330054(listJadwal &L, adr_jadwalP P);
void ShowJadwal_103032330054(listJadwal L);
void DeleteFirstJ_103032330054(listJadwal &L, adr_jadwalP &P);
adr_jadwalP SearchJ_103032330054(listJadwal L, string dari, string ke, string tanggal);
void createListPenumpang_103032330054(listPenumpang &LP);
adr_penumpangP createElemenPenumpang_103032330054(infotypePenumpang X);
void insertLastP_103032330054(listPenumpang &LP, adr_penumpangP P);
void booking_103032330054(listPenumpang &LP, infotypePenumpang X, listJadwal LJ, string dari, string ke, string tanggal);
void showPenumpang_103032330054(listPenumpang LP);
void reschedule_103032330054(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal);
void showAllListPenumpang_103032330054(listJadwal LJ, listPenumpang LP, string kode);
#endif // FLIGHT_H_INCLUDED
