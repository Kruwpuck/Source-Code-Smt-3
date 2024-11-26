#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk memproses N dan K sesuai dengan aturan yang diberikan
long long processNumber(long long N, int K) {
    // Mengubah N menjadi string untuk mempermudah manipulasi
    string N_str = to_string(N);
    set<int> unique_digits;
    vector<int> unique_list;

    // Ambil K digit unik pertama
    for (char c : N_str) {
        unique_digits.insert(c - '0');
        if (unique_digits.size() == K) {
            break;
        }
    }

    // Pindahkan set ke dalam vector dan urutkan
    unique_list.assign(unique_digits.begin(), unique_digits.end());

    // Tentukan digit terkecil dan terbesar dari K digit unik yang ditemukan
    int min_digit = *min_element(unique_list.begin(), unique_list.end());
    int last_unique_digit = unique_list.back();

    // Cari posisi terakhir dari digit unik yang sudah ditemukan
    int last_unique_position = N_str.find_last_of(to_string(last_unique_digit));

    // Periksa apakah digit terakhir lebih kecil daripada digit setelahnya
    bool conditionMet = false;
    if (last_unique_position < N_str.size() - 1 && N_str[last_unique_position] < N_str[last_unique_position + 1]) {
        conditionMet = true;
        // Tambah 1 pada digit terakhir
        last_unique_digit += 1;
        unique_list.back() = last_unique_digit;
    }

    // Tentukan digit yang akan digunakan untuk mengganti angka setelah posisi terakhir digit unik
    int replace_digit;
    if (conditionMet) {
        replace_digit = min_digit;
    } else {
        // Cari digit yang lebih besar daripada digit setelah unik terakhir
        replace_digit = -1;
        for (int digit : unique_list) {
            if (digit > (N_str[last_unique_position] - '0')) {
                replace_digit = digit;
                break;
            }
        }
    }

    // Ubah digit setelah posisi terakhir digit unik menjadi digit yang telah ditentukan
    string result = N_str;
    for (int i = last_unique_position + 1; i < result.size(); ++i) {
        result[i] = '0' + replace_digit;  // ubah menjadi digit yang dipilih
    }
    
    // Ubah sisa digit menjadi yang terkecil
    for (int i = last_unique_position + 1; i < result.size(); ++i) {
        result[i] = '0' + min_digit; // set sisa menjadi digit terkecil
    }

    // Konversi hasil kembali ke long long untuk perhitungan
    return stoll(result) - N;
}

int main() {
    long long N;
    int K;
    cin >> N >> K;
    
    // Proses angka dan tampilkan hasil
    long long result = processNumber(N, K);
    
    // Tampilkan hasil perbedaan antara hasil baru dan N
    cout << result << endl;
    
    return 0;
}
