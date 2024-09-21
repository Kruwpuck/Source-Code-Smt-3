#include <iostream>
using namespace std;

int kendaraan(int kapasitas_kendaraan, int jumlah_penumpang){
    int jumlah_kendaraan;
    jumlah_kendaraan = jumlah_penumpang / kapasitas_kendaraan;
    if (jumlah_penumpang % kapasitas_kendaraan > 0){
        jumlah_kendaraan++;
    }
    return jumlah_kendaraan;
}

int main(){
    int kap_kendaraan, jum_penumpang, banyak_kendaraan;
    cout << "Masukkan kapasitas kendaraan: ";
    cin >> kap_kendaraan;
    cout << "Masukkan jumlah penumpang: ";
    cin >> jum_penumpang;
    banyak_kendaraan = kendaraan(kap_kendaraan, jum_penumpang);
    cout << "Banyak kendaraan yang disewa: " << banyak_kendaraan << endl;
    return 0;
}
