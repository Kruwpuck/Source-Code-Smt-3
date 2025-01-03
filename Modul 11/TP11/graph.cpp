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
