#include "Tree.h"
adrNode newNode_103032330054(infotype x){
    adrNode P = new elm;
    P->left = NULL;
    P->right = NULL;
    P->info = x;
    return P;
}
adrNode findNode_103032330054(adrNode root, infotype x){
    if (root->info == x || root == NULL){
        return root;
    }
    if (x > root->info){
        return findNode_103032330054(root->right, x);
    }else if (x < root->info) {
        return findNode_103032330054(root->left, x);
    }
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
void printPreOrder_103032330054(adrNode root){
    if (root != NULL){
        cout << root->info << " ";
        printPreOrder_103032330054(root->left);
        printPreOrder_103032330054(root->right);
    }
}
void printDescendant_103032330054(adrNode root, infotype x){
    adrNode P = findNode_103032330054(root, x);

    if (P == NULL){
        cout << "Node " << x << "tidak ditemukan" << endl;
    }else{
        if (P->left != NULL){
            cout << P->left->info << " ";
            printDescendant_103032330054(P->left, P->left->info);
        }
        if (P->right != NULL){
            cout << P->right->info << " ";
            printDescendant_103032330054(P->right, P->right->info);
        }
    }
}
int sumNode_103032330054(adrNode root){
    if (root == NULL){
        return 0;
    }else{
        return root->info  + sumNode_103032330054(root->right) + sumNode_103032330054(root->left);
    }
}
int countLeaves_103032330054(adrNode root){
    if (root == NULL){
        return 0;
    }else if (root->left == NULL && root->right == NULL){
        return 1;
    }else{
        return countLeaves_103032330054(root->left) + countLeaves_103032330054(root->right);
    }
}
int heightTree_103032330054(adrNode root){
    if (root == NULL){
        return -1;
    }
    int left, right;
    int height = 1;
    left = heightTree_103032330054(root->left);
    right = heightTree_103032330054(root->right);
    if (left > right){
        return height + left;
    }else{
        return height + right;
    }
}
void printInOrder_103032330054(adrNode root){
    if (root != NULL){
        printInOrder_103032330054(root->left);
        cout << root->info << " ";
        printInOrder_103032330054(root->right);
    }
} 
void printPostOrder_103032330054(adrNode root){
    if (root != NULL){
        printPostOrder_103032330054(root->left);
        printPostOrder_103032330054(root->right);
        cout << root->info << " ";
    }
}  
void printLeftMostNode_103032330054(adrNode root){
    if (root != NULL){
        if (root->left == NULL){
            cout << root->info << " ";
        }else{
            printLeftMostNode_103032330054(root->left);
        }
    }
} 
void printRightMostNode_103032330054(adrNode root){
    if (root != NULL){
        if (root->right == NULL){
            cout << root->info << " ";
        }else{
            printRightMostNode_103032330054(root->right);
        }
    }
} 
int countNode_103032330054(adrNode root){
    if (root == NULL){
        return 0;
    }else{
        return 1 + countNode_103032330054(root->left) + countNode_103032330054(root->right);
    }
} 
void printAncestor_103032330054_103032330054(adrNode root, infotype x){
    if (root->info == x){
        return;
    }
    if (x > root->info){
        cout << root->info << " ";
        printAncestor_103032330054_103032330054(root->right, x);
    }else{
        cout << root->info << " ";
        printAncestor_103032330054_103032330054(root->left, x);
    }
} 
int countInternalNode(adrNode root){
    if (root == NULL){
        return 0;
    }else if (root->left != NULL || root->right != NULL){
        return 1 + countInternalNode(root->left) + countInternalNode(root->right);
    }else{
        return 0;
    }
} 
int depthNode_103032330054(adrNode root, infotype n){
    if (root == NULL){
        return -1;
    }else if (root->info == n){
        return 0;
    }else{
        if (n > root->info){
            return 1 + depthNode_103032330054(root->right, n);
        }else{
            return 1 + depthNode_103032330054(root->left, n);
        }
    }
} 
int levelNode_103032330054(adrNode root, infotype n){
    return depthNode_103032330054(root, n) + 1;
}
bool isComplete(adrNode root){
    if (root->left == NULL && root->right == NULL){
        return true;
    }else if (root->left != NULL && root->right != NULL){
        return true && isComplete(root->right) && isComplete(root->left);
    }else{
        return false;
    }
}