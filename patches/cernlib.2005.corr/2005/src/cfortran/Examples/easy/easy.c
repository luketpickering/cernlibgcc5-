/* easy.c */                   /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires easy_f.f      */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


                  PROTOCCALLSFSUB2(EASY,easy, PINT, INT)
#define EASY(A,B)      CCALLSFSUB2(EASY,easy, PINT, INT, A, B)

main() {
int a;
EASY(a,7);
printf("The FORTRAN routine EASY(a,7) returns a = %d\n", a);
return EXIT_SUCCESS;
}
