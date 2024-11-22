#include "graph.h"
int main()
{
    graph G;
    adrVertex P;
    initGraph_103032330054(G);
    buildGraph_103032330054(G);
    P = G.firstVertex;
    while (P != NULL){
        cout << endl << P->idVertex;
        P = P->nextVertex;
    }
}
