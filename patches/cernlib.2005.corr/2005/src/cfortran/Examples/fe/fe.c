/* fe.c == fe.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fe_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

void Ce(char v[][5])
{printf("ce: had string vector argument:%s,%s,%s.\n",v[0],v[1],v[2]);}
#define ce_STRV_A1 TERM_CHARS(' ',1)
FCALLSCSUB1(Ce,CE,ce, STRINGV)


                        PROTOCCALLSFSUB1(FE,fe, STRINGV)
#define FE(A1)               CCALLSFSUB1(FE,fe, STRINGV, A1)

main() 
{static char v[][5] = {"0000", "1", "22", ""}; FE(v); return EXIT_SUCCESS;}
