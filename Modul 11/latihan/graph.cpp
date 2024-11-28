#include "graph.h"
void createVertex_103032330054(char newVertexID, adrVertex &v){
    v->firstEdge = NULL;
    v->nextVertex = NULL;
    v->idVertex = newVertexID;
}
void initGraph_103032330054(graph &G){
    G.firstVertex = NULL;
}
void addVertex_103032330054(graph &G, char newVertexID){
    adrVertex P = new vertex;
    createVertex_103032330054(newVertexID, P);
    if (G.firstVertex == NULL){
        G.firstVertex = P;
    }else{
        P->nextVertex = G.firstVertex;
        G.firstVertex = P;
    }
}
void buildGraph_103032330054(graph &G){
    char input;
    cin >> input;
    adrVertex P;
    bool found = false;
    while (input >= 'A' && input <= 'Z'){
        P = G.firstVertex;
        while (P != NULL && !found ){
            if (P->idVertex == input){
                found = true;
            }else{
                P = P->nextVertex;
            }
        }
        if (!found){
            addVertex_103032330054(G, input);
            cin >> input;
        }else{
            cout << "Vertex sudah ada" << endl;
            cin >> input;
        }
    }
}
adrVertex searchVertex_103032330054(graph G, char IDsimpul){
    adrVertex P = G.firstVertex;
    while (P != NULL){
        if (P->idVertex == IDsimpul){
            return P;
        }
        P = P->nextVertex;
    }
    return NULL;
}
void createEdge_103032330054(char IDsimpulTujuan, int bobot, adrEdge &e){
    e = new edge;
    e->destVertexId = IDsimpulTujuan;
    e->weight = bobot;
    e->nextEdge = NULL;
}
void addEgde_103032330054(graph &G, char IDsimpulAsal, char IDsimpulTujuan, int bobot){
    adrVertex P = searchVertex_103032330054(G, IDsimpulAsal);
    adrEdge e;
    createEdge_103032330054(IDsimpulTujuan, bobot, e);
    if (P->firstEdge == NULL){
        P->firstEdge = e;
    }else{
        e->nextEdge = P->firstEdge;
        P->firstEdge = e;
    }

}
int outDegree_103032330054(graph G, char IDsimpul){
    adrVertex P = searchVertex_103032330054(G, IDsimpul);
    adrEdge Q;
    int degree = 0;
    if (P != NULL){
        Q = P->firstEdge;
        while (Q != NULL){
            degree++;
            Q = Q->nextEdge;
        }
        return degree;
    }
    return -1;
}
int inDegree_103032330054(graph G, char IDsimpul){
    adrVertex P = G.firstVertex;
    adrEdge Q;
    int degree = 0;
    if (P != NULL){
        while (P != NULL){
            Q = P->firstEdge;
            while (Q != NULL){
                if (Q->destVertexId == IDsimpul){
                    degree++;
                }
                Q = Q->nextEdge;
            }
            P = P->nextVertex;
        }
        return degree;
    }
    return -1;
}
int degree_103032330054(graph G, char IDsimpul){
    return inDegree_103032330054(G,IDsimpul) + outDegree_103032330054(G,IDsimpul);
}
