#include <iostream>

using namespace std;

struct Pekerjaan {
    string npwp, nama, jabatan, instansi;
    int tahun;
    float gaji;
};

typedef Pekerjaan infotype;
typedef struct elmList *adr;

struct elmList {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

// Primitive functions and procedures declaration
void Create_List(List &L);
adr New_Elemen( );
void Insert_First(List &L, adr p);
void Insert_Last(List &L, adr p);
void Insert_After(List &L, adr prec, adr p);
void Delete_First(List &L, adr &p);
void Delete_Last(List &L, adr &p);
void Delete_After(List &L, adr prec, adr &p);
void Show(List L);

void Create_List(List &L){
    L.first = NULL;
}

// Function New_Elemen2
adr New_Elemen(infotype data){
    adr p = new elmList;
    p->info = data;
    p->next = NULL;
    return p;
}

// Procedure Insert_First
void Insert_First(List &L, adr p){

    if (L.first == NULL){
            //jika l.firts masih kosong maka langsung akan menunjuk ke si p
        L.first = p;
    } else {
        //jika l.firts punya nilai dan pengen agar si p jdi urutan pertama
    p->next = L.first;
    L.first = p;
    }
}

// Procedure Insert_Last
void Insert_Last(List &L, adr p){
    adr q;

    if (L.first == NULL){ //semua insert pake ini
        L.first = p;
    }else{
        q = L.first;
        while (q->next != NULL){
            q = q->next;
            //q nya akan berubah trus menjadi next dari q
            //jika q next sudah mencapai nill maka akan berhenti loop
            //q nya akan berada di list terakhir
        }
        q->next = p;
        //q yang berada di list terakhir, q next nya di assign p
    }
}

// Procedure Insert_After
void Insert_After(List &L, adr prec, adr p){
    if (prec != NULL){
        //menghiindari agar prec nya tidak sama dengan null sehinga tidak bisa ditambahkan antara
        p->next = prec->next;
        prec->next = p;
    }
}

// Procedure Delete_First
void Delete_First(List &L, adr &p){
    if (L.first == NULL){
        p = NULL;
    }else{
        p = L.first;
        // p nya menunjuk ke l.firts
        L.first = p->next;
        // l.firts menunjuk ke nextnya dari p
        p->next = NULL;
        //next dari p diisi nill
    }
    //return p?
}

// Procedure Delete_Last
void Delete_Last(List &L, adr &p) {
    adr q;
    //pointer basntuan untuk mencari elemen terakhir

    if (L.first == NULL) {
        p = NULL;
    } else if (L.first->next ==NULL) {
        p = L.first;
        L.first = NULL;
    } else {
        adr q = L.first;
        while (q->next->next != NULL) {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
    }
}

// Procedure Delete_After
void Delete_After(List &L, adr prec, adr &p) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}

// Procedure Show
void Show(List L) {
    if (L.first == NULL) {
        cout << "List kosong" << endl;
    } else {
        adr p = L.first;
        while (p != NULL) {
            cout << "Nama: " << p->info.nama << ", npwp: " << p->info.npwp << ", Tahun mulai kerja: " << p->info.tahun <<", Jabatan: " << p->info.jabatan
                 << ", Instansi: " << p->info.instansi << ", Gaji: " << p->info.gaji << "juta" << endl;
            p = p->next;
        }
    }
}

int main() {
    // Deklarasi variable List
    List L;
    Create_List(L);
    adr p;

    // Meminta user data pertama yang akan dimasukkan ke list
    infotype data;
    cout << "Masukkan data pertama (nama, npwp, tahun bekerja, jabatan, instansi, gaji):" << endl;
    cin >> data.nama >> data.npwp >> data.tahun >> data.jabatan >> data.instansi >> data.gaji;

    // Melakukan create new elemen berdasarkan data yang diinputkan user
    p = New_Elemen(data);

    // Memanggil salah satu jenis insert (Insert First)
    Insert_First(L, p);

    // Meminta user data kedua yang akan dimasukkan ke list
    cout << "Masukkan data kedua (nama, npwp, tahun bekerja, jabatan, instansi, gaji):" << endl;
     cin >> data.nama >> data.npwp >> data.tahun >> data.jabatan >> data.instansi >> data.gaji;

    // Melakukan create new elemen berdasarkan data yang diinputkan user
    p = New_Elemen(data);

    // Memanggil salah satu jenis insert (Insert Last)
    Insert_Last(L, p);

    // Meminta user data ketiga yang akan dimasukkan ke list
   cout << "Masukkan data ketiga (nama, npwp, tahun bekerja, jabatan, instansi, gaji):" << endl;
     cin >> data.nama >> data.npwp >> data.tahun >> data.jabatan >> data.instansi >> data.gaji;

    // Melakukan create new elemen berdasarkan data yang diinputkan user
    p = New_Elemen(data);

    // Memanggil salah satu jenis insert (Insert First)
 Insert_First(L, p);

    // Meminta user data keempat yang akan dimasukkan ke list
    cout << "Masukkan data keempat (nama, npwp, tahun bekerja, jabatan, instansi, gaji):" << endl;
     cin >> data.nama >> data.npwp >> data.tahun >> data.jabatan >> data.instansi >> data.gaji;

    // Melakukan create new elemen berdasarkan data yang diinputkan user
    p = New_Elemen(data);

    // Memanggil salah satu jenis insert (Insert Last)
    Insert_Last(L, p);

    // Memanggil show untuk menampilkan data
    Show(L);

    // Melakukan penghapusan data dengan memanfaatkan salah satu jenis delete (Delete First)
    Delete_First(L, p);

    // Melakukan penghapusan data dengan memanfaatkan salah satu jenis delete (Delete Last)
    Delete_Last(L, p);

    // Menampilkan data setelah penghapusan
    Show(L);

    return 0;
}