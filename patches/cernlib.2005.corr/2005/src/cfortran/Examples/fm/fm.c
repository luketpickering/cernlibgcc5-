/* fm.c == fm.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fm_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* FORTRAN_REAL, instead of float, is only required for CRAY T3E.             */

FORTRAN_REAL Cm(FORTRAN_REAL a) {return a;}
FCALLSCFUN1(FLOAT,Cm,CM,cm, FLOAT)


PROTOCCALLSFFUN1(FLOAT,FM,fm,FLOAT) 
#define FM(A)               CCALLSFFUN1(FM,fm, FLOAT, A)

main() 
{printf("FM(111.) returns %f.\n",FM(111.)); return EXIT_SUCCESS;}
