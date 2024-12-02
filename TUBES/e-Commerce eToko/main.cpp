#include "header.h"

int main()
{
    List_Relasi Lr;
    List_eCommerce Lp;
    List_Toko Lc;
    Lr.first = NULL;
    Lp.first = NULL;
    Lc.first = NULL;
    Lc.last = NULL;
    menu(Lr, Lp, Lc);
    return 0;
}
