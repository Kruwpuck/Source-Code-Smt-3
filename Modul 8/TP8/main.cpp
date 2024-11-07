#include "QUEUE.h"
int main()
{
    Queue Q;
    createQueue_103032330054(Q);

    ElemQ* P1 = createElemQueue_103032330054("John Doe", 65, "lansia", 1);
    ElemQ* P2 = createElemQueue_103032330054("Alice", 30, "tenaga kesehatan", 2);
    ElemQ* P3 = createElemQueue_103032330054("Bob", 25, "pekerja", 3);
    ElemQ* P4 = createElemQueue_103032330054("Charlie", 70, "pensiunan", 4);
    ElemQ* P5 = createElemQueue_103032330054("David", 28, "pekerja", 5);

    enqueue_103032330054(Q, P1);
    enqueue_103032330054(Q, P2);
    enqueue_103032330054(Q, P3);
    enqueue_103032330054(Q, P4);
    enqueue_103032330054(Q, P5);

    cout << "Isi antrean awal:" << endl;
    printInfo_103032330054(Q);

    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    serveQueue_103032330054(Q);

    cout << "\nIsi antrean setelah pelayanan:" << endl;
    printInfo_103032330054(Q);

    ElemQ* P6 = createElemQueue_103032330054("Edward", 22, "pekerja", 6);
    enqueue_103032330054(Q, P6);

    cout << "\nMengatur ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue_103032330054(Q);
    printInfo_103032330054(Q);

    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime103032330054(Q, 130);
    printInfo_103032330054(Q);

    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle_103032330054(Q, 5);
    printInfo_103032330054(Q);

    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority_103032330054(Q);
    printInfo_103032330054(Q);

    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove_103032330054(Q, 3);

    if (removedElem) {
        cout << "Warga yang dihapus: " << info(removedElem).nama << endl;
    }
    printInfo_103032330054(Q);
    cout << "\nUkuran antrean saat ini: " << size_103032330054(Q) << endl;
    return 0;
}
