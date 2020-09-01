/* ss1.c == ss1.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires ss1_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


                       PROTOCCALLSFSUB1(SS1,ss1, PSTRING)
#define SS1(A1)             CCALLSFSUB1(SS1,ss1, PSTRING, A1)
                       PROTOCCALLSFSUB1(FORSTR1,forstr1, PSTRING)
#define FORSTR1(A1)         CCALLSFSUB1(FORSTR1,forstr1, PSTRING, A1)

main() {
static char b[] = "abcdefghij", forb[13] = "abcdefghijkl";
SS1(b); FORSTR1(forb);
printf("SS1(b) returns b = %s; FORSTR1(forb) = returns forb = %s;\n", b, forb);
return EXIT_SUCCESS;
}
