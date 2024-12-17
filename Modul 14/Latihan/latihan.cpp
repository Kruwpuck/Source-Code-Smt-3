#include "latihan.h"
adrNode createNode_103032330054(infotype data){
    adrNode P = new node;
    P->info = data;
    P->nextNode = NULL;
    P->firstEdge = NULL;
    return P;
}
void insertLastNode_103032330054(Graf &G, adrNode &N){
    if(G.firstNode == NULL){
        G.firstNode = N;
    }else{
        adrNode P = G.firstNode;
        while(P->nextNode != NULL){
            P = P->nextNode;
        }
        P->nextNode = N;
    }
}
adrEdge createEdge_103032330054(string id){
    adrEdge P = new edge;
    P->id = id;
    P->nextEdge = NULL;
    return P;
}
void insertLastEdge_103032330054(Graf &G, adrNode N, adrEdge E){
    if(N->firstEdge == NULL){
        N->firstEdge = E;
    }else{
        adrEdge P = N->firstEdge;
        while(P->nextEdge != NULL){
            P = P->nextEdge;
        }
        P->nextEdge = E;
    }
}
adrNode findNode_103032330054(Graf G, string idAkun){
    adrNode P = G.firstNode;
    while(P != NULL){
        if(P->info.id == idAkun){
            return P;
        }
        P = P->nextNode;
    }
    return NULL;
}
void showAkun_103032330054(Graf G){
    adrNode P = G.firstNode;
    while(P != NULL){
        cout << "ID Akun  : " << P->info.id << endl;
        cout << "Nama Akun: " << P->info.nama << endl;
        cout << "Following: " << P->info.following << endl;
        cout << "Followed : " << P->info.followed << endl;
        cout << endl;
        P = P->nextNode;
    }
}
void follow_103032330054(Graf &G, string idA, string idB){
    adrNode P = findNode_103032330054(G, idA);
    adrNode Q = findNode_103032330054(G, idB);
    if(P != NULL && Q != NULL){
        adrEdge E = createEdge_103032330054(Q->info.id);
        insertLastEdge_103032330054(G, P, E);
        P->info.following++;
        Q->info.followed++;
    }else{
        cout << "Akun tidak ditemukan" << endl;
    }
}
void showFollowing_103032330054(Graf G, string id){
    adrNode P = findNode_103032330054(G, id);
    if(P != NULL){
        adrEdge Q = P->firstEdge;
        if (Q == NULL){
            cout << "Tidak ada following" << endl;
        }else{
            while(Q != NULL){
                cout << "ID Akun  : " << Q->id << endl;
                Q = Q->nextEdge;
            }
        }
    }else{
        cout << "Akun tidak ditemukan" << endl;
    }
}
