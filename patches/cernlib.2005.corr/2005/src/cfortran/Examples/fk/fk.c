/* fk.c == fk.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fk_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* FORTRAN_REAL, instead of float, is only required for CRAY T3E.             */

FORTRAN_REAL Ck() {return 111.;}
FCALLSCFUN0(FLOAT,Ck,CK,ck)


PROTOCCALLSFFUN0(FLOAT,FK,fk)
#define FK()               CCALLSFFUN0(FK,fk)

main() 
{printf("FK() returns %f.\n",FK()); return EXIT_SUCCESS;}
