#ifndef LATIHAN_H_INCLUDED
#define LATIHAN_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct node *adrNode;
typedef struct edge *adrEdge;
struct infotype{
    string id;
    string nama;
    int following;
    int followed;
};
struct node{
    adrNode nextNode;
    adrEdge firstEdge;
    infotype info;
};
struct edge{
    string id;
    adrEdge nextEdge;
};
struct Graf{
    adrNode firstNode;
};
adrNode createNode_103032330054(infotype data);
void insertLastNode_103032330054(Graf &G, adrNode &N);
adrEdge createEdge_103032330054(string id);
void insertLastEdge_103032330054(Graf &G, adrNode N, adrEdge E);
adrNode findNode_103032330054(Graf G, string idAkun);
void showAkun_103032330054(Graf G);
void follow_103032330054(Graf &G, string idA, string idB);
void showFollowing_103032330054(Graf G, string id);

#endif // LATIHAN_H_INCLUDED
