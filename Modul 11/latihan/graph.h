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
adrVertex searchVertex_103032330054(graph G, char IDsimpul);
void createEdge_103032330054(char IDsimpulTujuan, int bobot, adrEdge &e);
void addEgde_103032330054(graph &G, char IDsimpulAsal, char IDsimpulTujuan, int bobot);
int outDegree_103032330054(graph G, char IDsimpul);
int inDegree_103032330054(graph G, char IDsimpul);
int degree_103032330054(graph G, char IDsimpul);

