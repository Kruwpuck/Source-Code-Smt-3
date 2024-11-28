#include "header.h"

using namespace std;

int main()
{
    List_Relasi Lr;
    List_Pertandingan Lp;
    List_Atlet La;
    Lr.first = NULL;
    Lr.last = NULL;
    Lp.first = NULL;
    La.first = NULL;
    La.last = NULL;
    menu(Lr, Lp, La);
    return 0;
}
