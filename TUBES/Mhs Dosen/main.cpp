#include "header.h"
int main()
{
    List_dosen Ld;
    List_mhs Lm;
    List_relasi Lr;
    Ld.first = NULL;
    Lr.first = NULL;
    Lm.first = NULL;
    Lm.last = NULL;
    menu(Lr, Ld, Lm);
    return 0;
}
