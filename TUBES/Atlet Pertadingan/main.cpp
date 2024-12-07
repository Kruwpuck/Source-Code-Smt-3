#include "header.h"

int main()
{
    List_Relasi Lr;
    List_Pertandingan Lp;
    List_Atlet La;
    Lr.first = NULL;
    Lp.first = NULL;
    La.first = NULL;
    La.last = NULL;
    menu(Lr, Lp, La);
    return 0;
}
