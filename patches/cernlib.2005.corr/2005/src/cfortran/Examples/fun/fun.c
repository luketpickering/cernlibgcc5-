/* fun.c == fun.C */           /* anonymous ftp@zebra.desy.de */
/* An example from cfortran.h package. Requires fun_f.f       */
/* Burkhard Burow  burow@desy.de                 1990 - 1997. */

#include <stdio.h>
#include <stdlib.h>    /* EXIT_SUCCESS */
#include "cfortran.h"

PROTOCCALLSFFUN3(INT,FUNADD,funadd,ROUTINE,INT,INT)
#define FUNADD(F,A,B) CCALLSFFUN3(FUNADD,funadd, ROUTINE, INT, INT, F, A, B)

int Cadd(int a, int b) {return a+b;}
FCALLSCFUN2(INT,Cadd,CADD,cadd, INT, INT)

/* Want fadd to be prototyped, though don't need the wrapper that is created. */
PROTOCCALLSFFUN2(INT,FADD,fadd,INT,INT)

main() {

printf("\nFUNADD(CADD,1,2) returns %d\n", 
       FUNADD(      C_FUNCTION(CADD,cadd),1,2) );
printf("\nFUNADD(FADD,3,4) returns %d\n", 
       FUNADD(FORTRAN_FUNCTION(FADD,fadd),3,4) );
return EXIT_SUCCESS;
}
