/* fi.c == fi.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fi_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

char *Ci(char v[][5]) {return v[3];}
#define ci_STRV_A1 NUM_ELEMS(6)
FCALLSCFUN1(STRING,Ci,CI,ci, STRINGV)


PROTOCCALLSFFUN1(STRING,FI,fi,STRINGV)
#define FI(A1)               CCALLSFFUN1(FI,fi, STRINGV, A1)

main() 
{static char v[][5] = {"0000", "1", "22", "333", "8", "9"}; 
 printf("FI(v) returns %s.\n",FI(v));
 return EXIT_SUCCESS;
}
