#include "flight.h"
int main()
{
    ListJadwal L;
    int n;
    infotype X;
    createListJadwal_103032330054(L);
    // minta inputan jadwal Penerbangan sebanyak n kali
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << endl <<"Masukkan Data Penerbangan ke-" << i+1 << endl;
        cout << "Kode Penerbangan : "; cin >> X.Kode;
        cout << endl << "Jenis Penerbangan : "; cin >> X.Jenis;
        cout << endl << "Tanggal Penerbangan : "; cin >> X.Tanggal;
        cout << endl << "Waktu Penerbangan : "; cin >> X.Waktu;
        cout << endl << "Asal Penerbangan : "; cin >> X.Asal;
        cout << endl << "Tujuan Penerbangan : "; cin >> X.Tujuan;
        cout << endl << "Kapasitas Penerbangan : "; cin >> X.Kapasitas;
        adr_jadwalP P = createElemenJadwal_103032330054(X);
        InsertLastJ_103032330054(L, P);
    }
    cout << endl << "--------------- SEBELUM DELETE FIRST ---------------" << endl;
    ShowJadwal_103032330054(L);
    cout << endl << "--------------- SETELAH DELETE FIRST ---------------" << endl;
    adr_jadwalP P;
    // delete Jadwal penerbangan
    DeleteFirstJ_103032330054(L, P);
    ShowJadwal_103032330054(L);
    // Cari jadwal penerbangan dari surabaya ke malang tanggal 9 Desember 2022
    P = SearchJ_103032330054(L, "Surabaya", "Malang", "2022-12-9");
    if (P != NULL){
        cout << endl << "--------------- DATA YANG DICARI ---------------" << endl;
        cout << endl << "Kode Penerbangan : " << P->info.Kode << endl;
        cout << "Jenis Penerbangan : " << P->info.Jenis << endl;
        cout << "Tanggal Penerbangan : " << P->info.Tanggal << endl;
        cout << "Waktu Penerbangan : " << P->info.Waktu << endl;
        cout << "Asal Penerbangan : " << P->info.Asal << endl;
        cout << "Tujuan Penerbangan : " << P->info.Tujuan << endl;
        cout << "Kapasitas Penerbangan : " << P->info.Kapasitas << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
    }
}
