#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
using namespace std;
typedef int infotype;
typedef struct elm *adrNode;
struct elm{
    adrNode right;
    adrNode left;
    infotype info;
};
adrNode newNode_103032330054(infotype x);
void insertNode_103032330054(adrNode &root, adrNode p);
void DeleteNode_103032330054(adrNode &root, adrNode &p);
void printInOrder_103032330054(adrNode root);
adrNode findMin_103032330054(adrNode root);

#endif // TREE_H_INCLUDED
