#include <iostream>
#define max 10

using namespace std;

const int nMax = 51;
struct mahasiswa {
    string NIM, nama;
    int nilai;
};

mahasiswa arrayMahasiswa[nMax];
int nilaiPertama(mahasiswa arrayMahasiswa[] , int N, string NIM){
    for (int i=0; i < N ;i++){
        if (arrayMahasiswa[i].NIM == NIM){
            return i;
        }
    }
    return -1;
}

int main(){
    int N,i;
    string NIM;
    cin >> N;
    for (i=0;i<N;i++){
        cin>>arrayMahasiswa[i].NIM;
        cin>>arrayMahasiswa[i].nama;
        cin>>arrayMahasiswa[i].nilai;
    }
    cin >> NIM;
    if (nilaiPertama(arrayMahasiswa,N,NIM)==-1){
        cout << "Tidak ditemukan";
    }else{
        cout << arrayMahasiswa[nilaiPertama(arrayMahasiswa,N,NIM)].nama << endl;
        cout << arrayMahasiswa[nilaiPertama(arrayMahasiswa,N,NIM)].NIM << endl;
        cout << arrayMahasiswa[nilaiPertama(arrayMahasiswa,N,NIM)].nilai << endl;
    }
}
