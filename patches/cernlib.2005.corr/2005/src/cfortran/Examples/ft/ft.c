/* ft.c == ft.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires ft_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"

/* FORTRAN_REAL, instead of float, is only required for CRAY T3E.             */

PROTOCCALLSFFUN3(STRING,FT,ft, PSTRINGV, STRINGV, FLOAT)
#define FT(A,B,C) CCALLSFFUN3(FT,ft, PSTRINGV, STRINGV, FLOAT, A, B, C)

main() {
static char v[][5] = {"000 ", "1", "22", " "};
static char w[][9]  = {" ", "bb","ccc ","dddd"};
FORTRAN_REAL a = 10.0;
printf("FT(v, w, a); returns:%s.\n",FT(v, w, a));
printf("main:v=%s,%s,%s,%s. PSTRINGV => Has had trailing blanks stripped.\n",
       v[0],v[1],v[2],v[3]);
printf("main:w=%s,%s,%s,%s. STRINGV => malloc'd copy for FORTRAN=> C intact.\n"
       ,w[0],w[1],w[2],w[3]);
return EXIT_SUCCESS;
}
