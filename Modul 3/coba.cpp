#include <iostream>

using namespace std;

const int nmax = 51;

void bacaData(int A[nmax], int &n) {
    int num, sisa, susa, i = 0;
    n = 0; // Inisialisasi n di sini

    cin >> num;
    while (num != 0 && i < nmax) {
        sisa = num / 10;
        susa = num % 10;
        if ((sisa + susa) % 2 == 0) { // Tambahkan tanda kurung
            A[i] = num;
            i++;
        }
        cin >> num;
    }
    n = i; // Menyimpan jumlah elemen yang dibaca
}

void cetakData(int A[nmax], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", A[i]); // Tambahkan endl untuk pemisah
    }
}

int main() {
    int data[nmax];
    int n;
    cout << "Masukkan bilangan (0 untuk berhenti): ";
    bacaData(data, n);
    cetakData(data, n);
    return 0;
}