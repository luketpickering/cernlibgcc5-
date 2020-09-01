/* forr.c == forr.C */         /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires forr_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

int Cor(int *a, int *b) {int t; t= *a;*a= *b;*b=t; return *a || *b;}
FCALLSCFUN2(LOGICAL,Cor,COR,cor, PLOGICAL, PLOGICAL)


PROTOCCALLSFFUN2(LOGICAL,FORR,forr,PLOGICAL,PLOGICAL)
#define FORR(A,B)             CCALLSFFUN2(FORR,forr, PLOGICAL, PLOGICAL, A, B)

main() 
{int a=2, b=0; printf("Calling FORR(a=%d, b=%d).\n", a,b);
               printf("FORR() returned %d.\n", FORR(a, b));
               printf("With a=%d, b=%d.\n", a,b);
 return EXIT_SUCCESS;
}
