#include "header.h"
int selectMenu_103032330054(){
    cout << endl << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan data min" << endl;
    cout << "4. Menambahkan data tengah" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu: ";

    int input = 0;
    cin >> input;

    return input;
}
void createList_Mhs(List_mhs &L){
    L.first = NULL;
    L.last = NULL;
}
void createList_Dosen(List_dosen &L){
    L.first = NULL;
}
void createList_Relasi(List_relasi &L){
    L.first = NULL;
}
adr_mahasiswa createElm_Mhs(infotype_mahasiswa data){
    adr_mahasiswa P = new elm_mahasiswa;
    P->info = data;
    P->next_mhs = NULL;
    P->prev_mhs = NULL;
    return P;
}
adr_dosen createElm_Dosen(infotype_dosen data){
    adr_dosen P = new elm_dosen;
    P->info = data;
    P->next_dosen = NULL;
    return P;
}
adr_relasi createElm_Relasi(infotype_relasi data){
    adr_dosen P = new elm_dosen;
    P->info = data;
    P->next_dosen = NULL;
    return P;
}
void insertDosen(List_dosen &L, adr_dosen P){

}
void insertMhs(List_mhs &L, adr_mahasiswa P){

}
void insertRelasi(List_relasi &L, adr_relasi P){

}
void deleteDosen(List_dosen &L, adr_dosen &P){

}
void deleteMhs(List_mhs &L, adr_mahasiswa &P){

}
void deleteRelasi(List_relasi &L, adr_relasi P){

}
void checkRelasi(List_relasi L, adr_mahasiswa P, adr_dosen Q){

}
void showDosen(List_dosen L){

}
void showMhs(List_mhs L){

}
void showMhs_dariDosen(List_relasi L, adr_dosen P){

}
void showDosen_dariMhs(List_relasi L, adr_mahasiswa P){

}
void showAll_relasiDosen(List_dosen Ld, List_relasi Lr){

}
void showAll_relasiMhs(List_dosen Lm, List_relasi Lr){

}
void countMhs(List_relasi L, adr_dosen P)(

)
void countDosen(List_relasi L, adr_mahasiswa P){

}
void countMhs_Less(List_relasi Lr, List_dosen Ld){

}
void countDosen_Less(List_relasi Lr, List_mhs Lm){

}
void editDosen(List_relasi L, adr_dosen P, adr_mahasiswa Q){

}
void editMhs(List_relasi L, adr_dosen P, adr_mahasiswa Q){

}
