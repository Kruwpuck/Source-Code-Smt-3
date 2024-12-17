#include "latihan.h"

int main()
{
    Graf G;
    G.firstNode = NULL;
    infotype data;
    adrNode P, Q;
    adrEdge E;
    data.id = "lovelySun";
    data.nama = "Chika";
    data.following = 0;
    data.followed = 0;
    P = createNode_103032330054(data);
    insertLastNode_103032330054(G, P);
    data.id = "jake123";
    data.nama = "jaka";
    data.following = 0;
    data.followed = 0;
    P = createNode_103032330054(data);
    insertLastNode_103032330054(G, P);
    data.id = "gummyS";
    data.nama = "Ghea";
    data.following = 0;
    data.followed = 0;
    P = createNode_103032330054(data);
    insertLastNode_103032330054(G, P);
    follow_103032330054(G, "jake123", "lovelySun");
    follow_103032330054(G, "jake123", "gummyS");
    follow_103032330054(G, "gummyS", "lovelySun");
    showAkun_103032330054(G);
    showFollowing_103032330054(G, "jake123");
    showFollowing_103032330054(G, "lovelySun");
    showFollowing_103032330054(G, "gummyS");

    return 0;
}
