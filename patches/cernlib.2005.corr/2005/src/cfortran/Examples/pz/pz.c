/* pz.c == pz.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires pz_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

#define pz_ELEMS_3   ZTRINGV_ARGS(4)
#define pz_ELEMLEN_3 ZTRINGV_NUM(8)
                 PROTOCCALLSFSUB4(PZ,pz, PSTRINGV,INT, PZTRINGV,INT)
#define PZ(S,IS,Z,IZ) CCALLSFSUB4(PZ,pz, PSTRINGV,INT, PZTRINGV,INT, S,IS,Z,IZ)

int main() {
char *p;
static char s[][7]={"000 ", " "}     , as[]  ="hihi";
static char z[][9]={" ", "bb","ccc "}, az[99]="hoho";

/*
 - z[][9] must match ZTRINGV_NUM(8), while az[99] can match or be bigger,
   since 8 character will be copied back.
 - Comments in SZ1 example above for Z|STRINGV, also apply for PZ|STRINGV.
 */

p = (char *)z;
PZ(s,2,p,3);
PZ(s[1],1,z[2],1);

PZ(as,1,az,1);
PZ(as,1,az,1);

return EXIT_SUCCESS;
}
