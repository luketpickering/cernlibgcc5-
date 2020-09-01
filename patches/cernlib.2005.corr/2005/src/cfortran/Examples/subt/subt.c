/* subt.c */                   /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires subt_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


               PROTOCCALLSFSUB3(SUBT,subt, PSTRINGV, STRINGV, FLOAT)
#define SUBT(A,B,C) CCALLSFSUB3(SUBT,subt, PSTRINGV, STRINGV, FLOAT, A, B, C)

int main() {
static char v[][5] = {"000 ", "1", "22", " "};
static char w[][9]  = {" ", "bb","ccc ","dddd"};
SUBT(v, w, 10.);
printf("main:v=%s,%s,%s,%s. PSTRINGV => Has had trailing blanks stripped.\n",
       v[0],v[1],v[2],v[3]);
printf("main:w=%s,%s,%s,%s. STRINGV => malloc'd copy for FORTRAN=> C intact.\n"
       ,w[0],w[1],w[2],w[3]);
return EXIT_SUCCESS;
}
