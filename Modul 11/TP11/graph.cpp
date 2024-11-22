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
    while (input >= 'A' && input <= 'Z'){
        addVertex_103032330054(G, input);
        cin >> input;
    }
}
