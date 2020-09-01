/* fg.c == fg.C */             /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fg_f.f        */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

int Ccg() {return 111;}
FCALLSCFUN0(INT,Ccg,CCG,ccg)

PROTOCCALLSFFUN0(INT,FG,fg)
#define FG()               CCALLSFFUN0(FG,fg)

main() 
{printf("FG() returns %d.\n",FG()); return EXIT_SUCCESS;}
