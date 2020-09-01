/* e2.c == e2.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires e2_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

/* Only to demo. that we can force a wrapper to be used for subroutines. */
PROTOCCALLSFFUN2(VOID,EASY,easy,PINT,INT)
#define EASY(A,B)      CCALLSFFUN2(EASY,easy, PINT, INT, A, B)

main() {
int a;
printf("\nEASY (2) EXAMPLE\n");
EASY(a,7);
printf("The FORTRAN routine EASY(a,7) returns a = %d\n", a);
return EXIT_SUCCESS;
}
