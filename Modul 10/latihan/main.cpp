#include "flight.h"


int main()
{
    listJadwal LJ;
    infotypeJadwal Y;
    adr_jadwalP Q;
    infotypePenumpang X;
    adr_penumpangP P;
    string nik;
    string asal, tujuan, tanggal, kode;
    createListJadwal_103032330054(LJ);
    cout << endl << "=============== INPUT PENERBANGAN ===============" << endl;
    for (int i = 1 ; i <= 4 ; i++){
        cout << "Data ke-" << i << endl;
        cout << "Kode     :";
        cin >> Y.kode;
        cout << endl << "Jenis    :";
        cin >> Y.jenis;
        cout << endl << "Tanggal  :";
        cin >> Y.tanggal;
        cout << endl << "Waktu    :";
        cin >> Y.waktu;
        cout << endl << "Asal     :";
        cin >> Y.asal;
        cout << endl << "Tujuan   :";
        cin >> Y.tujuan;
        cout << endl << "Kapasitas:";
        cin >> Y.kapasitas;
        cout << endl <<  endl ;
        Q = createElemenJadwal_103032330054(Y);
        InsertLastJ_103032330054(LJ, Q);
    }
    ShowJadwal_103032330054(LJ);
    listPenumpang LP;
    createListPenumpang_103032330054(LP);
    for (int j = 1 ; j<=6 ; j++){
        cout << "Data ke-" << j << endl;
        cout << "Nama                 :";
        cin >> X.nama;
        cout << endl << "NIK                  :";
        cin >> X.nik;
        cout << endl << "Jenis Kelamin        :";
        cin >> X.jk;
        cout << endl << "Usia                 :";
        cin >> X.usia;
        cout << endl << "Asal Penerbangan     :";
        cin >> asal;
        cout << endl << "Tujuan Penerbangan   :";
        cin >> tujuan;
        cout << endl << "Tanggal Penerbangan:";
        cin >> tanggal;
        cout << endl <<  endl ;
        booking_103032330054(LP,X,LJ,asal,tujuan,tanggal);
    }
    showPenumpang_103032330054(LP);
    cout << "Tampilkan Penumpang Berdasarkan Kode Penerbangan" << endl << "Kode: ";
    cin >> kode;
    showAllListPenumpang_103032330054(LJ,LP,kode);
    cout << endl << "Reschedule";
    cout << endl << "NIK    :";
    cin >> nik;
    cout << endl << "Asal   :";
    cin >> asal;
    cout << endl << "Tujuan :";
    cin >> tujuan;
    cout << endl << "Tanggal:";
    cin >> tanggal;

    cout << "Tampilkan Penumpang Berdasarkan Kode Penerbangan" << endl << "Kode: ";
    cin >> kode;
    cout << endl << endl << "===============PENUMPANG===============" << endl;
    showAllListPenumpang_103032330054(LJ,LP,kode);
    return 0;
}
