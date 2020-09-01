/* f0.c == f0.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires f0_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#include "cfortran.h"


void Exist() {printf("exist: was called.\n");}
FCALLSCSUB0(Exist,EXIST,exist)


                          PROTOCCALLSFSUB0(FEXIST,fexist)
#define FEXIST()               CCALLSFSUB0(FEXIST,fexist)

main() {FEXIST(); return EXIT_SUCCESS;}
