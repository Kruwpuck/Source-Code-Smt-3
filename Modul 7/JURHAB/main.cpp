#include "stack.h"

int main()
{
    stack S1, S2, S3;
    infotype xpop;
    createStack_103032330054(S1);
    printInfo_103032330054(S1);
    push_103032330054(S1, 'E');
    printInfo_103032330054(S1);
    push_103032330054(S1, 'T');
    printInfo_103032330054(S1);
    push_103032330054(S1, 'U');
    printInfo_103032330054(S1);
    pop_103032330054(S1, xpop);
    printInfo_103032330054(S1);
    cout << endl << "Data diurutkan ascending_103032330054:" << endl;
    ascending_103032330054(S1);
    printInfo_103032330054(S1);
    cout << endl << "Data diurutkan descending_103032330054:" << endl;
    descending_103032330054(S1);
    printInfo_103032330054(S1);
    createStack_103032330054(S2);
    string kalimat = "Hai kamu!!!";
    cout <<endl<< "\'Hai kamu!!!\' di dalam stack:" <<endl;
    stringToStack_103032330054(S2,kalimat);
    printInfo_103032330054(S2);
    cout << endl << "Data diurutkan ascending_103032330054:" << endl;
    ascending_103032330054(S2);
    printInfo_103032330054(S2);
    cout << endl << "Data diurutkan descending_103032330054:" << endl;
    descending_103032330054(S2);
    printInfo_103032330054(S2);
    createStack_103032330054(S3);
    cout <<endl<< "Membalik urutan elemen " <<endl;
    string input;
    cout << "Masukkan string: ";
    // Inputkan “IFLAB 2024/2025”
    getline(cin, input); // Menggunakan getline untuk membaca string dengan spasi
    stringToStack_103032330054(S3, input);
    cout << endl << "Data sebelum dibalik:";
    printInfo_103032330054(S3);
    cout << endl;
    reverseStack_103032330054(S3);
    cout << "Data setelah dibalik:";
    printInfo_103032330054(S3);
    cout << endl;
    return 0;

}
