/* fl.c == fl.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fl_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* DOUBLE_PRECISION, instead of double, is only required for CRAY (not T3E).  */

DOUBLE_PRECISION Cl() {return 111.;}
FCALLSCFUN0(DOUBLE,Cl,CL,cl)


PROTOCCALLSFFUN0(DOUBLE,FL,fl)
#define FL()               CCALLSFFUN0(FL,fl)

main() 
{printf("FL() returns %f.\n",(double)FL()); return EXIT_SUCCESS;}
