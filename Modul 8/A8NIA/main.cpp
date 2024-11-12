#include "QUEUE.h"
int main()
{
    Queue Q;
    createQueue_103032300018(Q);
    ElemQ* P1 = createElemQueue_103032300018("John Doe", 65, "lansia", 1);
    ElemQ* P2 = createElemQueue_103032300018("Alice", 30, "tenaga kesehatan", 2);
    ElemQ* P3 = createElemQueue_103032300018("Bob", 25, "pekerja", 3);
    ElemQ* P4 = createElemQueue_103032300018("Charlie", 70, "pensiunan", 4);
    ElemQ* P5 = createElemQueue_103032300018("David", 28, "pekerja", 5);
    enqueue_103032300018(Q, P1);
    enqueue_103032300018(Q, P2);
    enqueue_103032300018(Q, P3);
    enqueue_103032300018(Q, P4);
    enqueue_103032300018(Q, P5);
    cout << "Isi antrean awal:" << endl;
    printInfo_103032300018(Q);
    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    serveQueue_103032300018(Q);
    cout << "\nIsi antrean setelah pelayanan:" << endl;
    printInfo_103032300018(Q);
    ElemQ* P6 = createElemQueue_103032300018("Edward", 22, "pekerja", 6);
    enqueue_103032300018(Q, P6);
    cout << "\nMengatur ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue_103032300018(Q);
    printInfo_103032300018(Q);
    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime_103032300018(Q, 130);
    printInfo_103032300018(Q);
    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle_103032300018(Q, 5);
    printInfo_103032300018(Q);
    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority_103032300018(Q);
    printInfo_103032300018(Q);
    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove_103032300018(Q, 3);
    if (removedElem != NULL) {
        cout << "Warga yang dihapus: " << removedElem->info.nama << endl;
    }else{
        cout << "Warga dengan nomor antrean 3 tidak ditemukan"<< endl;
    }
    printInfo_103032300018(Q);
    cout << "\nUkuran antrean saat ini: " << size_103032300018(Q) << endl;
    return 0;
}
