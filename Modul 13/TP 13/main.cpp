#include "Tree.h"
int main()
{
    int x[9] = {5,3,9,10,4,7,1,8,6};
    /* Tampilkan isi dari array */
    adrNode root = NULL;
    for (int i=0; i<9; i++){
        cout << x[i] << " ";
    }
    /* 1. Tambahkan setiap elemen array x kedalam BST secara berurutan */
    /* sehingga dihasilkan BST seperti Gambar 1, gunakan looping*/
    for (int i=0; i<9; i++){
        insertNode_103032330054(root, newNode_103032330054(x[i]));
    }
    /* 2. Tampilkan node dari BST secara Pre-Order */
    cout << endl;
    cout << "Pre Order :" << endl;
    printPreOrder_103032330054(root);
    cout << endl;

    /* 3. Tampilkan keturunan dari node 9*/
    cout << endl << "Descendent of Node 9 :" << endl;
    printDescendant_103032330054(root, 9);

    /* 4. Tampilkan total info semua node pada BST */
    cout << endl;
    cout << "Sum of BST Info :" << endl;
    cout << sumNode_103032330054(root);
    /* 5. Tampilkan banyaknya daun dari BST */
    cout << endl;
    cout << "Number of Leaves :" << endl;
    cout << countLeaves_103032330054(root);
    /* 4. Tampilkan Tinggi dari Tree*/
    cout << endl << "Height of Tree :" << endl;
    cout << heightTree_103032330054(root);
    return 0;
}
