/* fstrtok.c == fstrtok.C */   /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fstrtok_f.f   */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"



#include <string.h>
FCALLSCFUN2(STRING,strtok,CSTRTOK,cstrtok, STRING, STRING)

                  PROTOCCALLSFSUB0(FSTRTOK,fstrtok)
#define FSTRTOK()      CCALLSFSUB0(FSTRTOK,fstrtok)

main() {FSTRTOK(); return EXIT_SUCCESS;}
