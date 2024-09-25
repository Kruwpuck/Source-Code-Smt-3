#include <iostream>
using namespace std;

int main() {
    char karakter;


    cout << "Masukkan sebuah karakter: ";
    cin >> karakter;

    cout << "Kode ASCII dari '" << karakter << "' adalah: " << int(karakter) << endl;

    return 0;
}
