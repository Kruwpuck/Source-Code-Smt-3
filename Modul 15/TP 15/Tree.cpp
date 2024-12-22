#include "Tree.h"
adrNode newNode_103032330054(infotype x){
    adrNode P = new elm;
    P->left = NULL;
    P->right = NULL;
    P->info = x;
    return P;
}
void insertNode_103032330054(adrNode &root, adrNode p){
    if (root == NULL){
        root = p;
    }else{
        if (p->info > root->info){
            insertNode_103032330054(root->right, p);
        }else{
            insertNode_103032330054(root->left, p);
        }
    }
}
adrNode findMin_103032330054(adrNode root){
    if (root->left == NULL){
        return root;
    }else{
        return findMin_103032330054(root->left);
    }
}
void DeleteNode_103032330054(adrNode &root, adrNode &p){
    adrNode temp;
    if (root == NULL){
        cout << "Node not found" << endl;
    }else if (p->info < root->info){
        DeleteNode_103032330054(root->left, p);
    }else if (p->info > root->info){
        DeleteNode_103032330054(root->right, p);
    }else{
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if (root->left == NULL){
            temp = root;
            root = root->right;
            delete temp;
        }else if (root->right == NULL){
            temp = root;
            root = root->left;
            delete temp;
        }else{
            temp = findMin_103032330054(root->right);
            root->info = temp->info;
            DeleteNode_103032330054(root->right, temp);
        }
    }
}
void printInOrder_103032330054(adrNode root){
    if (root != NULL){
        printInOrder_103032330054(root->left);
        cout << root->info << " ";
        printInOrder_103032330054(root->right);
    }
}
adrNode findNode_103032330054(adrNode root, infotype x){
    if (root == NULL){
        return NULL;
    }else if (root->info == x){
        return root;
    }else if (x > root->info){
        return findNode_103032330054(root->right, x);
    }else{
        return findNode_103032330054(root->left, x);
    }
}
