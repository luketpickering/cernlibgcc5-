/* abc.c == abc.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires abc_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


                 PROTOCCALLSFSUB3(ABC,abc, STRING, PSTRING, PSTRING)
#define ABC(A1,A2,A3) CCALLSFSUB3(ABC,abc, STRING, PSTRING, PSTRING, A1, A2, A3)

main() {
static char aa[] = "one  ", bb[] = "two  ", cc[] = "three"; int i; 
for (i=0; i<10; i++) {printf("%s;%s;%s;\n",aa,bb,cc); ABC(aa,bb,cc);}
return EXIT_SUCCESS;
}
