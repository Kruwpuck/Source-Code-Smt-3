#include "Tree.h"
int main()
{
    int x[7] = {6,3,8,1,5,7,9};
    adrNode root = NULL;
    /* Tampilkan isi dari array */
    for (int i=0; i<7; i++){
        cout << x[i] << " ";
    }
    /* 1. Tambahkan setiap elemen array x kedalam BST secara berurutan */
    /* sehingga dihasilkan BST seperti Gambar 1, gunakan looping*/
    for (int i=0; i<7; i++){
        insertNode_103032330054(root, newNode_103032330054(x[i]));
    }
    /* 2. Tampilan node dari BST secara In-Order, Pre-Order, dan Post-Order*/
    cout << endl << "In-Order :" << endl;
    printInOrder_103032330054(root);
    cout << endl << "Pre-Order :" << endl;
    printPreOrder_103032330054(root);
    cout << endl << "Post-Order :" << endl;
    printPostOrder_103032330054(root);
    cout << endl;

    /* 3. Menampilkan node paling kiri dan kanan dari BST*/
    cout << endl << "Left Most Node :" << endl;
    printLeftMostNode_103032330054(root);
    cout << endl << "Right Most Node :" << endl;
    printRightMostNode_103032330054(root);

    /* 4. Tampilkan leluhur keturuan dari node 3*/
    cout << endl;
    cout << "Descendent of Node 3: " << endl;
    printDescendant_103032330054(root, 3);
    /* 5. Tampilkan total info semua node pada BST */
    cout << endl;
    cout << "Sum of BST Info :" << endl;
    cout << sumNode_103032330054(root);
    /* 6. Tampilkan banyak node dari BST */
    cout << endl << "Height of Tree :" << endl;
    cout << heightTree_103032330054(root);
    /* 7. Tampilkan banyaknya daun dari BST */
    cout << endl << "Number of Leaves :" << endl;
    cout << countLeaves_103032330054(root);
    /* 8. Tampilkan Tinggi dari Tree*/
    cout << endl << "Height of Tree :" << endl;
    cout << heightTree_103032330054(root);
    cout << endl << "Ancestor of Node 5: " << endl;
    printAncestor_103032330054_103032330054(root, 5);
    cout << endl <<"Internal Node: " << endl;
    cout << countInternalNode(root) << endl;
    cout << endl << "Depth of Node 15: " << endl;
    cout << depthNode_103032330054(root, 15) << endl;
    cout << endl << "Level of Node 15: " << endl;
    cout << levelNode_103032330054(root, 15) << endl;
    cout << isComplete(root);
    return 0;
}
