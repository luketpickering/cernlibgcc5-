/* fand.c == fand.C */         /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fand_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

int Cand(int a, int b) {return a && b;}
FCALLSCFUN2(LOGICAL,Cand,CAND,cand, LOGICAL, LOGICAL)


PROTOCCALLSFFUN2(LOGICAL,FAND,fand,LOGICAL,LOGICAL)
#define FAND(A,B)             CCALLSFFUN2(FAND,fand, LOGICAL, LOGICAL, A, B)

main() 
{printf("FAND(0, 1) returns %d.\n",FAND(0, 1)); return EXIT_SUCCESS;}
