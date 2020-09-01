/* fn.c == fn.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fn_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* DOUBLE_PRECISION, instead of double, is only required for CRAY (not T3E).  */

DOUBLE_PRECISION Cn(DOUBLE_PRECISION a, DOUBLE_PRECISION b) {return a+b;}
FCALLSCFUN2(DOUBLE,Cn,CN,cn, DOUBLE, DOUBLE)


PROTOCCALLSFFUN2(DOUBLE,FN,fn,DOUBLE,DOUBLE)
#define FN(A,B)             CCALLSFFUN2(FN,fn, DOUBLE, DOUBLE, A, B)

main() 
{printf("FN(1./3, 2./3) returns %f.\n",(double)FN(1./3, 2./3));
 return EXIT_SUCCESS;
}
