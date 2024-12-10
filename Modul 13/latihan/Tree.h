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
adrNode findNode_103032330054(adrNode root, infotype x);
void insertNode_103032330054(adrNode &root, adrNode p);
void printPreOrder_103032330054(adrNode root);
void printDescendant_103032330054(adrNode root, infotype x);
int sumNode_103032330054(adrNode root);
int countLeaves_103032330054(adrNode root);
int heightTree_103032330054(adrNode root);
void printInOrder_103032330054(adrNode root); 
void printPostOrder_103032330054(adrNode root);  
void printLeftMostNode_103032330054(adrNode root); 
void printRightMostNode_103032330054(adrNode root); 
int countNode_103032330054(adrNode root); 
void printAncestor_103032330054_103032330054(adrNode root, infotype x); 
int countInternalNode(adrNode root); 
int depthNode_103032330054(adrNode root, infotype n); 
int levelNode_103032330054(adrNode root, infotype n); 

#endif // TREE_H_INCLUDED
