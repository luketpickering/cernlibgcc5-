/* fh.c == fh.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fh_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

char *Cch() {return "hello";}
FCALLSCFUN0(STRING,Cch,CCH,cch)


PROTOCCALLSFFUN0(STRING,FH,fh)
#define FH()               CCALLSFFUN0(FH,fh)

main() 
{printf("FH() returns %s.\n",FH()); return EXIT_SUCCESS;}
