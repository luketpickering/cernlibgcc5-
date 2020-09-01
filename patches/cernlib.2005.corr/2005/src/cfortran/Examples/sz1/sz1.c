/* sz1.c == sz1.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires sz1_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

#define sz1_ELEMS_3   ZTRINGV_ARGS(4)
#define sz1_ELEMLEN_3 ZTRINGV_NUM(8)
                  PROTOCCALLSFSUB4(SZ1,sz1, STRINGV,INT,ZTRINGV,INT)
#define SZ1(S,IS,Z,IZ) CCALLSFSUB4(SZ1,sz1, STRINGV,INT,ZTRINGV,INT, S,IS,Z,IZ)

int main() {
char *p;
static char s[][7]={"000 ", " "}     , os[][3]={"s"}, as[ ]="one element";
static char z[][9]={" ", "bb","ccc "}, oz[][9]={"z"}, az[6]="1234";

/*
  - z[][9] must match ZTRINGV_NUM(8), while az[6] does not have to
    since a single element argument may have the wrong length.
  - For arrays of strings, can pass a pointer for ZTRINGV, but not for STRINGV.
    i.e. Can't determine sizes for STRINGV, that's why we have ZTRINGV.
  - NEITHER STRINGV nor ZTRINGV can accept an array of pointers, e.g.
    NO: { char *p[3]; p[0]=z[0]; p[1]=z[1]; p[2]=z[2]; SZ1(s, 2, p, 3); }
 */

p = (char *)z;
SZ1(s   , 2, p     , 3);
SZ1(s[1], 1, z[1]  , 1);
SZ1(os  , 1, oz    , 1);
SZ1(as  , 1, az    , 1);
SZ1("hi", 1, "hoho", 1);

return EXIT_SUCCESS;
}
