/* fz.c == fz.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fz_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


#define fz_ELEMS_1   ZTRINGV_ARGF(3)
#define fz_ELEMLEN_1 ZTRINGV_NUM(6)
#define fz_ELEMS_2   ZTRINGV_NUM(4)
#define fz_ELEMLEN_2 ZTRINGV_NUM(8)
PROTOCCALLSFFUN3(STRING,FZ,fz, PZTRINGV, ZTRINGV, INT)
#define FZ(A,B,C) CCALLSFFUN3(FZ,fz, PZTRINGV, ZTRINGV, INT, A, B, C)

main() {
static char v[][7] = {"000 ", "1", "22", " "};
static char w[][9]  = {" ", "bb","ccc ","dddd"};
printf("FZ(v, w, a); returns:%s.\n",FZ(v, w, 4));
printf("main:v=%s,%s,%s,%s. PZTRINGV => Has had trailing blanks stripped.\n",
       v[0],v[1],v[2],v[3]);
printf("main:w=%s,%s,%s,%s. ZTRINGV => malloc'd copy for FORTRAN=> C intact.\n"
       ,w[0],w[1],w[2],w[3]);
return EXIT_SUCCESS;
}
