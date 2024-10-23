#include "DLL.h"


int main()
{
    List L;
    infotype H;
    address Elm;
    createList_103032330054(L);
    printList_103032330054(L);
    int i=0;
    /*
    // Soal 1
    for (int i=0;i<3;i++){
        cout << endl << endl << "Tittle      : ";
        cin >> H.title;
        cout << endl << "URL         : ";
        cin >> H.url;
        cout << endl << "Time Stamp  : " ;
        cin >> H.timestamp;
        cout << endl << "Visit Count : " ;
        cin >> H.visitcount;
        Elm = createElemen_103032330054(H);
        insertLast_103032330054(L,Elm);
        printList_103032330054(L);
    }

    deleteFirst_103032330054(L,Elm);
    printList_103032330054(L);

    deleteLast_103032330054(L,Elm);
    printList_103032330054(L;)

    deleteFirst_103032330054(L,Elm);
    printList_103032330054(L);
    */
    // Soal 2
    for (i=0;i<3;i++){
        cout << endl << endl << "Tittle      : ";
        cin >> H.title;
        cout << endl << "URL         : ";
        cin >> H.url;
        cout << endl << "Time Stamp  : " ;
        cin >> H.timestamp;
        cout << endl << "Visit Count : " ;
        cin >> H.visitcount;
        Elm = createElemen_103032330054(H);
        insertAscending_103032330054(L,H);
        printList_103032330054(L);
    }
    cout << findElemen_103032330054(L,"OpenAI") << endl;
    cout << moreThanOnce_103032330054(L);
}
