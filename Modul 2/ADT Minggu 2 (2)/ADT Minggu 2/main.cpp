#include "karyawan.h"

int main(){
    List IAI;
    infotype data;
    adr P;
    Create_List(IAI);
    cin >> data.nama >> data.npwp >> data.jabatan >> data.gaji;
    P = New_Elemen(data);
    Insert_First(IAI, P);
    cin >> data.nama >> data.npwp >> data.jabatan >> data.gaji;
    P = New_Elemen(data);
    Insert_Last(IAI, P);
    cin >> data.nama >> data.npwp >> data.jabatan >> data.gaji;
    P = New_Elemen(data);
    Insert_First(IAI, P);
    cin >> data.nama >> data.npwp >> data.jabatan >> data.gaji;
    P = New_Elemen(data);
    Insert_Last(IAI, P);
    cout << endl;
    Show(IAI);
    cout << endl;
    P = Delete_First(IAI);
    Show(IAI);
    cout << endl;
    P = Delete_Last(IAI);
    Show(IAI);
    cout << endl;

    return 0;
}

