/* ff.c == ff.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires ff_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

void Ccff(char v[][5], int n)
{int i;
printf("ccff: had %d string vector argument:",n);
for (i=0; i<n-1; i++) printf("%s,",v[i]);
printf("%s.\n",v[i]);
}
#define ccff_STRV_A1 NUM_ELEM_ARG(2)
FCALLSCSUB2(Ccff,CCFF,ccff, STRINGV, INT)

                        PROTOCCALLSFSUB2(FF,ff, STRINGV, INT)
#define FF(A1,A2)            CCALLSFSUB2(FF,ff, STRINGV, INT, A1, A2)

main() 
{static char v[][5] = {"0000", "1", "22", ""}; 
 FF(v,sizeof(v)/sizeof v[0]);
 return EXIT_SUCCESS;
}
