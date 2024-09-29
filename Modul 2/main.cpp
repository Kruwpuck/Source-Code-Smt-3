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
    Insert_Last(IAI, P);
    Show(IAI);
    Delete_First(IAI, P);
    Delete_Last(IAI, P);
    Show(IAI);

    return 0;
}

