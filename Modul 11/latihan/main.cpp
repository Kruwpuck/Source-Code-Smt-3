#include "graph.h"

int main()
{
    graph G;
    adrVertex P;
    initGraph_103032330054(G);
    buildGraph_103032330054(G);
    P = G.firstVertex;
    addEgde_103032330054(G, 'A', 'D', 60);
    addEgde_103032330054(G, 'A', 'C', 12);
    addEgde_103032330054(G, 'B', 'A', 10);
    addEgde_103032330054(G, 'C', 'B', 20);
    addEgde_103032330054(G, 'C', 'D', 32);
    addEgde_103032330054(G, 'E', 'A', 7);
    while (P != NULL){
        cout << "Vetex     : " << P->idVertex << endl;
        cout << "Out Degree: " << outDegree_103032330054(G, P->idVertex) << endl;
        cout << "In Degree : " << inDegree_103032330054(G, P->idVertex) << endl;
        cout << "Degree    : " << degree_103032330054(G, P->idVertex) << endl;
        cout << "========================================" << endl;
        P = P->nextVertex;
    }
}
