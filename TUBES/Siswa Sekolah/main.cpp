#include "header.h"

int main()
{
    List_Relasi Lr;
    List_Sekolah Lp;
    List_Siswa Lc;
    Lr.first = NULL;
    Lr.last = NULL;
    Lp.first = NULL;
    Lc.first = NULL;
    Lc.last = NULL;
    menu(Lr, Lp, Lc);
    return 0;
}
