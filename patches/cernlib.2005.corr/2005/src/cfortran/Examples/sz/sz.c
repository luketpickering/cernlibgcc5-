/* sz.c == sz.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires sz_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


#define sz_ELEMS_1   ZTRINGV_ARGS(3)
#define sz_ELEMLEN_1 ZTRINGV_NUM(6)
#define sz_ELEMS_2   ZTRINGV_NUM(4)
#define sz_ELEMLEN_2 ZTRINGV_NUM(8)
             PROTOCCALLSFSUB3(SZ,sz, PZTRINGV, ZTRINGV, INT)
#define SZ(A,B,C) CCALLSFSUB3(SZ,sz, PZTRINGV, ZTRINGV, INT, A, B, C)

int main() {
static char v[][7] = {"000 ", "1", "22", " "};
static char w[][9]  = {" ", "bb","ccc ","dddd"};
SZ(v, w, 4);
printf("main:v=%s,%s,%s,%s. PZTRINGV => Has had trailing blanks stripped.\n",
       v[0],v[1],v[2],v[3]);
printf("main:w=%s,%s,%s,%s. ZTRINGV => malloc'd copy for FORTRAN=> C intact.\n"
       ,w[0],w[1],w[2],w[3]);
return EXIT_SUCCESS;
}
