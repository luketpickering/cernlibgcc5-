/* fa.c == fa.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fa_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


void ca(int i) {printf("ca: had integer argument:%d.\n",i);}
FCALLSCSUB1(ca,CFORTRANCA,cfortranca, INT)
/*           ^      ^-----------^---------FORTRAN name. 
 *           |__ C name.
 * i.e. the C routine ca is named cfortranca when called from Fortran.
 */

                        PROTOCCALLSFSUB1(FA,fa, INT)
#define FA(A1)               CCALLSFSUB1(FA,fa, INT, A1)

main() {FA(1234); return EXIT_SUCCESS;}
