#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;
struct vertex{
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};
struct edge{
    char destVertexId;
    int weight;
    adrEdge nextEdge;
};
struct graph{
    adrVertex firstVertex;
};
void createVertex_103032330054(char newVertexID, adrVertex &v);
void initGraph_103032330054(graph &G);
void addVertex_103032330054(graph &G, char newVertexID);
void buildGraph_103032330054(graph &G);
#endif // GRAPH_H_INCLUDED
