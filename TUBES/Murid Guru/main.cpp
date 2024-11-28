#include "header.h"
int main()
{
    List_Guru Lg;
    List_Murid Lm;
    List_Relasi Lr;
    Lg.first = NULL;
    Lg.last = NULL;
    Lm.first = NULL;
    Lr.first = NULL;
    Lr.last = NULL;
    menu(Lr, Lg, Lm);
    return 0;
}
