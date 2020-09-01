/* fj.c == fj.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fj_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

char *Cj(int v) {printf("cj:v=%d\n",v);return "hello";}
FCALLSCFUN1(STRING,Cj,CJ,cj, INT)


PROTOCCALLSFFUN1(STRING,FJ,fj,INT)
#define FJ(A1)               CCALLSFFUN1(FJ,fj, INT, A1)

main() 
{ printf("FJ(2) returns %s.\n",FJ(2)); return EXIT_SUCCESS;}
