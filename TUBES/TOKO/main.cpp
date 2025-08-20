#include "header.h"
int main(){
    List_Bioskop Lb;
    List_film Lf;
    Lb.first = NULL;
    Lb.last = NULL;
    Lf.first = NULL;
    Lf.last = NULL;
    int pilihan = 1;
    while (pilihan != 0){
        cout << "------------------------------------------------------------" << endl;
        cout << "|   1. Bioskop                                             |" << endl;
        cout << "|   2. Film                                                |" << endl;
        cout << "|   3. Show                                                |" << endl;
        cout << "|   0. Keluar                                              |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            cout << "------------------------------------------------------------" << endl;
            cout << "|   1. Insert Last                                        |" << endl;
            cout << "|   2. Update                                             |" << endl;
            cout << "|   3. Search                                             |" << endl;
            cout << "|   4. Delete                                             |" << endl;
            cout << "|   0. Keluar                                             |" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "Masukkan pilihan: ";
            int subpilihan;
            cin >> subpilihan;
            if (subpilihan == 1){
                adr_bioskop Q = new elm_bioskop;
                Q->next_bioskop = NULL;
                Q->prev_bioskop = NULL;
                Q->film = NULL;
                cout << "Masukkan ID Bioskop: ";
                cin >> Q->info.id;
                cout << "Masukkan Nama Bioskop: ";
                cin >> Q->info.nama;
                cout << "Masukkan Kapasitas Bioskop: ";
                cin >> Q->info.kapasitas;
                cout << "Masukkan ID Film yang akan ditambahkan: ";
                string id_film;
                cin >> id_film;
                adr_film R;
                searchfilm(Lf, id_film, R);
                if (R != NULL){
                    Q->film = R;
                } else {
                    cout << "Film dengan ID tersebut tidak ditemukan." << endl;
                    Q->film = NULL;
                }
                insertLastBioskop(Lb, Q);
            } else if (subpilihan == 2){
                adr_bioskop P;
                string id;
                cout << "Masukkan ID Bioskop yang ingin diupdate: ";
                cin >> id;
                searchBioskop(Lb, id, P);
                if (P != NULL){
                    updateBioskop(Lb, P);
                    cout << "Bioskop dengan ID " << id << " telah diupdate." << endl;
                } else {
                    cout << "Bioskop dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 3){
                adr_bioskop P;
                string id;
                cout << "Masukkan ID Bioskop yang ingin dicari: ";
                cin >> id;
                searchBioskop(Lb, id, P);
                if (P == NULL){
                    cout << "Bioskop dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 4){
                adr_bioskop P;
                string id;
                cout << "Masukkan ID Bioskop yang ingin dihapus: ";
                cin >> id;
                searchBioskop(Lb, id, P);
                if (P != NULL){
                    deleteBioskop(Lb, P);
                    cout << "Bioskop dengan ID " << id << " telah dihapus." << endl;
                } else {
                    cout << "Bioskop dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 0){
                cout << "Keluar dari menu Bioskop." << endl;
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
        } else if (pilihan == 2){
            cout << "------------------------------------------------------------" << endl;
            cout << "|   1. Insert Last                                        |" << endl;
            cout << "|   2. Update                                             |" << endl;
            cout << "|   3. Search                                             |" << endl;
            cout << "|   4. Delete                                             |" << endl;
            cout << "|   5. Sort                                               |" << endl;
            cout << "|   0. Keluar                                             |" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "Masukkan pilihan: ";
            int subpilihan;
            cin >> subpilihan;
            if (subpilihan == 1){
                adr_film Q = new elm_film;
                Q->next_film = NULL;
                Q->prev_film = NULL;
                cout << "Masukkan ID Film: ";
                cin >> Q->info.id;
                cout << "Masukkan Judul Film: ";
                cin >> Q->info.judul;
                cout << "Masukkan Durasi Film: ";
                cin >> Q->info.durasi;
                insertLastfilm(Lf, Q);
            } else if (subpilihan == 2){
                adr_film P;
                string id;
                cout << "Masukkan ID Film yang ingin diupdate: ";
                cin >> id;
                searchfilm(Lf, id, P);
                if (P != NULL){
                    updatefilm(Lf, P);
                    cout << "Film dengan ID " << id << " telah diupdate." << endl;
                } else {
                    cout << "Film dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 3){
                adr_film P;
                string id;
                cout << "Masukkan ID Film yang ingin dicari: ";
                cin >> id;
                searchfilm(Lf, id, P);
                if (P == NULL){
                    cout << "Film dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 4){
                adr_film P;
                string id;
                cout << "Masukkan ID Film yang ingin dihapus: ";
                cin >> id;
                searchfilm(Lf, id, P);
                if (P != NULL){
                    deletefilm(Lf, P);
                    cout << "Film dengan ID " << id << " telah dihapus." << endl;
                } else {
                    cout << "Film dengan ID tersebut tidak ditemukan." << endl;
                }
            } else if (subpilihan == 5){
                sortfilm(Lf);
            } else if (subpilihan == 0){
                cout << "Keluar dari menu Film." << endl;
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
        } else if (pilihan == 3){
            showBioskop(Lb);
        } else if (pilihan == 0){
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
