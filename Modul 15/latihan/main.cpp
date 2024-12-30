#include "Tree.h"
int main()
{
    int x[9] = {8,6,15,4,7,12,17,9,13};
    adrNode root = NULL;
    for (int i=0; i<9; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    adrNode P = NULL;
    for (int i=0; i<9; i++){
        insertNode_103032330054(root, newNode_103032330054(x[i]));
    }
    printInOrder_103032330054(root);
    cout << endl;
    cout << mostLeftNode_103032330054(root)->info << endl;
    cout << mostRightNode_103032330054(root)->info << endl;
    return 0;
}
